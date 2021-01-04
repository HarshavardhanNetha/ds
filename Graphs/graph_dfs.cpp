#include <stdio.h>
#include <stdlib.h>

struct queue{
	int arr[50];
	int front;
	int rear;
};

void dfs(int, int[100], int[100][100],int);

int main(){
	int n;
	int i,j,k;
	

	struct queue* q;
	q=(struct queue*)malloc(sizeof(struct queue));
	q->front=-1;
	q->rear=-1;
	
	printf("Enter n of graph:");

	scanf("%d",&n);
	int a[100][100];
	int v[n] = {0};
	
	//input graph
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	}
	printf("\n");
	//output graph
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
			printf("%d ",a[i][j]);
		printf("\n");
	}
	printf("\n");
	int temp=0;
	//*q=enqueue(q,temp);
	
	//dfs
	dfs(0,v,a,n);
	
	for(i=0;i<n;i++){
		if(v[i]!=1)
			dfs(i,v,a,n);
	}
	
	return 0;
}


void dfs(int k, int v[100], int a[100][100],int n){
	int j;
	if(v[k]==0){
		v[k]=1;
		printf("%d ",k);
		for(j=0;j<n;j++){
			if(a[k][j]==1 && v[j]==0){
				dfs(j,v,a,n);
			}
		}
	}
}
