#include<stdio.h>
#include<string.h>
int max(int a,int b){
	return (a>b)?a:b;
}
int LCS(int n1,char x[],int n2,char y[]){
	int lcs[n1+1][n2+1],i,j;
	for(i=0;i<=n1;i++)
		lcs[i][0]=0;
	for(j=0;j<=n2;j++)
		lcs[0][j]=0;
	for(i=1;i<=n1;i++)
		for(j=1;j<=n2;j++)
			if(x[i-1]==y[j-1])
				lcs[i][j]=lcs[i-1][j-1]+1;
			else
				lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1]);
	return lcs[n1][n2];
}
main(){
	char s1[1000],s2[1000];
	printf("ENTER THE STRING 1 AND STRING 2 :\n");
	scanf("%s%s",s1,s2);
	int n1=strlen(s1),n2=strlen(s2);
	printf("%d",LCS(n1,s1,n2,s2));
}

