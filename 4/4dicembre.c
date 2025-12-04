#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int sum = 0;
void find (int row, int col ,char **map,size_t righe){
    int cols = strlen(map[row]);
    char batt = '@';	
    int val = 0;
    if (row > 0) { 
	if(map[row-1][col] == '@'){val++;} 
        if (col > 0) { if(map[row-1][col-1] == '@'){val++;} }
        if (col + 1 < strlen(map[row-1])) { if(map[row-1][col+1] == '@'){val++;} }  
    }

    if (row + 1 < righe) { 
	if(map[row+1][col] == '@'){val++;}
        if (col > 0) { if(map[row+1][col-1] == '@'){val++;} }
        if (col + 1 < strlen(map[row+1])) { if(map[row+1][col+1] == '@'){val++;} }
         
    }

    if (col > 0) {  if(map[row][col-1] == '@'){val++;}}
    if (col + 1 < cols) { if(map[row][col+1] == '@'){val++;}}

    if(val < 4) sum++;
    //debug
    //printf("%c\n",map[row][col]);	
    //printf("Valore%d\n",val);
    //printf("Valore%d\n",sum);
}
void check(char **mappa, size_t righe) {
    for (size_t i = 0; i < righe; i++) {
        for (size_t j = 0; mappa[i][j] != '\0'; j++) {
          if(mappa[i][j] == '@'){find(i,j,mappa,righe);} 
        }
    }
}

int  main(void){
    FILE *fp = fopen("input.txt","r");	  	
    char **mappa = NULL;
    size_t righe = 0;
    char line[256];

    while (fgets(line, sizeof(line), fp)) {
        line[strcspn(line, "\n")] = '\0';

        char *riga = malloc(strlen(line) + 1);
        strcpy(riga, line);

        mappa = realloc(mappa, (righe + 1) * sizeof(char*));
        mappa[righe] = riga;
        righe++;
    }

    fclose(fp);

    check(mappa, righe);
    
	printf("Res %d", sum);
	return 1;
}

