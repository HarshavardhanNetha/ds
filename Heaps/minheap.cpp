//perform minheap using array
//B171325
//Harsha

#include <stdio.h>

int* heapify(int*,int,int);
int* swap(int*,int,int);

int main(){
	
	int *a,arr[100];
	int n;
	
	printf("Enter the size:");
	scanf("%d",&n);
	
	int i;
	for(i=0;i<n;i++){
		printf("Enter the value:");
		scanf("%d",&arr[i]);
	}
	
	a=arr;
	
	for(i=n/2;i>0;i--){
		a=heapify(a,n,i); //a is array n is length of array and i is position
	}
	
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	
	return 0;
}

int* swap(int *a,int n, int min){
	int temp;
	temp=a[min];
	a[min]=a[n];
	a[n]=temp;
	
	return a;
}

int* heapify(int *a,int n, int i){
	int l,r,min=-1;
	l=(2*i)+1;
	r=(2*i)+2;
	if(r<n){
		if(a[l]<a[r]){
			min=l;
		}
		else
			min = r;
	}
	else if(l<n){
		min=l;
	}
	if(min!=-1 && a[i]>a[min]){
		a=swap(a,i,min);
		a=heapify(a,n,min);
	}
	return a;
}
