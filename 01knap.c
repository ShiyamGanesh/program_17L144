#include<stdio.h>
int max(int a,int b){
	return (a>b)?a:b;
}
int fractionalknapsack(int n, int w[],int v[],int c){
	int f[n+1][c+1],i,j;
	for(i=0,j=0;i<=n,j<=c;i++,j++){
		f[i][0]=0;
		f[0][j]=0;
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=c;j++){
			if(j-w[i]<0)
				f[i][j]=f[i-1][j];
			else
				f[i][j]=max(f[i-1][j],v[i]+f[i-1][j-w[i]]);
		}
	}
	return f[n][c];
}
main(){
	int n,i,c;
	printf("ENTER THE SIZE = ");
	scanf("%d",&n);
	int a[n+1],b[n+1];
	printf("ENTER VALUE AND ITS WEIGHT : \n");
	for(i=1;i<=n;i++)
		scanf("%d%d",&a[i],&b[i]);
	printf("ENTER THE TOTAL CAPACITY = ");
	scanf("%d",&c);
	printf("MAXIMUM PROFIT = %d",fractionalknapsack(n,a,b,c));
}

