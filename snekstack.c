#include "snekstack.h"
#include <assert.h>
#include <stddef.h>
#include <stdlib.h>

void *stack_pop(stack_t *stack) {
  if (stack->count == 0){
    return NULL;
  }
  stack->count--; //count is really the amount of count, so its +1 of the idx
  void *obj = stack->data[stack->count];
  stack->data[stack->count] = NULL; // set to NULL then the gc will know its not needed in the future
  return obj;
}


void stack_push(stack_t *stack, void *obj) {
  if (stack->count == stack->capacity) {
    stack->capacity *= 2;
    void **temp = realloc(stack->data, stack->capacity * sizeof(void *));
    if (temp == NULL) {
      free(stack->data);
      exit(1);
    }
    stack->data = temp;
  }
  stack->data[stack->count] = obj;
  stack->count++;
  return;
}

stack_t *stack_new(size_t capacity) {
  stack_t *stack = malloc(sizeof(stack_t));
  if (stack == NULL) {
    return NULL;
  }

  stack->count = 0;
  stack->capacity = capacity;
  stack->data = malloc(stack->capacity * sizeof(void *));
  if (stack->data == NULL) {
    free(stack);
    return NULL;
  }

  return stack;
}


//problematic implementation's resulting in multiple types into the stack

void scary_double_push(stack_t *s) {
  //push int 
  stack_push(s, (void*)1337);
  //push int pointer
  int *intptr = (int*)malloc(sizeof(int));
  *intptr = 1024;
  stack_push(s, intptr);
  return;
}

void stack_push_multiple_types(stack_t *s) {
  float *fo = (float*)malloc(sizeof(float));
  *fo = 3.14;
  stack_push(s, fo);

  
  char *co = (char *)malloc(strlen("Sneklang is blazingly slow!") + 1);
  strcpy(co, "Sneklang is blazingly slow!");
  stack_push(s, co);

  return;
}

