//done
//program to demonstrate stack with structure and array using functions
//b171325
//Harsha

#include <stdio.h>
#include <stdlib.h>

struct stack{
	int a[20];
	int top;
	int max;
};

struct stack push(struct stack s,int ele){
	if(s.top==s.max-1)
		printf("Stack is full!\n");
	else{
		s.top++;
		scanf("%d",&ele);
		s.a[s.top]=ele;
	}
	return s;
}

struct stack pop(struct stack s,int ele){
	if(s.top==-1)
		printf("Stack is empty!\n");
	else{
		printf("%d\n",s.a[s.top]);
		s.top--;
	}
	return s;
}

int main(){
	struct stack s;
	s.max=20;
	s.top=-1;
	int option,ele;
	
	do{
		printf("1.Push\n2.Pop\n3.Exit\nEnter your option:");
		scanf("%d",&option);
		
		switch(option){
			case 1:{
				s=push(s,ele);
				//printf("%d",top);
				//printf("%d\n",s.top);
				//printf("%d\n",s.a[s.top]);
				break;
			}
			case 2:{
				s=pop(s,ele);
				//printf("%d",top);
				break;
			}
			case 3:
				exit(0);
			default:{
				printf("Enter valid option.\n");
				break;
			}
		}
	}
	while(option!=3);
	return 0;
}
