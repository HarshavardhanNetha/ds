#include <stdio.h>
#include <stdlib.h>

int main(){
	char a[20];
	int size=20,top=-1,option,ele;
	
	do{
		printf("1.Push\n2.Pop\n3.Exit\nEnter your option:");
		scanf("%d",&option);
		
		switch(option){
			case 1:{
				if(top==size-1)
					printf("Stack is full!\n");
				else{
					top++;
					scanf("%d",&ele);
					a[top]=ele;
				}
				break;
			}
			case 2:{
				if(top==-1)
					printf("Stack is empty!\n");
				else{
					printf("%d\n",a[top]);
					top--;
				}			
				break;
			}
			case 3:{
				exit(0);
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
