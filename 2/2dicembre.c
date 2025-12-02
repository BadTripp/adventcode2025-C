#include<stdio.h>
#include<string.h>
char* fileName = "input.txt"; 
long long int idSum = 0;
bool checkid (long long int  id){			
	long int t = 1;
	int len = 0;
	long long int num = id;
	while(num > 0){
		num/=10;
		len++;
	}	
	//printf("%d\n",len);
	if((len % 2) == 0){
		for(int l = len/2;l > 0;l--){
			t *= 10;
			//printf("%d\n",id);	
		}
		int high = id / t;
		int low  = id % t;
		//printf("%d %d\n",high,low);
		if(high == low){
			
			idSum=idSum+id;
			printf("Trovato %lld Somma totale : %lld\n",id,idSum);
		}
	}	
}
void finder(long long int  start,long long int end){
	for(long long int  i = start ; i <= end ;i++){
		//printf("start %d end%d\n",start,end);
		checkid(i);
	}
}
int main (){
	FILE *fp = fopen(fileName,"r");
	long long int  start,end;
	while(fscanf(fp," %lld-%lld%*[,]", &start, &end) ==2){
	//	printf("%lld-%lld\n",start,end);
		finder(start,end);
	}
	printf("%d",idSum);
	return 1;
}

