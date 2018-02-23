#include<stdio.h>
#include<stdlib.h>

int status;


void sms(char num[], char mess[]){
    int system(const char *command);
    system("gammu entersecuritycode PIN 9482");
    
    char hey[200];
    sprintf(hey, "gammu sendsms TEXT %s -text \" %s \"", num, mess);
    printf("%s", hey);
    //hey = "gammu sendsms TEXT " + num + " -text \"" + mess + "\"";
    FILE *fp = popen(hey, "w");
    status = pclose(fp);
}

