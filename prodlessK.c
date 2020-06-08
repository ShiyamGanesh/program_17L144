#include<stdio.h>
int sub(int a[],int n,int k){  
    int m[k+1][n+1],i,j; 
	for(i=0;i<=k;i++)
		for(j=0;j<=n;j++)
			m[i][j]=0;
    for(i=1;i<=k;i++){ 
        for(j=1;j<=n;j++){
            m[i][j]=m[i][j-1]; 
            if(a[j-1]<=i && a[j-1]>0)
                m[i][j]+=m[i/a[j-1]][j-1]+1; 
        } 
    } 
    return m[k][n]; 
}
   
int main(){
	int n,k;
	printf("ENTER THE SIZEE = ");
	scanf("%d",&n);
	int a[n],i;
	printf("ENTER THE ELEMENTS :\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("ENTER k = ");
	scanf("%d",&k);
	printf("NUMBER OF SUBSEQ PRODUCT LESS THAN k = %d",sub(a,n,k));  
}
