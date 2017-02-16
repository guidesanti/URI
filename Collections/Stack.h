#pragma once

#ifndef __STACK_H__
#define __STACK_H__

#define STACK_OK			(0)
#define STACK_EMPTY			(1)
#define STACK_OUT_OF_MEMORY	(2)
#define STACK_NULL_ARG		(3)

typedef struct StackFrame StackFrame;
typedef struct Stack Stack;

Stack* Stack_Create();
int Stack_Destroy(Stack* stack);
int Stack_Clear(Stack* stack);
int Stack_Push(Stack* stack, int data);
int Stack_Pop(Stack* stack, int* data);
int Stack_Size(Stack* stack, int* size);
int Stack_ToString(Stack* stack, char** str);

#endif __STACK_H__