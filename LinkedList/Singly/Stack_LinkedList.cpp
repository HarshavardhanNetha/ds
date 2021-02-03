//program to demonstrate stack with linked list
//b171325
//Harsha

#include <stdio.h>
#include <stdlib.h>

struct node{
	int ele;
	struct node * next;
};

struct node * insert_head(struct node*);
struct node * delete_head(struct node*);
void print(struct node*);

int main(){
	struct node * head = NULL;
	int opt;
	while(1){
		printf("1. Push\n2. Pop\n3. Print\n4. Quit\nEnter:");
		scanf("%d",&opt);
		
		switch(opt){
			case 1:{
				head=insert_head(head);
				break;
			}
			case 2:{
				head=delete_head(head);
				break;
			}
			case 4:{
				exit(0);
				break;
			}
			case 3:{
				print(head);
				break;
			}
			default: printf("Enter valid input.\n");
		}
	}
	return 0;
}

struct node * insert_head(struct node* head){
	if(head==NULL){
		head = (struct node*)malloc(sizeof(struct node));
		printf("Enter value to push:");
		int val;
		scanf("%d",&val);
		head->ele=val;
		head->next=NULL;
		return head;
	}
	else{
		struct node * temp=head;
		temp = (struct node*)malloc(sizeof(struct node));
		printf("Enter value to push:");
		int val;
		scanf("%d",&val);
		temp->ele=val;
		temp->next=head;
		head=temp;
		return head;
	}
}

struct node* delete_head(struct node * head){
	if(head==NULL){
		printf("Stack is empty!\n");
		return head;
	}
	else{
		printf("%d\n",head->ele);
		head=head->next;
		return head;
	}
}

void print(struct node * head){
	struct node *temp=head;
	while(temp!=NULL){
		printf("%d ",temp->ele);
		temp=temp->next;
	}
	printf("\n");
}
