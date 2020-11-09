#include <stdio.h>
#include <stdlib.h>

struct node{
	int ele;
	struct node* next;
};

void print(struct node*);
struct node* insert_at_head(struct node*);
struct node* insert_at_tail(struct node*);
int getLength(struct node*);
struct node* insert_at_pos(int, int, struct node*);
struct node* insert_at_mid(int,struct node*);
struct node* delete_ele(int,struct node*s);
struct node* delete_pos(int,int,struct node*);
bool search(int,struct node*);
struct node* adjustTail(struct node*);

int main(){
	struct node* head = NULL;

	while(1){
		
	int option,count,x;
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
		case 3:{
			count=getLength(head);
			//printf("%d",count);
			printf("Postition:");
			scanf("%d",&x);
			head=insert_at_pos(x,count,head);
			break;
		}
		case 4:{
			count=getLength(head);
			if(count%2==0)
				count=count/2;
			
			else
				count= (count+1)/2;
			//printf("Postition:");
			//scanf("%d",&x);
			head=insert_at_mid(count,head);
			break;
		}
		case 5:{
			int opt,find;
			printf("Enter element to search:");
			scanf("%d",&opt);
			find=search(opt,head);
			if(find){
				printf("Found!!!\n");
			}
			else
				printf("Not found!\n");
			break;
		}
		case 6:{
			int x;
			if(getLength(head)==0){
				printf("Linked list is empty!\n");
			}
			else{
				printf("Enter which element to remove:");
				scanf("%d",&x);
				head=delete_ele(x,head);
			}
			
			break;
		}
		case 7:{
			int x,c;
			c=getLength(head);
			if(c==0){
				printf("Linked list is empty!\n");
			}
			else{
				printf("Enter which position to remove:");
				scanf("%d",&x);
				head=delete_pos(x,c,head);
			}
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

struct node* insert_at_head(struct node* head){
	int value;
	printf("Enter value:");
	scanf("%d",&value);
	struct node* temp;
	
	if(head==NULL){
		head=(struct node*)malloc(sizeof(struct node));
		head->ele=value;
		head->next=head;
	}
	else{
		temp=(struct node*)malloc(sizeof(struct node));
		temp->ele=value;
		temp->next=head;
		head=temp;
		//printf("1");
		struct node* temp=head;
		do{
			temp=temp->next;
		}while(temp!=head);
		
		temp=head->next;
		temp->next=head;

	}
	
	
	return head;
}


struct node* insert_at_tail(struct node* head){
	int value;
	printf("Enter value:");
	scanf("%d",&value);
	
	struct node* temp;
	temp= (struct node*)malloc(sizeof(struct node));
	
	temp->ele = value;
	temp->next=head;	
	
	if(head==NULL){		
		head=temp;
		head->next=head;
	}
	else{
		struct node* temp1;
		temp1 = (struct node*)malloc(sizeof(struct node));
		temp1=head;
		while(temp1->next!=head)
			temp1=temp1->next;
		temp1->next=temp;
	}
	return head;
}

void print(struct node *head){
	struct node* temp = head;
	do{
		printf("%d ",temp->ele);
		temp=temp->next;
	}while(temp!=head);
}

int getLength(struct node *head){
	int c;
	struct node *temp=head;
	do{
		c++;
		temp=temp->next;
	}
	while(temp!=head);
	printf("Count: %d \n",c);
	return c;
}

struct node* insert_at_pos(int x,int c,struct node * head){
	int i=1;
	if(x==1){
		struct node* new_node;
		
		new_node=(struct node*)malloc(sizeof(struct node));
		printf("Enter element:");
		int value;
		scanf("%d",&value);
		
		new_node->ele=value;
		new_node->next=head;
		head=new_node;
		head=adjustTail(head);
	}
	else if(x<=c && x!=0){
		struct node* new_node;
		struct node* prev;
		new_node=(struct node*)malloc(sizeof(struct node));
		//temp1=(struct node*)malloc(sizeof(struct node));
		prev=head;
		while(i<x-1){
			prev=prev->next;
			i++;
		}
		printf("Enter element:");
		int value;
		scanf("%d",&value);
		new_node->ele=value;
		//temp->next=NULL;
		new_node->next=prev->next;
		prev->next=new_node;
	}
	else{
		printf("Enter valid range!\n");
	}
	return head;
}
struct node* insert_at_mid(int x,struct node* head){
	int i=1;
		struct node* new_node;
		struct node* prev;
		new_node=(struct node*)malloc(sizeof(struct node));
		//temp1=(struct node*)malloc(sizeof(struct node));
		prev=head;
		while(i<x-1){
			prev=prev->next;
			i++;
		}
		printf("Enter element:");
		int value;
		scanf("%d",&value);
		new_node->ele=value;
		//temp->next=NULL;
		new_node->next=prev->next;
		prev->next=new_node;
	return head;
}
bool search(int a,struct node* head){
	struct node* temp=head;
	
	do{
		if(temp->ele==a){
			return true;
		}
		temp=temp->next;
	}while(temp!=head);
	return false;
}
//act_node = actual node
//prev_node = previous node
struct node* delete_ele(int x,struct node* head){
	struct node* act_node = head;
	struct node* prev_node = head;
	struct node* temp=head;
	
	int flag=0;
	do{
		if(temp->ele==x){
			act_node=temp;
			flag=1;
		}
		temp=temp->next;
	}while(temp!=head);
	if(flag==0){
		printf("Element not found!\n");
		return head;
	}
	if(head->ele==x){
		head=head->next;
		head=adjustTail(head);
	}
	else{
		while(prev_node->next!=act_node){
			prev_node=prev_node->next;
		}
		prev_node->next=act_node->next;
	}
	return head;
}

struct node* delete_pos(int x,int c,struct node * head){
	struct node* act_node = head;
	struct node* prev_node = head;
	struct node* temp=head;
	
	int j=1,i=1;
	
	if(x==1){
		head=head->next;
		head=adjustTail(head);
	}
	else if(x<=c && x!=0){
		while(j<x){
			temp=temp->next;
			j++;
		}
		act_node=temp;
		while(i<x-1){
			prev_node=prev_node->next;
			i++;
		}
		prev_node->next=act_node->next;
	}
	else{
		printf("Enter valid range!\n");
	}
	return head;
}

struct node* adjustTail(struct node* head){
	struct node* temp=head;
	do{
		temp=temp->next;
	}while(temp!=head);
	temp->next=head;
	
	return head;
}
