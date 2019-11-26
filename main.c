#include "vector.h"
#include <stdio.h>
#include <stdlib.h>

void check(ERRORCODE error)
{
	switch(error)
	{
		case E_NULL_PTR:
			printf("null ptr\n");
			break;
		case E_UNDERFLOW:
			printf("underflow\n");
			break;
		case E_ALLOCATION_ERROR:
			printf("allocation error\n");
			break;
		case E_BAD_INDEX:
			printf("bad index\n");
			break;
		default:
			printf("ok\n");
	}
}

int main()
{	
	int num;
	size_t numt;
	vector* a;
	vector* b;
	vector* c;
	ERRORCODE e;
	
	/*checking*/

	/*create a vector*/
	a = vector_create(5);
	#ifdef _DEBUG
	printf("the size is:%ld", vector_get_size(a, &e));
	#endif
	
	/*push*/
	e = vector_push(8,a);
	#ifdef _DEBUG
	printf("%d", vector_get_element(a, 0, &e));
	check(e);
	#endif
	e = vector_push(3,a);
	#ifdef _DEBUG
	printf("%d",vector_get_element(a, 1, &e));
	check(e);
	#endif
	e = vector_insert(a,4,1);
	#ifdef _DEBUG
	vector_print(a);
	check(e);
	#endif

	/*remove*/
	e = vector_remove(a,1);
	#ifdef _DEBUG
	vector_print(a);
	check(e);
	#endif
	
	/*pop*/
	e = vector_pop(a);
	#ifdef _DEBUG
	vector_print(a);
	check(e);
	#endif
	
	/*get element*/
	num  = vector_get_element(a, 1, &e);
	#ifdef _DEBUG
	printf("%d\n",num);
	check(e);
	#endif
	
	/*set element*/
	e = vector_set_element(a, 2, 5);
	#ifdef _DEBUG
	check(e);
	#endif
	
	/*get count*/
	e = vector_push(8,a);
	#ifdef _DEBUG
	check(e);
	#endif
	num = vector_count(a, 8); 
	#ifdef _DEBUG
	printf("%d times\n",num);
	vector_print(a);
	#endif

	/*get size*/
	numt =  vector_get_size(a, &e);
	#ifdef _DEBUG
	printf("%ld\n",numt);
	check(e);
	vector_print(a);
	#endif

	/*get capacity*/
	numt = vector_get_capacity(a, &e);
	#ifdef _DEBUG
	printf("%d\n",num);
	check(e);
	vector_print(a);
	#endif

	/*check special cases*/
	#ifdef _DEBUG
	printf("\nchecking special cases:\n");
	#endif
	c = vector_create(3);
	vector_push(8, c);
	vector_push(3, c);
	vector_insert(c, 9, 1);
	#ifdef _DEBUG
	vector_print(c);
	#endif

	/*push*/
	e = vector_push(4, c);
	#ifdef _DEBUG
	check(e);
	vector_print(c);
	#endif
	
	/*pop*/
	e = vector_pop(c);
	#ifdef _DEBUG
	check(e);
	#endif
	
	/*insert*/
	e = vector_insert(c, 5, 9);
	#ifdef _DEBUG
	check(e);
	#endif
	e = vector_insert(c, 5, 6);
	#ifdef _DEBUG
	check(e);
	#endif
	e = vector_insert(c, 18, 2);
	#ifdef _DEBUG
	check(e);
	vector_print(c);
	#endif
	
	/*remove*/
	e = vector_remove(c, 8);
	#ifdef _DEBUG
	check(e);
	#endif
	e = vector_remove(c, 5);
	#ifdef _DEBUG
	check(e);
	#endif
	e = vector_remove(c, 5);
	#ifdef _DEBUG
	check(e);
	#endif
	
	/*get element*/
	num = vector_get_element(c, 9, &e);
	#ifdef _DEBUG
	printf("\n%d ",num);
	check(e);
	#endif
	num =  vector_get_element(c, 5, &e);
	#ifdef _DEBUG
	printf("\n%d ",num);
	check(e);
	#endif

	/*set element*/
	e = vector_set_element(c, 10, 6);
	#ifdef _DEBUG
	check(e);
	#endif
	e = vector_set_element(c, 5, 6);
	#ifdef _DEBUG
	check(e);
	#endif
	numt ++;
	num++;

	/*destroy A vector*/
	e = vector_destroy(&b);
	#ifdef _DEBUG
	printf("%d",vector_get_element(b, 0, &e));
	#endif
	return 0;
}


