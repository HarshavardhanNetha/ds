//inserting at the beginning

#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node* next;
};

int main(){
	struct node *head=NULL;
	int n,i,ele;
	printf("How many nodes you wish to have:");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		struct node *temp;
		temp=(struct node*)malloc(sizeof(struct node));
		scanf("%d",&ele);
		temp->data=ele;
		temp->next=head;
		//if(head!=NULL)
		//	temp.next=head;
		head=temp;
	}
	
	//printing them
	struct node *temp1=head;
	while(temp1!=NULL){
		printf("%d",temp1->data);
		temp1=temp1->next;
	}
	return 0;
}
