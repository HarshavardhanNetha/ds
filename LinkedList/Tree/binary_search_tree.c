#include <stdio.h>
#include <stdlib.h>

struct node{
	int e;
	struct node* prev;
	struct node* next;
};

struct queue{
	struct node* a[20];
	int rear;
	int front;
};

struct node* insert(struct node*,int);
void print(struct node*);
struct queue* enqueue(struct queue*,struct node*);
struct node* dequeue(struct queue*);
struct node* search(struct node*,int);
struct node* remove_val(struct node*, int);

int isEmpty(struct queue* q){
	if(q->front==q->rear)
		return 1;
	else
		return 0;
}


int main(){
	struct node* root=NULL;
	int opt,val;
	while(1){
		printf("1.Insert\n2.Print\n3.Search\n4.Remove\n5.Quit\nChoose one:");
		scanf("%d",&opt);
		switch(opt){
			case 1:{
				printf("Enter a value:");
				scanf("%d",&val);
				root=insert(root,val);
				break;
			}
			case 2:{
				print(root);
				break;
			}
			case 3:{
				printf("What to search:");
				scanf("%d",&val);
				struct node* temp;
				temp=search(root,val);
				if(!temp)
					printf("Not Found!\n");
				else
					printf("Found\n");
				break;
			}
			case 4:{
				printf("What to delete:");
				scanf("%d",&val);
				root=remove_val(root,val);
				break;
			}
			case 5:
				exit(0);
		}
	}
	return 0;
}

struct node* insert(struct node* root,int val){
	if(root==NULL){
		root=(struct node*)malloc(sizeof(struct node));
		root->e=val;
		root->prev=NULL;
		root->next=NULL;
		
		return root;
	}	
	else{
		struct node* temp = root;
		struct node* new_node;
		new_node=(struct node*)malloc(sizeof(struct node));
		//temp=(struct node*)malloc(sizeof(struct node));
		new_node->e=val;
		new_node->prev=NULL;
		new_node->next=NULL;
		
		while(1){
			if(temp->e>val){
				if(temp->prev!=NULL){
					temp=temp->prev;
				}
				else{
					temp->prev=new_node;
					break;
				}
			}
			else{
				if(temp->next!=NULL)
					temp=temp->next;
				else{
					temp->next=new_node;
					break;
				}
			}
		}
		return root;
	}
	
}

struct node* search(struct node* root,int val){
	if(root==NULL){
		
		return NULL;
	}	
	else{
		struct node* temp = root;
		if(root->e==val)
			return root;
		while(1){
			if(temp->e>val){
				if(temp->prev!=NULL){
					if(temp->prev->e==val)
						return temp;
					temp=temp->prev;
				}
				else{
					return NULL;
				}
			}
			else{
				if(temp->next!=NULL){
					if(temp->next->e==val)
						return temp;
					temp=temp->next;
				}	
				else{
					return NULL;
				}
			}
		}
	}
	
}

struct queue* enqueue(struct queue* q,struct node* ele){
	q->front++;
	q->a[q->front]=ele;
	return q;
}

struct node* dequeue(struct queue* q){
	q->rear++;
	return q->a[q->rear];
}


void print(struct node* root){
	if(root==NULL){
		printf("EMPTY!");
	}	
	
	else{
		struct queue* qq;
		qq=(struct queue*)malloc(30*sizeof(struct queue));				
		struct node* temp;
		qq->front=0;
		qq->rear=0;		
		
		printf("%d ",root->e);

		qq=enqueue(qq,root);
		
		while(!isEmpty(qq)){
			temp=dequeue(qq);
			
			if(temp->prev!=NULL){
				printf("%d ",temp->prev->e);
				enqueue(qq,temp->prev);
			}
			if(temp->next!=NULL){
				printf("%d ",temp->next->e);
				enqueue(qq,temp->next);
			}
		}
	}
	printf("\n");
}

struct node* remove_val(struct node* root, int val){
	struct node* temp;
	temp=search(root,val);
	if(!temp){
		printf("Value not found!\n");
		return root;
	}
	else{
		struct node* parent;
		struct node* actual;
		actual = (struct node*)malloc(sizeof(struct node));
		parent=temp;
		if(temp->e<val){
			temp=temp->next;
			actual=actual->next;
			//right removal - replacing largest from right pool
			temp=temp->next;
			if(temp->prev==NULL){
				temp=NULL;
				actual->next=temp->next;
			}
			else{
				while(temp->prev!=NULL){
					temp=temp->prev;
				}
				temp->e=actual->e;
				temp=NULL;
			}
		}
		return root;
	}
}
