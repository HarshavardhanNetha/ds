#include<stdio.h>
#include<stdlib.h>

struct tree{
	struct tree* prev;
	int e;
	struct tree* next;
};

struct queue{
	struct tree* a[10];
	int rear;
	int front;
};

struct tree* insert(struct tree*,int,struct queue*);
struct queue* enqueue(struct queue*,struct tree*);
struct tree* dequeue(struct queue**);
void print(struct tree*);

int main(){
	struct tree* root=NULL;
	struct queue* q;
	q=(struct queue*)malloc(10*sizeof(struct queue));
	
	q->front=0;
	q->rear=0;
	int opt,val;
	while(1){
		printf("1. Insert\n2. Print\n3. Search\n4. Exit\nEnter:");
		scanf("%d",&opt);
		switch(opt){
			case 1:{
				printf("Element:");
				scanf("%d",&val);
				root=insert(root,val,q);
				break;
			}
			case 2:{
				print(root);
				break;
			}
			case 3:{
				
				break;
			}
			case 4:{
				exit(0);
			}
			default:
				break;
		}
	}

	return 0;
}

struct tree* insert(struct tree* root,int ele, struct queue* q){
	if(root==NULL){
		root=(struct tree*)malloc(sizeof(struct tree));
		root->next=NULL;
		root->prev=NULL;
		root->e=ele;
	}
	else{
		
		q=enqueue(q,root);
		
		struct tree* temp;
		
		while(1){
			temp=dequeue(&q);
			
			if(temp->prev!=NULL){
				enqueue(q,temp->prev);	
			}
			else
				break;
			if(temp->next!=NULL){
				enqueue(q,temp->next);
			}
			else
				break;	
		}
			
		struct tree* new_node;
		new_node=(struct tree*)malloc(sizeof(struct tree));
		new_node->e=ele;
		new_node->next=NULL;
		new_node->prev=NULL;
			
		if(temp->prev==NULL){
			temp->prev=new_node;
		}
		else
			temp->next=new_node;
	}
	return root;
}

struct queue* enqueue(struct queue* q,struct tree* ele){
	q->front++;
	q->a[q->front]=ele;
	return q;
}

struct tree* dequeue(struct queue** q){
	(*q)->rear++;
	return (*q)->a[(*q)->rear];
}

void print(struct tree* root){
	if(root==NULL){
		printf("EMPTY!");
	}	
	else{
		struct queue* qq;
		//qq=(struct queue*)malloc(10*sizeof(struct queue));				
		struct tree* temp;
		qq->front=0;
		qq->rear=0;		
		
		printf("%d ",root->e);

		qq=enqueue(qq,root);
		
		while(1){
			temp=dequeue(&qq);
			
			if(temp->prev!=NULL){
				printf("%d ",temp->prev->e);
				enqueue(qq,temp->prev);
			}
			else
				break;
			if(temp->next!=NULL){
				printf("%d ",temp->next->e);
				enqueue(qq,temp->next);
			}
			else
				break;	
		}
	}
	printf("\n");
}
