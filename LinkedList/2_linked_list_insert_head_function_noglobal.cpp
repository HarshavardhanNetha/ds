//inserting at the beginning with functions

#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node* next;
};


struct node* insert(struct node *head,int ele){
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=ele;
	temp->next=head;
	//if(head!=NULL)
	//	temp.next=head;
	head=temp;
	return head;
}


void print(struct node *head){
	while(head!=NULL){
		printf("%d",head->data);
		head=head->next;
	}
}


int main(){
	struct node *head;
	head=NULL;
	int n,i,ele;
	printf("How many nodes you wish to have:");
	scanf("%d",&n);
	
	//inserting
	for(i=0;i<n;i++){
		printf("Enter element to insert:");
		scanf("%d",&ele);
		head=insert(head,ele);
	}
	//printing them
	print(head);
	return 0;
}
