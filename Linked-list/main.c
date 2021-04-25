#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void destroy(void *data)
{
	printf("Destroying: %p %d\n", data, *(int *)data);
	free(data);
}

int main()
{
	List *lista = (List *)malloc(sizeof(List));
	list_init(lista, destroy);
	int num, count = 0;
	while (scanf("%d", &num) != EOF)
	{
		int *data = malloc(sizeof(int));
		*data = num;
		list_ins_next(lista, list_tail(lista), (const void *)data);
	}
	ListElmt *it = list_head(lista);
	printf("List iteration(Pointer/Element/Position):\n");
	while (it != NULL)
	{
		printf("%p %d %d\n", it, *(int *)it->data, count++);
		it = it->next;
	}
	// printf("List destruction(Pointer/Head/Deleted element/List size):\n");
	// while (list_size(lista) > 0)
	// {
	// 	void *data;
	// 	printf("%p %d ", list_head(lista), *(int *)list_head(lista)->data);
	// 	list_rem_next(lista, NULL, &data);
	// 	printf("%d %d\n", *(int *)data, list_size(lista));
	// }
	list_destroy(lista);
	return 0;
}
