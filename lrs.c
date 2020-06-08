#include<stdio.h>
#include<string.h>
int max(int a,int b){
	return (a>b)?a:b;
}
int LRS(char s[],int n){ 
    int i,j,k=0; 
    char x[1000];
    int d[n+1][n+1]; 
    for(i=0;i<=n;i++) 
        for(j=0;j<=n;j++) 
            d[i][j]=0; 
    for(i=1;i<=n;i++){ 
        for(j=1;j<=n;j++){ 
            if (s[i-1]==s[j-1] && i!=j){
                d[i][j]=d[i-1][j-1]+1;
                x[k++]=s[i];
            }
            else
                d[i][j]=max(d[i][j-1],d[i-1][j]); 
        } 
    }
    printf("LONGEST REPEATING SUBSEQUENCE : ");
    for(i=0;i<d[n][n];i++)
    	printf("%c",x[i]);
    printf("\n");
    return d[n][n]; 
}
int main(){ 
    char s[1000];
    printf("ENTER THE STRING : ")
	scanf("%s",s);
	int n=strlen(s);
	printf("LENGTH OF REPEATING SUBSEQUENCE = %d",LRS(s,n));
	return 0;
}
