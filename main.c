#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include "server.h"

char low_line[512];
char low_pattern[512];
int wordcount=0, lineno=0;
FILE *fp;
char filename[256], option[10], parameter[512], line[512];

int main(int argc , char*argv[])
{

    int i , j ;


    if(argc >= 3) {

        if(argc == 4) {
            strncpy(option, argv[1], sizeof(option));
            strncpy(parameter, argv[2], sizeof(parameter));
            strncpy(filename, argv[3], sizeof(filename));
            if(checkValidInput(option)){
                    if(checkFile()){
                        OptionBasedExecution();
                    }

            }
            else {
                printUsage();
            }

        }
        else if (argc==3){
            strncpy(parameter, argv[1], sizeof(parameter));
            strncpy(filename, argv[2], sizeof(filename));
            BasicMatch();

        }
    }else {
            printUsage();
    }
    return 0;
}
