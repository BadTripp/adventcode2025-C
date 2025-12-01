#include<stdio.h> 
int pos = 50;
int password[2] = {0,0};
char* fileName = "input.txt";
void calc(char dir,int number){ 
	while(number > 0 ){		
		number--;	
		if(dir == 'R'){
			if(pos == 99){
				pos = 0;	
			}else{
				pos++;
			}
		}		
		if(dir == 'L'){
			if(pos == 0){
				pos = 99;	
			}else{
				pos--;
			}	
		}	
		printf("Pos: %d \n",pos);
		if(pos == 0){
			password[1]++;
		}	
	}
	if(pos == 0){	
			password[0]++;
		}	
}

int main (){
	FILE *fp = fopen(fileName,"r");
	char dir;
	int number;
	while (fscanf(fp," %c%d",&dir,&number)== 2){
		printf("dir: %c, num: %d\n",dir,number);
		calc(dir,number);
		printf("Password 1 : %d \n Password2 : %d \n",password[0],password[1] );
	}
}
