//program to demonstrate queue with basic array and no functions
//b171325
//Harsha

#include <stdio.h>
#include <stdlib.h>

int main(){
	int front=-1,rear=-1,option,ele;
	int a[10],size=10;
	
	do{
		printf("1.Enqueue\n2.Dequeue\n3.Exit\n");
		scanf("%d",&option);
		switch(option){
			case 1:{
				if(rear==size-1)
					printf("Queue is full!\n");
				else{
					rear++;
					scanf("%d",&ele);
					a[rear]=ele;					
				}
				break;
			}
			case 2:{
				if(front==rear)
					printf("Queue is empty!\n");
				else{
					front++;
					printf("%d",a[front]);
				}
				break;
			}
			case 3:{
				exit(0);
				break;
			}
			default: printf("Enter a valid option.");
			
		}
	}
	while(option!=3);
	return 0;
}
