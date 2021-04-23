#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void destroy(void *data){
	printf("Destroying: %p %d\n",data,*(int *)data);
	free(data);
}


int main(){
	List lista;
	list_init(&lista,destroy);
	ListElmt it=*list_head(&lista);
	int num,count=0;
	while(scanf("%d",&num)!=EOF){
		printf("%d\n",num);
		int* data = malloc(sizeof(int));
		*data = num;
		list_ins_next(&lista,NULL,(void *)data);
	}
//	do{
//		printf("%d - %d",count++,*(int *)list_data(&lista));
//	}while(ListElmt!=NULL);
	return 0;
}
