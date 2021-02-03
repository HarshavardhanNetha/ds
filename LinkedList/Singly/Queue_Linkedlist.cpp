//program to demonstrate queue with linked list
//b171325
//Harsha

#include <stdio.h>
#include <stdlib.h>

struct node{
	int ele;
	struct node * next;
};

struct node * insert_tail(struct node*);
struct node * delete_head(struct node*);
void print(struct node*);

int main(){
	struct node * head = NULL;
	int opt;
	while(1){
		printf("1. Enqueue\n2. Dequeue\n3. Print\n4. Quit\nEnter:");
		scanf("%d",&opt);
		
		switch(opt){
			case 1:{
				head=insert_tail(head);
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

struct node * insert_tail(struct node* head){
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
		struct node* temp,*temp1;
		temp = (struct node*)malloc(sizeof(struct node));
		temp1 = (struct node*)malloc(sizeof(struct node));
		
		temp1=head;
		
		while(temp1->next!=NULL){
			temp1=temp1->next;
		}
		
		printf("Enter value to push:");
		int val;
		scanf("%d",&val);
		temp->ele=val;
		temp->next=NULL;
		temp1->next=temp;
		
		return head;
	}
}

struct node* delete_head(struct node * head){
	if(head==NULL){
		printf("Queue is empty!\n");
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
