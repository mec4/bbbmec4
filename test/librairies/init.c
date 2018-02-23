#include <rc_usefulincludes.h> 
// main roboticscape API header
#include <roboticscape.h>
#include "param.h"
#include "init_utilisateur.c"
#include "imu.c"
#include "detection.c"
#include "serveur_socket.c"
#include "sms.c"



// choice of 1,2,4,8,16 oversampling. Here we use 16 and sample at 25hz which
// is close to the update rate specified in robotics_cape.h for that oversample.
#define OVERSAMPLE  BMP_OVERSAMPLE_16
// choice of OFF, 2, 4, 8, 16 filter constants. Here we turn off the filter and
// opt to use our own 2nd order filter instead.
#define INTERNAL_FILTER	BMP_FILTER_OFF



//bouttons
void on_pause_pressed(){
	rc_set_led(RED, ON);
	chute = -1;
	printf("Appel au secours demandé\n");
	sprintf(comm, "echo \"L'utilisateur a appuyé sur le bouton d'appel au secours\" | mutt -x -s \"Alerte : l'utilisateur requiert de l'aide\" info.mec4@gmail.com -a data.csv");
	system(comm);

	//return;
}

void on_mode_pressed(){
	if((compteur >nb_e )&& (compteur<(nb_e+nb_check))){
		printf("La personne ne requiert pas l'appel des secours\n");
		rc_set_led(RED, OFF);
		compteur = 0;
		etat = 0;
	}
	//return;
}

int init(void){

	
	rc_imu_config_t conf = rc_default_imu_config();
	rc_filter_t lowpass = rc_empty_filter(); //Filtre passe bas altimètre

	// initialize hardware first
	if(rc_initialize()){
		fprintf(stderr,"ERROR: failed to run rc_initialize(), are you root?\n");
		return -1;
	}

	//boutons
	rc_set_pause_pressed_func(&on_pause_pressed);
	rc_set_mode_pressed_func(&on_mode_pressed);

	if(rc_initialize_imu(&data, conf)){
		fprintf(stderr,"rc_initialize_imu_failed\n");
		return -1;
	}

	if(rc_initialize_barometer(OVERSAMPLE, INTERNAL_FILTER)<0){
		fprintf(stderr,"ERROR: rc_initialize_barometer failed\n");
		return -1;
	}

	// create the lowpass filter and prefill with current altitude
	if(rc_butterworth_lowpass(&lowpass,ORDER, DT, CUTOFF_FREQ)){
		fprintf(stderr,"ERROR: failed to make butterworth filter\n");
		return -1;
	}

	printf("Démarage\n");
	altitude = rc_bmp_get_altitude_m();
	rc_prefill_filter_inputs(&lowpass, altitude);
	rc_prefill_filter_outputs(&lowpass, altitude);

		fd = open("data.csv", O_CREAT|O_WRONLY|O_TRUNC);
			if(fd < 0)
			{
				printf("erreur open\n");
				return -1;
			}
			system("chmod a+rw data.csv");

	return 0;
}

void arret(void){
	rc_power_off_imu();
	rc_power_off_barometer();
	rc_cleanup();
}