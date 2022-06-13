#include <stdlib.h>
#include <stdio.h>

mm(int *v,int x, int *mi, int*ma){
	*mi=v[0];
	*ma=v[0];
	for(int i=1;i<x;i++){
		if(*mi>v[i]){
			*mi=v[i];	
		}
		if(*ma<v[i]){
			*ma=v[i];
		}
	}
}

main(){
	int v[10]={0,1,2,3,4,5,6,7,8,9},min,max;
	mm(v,(sizeof(v)/sizeof(int)),&min,&max);
	printf("Max: %d\nMin: %d",min,max);
}
