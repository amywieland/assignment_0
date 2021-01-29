#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define ARRAY_SIZE 25
void simulate(int table[ARRAY_SIZE][ARRAY_SIZE]);
void tableprint(int table[ARRAY_SIZE][ARRAY_SIZE]);

int main (int argc, char *argv[]){
  int table[ARRAY_SIZE][ARRAY_SIZE] = {0};

  if(argc > 1){
    if(!strcmp("--fps", argv[1])){
      // int fps = atoi(argv[2]);
     int j = 3;
     while (j<argc){
       table[atoi(argv[j])][atoi(argv[j+1])] = atoi(argv[j+2]);
       j+=3;
     }
    }
    
    int i = 1;
    while (i<argc){
      table[atoi(argv[i])][atoi(argv[i+1])] = atoi(argv[i+2]);
      i+=3;
    }
  }
 
  //setting bounds of the table = to -1
  
  int j;
  for (j = 0; j < ARRAY_SIZE; j++){
    table[j][0] = -1;
    table[j][ARRAY_SIZE] = -1;
  }

  int i;
  for (i = 0; j < ARRAY_SIZE; i++){
    table[0][i] = -1;
    table[ARRAY_SIZE][i] = -1;
  }

  simulate(table);
  
  return 0;
}

void tableprint(int table[ARRAY_SIZE][ARRAY_SIZE]){
  int j, i;
  for (j = 1; j < ARRAY_SIZE-1 ; j++){
    printf("\n");
    for (i = 1; i < ARRAY_SIZE-1 ; i++){
      if (table[j][i] == -1){
	printf(" #");
      }
      else{
      printf(" %d",table[j][i]);
      }
    }
  }
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
	if (table[j-1][i-1] != -1){
	  table[j-1][i-1]++;
	}
	if (table[j-1][i+1] != -1){
	  table[j-1][i+1]++;
	}
	if (table[j+1][i-1] != -1){
	  table[j+1][i-1]++;
	}
	if (table[j+1][i+1] != -1){
	  table[j+1][i+1]++;
	}
	
	if (table[j-1][i] != -1){
	  table[j-1][i]++;
	}
	if (table[j][i-1] != -1){
	  table[j][i-1]++;
	}
       	if (table[j][i+1] != -1){
	  table[j][i+1]++;
	}
	if (table[j+1][i] != -1){
	  table[j+1][i]++;
	}
      }
    }
  }
  }
}
	
