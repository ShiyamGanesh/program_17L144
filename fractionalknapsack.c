#include<stdio.h>
float find_fractional_knapsack(int v[],int w[],int n,int capacity){
	float totalweight=0;
	int i;
	for(i=0;i<n;i++){
		if(w[i]<=capacity){
			capacity-=w[i];
			totalweight+=v[i];	
		}	
		else{
			totalweight+=(float)v[i]*(float)capacity/(float)w[i];
			break;
		}
	}
	return totalweight;
}

main(){
	int n,i,j;
	printf("ENTER THE SIZE: ");
	scanf("%d",&n);
	int w[n],v[n],capacity;
	float profit[n];
		printf("ENTER TOTAL CAPACITY: ");
	scanf("%d",&capacity);
	printf("ENTER VALUE AND ITS WEIGHT:\n");
	for( i=0;i<n;i++){
		scanf("%d%d",&v[i],&w[i]);
		profit[i]=(float)v[i]/(float)w[i];
	}
	for(i=0;i<n-1;i++){
		for(j=0;j<n-i-1;j++){
			if(profit[j]<profit[j+1]){
				float t1=profit[j];
				profit[j]=profit[j+1];
				profit[j+1]=t1;
				int t2=v[j];
				v[j]=v[j+1];
				v[j+1]=t2;
				t2=w[j];
				w[j]=w[j+1];
				w[j+1]=t2;
				
			}
		}
		
	}
	printf("MAXIMUM VALUE OF KNAPSACK CAPACITY CONTAINING: %f\n",find_fractional_knapsack(v,w,n,capacity));
}
