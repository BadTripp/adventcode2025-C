#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int sum = 0;
char sumRange[256] ="0" ;
typedef struct {
	long long int primo;
	long long int secondo;
} Coppia;
int sumRangeString(){
	int len = strlen(sumRange)-1;	
	while(len >= 0){
		if(sumRange[len] < '9'){
			sumRange[len]++;
			return 1;
		}
		if(sumRange[len] == '9'){
			if(len == 0){
				sumRange[len] = '0';
				memmove(sumRange+1,sumRange,strlen(sumRange)+1);	
				sumRange[0]= '1'; 
			}else{
				sumRange[len] = '0';
			}
			
				
		}
		
		len--;
	}
}

void countRange(Coppia *range,int dim){
	for(int i = 0; i < dim;i++){
		for(long long j = range[i].primo; j <= range[i].secondo;j++){
			//printf("%s\n",sumRange);	
			int check = 0;
			for(long long k = i-1 ; k >= 0 ; k--){
				// se presente nei range  precedenti
				if(j >= range[k].primo && j <= range[k].secondo){
					check = 1;	
					printf("%lld \n",j);
				}	

			}	
			if(check == 0){
				printf("\033[H\033[J");
				printf("totale range %d\n",dim);
				printf("range %d\n",i);
				printf("%s\n",sumRange);
			  	sumRangeString();
			}
			
				
			
				
			//printf("contatore%d\n",j);		
			}
	}
}
int checkId(long long int ingr,Coppia *range,int dim){
		for(int i = 0; i < dim;i++){
			if(ingr >= range[i].primo && ingr <= range[i].secondo){	
				//printf("Sommo %d , %ld ,%ld\n",ingr,range[i].primo,range[i].secondo);
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
			//printf("number %lld\n",num);
			}
						
	}
	for(int i = 0; i < lc;i++){
		//printf("Range : %lld,%lld\n",range[i].primo,range[i].secondo);
		}
	countRange(range,lc);
	printf("sum : %d  sumRange : %s \n",sum,sumRange);

			
	return 1;
}
