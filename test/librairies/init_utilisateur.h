


void init_utilisateur (void){
    FILE* fichier = NULL;
    fichier = fopen("info.txt", "r");

    if (fichier != NULL){
	//ON CHERCHE LE NOMBRE DE LIGNES
	puts("fichier ouvert");
	int nb_ligne=0;
	char c;
	do{
		c= fgetc(fichier);
		if(c=='\n'){
			nb_ligne++;
		}
	}while(nb_ligne<3);//(c!=EOF);
	printf("nombre de ligne : %d \n\n", nb_ligne);

	//On replace le curseur au debut du fichier
	fseek( fichier, 0, SEEK_SET );
printf("nombre de ligne %d", nb_ligne);

	//Définition des tableaux qui vont stocker les données

	//char contact4[5][TAILLE_MAX];
	//char contact5[5][TAILLE_MAX];

//On va parser chaque ligne indépendamment, et on va incorporer ça dans le tableau correspondant. Le nombre de chaine a lire dépend du nombre de ligne dans le .txt

//Déclaration des variables utilisées pour le parsing :

	int mot=0;
	int debutmot=0;
	int i=0;
	int j=0;
	int k=0;
	int longueurmot=0;
	int u,v;
	int longueurChaine;


	//Parsing chaine1
	if(nb_ligne>0){

		char chaine[TAILLE_MAX] = ""; //Contient user
		fgets(chaine, TAILLE_MAX, fichier); //On récupère la première ligne du fichier
		mot=0;
		debutmot=0;
		i=0;
		j=0;
		k=0;
		longueurmot=0;

		//Initialisation du tableau
		for(u=0;u<TAILLE_MAX;u++){
			for(v=0;v<5;v++){
				user[v][u]='\0';
			}
		}
		//Remplissage du Tableau avec le parsing
		longueurChaine = strlen(chaine);
		for(i=0;i<=longueurChaine;i++){
			if ((chaine[i] == ',')||(chaine[i]=='\n')){
				longueurmot=i-debutmot;
				for(j=debutmot;j<=i-1;j++){
					user[mot][j-debutmot]=chaine[j]; //On concatène notre chaine avec le caractère
				}
				debutmot=debutmot+longueurmot+1;
				mot++; //On passe à la case suivante

			}
		}
		//On vérifie le résulat
		for (k=0;k<5;k++){
			printf("user %d : %s \n", k, user[k]);
		}
	}



	//Parsing Contact1
	if(nb_ligne>1){

		for(u=0;u<TAILLE_MAX;u++){
			for(v=0;v<5;v++){
				contact1[v][u]='\0';
			}
		}

		char chaine1[TAILLE_MAX] = ""; //Contient contact 1
		fgets(chaine1, TAILLE_MAX, fichier);

		//réinitialisation des variables
		mot=0;
		debutmot=0;
		i=0;
		j=0;
		k=0;
		longueurmot=0;

		longueurChaine = strlen(chaine1);
		for(i=0;i<=longueurChaine;i++){
			if ((chaine1[i] == ',')||(chaine1[i]=='\n')){
				longueurmot=i-debutmot;
				for(j=debutmot;j<=i-1;j++){
					contact1[mot][j-debutmot]=chaine1[j]; //On concatène notre chaine
				}
				debutmot=debutmot+longueurmot+1;
				mot++; //On passe à la case suivante
			}
		}
		for (k=0;k<5;k++){
			printf("contact 1 : %d : %s \n", k, contact1[k]);
		}
	}


//Parsing Contact2
	if(nb_ligne>2){

		for(u=0;u<TAILLE_MAX;u++){
			for(v=0;v<5;v++){
				contact2[v][u]='\0';
			}
		}

		char chaine2[TAILLE_MAX] = "";
		fgets(chaine2, TAILLE_MAX, fichier);
		mot=0;
		debutmot=0;
		i=0;
		j=0;
		k=0;
		longueurmot=0;

		longueurChaine = strlen(chaine2);
		for(i=0;i<=longueurChaine;i++){
			if ((chaine2[i] == ',')||(chaine2[i]=='\n')){
				longueurmot=i-debutmot;
				for(j=debutmot;j<=i-1;j++){
					contact2[mot][j-debutmot]=chaine2[j]; //On concatène notre chaine
				}
				debutmot=debutmot+longueurmot+1;
				mot++; //On passe à la case suivante
			}
		}
		for (k=0;k<5;k++){
			printf("contact 2: %d : %s \n", k, contact2[k]);
		}
	}
puts("fin parsing");
/*
//Parsing Contact3
	if(nb_ligne>3){

		for(u=0;u<TAILLE_MAX;u++){
			for(v=0;v<5;v++){
				contact3[v][u]='\0';
			}
		}

		char chaine3[TAILLE_MAX] = "";
		fgets(chaine3, TAILLE_MAX, fichier);
		mot=0;
		debutmot=0;
		i=0;
		j=0;
		k=0;
		longueurmot=0;

		longueurChaine = strlen(chaine3);
		for(i=0;i<=longueurChaine;i++){
			if ((chaine3[i] == ',')||(chaine3[i]=='\n')){
				longueurmot=i-debutmot;
				for(j=debutmot;j<=i-1;j++){
					contact3[mot][j-debutmot]=chaine3[j]; //On concatène notre chaine
				}
				debutmot=debutmot+longueurmot+1;
				mot++; //On passe à la case suivante
			}
		}
		for (k=0;k<5;k++){
			printf("contact 3 : %d : %s \n", k, contact3[k]);
		}
	}
*/

}




//Fin Parsing
}