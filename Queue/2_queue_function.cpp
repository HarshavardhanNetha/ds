//done size taken static
#include <stdio.h>
#include <stdlib.h>

static int front=-1,rear=-1,option;
static int a[20];

int enqueue(){
	int size=20;
	if(rear==size-1)
		printf("Queue is full!\n");
	else{
		int ele;
		rear++;
		scanf("%d",&ele);
		a[rear]=ele;
	}
	return 0;	
}

int dequeue(){
	if(front==rear)
		printf("Queue is empty!\n");
	else{
		front++;
		printf("%d",a[front]);
	}
	return 0;
}

int main(){
	
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
			default: printf("Enter valid input.");
		}
	}
	while(option!=3);
	
	return 0;
}
