#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#define ARRAY_SIZE 23
void simulate(int table[ARRAY_SIZE][ARRAY_SIZE]);
void tableprint(int table[ARRAY_SIZE][ARRAY_SIZE]);

int main (int argc, char *argv[]){
  int table[ARRAY_SIZE][ARRAY_SIZE] = {0};
  int fps;
  
  if(argc > 1){
    if(!strcmp("--fps", argv[1])){
     fps = atoi(argv[2]);
     int j = 3;
     while (j<argc){
       //preventing sink at center
       if(atoi(argv[j]) == 11 && atoi(argv[j+1]) == 11 && atoi(argv[j+2]) == -1){
	j+=3;
       }
       else{
	table[atoi(argv[j])][atoi(argv[j+1])] = atoi(argv[j+2]);
	tableprint(table);
	j+=3;
       }
     }
    }

    fps = 1;
    int i = 1;
    while (i<argc){
      //preventing sink at center
      if(atoi(argv[i]) == 11 && atoi(argv[i+1]) == 11 && atoi(argv[i+2]) == -1){
	i+=3;
      }
      else{
	table[atoi(argv[i])][atoi(argv[i+1])] = atoi(argv[i+2]);
	tableprint(table);
	i+=3;
      }
    }
  }

  while(1){
    
    simulate(table);
    tableprint(table);
    usleep(1000000/fps);
  }
  
  return 0;
}

void tableprint(int table[ARRAY_SIZE][ARRAY_SIZE]){
  int j, i;
  for (j = 0; j < ARRAY_SIZE; j++){
    printf("\n");
    for (i = 0; i < ARRAY_SIZE; i++){
      if (table[j][i] == -1){
	printf(" #");
      }
      else{
	printf(" %d",table[j][i]);
      }
    }
  }
  printf("\n");
}

void simulate(int table[ARRAY_SIZE][ARRAY_SIZE]){

  int center = ARRAY_SIZE/2;

  table[center][center]++;

  int i;
  int j;
  bool topple = true; //signals whether a topple has occurred or not

  while (topple){
    topple = false;
    j=0;
    i=0;
  for (j = 0; j < ARRAY_SIZE; j++){
    tableprint(table);
    for (i = 0; i < ARRAY_SIZE; i++){
      if (table[j][i] > 8){
	table[j][i] = 1;
	topple = true;
	if (j-1 > 0 || i-1 > 0 || table[j-1][i-1] != -1){
	  table[j-1][i-1]++;
	}
	if (j-1 > 0 || i+1 < ARRAY_SIZE || table[j-1][i+1] != -1){
	  table[j-1][i+1]++;
	}
	if (j+1 < ARRAY_SIZE || i-1 > 0 || table[j+1][i-1] != -1){
	  table[j+1][i-1]++;
	}
	if (j+1 < ARRAY_SIZE || i+1 < ARRAY_SIZE || table[j+1][i+1] != -1){
	  table[j+1][i+1]++;
	}
	
	if (j-1 > 0 || table[j-1][i] != -1){
	  table[j-1][i]++;
	}
	if (i-1 > 0 || table[j][i-1] != -1){
	  table[j][i-1]++;
	}
       	if (i+1 < ARRAY_SIZE || table[j][i+1] != -1){
	  table[j][i+1]++;
	}
	if (j+1 < ARRAY_SIZE || table[j+1][i] != -1){
	  table[j+1][i]++;
	}
      }
    }
  }
  }
}
	
