#include <stdio.h>
#include <stdlib.h>

struct node{
	node* prev;
	int ele;
	node* next;
};

struct node* insert_at_head(struct node*);
struct node* insert_at_tail(struct node*);
void print(struct node*);

int main(){
	struct node * head=NULL;
	while(1){
		int option;
		printf("1. Insert at head\n2. Insert at tail\n3. Insert at postion\n4. Insert at middle\n5. Search\n6. Remove an element\n7. Remove at postion\n8. Print\nEnter your option:");
		scanf("%d",&option);
		
		switch(option){
			case 1:{
				head=insert_at_head(head);
				break;
			}
			case 2:{
				head=insert_at_tail(head);
				break;
			}
			case 8:{
				print(head);
				printf("\n");
				break;
			}
		}
	}
	
}

struct node * insert_at_tail(struct node *head){
	int val;
	printf("Enter a value:");
	scanf("%d",&val);
	if(head==NULL){
		head=(struct node*)malloc(sizeof(struct node*));
		head->prev=NULL;
		head->ele=val;
		head->next=NULL;
	}
	else{
		struct node* temp;
		struct node*temp1;
		temp=(struct node*)malloc(sizeof(struct node*));
		temp1=(struct node*)malloc(sizeof(struct node*));
		temp1=head;
		while(temp1->next!=NULL){
			temp1=temp1->next;
		}
		temp->ele=val;
		temp->prev=temp1;
		temp->next=NULL;
		temp1->next=temp;
	}
	return head;
}
struct node * insert_at_head(struct node *head){
	int val;
	printf("Enter a value:");
	scanf("%d",&val);
	if(head==NULL){
		head=(struct node*)malloc(sizeof(struct node*));
		head->prev=NULL;
		head->ele=val;
		head->next=NULL;
	}
	else{
		struct node* temp;
		temp=(struct node*)malloc(sizeof(struct node*));
		temp->ele=val;
		temp->prev=NULL;
		temp->next=head;
		head=temp;
		temp->next->prev=temp;
	}
	return head;
}

void print(struct node *head){
	struct node* temp = head;
	while(temp!=NULL){
		printf("%d ",temp->ele);
		temp=temp->next;
	}
}
