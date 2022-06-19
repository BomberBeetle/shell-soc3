#include "datahora.h"
#include "../command.h"

#include <time.h>
#include <stdio.h>

int data(int argc, char *argv[]){

    time_t rawtime;
    struct tm * timeinfo;

    time ( &rawtime );
    timeinfo = localtime ( &rawtime );

    char datastr[25];
    strftime(datastr, sizeof datastr, "%d/%m/%Y", timeinfo);

    printf( "Data atual: %s\n", datastr );

    return RESULT_SUCCESS;
}

int hora(int argc, char *argv[]){

    time_t rawtime;
    struct tm * timeinfo;

    time ( &rawtime );
    timeinfo = localtime ( &rawtime );

    char datastr[25];
    strftime(datastr, sizeof datastr, "%H:%M", timeinfo);

    printf( "Hora atual: %s\n", datastr );

    return RESULT_SUCCESS;
}