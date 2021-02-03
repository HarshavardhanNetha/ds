//perform maxheap using array
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

int* swap(int *a,int n, int max){
	int temp;
	temp=a[max];
	a[max]=a[n];
	a[n]=temp;
	
	return a;
}

int* heapify(int *a,int n, int i){
	int l,r,max=-1;
	l=(2*i)+1;
	r=(2*i)+2;
	if(r<n){
		if(a[l]>a[r]){
			max=l;
		}
		else
			max = r;
	}
	else if(l<n){
		max=l;
	}
	if(max!=-1 && a[i]<a[max]){
		a=swap(a,i,max);
		a=heapify(a,n,max);
	}
	return a;
}
