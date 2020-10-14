//inserting at the beginning with functions search

#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node* next;
};

struct node *head=NULL;
struct node *tail;

int insert(){
	int ele;
	printf("Enter element to insert:");
	scanf("%d",&ele);
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=ele;
	temp->next=head;
	head=temp;
	return 0;
}


void print(){
	struct node *temp1=head;
	//temp1=(struct node*)malloc(sizeof(struct node));
	while(temp1!=NULL){
		printf("%d ",temp1->data);
		//printf("%o ",temp1->next);
		temp1=temp1->next;
	}
}

bool search(int ele){
	struct node *temp2=head;
	//temp2=(struct node*)malloc(sizeof(struct node));
	while(temp2!=NULL){
		if(temp2->data==ele)
			return true;
		temp2=temp2->next;
	}
	return false;
}

struct node* getAdd(int ele){
	struct node *temp2=head;
	//temp2=(struct node*)malloc(sizeof(struct node));
	while(temp2!=NULL){
		if(temp2->data==ele)
			return temp2->next;
		tail=temp2;
		temp2=temp2->next;
	}
	return 0;
}

int main(){
	int n,i,ele,check;
	printf("How many nodes you wish to have:");
	scanf("%d",&n);
	
	//inserting
	for(i=0;i<n;i++){
		insert();
	}
	//printing them
	print();
	printf("\n");
	
	//searching
	printf("Enter what to delete:");
	scanf("%d",&check);
	struct node* next_node;
	next_node=(struct node*)malloc(sizeof(struct node));
	if(search(check)){
		next_node=getAdd(check);
		//printf("%o %o\n",tail,next_node);
		while(head->next==tail){
			head->next=next_node;
		}
		print();
	}
	else
		printf("Element not found.");
	return 0;
}
