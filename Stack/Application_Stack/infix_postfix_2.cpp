//done
//program to demonstrate application of stack i.e infix and postfix
//b171325
//Harsha

#include <stdio.h>
#include <stdlib.h>

char stack[100];
int top = -1;

void push(char ele){
	top++;
	stack[top]=ele;
}

char pop(){
	if(top==-1)
		return 0;
	else
		return stack[top--];
}

char top_ele(){
	return stack[top];
}

int prior(char c){
	if(c=='(')
		return 0;
	if(c=='+' || c=='-')
		return 1;
	if(c=='*' || c=='/')
		return 2;
	if(c=='^')
		return 3;
	else
		return 0;
}

int main(){
	char arr[20];
	scanf("%s",arr);
	char *a = arr;
	//a=arr;
	while(*a!='\0'){
		if(*a=='('){
			push(*a);
		}
		else if(*a=='+' || *a=='-'){
			while(prior(top_ele())>=prior(*a)){
				printf("%c",pop());
			}
			push(*a);
		}
		else if(*a=='*' || *a=='/'){
			while(prior(top_ele())>=prior(*a)){
				printf("%c",pop());
			}
			push(*a);
		}
		else if(*a=='^'){
			while(prior(top_ele())>=prior(*a)){
				printf("%c",pop());
			}
			push(*a);
		}
		else if(*a==')'){
			while(top_ele()!='('){
				printf("%c",pop());
			}
			pop();
		}
		else{
			printf("%c",*a);
		}
		a++;
	}
	while(top!=-1){
		printf("%c",pop());
	}
	
	return 0;	
}
