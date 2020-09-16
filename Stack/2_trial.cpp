#include <stdio.h>
#include <stdlib.h>

struct temp{
	int a;
};

struct temp push(int max, struct temp t){
	t.a=max;
	return t;
}

int main(){
	struct temp t;
	int max=10;
	t = push(max,t);
	printf("%d\n",t.a);
}
