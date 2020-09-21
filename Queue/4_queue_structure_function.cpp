#include <stdio.h>
#include <stdlib.h>

struct queue{
	int a[10];
	int rear,front;
	int size;
};

//global declaration
struct queue q;

void enqueue(){
	if(q.rear==q.size-1)
		printf("Queue is full!\n");
	else{
		int ele;
		scanf("%d",&ele);
		q.rear++;
		q.a[q.rear]=ele;
	}
}

void dequeue(){
	if(q.front==q.rear)
		printf("Queue is empty!\n");
	else{
		q.front++;
		printf("%d\n",q.a[q.front]);
	}	
}

int main(){
	q.rear=-1;
	q.front=-1;
	q.size=10;
	
	int option;
	
	do{
		printf("1.Enqueue\n2.Dequeue\n3.Exit\n");
		scanf("%d",&option);
	
		switch(option){
			case 1:{
				enqueue();
				break;
			}
			case 2:{
				dequeue();
				break;
			}
			case 3:{
				exit(0);
				break;
			}
			default: printf("Enter valid input.\n");
		}
	}
	while(option!=3);
}
