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
	struct node* head = NULL;
	while(1){
		
	int option;
	printf("1. Insert at head\n2. Insert at tail\n3. Insert at postion\n4. Insert at middle\n5. Search\n6. Remove an element\n7. Remove at postion\n8. Print\nEnter your option:");
	scanf("%d",&option);
	

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
		*head=(struct node*)malloc(sizeof(struct node));
		printf("Inserted!\n");
		(*head)->ele = value;
		(*head)->next=NULL;
	}
	else{
		struct node* temp;
		temp=(struct node*)malloc(sizeof(struct node));
		temp->ele=value;
		temp->next=*head;
		*head=temp;
	}
}

void print(struct node *head){
	struct node* temp = head;
	while(temp!=NULL){
		printf("%d ",temp->ele);
		temp=temp->next;
	}
}
