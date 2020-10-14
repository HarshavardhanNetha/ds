#include <stdio.h>
#include <stdlib.h>

struct node{
	int ele;
	struct node* next;
};

void print(struct node*);
void insert_at_head(struct node**);
void insert_at_tail(struct node**);
void search(struct node*);

int main(){
	int option;
	while(1){
		
	printf("1. Insert at head\n2. Insert at tail\n3. Insert at postion\n4. Insert at middle\n5. Search\n6. Remove an element\n7. Remove at postion\n8. Print\nEnter your option:");
	scanf("%d",&option);
	
	struct node* head = NULL;

	switch(option){
		case 1:{
			insert_at_head(&head);
			break;
		}
		case 8:{
			print(head);
			printf("\n");
			break;
		}
	}
	
	}
	return 0;
}

void insert_at_head(struct node** head){
	int value;
	printf("Enter value:");
	scanf("%d",&value);
	
	if(*head==NULL){
		struct node* head=(struct node*)malloc(sizeof(struct node));
		
		head->ele = value;
		head->next=NULL;
	}
	else{
		head->ele=value;
		head->next=*head;
	}
}

void print(struct node *head){
	struct node* temp = head;
	while(temp!=NULL){
		printf("%d ",temp->ele);
		temp=temp->next;
	}
}
