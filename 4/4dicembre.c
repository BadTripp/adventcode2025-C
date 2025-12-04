#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int sum = 0;
int removed = 0;
char **mappaClone=NULL;
void printMap(char **map, size_t righe) {
    for (size_t i = 0; i < righe; i++) {
        printf("%s\n", map[i]);
    }
    printf("\n");
}

bool removeP(bool toRem,char val,int i, int j){
	if(toRem){
	    mappaClone[i][j] = 'x';
	    removed++;
	    return true;
	}else{
	    mappaClone[i][j] = val;
	    return false;
	}
	
}
bool  find (int row, int col ,char **map,size_t righe){
    int cols = strlen(map[row]);
    int val = 0;
    

		
	if (row > 0) {
	    int colsAbove = strlen(map[row-1]);
	    if (col < colsAbove) val += (map[row-1][col] == '@');// sopra
	    if (col > 0 && col-1 < colsAbove) val += (map[row-1][col-1] == '@');//sopra sinitra
	    if (col + 1 < colsAbove) val += (map[row-1][col+1] == '@');//sopra destra
	}

	
	if (row + 1 < righe) {
	    int colsBelow = strlen(map[row+1]);
	    if (col < colsBelow) val += (map[row+1][col] == '@');//sotto
	    if (col > 0 && col-1 < colsBelow) val += (map[row+1][col-1] == '@');//sotto sinistra
	    if (col + 1 < colsBelow) val += (map[row+1][col+1] == '@'); //sotto destra
	}


	
	if (col > 0) if(map[row][col-1] == '@') val++;
	if (col + 1 < cols) if(map[row][col+1] == '@') val++;


    if(val < 4){ 
	sum++;
	return true;
    }
    return false;
    //debug
    //printf("%c\n",map[row][col]);	
    //printf("Valore%d\n",val);
    //printf("Valore%d\n",sum);
}
void check(char **mappa, size_t righe) {
	int rep = 0;
	printMap(mappa,righe);
    for (size_t i = 0; i < righe; i++) {
        for (size_t j = 0; mappa[i][j] != '\0'; j++) {
          if(mappa[i][j] == '@'){
		if(removeP(find(i,j,mappa,righe),mappa[i][j],i,j)){rep++; }
	  } 
        }
    }
    if(rep >= 1) {
    for (size_t i = 0; i < righe; i++) {
        strcpy(mappa[i], mappaClone[i]);
    }
    check(mappa,righe);
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

	mappaClone = malloc(righe * sizeof(char*));

	for (size_t i = 0; i < righe; i++) {
    	size_t len = strlen(mappa[i]);
    	mappaClone[i] = malloc(len + 1);
    	memset(mappaClone[i], '.', len);
    	mappaClone[i][len] = '\0';
	}
    check(mappa, righe);
	for (size_t i = 0; i < righe; i++) {
	    free(mappa[i]);
	    free(mappaClone[i]);
	}
	free(mappa);
	free(mappaClone);

	printf("Res: %d Rimossi: %d\n", sum,removed);
	return 1;
}

