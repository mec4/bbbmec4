#define TAILLE_MAX 256
char user[5][TAILLE_MAX]; //Le nombre de lignes du tableau dépend du nombre d'informations à récupérer
char contact1[5][TAILLE_MAX];
char contact2[5][TAILLE_MAX];
//char contact3[5][TAILLE_MAX];


//Sockets
#define MY_PORT		5000
int lsockfd, csockfd;
int ret;
char buf[1600];
struct sockaddr_in serv_addr;
	
char comm[256];

int system(const char *command);
	
	// our own low pass filter
#define ORDER			2
#define CUTOFF_FREQ		2.0f	// 2rad/s, about 0.3hz
#define BMP_CHECK_HZ	25
#define	DT				1.0f/BMP_CHECK_HZ

//Paramètres
#define nb_e 5 //nombre échantillon de détection de chute
#define nb_check 50 //nb de boucle apres chute de demande d etat de la personne
#define sh_alr 40 //seuil haut
float pas=0.05;
int stack_envoi=0;
int chute=0; // flag de chute détectée
int compteur = 0;
int etat =0;

float valeur[nb_e];
float alr; //résultante de l'accélération
int alr_max=0; //valeur max de alr lors d'une chute
float t_alr_max=0; // temps corresponds a alr_max
//int i=0; //variable d'itération de boucle
int q=0;
int ret;

//Accelerometre

double altitude, filtered_alt;
	
rc_imu_data_t data; //struct to hold new data
float tim=0;
rc_filter_t lowpass;
    

int fd;
			