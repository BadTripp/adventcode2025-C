#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int sum = 0;
char sumRange[256] ="0" ;
typedef struct {
	long long int primo;
	long long int secondo;
} Coppia;
void sommaStringToString(unsigned long long number){
    char str[256];
    sprintf(str, "%llu", number);

    int lenSum = strlen(sumRange) - 1;
    int lenStr = strlen(str) - 1;
    int resto = 0;
    int c = 0;
    
    char sum[256];
    while(lenSum >= 0 || lenStr >= 0 || resto > 0){
        //printf("Dentro");
        int n1,n2;
        if(lenSum >= 0){
            n1 = sumRange[lenSum] - '0';
            
        }else{
            n1 = 0;
        }
        if(lenStr >= 0){
            n2 = str[lenStr] - '0';
            
        }else{
            n2 = 0;
        }
        
        
        int x = n1 + n2 + resto;
        
        sum[c] = x % 10 + '0';
        
        resto =  x / 10;
        //printf("%d %d %d", n1 , n2 , x);
        c++;
        lenSum--;
        lenStr--;
       
        
    }
    
    while (c > 1 && sum[c - 1] == '0') {
        c--;
    }
    
    //printf("%s\n",sum);
    for(int i = 0; i < c; i++){
        sumRange[i] = sum[c - i - 1];
    }
    sumRange[c] = '\0';

    //if(sumRange[0] == '0'){
    //	memmove(sumRange, sumRange + 1, strlen(sumRange + 1) + 1);
    //}
    printf("%s\n",sumRange);
}
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
void order (Coppia *range,long long int *a,long long int *b,int dim){
	for(int i = 0; i < dim ; i++){
		if(*a < range[i].primo){
			long long int x;
			//nuovo range prende posizine 
			x = *a;
			*a = range[i].primo;
			range[i].primo = x;

			x = *b;	
			*b = range[i].secondo;
			range[i].secondo = x;
			
		}

	}
}
long long max (long long a,long long b,int i){
	if(a>b){
		return i;
	}else{
		return i-1;
	}
	
}
int  optimize (Coppia *range,int dim){
	int newdim = dim;
	if(dim > 0){
	for(int i = 1; i < newdim ;){
		if(i - 1 >= 0 ){
			if(range[i].primo <= range[i-1].secondo){
				range[i-1].secondo = range[max(range[i].secondo,range[i-1].secondo,i)].secondo;
				memmove(&range[i],&range[i+1],(newdim-i-1) * sizeof(range[0]));	
				newdim--;
			
			}else{
				i++;		
			}
		}	
	}
	}
	return newdim;
}
void countRange(Coppia *range,int dim){
	for(int i = 0; i < dim;i++){
		//for(long long j = range[i].primo; j <= range[i].secondo;j++){
			printf("Riga%d\n",i);	
			// sei lento
			//sumRangeString();
			sommaStringToString(range[i].secondo - range[i].primo + 1);
			
				
			
				
			//printf("contatore%d\n",j);		
			//}
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
			order(range,&n1,&n2,lc);	
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
	lc = optimize(range,lc);
	for(int i = 0; i < lc;i++){
		printf("Range : %lld,%lld\n",range[i].primo,range[i].secondo);
		}
	countRange(range,lc);
	printf("sum : %d  sumRange : %s \n",sum,sumRange);

			
	return 1;
}
