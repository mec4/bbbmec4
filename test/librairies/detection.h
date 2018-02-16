
void detection(void){


		alr = sqrt(data.accel[0]*data.accel[0]+data.accel[1]*data.accel[1]+data.accel[2]*data.accel[2]);

		//affichage terminal
		//printf("in printf : %6.2f,%6.2f,%6.2f,%6.1f,%6.1f,%6.1f,%8.2f,%6.2f,%6.2f\n", data.accel[0], data.accel[1], data.accel[2], data.gyro[0]*DEG_TO_RAD, data.gyro[1]*DEG_TO_RAD, data.gyro[2]*DEG_TO_RAD, filtered_alt, tim,alr);
		printf("t = %6.2f s -> alr =%6.2f m/s² \n",tim,alr);

		


		if(((compteur > 0) && (compteur < nb_e))||(alr > sh_alr)){
			etat = 1;
		}
		else if(compteur == nb_e){
			etat = 2;
		}
		else if((compteur > nb_e) && (compteur< (nb_e + nb_check))){
			etat =3;
		}
		else if(compteur == (nb_e + nb_check)){
			etat = 4;
		}
		else if(compteur == 0){
			etat = 0;
		}


		switch(etat){
			case 0 :	printf("Etat 0 \t");
						//Detection de chute active
						break;
			case 1 :	printf("etat 1 \t");
						//Chute détectée
						valeur[compteur]=alr;
						compteur+=1;
						rc_set_led(RED, ON);
						break;

			case 2 :	printf("etat 2 \t");
						alr_max=valeur[0];
						t_alr_max=tim-(nb_e-1)*pas;

						for(q=1;q==nb_e-1;q++){
							if(valeur[q]>alr_max){
								alr_max=valeur[q];
								t_alr_max+=q*pas;
							}
						}
						compteur += 1;
						break;

			case 3 :	printf("etat 3 \t");
						compteur += 1;
						break;

			case 4 :	printf("etat 4 \t");
						//sprintf(comm, "echo \"une chute à été detectée, pas de reponse de l'utilisateur. Valeur pic alr= %d à t simu= %6.2f secondes \" | mutt -x -s \"Alerte : Chute + utilisateur inconcient?\" info.mec4@gmail.com -a data.csv", alr_max, t_alr_max);
sprintf(comm, "echo \"Bonjour %s %s,\n une chute à été detectée au domicile de %s %s (adresse : %s), pas de reponse de l'utilisateur. Valeur pic alr= %d à t simu= %6.2f secondes \" | mutt -x -s \"Alerte : Chute + utilisateur inconcient?\" %s -a data.csv", contact1[2], contact1[0], user[0], user[1], user[2], alr_max, t_alr_max, contact1[3]);
system(comm);
						printf("chute détectée à alr= %d à t simu= %6.2f secondes\n",alr_max,t_alr_max);
						chute = -1;
						break;

			default :	break;
		}
}