#include<stdio.h>
#include<stdlib.h>

#define MAX_SYMBOLS 2
#define MAX_STATES 10

typedef struct{
	int transitions[MAX_SYMBOLS][MAX_STATES];
	int isfinal;
}DFAstate;
int main(){
	int nfastates,symbols,i,j,k;
	printf("no.of states\n");
	scanf("%d\n",&nfastates);
		printf("no.of symbols\n");
	scanf("%d\n",&symbols);
	
	DFAstate dfastates[MAX_STATES];
	int visited[MAX_STATES]={0};
	int queue[MAX_STATES],front=-1,rear=-1;
	
	for(i=0;i<MAX_STATES;i++){
		dfastates[i].isfinal=0;
		for(j=0;j<MAX_SYMBOLS;j++){
			for(k=0;k<MAX_STATES;k++){
				dfastates[i].transitions[j][k]=-1;
			}
		}
	}
	for(i=0;i<nfastates;i++){
		printf("enter transition for state %d\n",i);
		int numtransitions;
		scanf("%d\n",&numtransitions);
		
		printf("for state %d",i);
		for(j=0;j<numtransitions;j++){
			char symbol;
			int nextstate;
			printf("enter input symbol");
			scanf("%c\n",symbol);
			printf("enter the input for %c",symbol);
			scanf("%d\n",&nextstate);
			dfastates[i].transitions[symbol -'0'][j]=nextstate;
		}
	}
      front=rear=0;
	queue[rear++];
	visited[0]=1;
	
	while(front<rear){
		int currentstate=queue[front++];
		for(i=0;i<MAX_SYMBOLS;i++){
		for(j=0;j<nfastates;j++){
		
		if(dfastates[currentstate].transitions[i][j]!=1){
			if(!visited[dfastates[currentstate].transitions[i][j]]){
				queue[rear++]=dfastates[currentstate].transitions[i][j];
				visited[dfastates[currentstate].transitions[i][j]]=1;
						}
		}
	}
}
}
	
	printf("\ndfa table\n");
	printf("state\t|0\t|1\t|\n");
	printf("---------------------\n");
	for(i=0;i<nfastates;i++){
		printf("%d\t|",i);
		for(j=0;j<MAX_SYMBOLS;j++){
			if(visited[i]){
				printf("%d\t|",dfastates[i].transitions[0][j]);
			}
			else{
				printf("-\t");
			}
		}
		printf("\n");
	}
	return 0;
	
}
