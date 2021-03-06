//done
//program to demonstrate stack with structure and pointers using functions and DMA
//b171325
//Harsha

#include <stdio.h>
#include <stdlib.h>

struct stack{
	int *a;
	int top;
	int max;
};

int push(struct stack *s,int ele){
	if(s->top==s->max-1)
		printf("Stack is full!\n");
	else{
		s->top++;
		scanf("%d",&ele);
		s->a[s->top]=ele;
	}
	return 0;
}

int pop(struct stack *s,int ele){
	if(s->top==-1)
		printf("Stack is empty!\n");
	else{
		printf("%d\n",s->a[s->top]);
		s->top--;
	}
	return 0;
}

int main(){
	struct stack *s;
	int ary;
	printf("Enter the size for DMA:");
	scanf("%d",&ary);
	s=(struct stack *)malloc(sizeof(struct stack));
	s->a=(int*)malloc(ary*sizeof(int));
	s->max=ary;
	s->top=-1;
	int option,ele;
	
	do{
		printf("1.Push\n2.Pop\n3.Exit\nEnter your option:");
		scanf("%d",&option);
		
		switch(option){
			case 1:{
				push(s,ele);
				//printf("%d",top);
				//printf("%d\n",s->top);
				//printf("%d\n",s->a[s->top]);
				break;
			}
			case 2:{
				pop(s,ele);
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
