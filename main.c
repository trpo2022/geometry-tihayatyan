#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXIMUM 269

typedef struct Coord{
	char coor[30];
} co;

int main(void){
	char ch1[] = "Circle\0";
	char ch2[] = "(, , )\0";
	char str[MAXIMUM];
	char name[10];
	co coordin[10];

	int n = 0;
	int k = 0;

	puts("Enter string:\n");
	fgets(str, MAXIMUM - 1, stdin);

	for(int i = 0; ch1[i] != '\0'; i++){
		if(islower(str[0])){
			puts("1st letter must be in upper case.\n");
			break;
		}
		if(str[i] == ch1[i]){
			n++;
			name[i] = str[i];
		}
		k = i + 2;
	}

	int c = 0;
	if(n != strlen(ch1)){
		puts("Check name or bracket.");
		c++;
	}

	int m = 0;
	int j = 0;
	int com = 0;

	for(int i = k; str[i] != ')'; i++){

		if(c != 0) break;

		if(str[i] == ' '){
			n++;
			continue;
		}

		if(str[i] == '.' || isdigit(str[i])){
			coordin[m].coor[j] = str[i];
			j++;
		}
		else if(str[i] == ','){
			m++;
			n++;
			com++;
			j = 0;
		}
		else{
			puts("Check input data or commas.\n");
			break;
		}
	}
	int l = 0;
	while(l < 3){
		if(com < 2){
			puts("Too few args, try again.\n");
			break;
		}

		printf("Объект: %s\n", name);
		l++;

		printf("Координаты: (%s, %s)\n", coordin[0].coor, coordin[1].coor);
		l++;

		printf("Радиус: %s\n", coordin[2].coor);
		l++;
	}
return 0;
}
