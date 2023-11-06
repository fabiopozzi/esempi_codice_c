#include<stdio.h>
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define N 10

int main(){
	int i, j;
	int pos[N]={0}; // positivi
	int v[N]={0}; // valori
	int neg[N]={0}; // negativi

	srand(time(0));
	int tmp;
	int n=0; // posizioni negativi
	int p=0; // posizioni positivi

    // inserisco numeri casuali in array
	for(i=0;i<N;i++){
		v[i]=rand()%40;
		v[i]=v[i]-20;
	}

    //
	for(i=0;i<N;i++){
		// se il numero e' negativo
		if(v[i]<0){
			neg[n]=v[i];
			n++;
		}else{
			pos[p]=v[i];
			p++;
		}
	}

    // ordino i valori negativi
	for(i=0; i<n; i++){
		for(j=0; j < n - i - 1; j++){
			if(neg[j]>neg[j+1]){
				tmp=neg[j];
				neg[j]=neg[j+1];
				neg[j+1]=tmp;
			}
		}
	}

    // ordino i valori positivi
	for(i=0;i<p;i++){
		for(j=0;j<p- i - 1;j++){
			if(pos[j]>pos[j+1]){
				tmp=pos[j];
				pos[j]=pos[j+1];
				pos[j+1]=tmp;
			}
		}
	}
    printf("positivi:\n");
	for(i=0;i<p;i++){
        printf("%3d",pos[i]);
	}
	printf("\n");

    printf("negativi:\n");
	for(i=0;i<n;i++){
        printf("%3d",neg[i]);
	}
}

