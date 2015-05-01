#include<stdio.h>
#define MAX 99999

int mat[10][10] = {{0}};

int OBST(int *w,int p,int q){
	int len,sum,i,j,r,k,val,size;
	size=q-p+1;
	for(len=1;len<size;len++){
		for(i=0;i<size-len;i++){
			j=i+len;
			sum=0;
			mat[i][j] = MAX;
	//		printf("%d,%d\n",i,j);
			for(k=i;k<=j;k++){
				sum=sum+w[k];
			}
			for(r=i;r<j;r++){
				val = mat[i][r] + mat[r+1][j] + sum;
				if(val < mat[i][j]){
					mat[i][j] = val;
				}
			}
			printf("%d,%d,%d\n",i,j,mat[i][j]);
		}
	}
	return mat[p][q];

}
int main(){
	int num,i,minCost;
	scanf("%d",&num);
	int w[num];
	for(i=0;i<num;i++){
		scanf("%d",&w[i]);
	}
	minCost = OBST(w,0,num-1);
	printf("Minimum cost is=%d\n",minCost);
	return 0;
}
