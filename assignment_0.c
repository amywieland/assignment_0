#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ARRAY_SIZE 25
void simulate(int table[ARRAY_SIZE][ARRAY_SIZE]);

int main (int argc, char *argv[]){
  int table[ARRAY_SIZE][ARRAY_SIZE];

  if(argc > 1){
    if(!strcmp "--fps", argc[1]){
     int fps = atoi(argv[2]);
    }
    
  int i = 3
  while (i<argc){
    
    
    
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
  
}

void tableprint(int table[ARRAY_SIZE][ARRAY_SIZE]){
  int j, i;
  for (j = 0; j < ARRAY_SIZE; j++){
    for (i = 0; i < ARRAY_SIZE; i++){
      printf("%d",table[j][i]);
    }
  }
  
}

void simulate(int table[ARRAY_SIZE][ARRAY_SIZE]){

  int center = ARRAY_SIZE/2

  table[center][center]++;

  int i;
  int j;
  boolean topple = true; //signals whether a topple has occurred or not

  while (topple){
    topple = false;
  for (j = 0; j < ARRAY_SIZE; j++){
    for (i = 0; j < ARRAY_SIZE; i++){
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
	
