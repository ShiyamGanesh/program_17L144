#include<stdio.h>
int adj[15][15],visited[15],n;
void createGraph(){
	int ch,a,b;
	do{
	    printf("ENTER THE VERTICE: ");
	    scanf("%d%d",&a,&b);
		adj[a][b]=1;
		printf("ENTER 1 TO CONTINUE: ");
		scanf("%d",&ch);
	}while(ch==1);
}
void DFS(int v){
	int i;
	visited[v]=1;
	printf("%d ",v);
	for(i=0;i<n;i++){
		if(adj[v][i] && visited[i]==0)
			DFS(i);
	}
}
main(){
    int i;
    printf("ENTER THE TOTAL VERTICES: ");
	scanf("%d",&n);
	createGraph(n);
	printf("DFS ORDER:\n");
	for(i=0;i<n;i++){
		if(visited[i]==0)
			DFS(i);
	}
}

