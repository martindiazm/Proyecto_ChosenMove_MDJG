#ifndef STACK_H
#define STACK_H
#include "list.h"

typedef List Stack;

static Stack *stack_create(Stack *stack) { return list_create(); }

static void stack_push(Stack *stack, void *data) { list_pushFront(stack, data); }

static void *stack_top(Stack *stack) { return list_first(stack); }

static void *stack_pop(Stack *stack) { return list_popFront(stack); }

static void stack_clean(Stack *stack) { list_clean(stack); }

#endif /* STACK_H */