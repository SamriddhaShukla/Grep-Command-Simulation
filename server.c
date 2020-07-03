#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include "server.h"

//To check the validity of the filename given
int checkFile(){
    FILE *fp;


    fp = fopen(filename, "r");
    if(fp != NULL){
        return 1;

    }
    return 0;
}

//To give a disclaimer of the manner of input and available options
void printUsage() {
  puts("usage: ./grep [-options] [contentToSearchFor] [fileToSearchIn]");
  puts("[-c] Print only count of the lines\n[-i] Make results case insensitive \n[-n] Gives line number of pattern match with the line\n[-v] Reverses search giving NOT containing string (invert result) \n[-e] For no options \n[-f] For checking if the given file has atleast one instance of the given pattern.");
}


//checking whether the input in the option section is valid
int checkValidInput() {

    if(!strcmp(option, "-i") || !strcmp(option, "-c") || !strcmp(option, "-l") || !strcmp(option, "-n") || !strcmp(option, "-v") || !strcmp(option, "-x") || !strcmp(option, "-w")) {
            return 1;
    }
    return 0;
}

//taking in the option input and turning it into the function to be followed with
void OptionBasedExecution() {
    if (strcmp(option, "-i")==0){
        CaseInsensitive();
    }
    else if (strcmp(option, "-c")==0){
            CountLines();

    }
    else if (strcmp(option, "-v")==0){
            InvertMatch();

    }
    else if (strcmp(option, "-e")==0){
            BasicMatch();

    }
    else if (strcmp(option, "-n")==0){
            SerialisedLines();

    }
    else if (strcmp(option, "-f")==0){
            MatchStatus();

    }
    else {
        printf("enter the correct input ");
    }
}

//in case of option -i it gives output for pattern matches irrespective of one being upper and the other being lower case .
void CaseInsensitive(){

    fp = fopen(filename, "r");
    switchtolower();
	while(fgets(line, 1024, fp))
	{
		lowertheline();
		if(strstr(low_line, low_pattern) != NULL)
			printf("%s\n", line);
	}
	fclose(fp);
}

//changes the parameter to be searched to lowercase
void switchtolower(){

    for(int i = 0; parameter[i]; i++){
            low_pattern[i] = tolower(parameter[i]);
    }
}

//changes the line being read to lowercase for the -i option
void lowertheline(){

    for(int i = 0; line[i]; i++){
            low_line[i] = tolower(line[i]);
    }
}

//in case of option -c it gives output for the number of lines containing a matched pattern .
void CountLines(){
	fp = fopen(filename, "r");
    while(fgets(line, 1024, fp)){
            if(strstr(line, parameter) != NULL){
                lineno++;
            }


    }
    printf("The number of lines containing \"%s\" is %d",parameter,lineno);
	fclose(fp);
}

//in case of option -v prints out the lines not containing the given parameter/pattern
void InvertMatch(){

    fp = fopen(filename, "r");

	while(fgets(line, 1024, fp))
	{

		if(strstr(line, parameter) = NULL)
			printf("%s\n", line);
	}
	fclose(fp);
}

//in case of option -e or a argc==3 it gives a basic grep output as print
void BasicMatch(){

    fp = fopen(filename, "r");

	while(fgets(line, 1024, fp))
	{

		if(strstr(line, parameter) != NULL)
			printf("%s\n", line);
	}
	fclose(fp);
}

void SerialisedLines(){
	fp = fopen(filename, "r");
    while(fgets(line, 1024, fp)){
            if(strstr(line, parameter) != NULL){
                lineno++;
                printf("Line No: %d :- %s",lineno,line)
            }
            else if(strstr(line, parameter) = NULL){
                lineno++
            }


    }

	fclose(fp);
}

void MatchStatus(){

    fp = fopen(filename, "r");

	while(fgets(line, 1024, fp))
	{

		if(strstr(line, parameter) != NULL)
			lineno++;
	}
	if(lineno>=1){
        printf("Yes , the file : %s contains the given pattern .",filename)
	}

	fclose(fp);
}

