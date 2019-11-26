#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

struct v
{
	int* element;
	size_t size;
	size_t capacity;
};

vector* vector_create(size_t size)
{
	int* temp;
	vector *vect = (vector*)malloc(sizeof(vector));
	if(vect == NULL)
	{
		free(vect);
		return NULL;
	}
	
	temp = (int*)calloc(size,sizeof(int));
	
	if(temp == NULL)
		return NULL;
	
	vect ->element = temp;
	vect -> size = size;
	vect -> capacity = 0;
	return vect;
}

ERRORCODE vector_destroy(vector** vect)
{
	if(vect == NULL)
		return E_NULL_PTR;
	if(*vect == NULL)
		return E_NULL_PTR;
	free((*vect) -> element);
	free(*vect);
	*vect = NULL;
 	return E_OK;
}

ERRORCODE vector_push(int number,vector* vect)
{
	if(vect == NULL)
		return E_NULL_PTR;
	return vector_insert(vect, number, vect -> capacity+1);
}

ERRORCODE vector_pop(vector* vect)
{
	if(vect == NULL)
		return E_NULL_PTR;
	return vector_remove(vect, vect -> capacity);
}

ERRORCODE vector_insert(vector* vect, int number, size_t index)
{
	size_t i;
	int* temp;

	if(vect == NULL)
		return E_NULL_PTR;
	
	if (index > vect -> size)
		return E_BAD_INDEX;	
	
	if(index > (vect -> capacity) +1)
		return E_BAD_INDEX;
	
	if(vect -> capacity == vect -> size)
	{		
		temp = realloc(vect -> element, ((vect -> size) * 2 * (sizeof(int))));
		
		if (temp == NULL)
			return E_ALLOCATION_ERROR;
		
		vect -> element = temp;
		vect -> size *= 2;
	}
	
	for(i = vect -> capacity; i >= index; i--)
		vect -> element[i] = vect -> element[i-1];
	
	vect -> element[index-1] = number;
	vect -> capacity += 1;	
	return E_OK;
}

ERRORCODE vector_remove(vector* vect, size_t index)
{
	size_t i;
	
	if(vect == NULL)
		return E_NULL_PTR;
	
	if (index > vect -> size)
		return E_UNDERFLOW;	
	
	if (index > vect->capacity)
		return E_BAD_INDEX;
	
	for (i = index-1; i < vect->capacity-1; i++)
		vect->element[i] = vect->element[i + 1];
	
	vect->capacity -= 1;
	return E_OK;
}

size_t vector_get_size(const vector* vect, ERRORCODE* error)
{
	if(vect == NULL)
	{
		*error = E_NULL_PTR;
		return (size_t)(-1);
	}
	
	*error = E_OK;
	return vect -> size;
}

size_t vector_get_capacity(const vector* vect, ERRORCODE* error)
{
	if(vect == NULL)
	{
		*error = E_NULL_PTR;
		return 1;
	}
	
	return vect -> capacity;
}

int vector_get_element(const vector* vect, int index, ERRORCODE *error)
{	
	if(vect ==NULL)
	{
		*error = E_NULL_PTR;
		return -1;
	}
	if(index > vect -> capacity)
	{
		*error = E_BAD_INDEX;
		return -1;
	}
	
	if(index > vect -> size)
	{
		*error = E_BAD_INDEX;
		return -1;
	}

	return vect -> element[index-1];
}

ERRORCODE vector_set_element( vector* vect, int index, int number)
{
	if(vect == NULL)
		return E_NULL_PTR;
	
	if(index > vect -> capacity)
		return E_BAD_INDEX;
	
	if(index > vect -> size)
		return E_UNDERFLOW;
	
	vect -> element[index-1] = number;
	return E_OK;
}

#ifdef _DEBUG
ERRORCODE vector_print(const vector* vect)
{
	int i;
	if(vect == NULL)
		return E_NULL_PTR;

	for (i = 0; i < vect -> capacity; i++)
		printf("%d", vect->element[i]);
	
	printf("\n The capacity is:%ld\n", vect -> capacity);
	printf("The size is:%ld \n", vect -> size);
	return E_OK;
}
#endif

int vector_count(const vector* vect, int number)
{
	int i;
	int count = 0;

	for (i = 0; i < vect -> capacity; i++)
	{
		if (vect -> element[i] == number)
			count++;
	}
	return count;
}
