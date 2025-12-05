#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int sum = 0;
int sumRange = 0;
typedef struct {
	long long int primo;
	long long int secondo;
} Coppia;
void countRange(Coppia *range,int dim){
	for(int i = 0; i < dim;i++){
		for(long long j = range[i].primo; j <= range[i].secondo;j++){
			sumRange++;	
			}
	}
}
int checkId(long long int ingr,Coppia *range,int dim){
		for(int i = 0; i < dim;i++){
			if(ingr >= range[i].primo && ingr <= range[i].secondo){	
				printf("Sommo %d , %ld ,%ld\n",ingr,range[i].primo,range[i].secondo);
				sum++;
				return 1;	
			}
			
		}
		


	
}
int  main (void){
	FILE *fp = fopen("input.txt","r");
	Coppia *range = NULL;	
	char line[256];
	int lc = 0;
	int mode = 1;
	while(fgets(line,sizeof(line),fp)){
		
		line[strcspn(line,"\n")] = '\0';

		if(strlen(line) == 0){			
			mode = 0;
			continue;
			}
		if(mode == 1){
			long long  int n1,n2;
					
			sscanf(line,"%lld-%lld",&n1,&n2);
			Coppia *tmp = realloc(range,(lc + 1) * sizeof(Coppia));
			if(tmp == NULL){
				printf("Coppia non basta piu!");	
				return 0;
			}else{
				range = tmp;
				range[lc].primo = n1;
				range[lc].secondo  = n2;	
			}
			lc++;	
			//printf("Range %d-%d\n", n1,n2);
			}
		if(mode == 0){
			long long  int num;
			
			sscanf(line,"%lld",&num);
			checkId(num,range,lc);		
			printf("number %lld\n",num);
			}
						
	}
	for(int i = 0; i < lc;i++){
		printf("Range : %d,%d\n",range[i].primo,range[i].secondo);
		}
	countRange(range,lc);
	printf("sum : %d  sumRange : %lld \n",sum,sumRange);

			
	return 1;
}
