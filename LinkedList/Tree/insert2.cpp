#include<stdio.h>
#include<stdlib.h>

struct tree{
	struct tree* prev;
	int e;
	struct tree* next;
};

struct queue{
	struct tree* a[20];
	int rear;
	int front;
};

struct tree* insert(struct tree*,int,struct queue*);
struct queue* enqueue(struct queue*,struct tree*);
struct tree* dequeue(struct queue**);
void print(struct tree*);
bool search(struct tree*,int);
struct tree* remove(struct tree*,int);

bool isEmpty(struct tree* root){
	if(root->prev==root->next)
		return true;
	else
		return false;
}

int main(){
	struct tree* root=NULL;
	struct queue* q;
	q=(struct queue*)malloc(20*sizeof(struct queue));
	
	q->front=0;
	q->rear=0;
	int opt,val;
	while(1){
		printf("1. Insert\n2. Print\n3. Search\n4. Remove\n5. Exit\nEnter:");
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
				bool check;
				int ele;
				printf("Enter to search:");
				scanf("%d",&ele);
				check=search(root,ele);
				if(check)
					printf("Found!\n");
				else
					printf("Not Found!\n");
				break;
			}
			case 4:{
				int ele;
				printf("What to remove:");
				scanf("%d",&ele);
				root=remove(root,ele);
				break;
			}
			case 5:{
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
		
		struct tree* new_node;
		new_node=(struct tree*)malloc(sizeof(struct tree));
		new_node->e=ele;
		new_node->next=NULL;
		new_node->prev=NULL;
			
		while(!isEmpty(root)){
			temp=dequeue(&q);
			
			if(temp->prev!=NULL){
				enqueue(q,temp->prev);	
			}
			else{
				temp->prev=new_node;
				return root;
			}
			if(temp->next!=NULL){
				enqueue(q,temp->next);
			}
			else{
				temp->next=new_node;
				return root;
			}
		}
	}
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

bool search(struct tree* root,int x){
	if(root==NULL){
		return false;
	}	
	else{
		struct queue* qq;
		//qq=(struct queue*)malloc(10*sizeof(struct queue));				
		struct tree* temp;
		qq->front=0;
		qq->rear=0;		
		
		if(root->e==x)
			return true;

		qq=enqueue(qq,root);
		
		while(1){
			temp=dequeue(&qq);
			
			if(temp->prev!=NULL){
				if(temp->prev->e==x)
					return true;
				enqueue(qq,temp->prev);
			}
			else
				break;
			if(temp->next!=NULL){
				if(temp->next->e==x)
					return true;
				enqueue(qq,temp->next);
			}
			else
				break;	
		}
	}
	return false;
	
}
struct tree* remove(struct tree* root,int x){
	if(root==NULL){
		return root;
	}	
	else{
		struct queue* qq;
		//qq=(struct queue*)malloc(10*sizeof(struct queue));				
		struct tree* temp;
		temp=(struct tree*)malloc(sizeof(struct tree));
		qq->front=0;
		qq->rear=0;		
		
		if(root->e==x){
			root=NULL;
			root->next=NULL;
			root->prev=NULL;
			return root;
		}
			

		qq=enqueue(qq,root);
		
		while(1){
			temp=dequeue(&qq);
			
			if(temp->prev!=NULL){
				if(temp->prev->e==x){
					temp->prev=NULL;
					//temp->next->next=NULL;
					//temp->prev->prev=NULL;
					return root;	
				}
				enqueue(qq,temp->prev);
			}
			else
				break;
			if(temp->next!=NULL){
				if(temp->next->e==x){
					temp->next=NULL;
					//temp->next->next=NULL;
					//temp->prev->prev=NULL;
					return root;	
				}
				enqueue(qq,temp->next);
			}
			else
				break;	
		}
	}
	return root;
	
}
