#include<stdio.h>
#define max 15
int n,cost[max][max],visited[max]={0},i,j,min,ne=1,totalmincost=0,a,b,v,x;
int main(){
	printf("ENTER THE SIZE OF VERTICES AND EDGES: ");
	scanf("%d%d",&v,&n);
	for(i=1;i<=n;i++){
    	for(j=1;j<=n;j++)
        	cost[i][j]=999;
	}
	printf("ENTER THE VERTICES AND COST:\n");
	while(ne<=n){
		scanf("%d%d%d",&i,&j,&x);
		cost[i][j]=x;
		if(cost[i][j]==0)
			cost[i][j]=999;
		ne++;
	}
	visited[1]=1;
	ne=1;
	while(ne<n){
		min=999;
		for(i=1;i<=n;i++){
			if(visited[i]){
				for(j=1;j<=n;j++){
					if(cost[i][j]<min){
						min=cost[i][j];
						a=i;
						b=j;
					}
				}
			}
		}
		if(visited[b]==0){
			printf("EDGE(%d,%d)\tCOST= %d\n",a,b,min);
			totalmincost+=min;
			visited[b]=1;
		}
		cost[a][b]=cost[b][a]=999;
		ne++;
	}
	printf("....MINIMUM COST....= %d\n",totalmincost);
}
