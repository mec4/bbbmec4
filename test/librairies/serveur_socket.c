



/*	if(rc_initialize_imu(&data, conf)){
		fprintf(stderr,"rc_initialize_imu_failed\n");
		return -1;
	}
*/

void envoie_i(void){

	lsockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(lsockfd < 0)
	{
		printf("erreur socket\n");
		
	}

	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(MY_PORT);
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);

	ret = bind(lsockfd, (struct sockaddr *)&serv_addr, sizeof(struct sockaddr));
	if(ret < 0)
	{
		printf("erreur bind\n");
		
	}

	printf("listening\n");
	ret = listen(lsockfd, 10);
	if(ret < 0)
	{
		printf("erreur listen\n");
		
	}

	printf("accepting\n");
	csockfd = accept(lsockfd, (struct sockaddr *)NULL, NULL);
	if(csockfd < 0)
	{
		printf("erreur accept\n");
		
	}
	printf("client connecté \n");


//Accelerometre

	//double altitude, filtered_alt;
	//rc_filter_t lowpass = rc_empty_filter(); //Filtre passe bas altimètre
	//rc_imu_data_t data; //struct to hold new data
	//rc_imu_config_t conf = rc_default_imu_config();




//float tim=0;
}
void envoie_go(void){

	//rc_usleep(1000000/BMP_CHECK_HZ);
	//rc_usleep(100000);
char temp[500];
if(stack_envoi==4){
	ret = write(csockfd, &buf, sizeof(buf));
	if(ret <= 0)
		{
			printf("erreur write value\n");
			
		}
		stack_envoi=1;
		memset(buf,0,strlen(buf));
		//envoi des données
		sprintf(buf, "%6.2f,%6.2f,%6.2f,%6.1f,%6.1f,%6.1f,%8.2f,%6.2f \n ", data.accel[0], data.accel[1], data.accel[2], data.gyro[0]*DEG_TO_RAD, data.gyro[1]*DEG_TO_RAD, data.gyro[2]*DEG_TO_RAD, filtered_alt, tim);	
		printf(" by string : %s", buf);
	}
	else{
		memset(temp,0,strlen(temp));
		sprintf(temp, "%6.2f,%6.2f,%6.2f,%6.1f,%6.1f,%6.1f,%8.2f,%6.2f \n ", data.accel[0], data.accel[1], data.accel[2], data.gyro[0]*DEG_TO_RAD, data.gyro[1]*DEG_TO_RAD, data.gyro[2]*DEG_TO_RAD, filtered_alt, tim);
		strcat(buf, temp);

		printf("\nbuf = %s\n", buf);
		stack_envoi++;
		printf("stack_envoi = %d", stack_envoi);
	}
}
