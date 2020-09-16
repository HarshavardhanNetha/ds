//done
#include <stdio.h>
#include <stdlib.h>

struct stack{
	int a[20];
	int top;
	int max;
};

int main(){
	struct stack *s;
	s=(struct stack *)malloc(sizeof(struct stack));
	s->max=20;
	s->top=-1;
	int option,ele;
	
	do{
		printf("1.Push\n2.Pop\n3.Exit\nEnter your option:");
		scanf("%d",&option);
		
		switch(option){
			case 1:{
				if(s->top==s->max-1)
					printf("Stack is full!\n");
				else{
					s->top++;
					scanf("%d",&ele);
					s->a[s->top]=ele;
				}
				break;
			}
			case 2:{
				if(s->top==-1)
					printf("Stack is empty!\n");
				else{
					printf("%d\n",s->a[s->top]);
					s->top--;
				}			
				break;
			}
			case 3:{
				//exit(0);
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
