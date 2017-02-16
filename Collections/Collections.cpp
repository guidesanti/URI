#include <stdio.h>
#include "Stack.h"

int main()
{
	Stack* stack = Stack_Create();
	if (stack) {
		int size = 0;
		int value = 0;
		int result = 0;
		char* str = NULL;

		for (value = 0; value < 10; value++) {
			result = Stack_Push(stack, value);
			Stack_ToString(stack, &str);
		}

		result = Stack_Pop(stack, &value);
		Stack_ToString(stack, &str);

		result = Stack_Pop(stack, &value);
		Stack_ToString(stack, &str);

		result = Stack_Clear(stack);
		Stack_ToString(stack, &str);

		result = Stack_Destroy(stack);
	}

    return 0;
}