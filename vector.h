#include <stdio.h>
#ifndef __VECTOR_H__
#define __VECTOR_H__

typedef enum{
	E_OK,
	E_NULL_PTR,
	E_UNDERFLOW,
	E_ALLOCATION_ERROR,
	E_BAD_INDEX
}ERRORCODE;

typedef struct v vector;

ERRORCODE vector_destroy(vector** vect);

vector* vector_create(size_t size);

ERRORCODE vector_pop(vector* vect);

ERRORCODE vector_push(int number, vector* vect);

ERRORCODE vector_insert(vector* vect, int number, size_t index);

ERRORCODE vector_remove(vector* vect, size_t index);

size_t vector_get_capacity(const vector* vect, ERRORCODE* error);

size_t vector_get_size(const vector* vect, ERRORCODE* error);

int vector_get_element(const vector* vect, int index, ERRORCODE *error);

ERRORCODE vector_set_element(vector* vect, int index, int number);

#ifdef _DEBUG
ERRORCODE vector_print(const vector* vect);
#endif
int vector_count(const vector* vect, int number);

#endif





