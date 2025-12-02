#include<stdio.h>
#include<string.h>
char* fileName = "input.txt"; 
long long int idSum = 0;
bool checkArray (int v[],int len){
	for(int i=0;i<len;i++)
		for(int j = i + 1;j < len; j++)
			if(v[i]==v[j]) return true;
	return false;
}
void  checkid_2(int len,long long id){
	long int t = 1;
	int c = 1;
	long long idCopy = id;
	while (c < len){	
		long int t = 1;
		int val[len/c];
		if(len%c == 0){	
			for(int l = c ;l > 0;l--){
				t *= 10;			
				//printf("Valore id%d\n",t);
			}	
			for(int i = idCopy , j = 0; i > 0;i/=t,j++){
				
				//printf("Valore id%d\n",i);	
				val[j] = i%t;	
			}
		}
		c++;
		//printf("%d\n",checkArray(val,len));	
		if(checkArray(val,len/c)){
			idSum = idSum + id;
			break;
		}
					
	}

}
void  checkid (long long int  id){			
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
	checkid_2(len,id);
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
	
	
	return 1;
}

