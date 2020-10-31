//inserting at the beginning with functions

#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node* next;
};

struct node *head;

void insert(int ele){
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=ele;
	temp->next=head;
	//if(head!=NULL)
	//	temp.next=head;
	head=temp;
}


void print(){
	struct node *temp1=head;
	while(temp1!=NULL){
		printf("%d ",temp1->data);
		temp1=temp1->next;
	}
}


int main(){
	head=NULL;
	int n,i,ele;
	printf("How many nodes you wish to have:");
	scanf("%d",&n);
	
	//inserting
	for(i=0;i<n;i++){
		printf("Enter element to insert:");
		scanf("%d",&ele);
		insert(ele);
	}
	//printing them
	print();
	return 0;
}
