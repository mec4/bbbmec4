#include "librairies/init.h"


int main(int argc, char *argv[]){

	
	//init_utilisateur();
	init();
	envoie_i();
	while((rc_get_state()!=EXITING)&&(chute!=-1)){
		lire_imu();
		//imu2csv();
		//detection();
		envoie_go();
		
	}
	rc_power_off_imu();
	rc_power_off_barometer();
	rc_cleanup();
	return 0;
}
