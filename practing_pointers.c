#include <stdio.h>
#include <stdlib.h>
#include "frames.h"
#include "list.h"

void destroy(void *data){
    printf("Destroying:%p %d\n",data ,*(int*)data);
    free(data);
}

int main(){
	int a = 2;
	int* ptr=malloc(sizeof(int));
	*ptr = a;
	destroy((void *) ptr);
	return 0;
}
