/*
 * CSE30 WI22 HW3
 * Username: cs30wi22fh 
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char* argv[]) {
	/* Local Variables */
	int lines = 0;
	size_t fieldCharacter = 0;
	int length;
	if(strcmp(argv[1],"-c")!=0){
		length = argc-2; 
	}
	else{
		length = argc-3;
	}
	int *obuf = malloc(length*sizeof(int));
        char ** buf;	
	if(length==argc-2){
		buf = malloc(atoi(argv[1])*sizeof(char*));
	}
	else{
		buf = malloc(atoi(argv[2])*sizeof(char*));
	}
	char* readbuffer = NULL;
	/* save th e other cli args */
	int index=0;
	int k;
	//if not '-c'
	if(length==argc-2){
		k=2;
	}
	//if has '-c'
	else{
		k=3;
	}
	while(k<argc){
		obuf[index]=atoi(argv[k]);
		index++;
		k++;
	} 
	/* process the input as described in the writeup */
	int i = 0;
	int l = 0;
	int prev=0;
	int current=0;
	int longest;
	while(getline(&readbuffer,&fieldCharacter,stdin)!=-1){ 
		while(readbuffer[l] != '\0'){
			prev = current;
			buf[i]=&readbuffer[l];
			l++;
			while(readbuffer[l]!=' ' &readbuffer[l]!='\n'&readbuffer[l]!='\t'){
			l++;
			}
			current = l - prev;
			if(current < prev){
				longest = prev;
			}
			else{
				longest = current;
			}
			readbuffer[l]='\0';
			l++;
			while(readbuffer[l]=='\t' || readbuffer[l] == ' '){
			l++;
			}
			i++;
		}
		for(int l = 0;l<length;l++){
			if(obuf[l]<0){
				if(length==argc-2){
					int revInd = atoi(argv[1])+obuf[l];
					printf("%s",buf[revInd]);
				}
				else{
					int revInd = atoi(argv[2])+obuf[l];
					printf("%s",buf[revInd]);
				}
			}
			else{
				printf("%s",buf[obuf[l]]);
			}
			if(l<length-1){
				printf(" ");
			}
			else{
				printf("\n");
				lines++;
			}
		}
		l = 0;
		i = 0;	
	}
	if(length == argc-3){
		printf("Number of lines: %d\n"
		"Longest field: %d characters\n",
		lines,longest);
	}
	free(buf);
	free(obuf);
	return 0;
}