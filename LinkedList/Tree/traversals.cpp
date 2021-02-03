//program to implement different ways of tree traversals
//b171325
//Harsha

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

struct tree* insert(struct tree*,int);
struct queue* enqueue(struct queue*,struct tree*);
struct tree* dequeue(struct queue*);
void print(struct tree*);
void preorder(struct tree*);
void postorder(struct tree*);
void inorder(struct tree*);

bool isEmpty(struct queue* q){
	if(q->front==q->rear)
		return true;
	else
		return false;
}

int main(){
	struct tree* root=NULL;

	int opt,val;
	while(1){
		printf("1. Insert\n2. Preorder\n3. Postorder\n4. Inorder\n5. Exit\nEnter:");
		scanf("%d",&opt);
		switch(opt){
			case 1:{
				printf("Element:");
				scanf("%d",&val);
				root=insert(root,val);
				break;
			}
			case 2:{
				preorder(root);
				printf("\n");
				break;
			}
			case 6:{
				print(root);
				break;
			}
			case 3:{
				postorder(root);
				printf("\n");				
				break;
			}
			case 4:{
				inorder(root);
				printf("\n");
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

struct tree* insert(struct tree* root,int ele){
	if(root==NULL){
		root=(struct tree*)malloc(sizeof(struct tree));
		root->next=NULL;
		root->prev=NULL;
		root->e=ele;
	}
	else{
		struct queue* q;
		q=(struct queue*)malloc(20*sizeof(struct queue));
		
		q->front=0;
		q->rear=0;
		q=enqueue(q,root);
		
		struct tree* temp;
		
		struct tree* new_node;
		new_node=(struct tree*)malloc(sizeof(struct tree));
		new_node->e=ele;
		new_node->next=NULL;
		new_node->prev=NULL;
			
		while(!isEmpty(q)){
			temp=dequeue(q);
			
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

struct tree* dequeue(struct queue* q){
	q->rear++;
	return q->a[q->rear];
}

void print(struct tree* root){
	if(root==NULL){
		printf("EMPTY!");
	}	
	else{
		struct queue* qq;
		qq=(struct queue*)malloc(30*sizeof(struct queue));				
		struct tree* temp;
		qq->front=0;
		qq->rear=0;		
		
		printf("%d ",root->e);

		qq=enqueue(qq,root);
		
		while(1){
			temp=dequeue(qq);
			
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

void preorder(struct tree* root){
	if(root!=NULL){
		printf("%d ",root->e);
		preorder(root->prev);
		preorder(root->next);
	}
}
void postorder(struct tree* root){
	if(root!=NULL){
		postorder(root->prev);
		postorder(root->next);
		printf("%d ",root->e);
	}
}

void inorder(struct tree* root){
	if(root!=NULL){
		inorder(root->prev);
		printf("%d ",root->e);
		inorder(root->next);
	}
}

