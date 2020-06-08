#include<stdio.h>
int LIS(int a[],int n){  
    int l[n],i,j; 
   	l[0]=1;
    for(i=1;i<n;i++){ 
        l[i]=1; 
        for(j=0;j<i;j++)   
            if(a[i]>a[j] && l[i]<l[j]+1)  
                l[i]=l[j]+1;  
    }
    int max=l[0];
    for(i=1;i<n;i++) 
        if(l[i]>max) 
            max=l[i];
    return max;
}
main(){  
    int n;
    printf("ENTER THE SIZE = ");
    scanf("%d",&n);
    int a[n],i;
    printf("ENTER THE ARRAY:\n");
    for(i=0;i<n;i++)
    	scanf("%d",&a[i]);
    printf("LENGTH OF LONGEST INCREASING SUBSEQUENCE = %d",LIS(a,n)); 
}
