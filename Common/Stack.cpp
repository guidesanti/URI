#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>

struct StackFrame {
	int			data;
	StackFrame*	next;
};

struct Stack {
	StackFrame*	head;
	int			size;
};

Stack* Stack_Create() {
	Stack* stack = (Stack*)malloc(sizeof(Stack));

	stack->head = NULL;
	stack->size = 0;

	return stack;
}

int Stack_Destroy(Stack* stack) {
	if (!stack) {
		return STACK_NULL_ARG;
	}

	StackFrame* currentStackFrame = stack->head;
	StackFrame* nextStackFrame = NULL;
	while (currentStackFrame) {
		nextStackFrame = currentStackFrame->next;
		free(currentStackFrame);
		currentStackFrame = nextStackFrame;
	}

	free(stack);

	return STACK_OK;
}

int Stack_Clear(Stack* stack) {
	if (!stack) {
		return STACK_NULL_ARG;
	}

	StackFrame* currentStackFrame = stack->head;
	StackFrame* nextStackFrame = NULL;
	while (currentStackFrame) {
		nextStackFrame = currentStackFrame->next;
		currentStackFrame->next = NULL;
		free(currentStackFrame);
		currentStackFrame = nextStackFrame;
	}

	stack->head = NULL;
	stack->size = 0;

	return STACK_OK;
}

int Stack_Push(Stack* stack, StackDataType data) {
	if (!stack) {
		return STACK_NULL_ARG;
	}

	StackFrame* stackFrame = (StackFrame*)malloc(sizeof(StackFrame));
	if (!stackFrame) {
		return STACK_OUT_OF_MEMORY;
	}

	stackFrame->data = data;
	stackFrame->next = stack->head;
	stack->head = stackFrame;
	stack->size++;

	return STACK_OK;
}

int Stack_Pop(Stack* stack, StackDataType* data) {
	if ((!stack) || (!data)) {
		return STACK_NULL_ARG;
	}

	if (!stack->head) {
		*data = NULL;
		return STACK_EMPTY;
	}

	StackFrame* stackFrame = stack->head;
	*data = stackFrame->data;
	stack->head = stackFrame->next;
	stack->size--;
	free(stackFrame);

	return STACK_OK;
}

int Stack_Size(Stack* stack, int* size) {
	if ((!stack) || (!size)) {
		return STACK_NULL_ARG;
	}

	*size = stack->size;

	return STACK_OK;
}

int Stack_ToString(Stack* stack, char** str) {
	if (!str) {
		return STACK_NULL_ARG;
	}

	*str = (char*)malloc(1024 * sizeof(char));

	if (!stack) {
		sprintf(*str, "null");
		return STACK_OK;
	}

	StackFrame* stackFrame = stack->head;
	int index = sprintf(*str, "{ ");
	while (stackFrame) {
		if (stackFrame->next) {
			index += sprintf(*str + index, "%d -> ", stackFrame->data);
		} else {
			index += sprintf(*str + index, "%d", stackFrame->data);
		}
		stackFrame = stackFrame->next;
	}
	sprintf(*str + index, " }");

	return STACK_OK;
}