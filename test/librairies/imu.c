extern float tim;
extern float pas;
void lire_imu(void){
    	
    	rc_usleep(1000000*pas);
		tim+=pas;
		
		if(rc_read_barometer()<0){
			fprintf(stderr,"\rERROR: Can't read Barometer");
			//fflush(stdout);
			//continue;
		}

		if(rc_read_accel_data(&data)<0){
			printf("read accel data failed\n");
		}

		if(rc_read_gyro_data(&data)<0){
			printf("read gyro data failed\n");
		}

		// if we got here, new data was read and is ready to be accessed.
		// these are very fast function calls and don't actually use i2c
		float alr;
		alr = sqrt(data.accel[0]*data.accel[0]+data.accel[1]*data.accel[1]+data.accel[2]*data.accel[2]);
		if(alr<8){
			pas = 0.01;
		}
		
		altitude = rc_bmp_get_altitude_m();
		//filtered_alt = rc_march_filter(&lowpass,altitude);
		//rc_read_accel_data(&data);
		//rc_read_gyro_data(&data);

        printf("%6.2f,%6.2f,%6.2f,%6.1f,%6.1f,%6.1f,%8.2f,%6.2f\n", data.accel[0], data.accel[1], data.accel[2], data.gyro[0]*DEG_TO_RAD, data.gyro[1]*DEG_TO_RAD, data.gyro[2]*DEG_TO_RAD, filtered_alt, tim);
        
}

int imu2csv(void){
	//envoie des données dans le fichier data.csv
		sprintf(buf, "%6.2f,%6.2f,%6.2f,%6.1f,%6.1f,%6.1f,%8.2f,%6.2f\n", data.accel[0], data.accel[1], data.accel[2], data.gyro[0]*DEG_TO_RAD, data.gyro[1]*DEG_TO_RAD, data.gyro[2]*DEG_TO_RAD, filtered_alt, tim);
		
		ret = write(fd, buf, strlen(buf));
		if(ret <= 0){
				printf("erreur write\n");
			return -1;
		}
		//printf("written \n");
		//close(fd);
		
		return 0;
}