#include "librairies/init.c"


int main(int argc, char *argv[]){

	init();
	//init_utilisateur();
	//sms(0612557877,"bonjour");
	envoie_i();
	while((rc_get_state()!=EXITING)&&(chute!=-1)){
		lire_imu();
		//imu2csv();
		//detection();
		//puts("hello");
		envoie_go();
		//rc_usleep(1000);
	}
	arret();
	return 0;
}
