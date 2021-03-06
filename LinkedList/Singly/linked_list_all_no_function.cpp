//program to demonstrate linked list without functions
//b171325
//Harsha

#include <stdio.h>
#include <stdlib.h>

struct node{
	int ele;
	struct node* next;
};

void print();
void insert_at_head();
void insert_at_tail();
void insert_at_pos(int,int);
void insert_at_mid(int);
void search();
void delete_ele(int);
void delete_pos(int,int);
int getLength();
bool search(int);

struct node* head = NULL;

int main(){
	int option,count,x;

	while(1){
		
	printf("1. Insert at head\n2. Insert at tail\n3. Insert at postion\n4. Insert at middle\n5. Search\n6. Remove an element\n7. Remove at postion\n8. Print\nEnter your option:");
	scanf("%d",&option);
	

	switch(option){
		case 1:{
			insert_at_head();
			break;
		}
		case 2:{
			insert_at_tail();
			break;
		}
		case 3:{
			count=getLength();
			//printf("%d",count);
			printf("Postition:");
			scanf("%d",&x);
			insert_at_pos(x,count);
			break;
		}
		case 4:{
			count=getLength();
			if(count%2==0)
				count=count/2;
			
			else
				count= (count+1)/2;
			//printf("Postition:");
			//scanf("%d",&x);
			insert_at_mid(count);
			break;
		}
		case 5:{
			int opt,find;
			printf("Enter element to search:");
			scanf("%d",&opt);
			find=search(opt);
			if(find){
				printf("Found!!!\n");
			}
			else
				printf("Not found!\n");
			break;
		}
		case 6:{
			int x;
			if(getLength()==0){
				printf("Linked list is empty!\n");
			}
			else{
				printf("Enter which element to remove:");
				scanf("%d",&x);
				delete_ele(x);
			}
			
			break;
		}
		case 7:{
			int x,c;
			c=getLength();
			if(c==0){
				printf("Linked list is empty!\n");
			}
			else{
				printf("Enter which position to remove:");
				scanf("%d",&x);
				delete_pos(x,c);
			}
			break;
		}
		case 8:{
			print();
			printf("\n");
			break;
		}
	}
	
	}
	return 0;
}

void insert_at_head(){
	int value;
	printf("Enter value:");
	scanf("%d",&value);
	
	struct node* temp;
	temp= (struct node*)malloc(sizeof(struct node));
	
	temp->ele=value;
	temp->next=head;
	
	head=temp;
}

void insert_at_tail(){
	int value;
	printf("Enter value:");
	scanf("%d",&value);
	
	struct node* temp;
	temp= (struct node*)malloc(sizeof(struct node));
	
	temp->ele = value;
	temp->next=NULL;	
	
	if(head==NULL){		
		head=temp;
	}
	else{
		struct node* temp1;
		temp1 = (struct node*)malloc(sizeof(struct node));
		temp1=head;
		while(temp1->next!=NULL)
			temp1=temp1->next;
		temp1->next=temp;
	}
}


void print(){
	struct node* temp = head;
	while(temp!=NULL){
		printf("%d ",temp->ele);
		temp=temp->next;
	}
}

int getLength(){
	int c;
	struct node *temp=head;
	while(temp!=NULL){
		c++;
		temp=temp->next;
	}
	return c;
}

void insert_at_pos(int x,int c){
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
}

void insert_at_mid(int x){
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
}

bool search(int a){
	struct node* temp=head;
	
	while(temp!=NULL){
		if(temp->ele==a){
			return true;
		}
		temp=temp->next;
	}
	return false;
}
//act_node = actual node
//prev_node = previous node
void delete_ele(int x){
	struct node* act_node = head;
	struct node* prev_node = head;
	struct node* temp=head;
	
	int flag=0;
	while(temp!=NULL){
		if(temp->ele==x){
			act_node=temp;
			flag=1;
		}
		temp=temp->next;
	}
	if(flag==0){
		printf("Element not found!\n");
		return ;
	}
	if(head->ele==x){
		head=head->next;
	}
	else{
		while(prev_node->next!=act_node){
			prev_node=prev_node->next;
		}
		prev_node->next=act_node->next;
	}
}

void delete_pos(int x,int c){
	struct node* act_node = head;
	struct node* prev_node = head;
	struct node* temp=head;
	
	int j=1,i=1;
	
	if(x==1){
		head=head->next;
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
}
