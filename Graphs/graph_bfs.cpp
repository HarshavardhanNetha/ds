#include <stdio.h>
#include <stdlib.h>

struct queue{
	int arr[50];
	int front;
	int rear;
};

struct queue enqueue(struct queue*,int);
int dequeue(struct queue**);
int isempty(struct queue*);

int main(){
	int n;
	int i,j,k;
	

	struct queue* q;
	q=(struct queue*)malloc(sizeof(struct queue));
	q->front=-1;
	q->rear=-1;
	
	printf("Enter n of graph:");
	scanf("%d",&n);
	int a[n][n];
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
	
	*q=enqueue(q,temp);

	//bfs
	
	while(!isempty(q)){
		k=dequeue(&q);
		if(v[k]==0){
			v[k]=1;
			printf("%d ",k);
			for(j=0;j<n;j++){
				if(a[k][j]==1 && v[j]==0){
					*q=enqueue(q,j);
				}
			}
		}
	} 
		
	return 0;
}

int isempty(struct queue* q){
	if(q->front==q->rear)
		return 1;
	return 0;
}

struct queue enqueue(struct queue* q,int a){
	q->rear++;
	q->arr[q->rear]=a;
	return *q;
}

int dequeue(struct queue** q){
	(*q)->front++;
	return (*q)->arr[(*q)->front];
}
