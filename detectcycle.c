#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int n;
int adj[MAX][MAX];
void create_graph();
int queue[MAX],front=-1,rear=-1;
void insert_queue(int v);
int delete_queue();
int isEmpty_queue();
int indegree(int v);
int main(){
    int i,v,count,indeg[MAX];
    create_graph();
    for(i=0;i<n;i++){
        indeg[i]=indegree(i);
        if(indeg[i]==0)
            insert_queue(i);
    }
    count = 0;
    while(!isEmpty_queue() && count<n){
        v=delete_queue();
        ++count;
        for(i=0;i<n;i++){
            if(adj[v][i]==1){
            	adj[v][i]=0;
            	indeg[i]=indeg[i]-1;
            	if(indeg[i]==0)
                	insert_queue(i);
            }
        }
	}
    if(count<n )
        printf("It is a cyclic graph\n");
    else
    	printf("It is a acyclic graph\n");
}
void insert_queue(int vertex){
    if (rear==MAX-1)
        printf("\nQueue Overflow\n");
    else{
        if(front==-1)
            front=0;
        rear=rear+1;
        queue[rear]=vertex;
    }
}
int isEmpty_queue(){
    if(front==-1 || front>rear)
        return 1;
    else
        return 0;
}
int delete_queue(){
    int del_item;
    if(front==-1 || front>rear){
        printf("\nQueue Underflow\n");
        exit(1);
    }
    else{
        del_item=queue[front];
        front=front+1;
        return del_item;
    }
}
int indegree(int v){
    int i,in_deg=0;
    for(i=0;i<n;i++)
        if(adj[i][v]==1)
            in_deg++;
	return in_deg;
}
void create_graph(){
    int i,max_edges,a,b;
	printf("ENTER THE SIZE OF VERTICES: ");
    scanf("%d",&n);
    max_edges=n*(n-1);
    printf("ENTER THE EDGE(-1 to quit):\n");
    for(i=1;i<=max_edges;i++){
        scanf("%d %d",&a,&b);
		if(a==-1 || b==-1)
            break;
        else
        	adj[a][b]=1;
    }
}
