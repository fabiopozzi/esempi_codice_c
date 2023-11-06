#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define N 10
int main(){
	int i;
	int j;
	int val[N]={0}; // positivi
	int str[N]={0}; // valori
	int val1[N]={0}; // negativi

	srand(time(0));
	int tmp;
	int k=0; // posizioni
	int s=0; // posizioni

    // inserisco numeri casuali in array
	for(i=0;i<N;i++){
		str[i]=rand()%40;
		str[i]=str[i]-20;
	}

    //
	for(i=0;i<N;i++){
		// se il numero e' negativo
		if(str[i]<0){
			val[s]=str[i]; // inserisco nella posizione s
			s++;
		}else if(str[i]>=0){
			val1[k]=str[i];
			k++;
		}
	}

    // ordino i valori negativi
	for(i=0;i<N;i++){
		for(j=0;j<N-1;j++){
			if(val[j]>val[j+1]){
				tmp=val[j];
				val[j]=val[j+1];
				val[j+1]=tmp;
			}
		}
	}

    // ordino i valori positivi
	for(i=0;i<N;i++){
		for(j=0;j<N-1;j++){
			if(val1[j]>val1[j+1]){
				tmp=val1[j];
				val1[j]=val1[j+1];
				val1[j+1]=tmp;
			}
		}
	}
	for(i=0;i<N;i++){
		if(val[i]<0){
			printf("%3d",val[i]);
		}
	}
	printf("\n");
	for(i=0;i<N;i++){
		if(val1[i]>0){	
			printf("%3d",val1[i]);
		}
	}
}
