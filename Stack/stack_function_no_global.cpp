//program to demonstrate basic stack with no global variables
//b171325
//Harsha

#include <stdio.h>
#include <stdlib.h>


int push(int top,char a[20],int ele,int size){
	if(top==size-1)
		printf("Stack is full!\n");
	else{
		top++;
		scanf("%d",&ele);
		a[top]=ele;
	}
	return top;
}

int pop(int top,char a[20],int ele,int size){
	if(top==-1)
		printf("Stack is empty!\n");
	else{
		printf("%d\n",a[top]);
		top--;
	}
	return top;
}

int main(){	
	static char a[20];
	static int size=20,top=-1,option;
	static int ele;
	do{
		printf("1.Push\n2.Pop\n3.Exit\nEnter your option:");
		scanf("%d",&option);
		
		switch(option){
			case 1:{
				top=push(top,a,ele,size);
				//printf("%d",top);
				break;
			}
			case 2:{
				top=pop(top,a,ele,size);
				//printf("%d",top);
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
