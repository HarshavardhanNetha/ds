//program to demonstrate stack with functions -basic one
//b171325
//Harsha

#include <stdio.h>
#include <stdlib.h>

void push();
void pop();

char a[20];
int size=20,top=-1,option;
int ele;
	
int main(){	
	do{
		printf("1.Push\n2.Pop\n3.Exit\nEnter your option:");
		scanf("%d",&option);
		
		switch(option){
			case 1:{
				push();
				break;
			}
			case 2:{
				pop();
				break;
			}
			default:{
				printf("Enter valid option.\n");
				break;
			}
		}
	}
	while(option!=3);
	return 0;
}

void push(){
	if(top==size-1)
		printf("Stack is full!\n");
	else{
		top++;
		scanf("%d",&ele);
		a[top]=ele;
	}
}

void pop(){
	if(top==-1)
		printf("Stack is empty!\n");
	else{
		printf("%d\n",a[top]);
		top--;
	}
}
