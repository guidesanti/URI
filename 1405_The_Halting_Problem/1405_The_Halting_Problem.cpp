#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VALUE				(999)
#define NUMBER_OF_OPERATIONS	(15)
#define NUMBER_OF_REGISTERS		(10)

#define OP_1			(1)
#define OP_2			(2)

#define OP_CODE_MOV		(0)
#define OP_CODE_ADD		(1)
#define OP_CODE_SUB		(2)
#define OP_CODE_MUL		(3)
#define OP_CODE_DIV		(4)
#define OP_CODE_MOD		(5)
#define OP_CODE_IFEQ	(6)
#define OP_CODE_IFNEQ	(7)
#define OP_CODE_IFG		(8)
#define OP_CODE_IFL		(9)
#define OP_CODE_IFGE	(10)
#define OP_CODE_IFLE	(11)
#define OP_CODE_ENDIF	(12)
#define OP_CODE_CALL	(13)
#define OP_CODE_RET		(14)

typedef struct Context Context;
typedef struct Operation Operation;
typedef struct Register Register;

struct Context {
	int R0;
	int R1;
	int R2;
	int R3;
	int R4;
	int R5;
	int R6;
	int R7;
	int R8;
	int R9;
	int PC;
	Context* next;
};

struct Operation  {
	int		opCode;
	int*	op1Addr;
	int		op1Value;
	int*	op2Addr;
	int		op2Value;
};

char strBuffer[100];
int R0 = 0;
int R1 = 0;
int R2 = 0;
int R3 = 0;
int R4 = 0;
int R5 = 0;
int R6 = 0;
int R7 = 0;
int R8 = 0;
int R9 = 0;
int PC = 0;
int L = 0;
int N = 0;
Operation program[100];
Context* stackPointer = NULL;

struct Register {
	char*	regName;
	int*	regAddr;
};

Register registerTable[NUMBER_OF_REGISTERS] = {
	{ "R0", &R0 },
	{ "R1", &R1 },
	{ "R2", &R2 },
	{ "R3", &R3 },
	{ "R4", &R4 },
	{ "R5", &R5 },
	{ "R6", &R6 },
	{ "R7", &R7 },
	{ "R8", &R8 },
	{ "R9", &R9 },
};

char* opCodeTable[NUMBER_OF_OPERATIONS] = {
	/* 0 */		"MOV",
	/* 1 */		"ADD",
	/* 2 */		"SUB",
	/* 3 */		"MUL",
	/* 4 */		"DIV",
	/* 5 */		"MOD",
	/* 6 */		"IFEQ",
	/* 7 */		"IFNEQ",
	/* 8 */		"IFG",
	/* 9 */		"IFL",
	/* 10 */	"IFGE",
	/* 11 */	"IFLE",
	/* 12 */	"ENDIF",
	/* 13 */	"CALL",
	/* 14 */	"RET",
};

int getOpCode(char* opCodeStr) {
	int opCode = 0;
	for (opCode = 0; opCode < NUMBER_OF_OPERATIONS; opCode++) {
		if (strcmp(opCodeStr, opCodeTable[opCode]) == 0) {
			break;
		}
	}
	return opCode;
}

void getOpRegAddr(char* regName, Operation* operation, int op) {
	if (regName[0] == 'R') {
		int reg = 0;
		for (reg = 0; reg < NUMBER_OF_REGISTERS; reg++) {
			if (strcmp(regName, registerTable[reg].regName) == 0) {
				if (op == OP_1) {
					operation->op1Addr = registerTable[reg].regAddr;
				} else {
					operation->op2Addr = registerTable[reg].regAddr;
				}
				return;
			}
		}
	}
	if (op == OP_1) {
		operation->op1Addr = &(operation->op1Value);
		operation->op1Value = atoi(regName);
	}
	else {
		operation->op2Addr = &(operation->op2Value);
		operation->op2Value = atoi(regName);
	}
}

void saveContext() {
	Context* context = (Context*)malloc(sizeof(Context));
	context->R0 = R0;
	context->R1 = R1;
	context->R2 = R2;
	context->R3 = R3;
	context->R4 = R4;
	context->R5 = R5;
	context->R6 = R6;
	context->R7 = R7;
	context->R8 = R8;
	//context->R9 = R9;
	context->PC = PC;
	context->next = stackPointer;
	stackPointer = context;
}

void restoreContext() {
	Context* context = stackPointer;
	stackPointer = context->next;
	R0 = context->R0;
	R1 = context->R1;
	R2 = context->R2;
	R3 = context->R3;
	R4 = context->R4;
	R5 = context->R5;
	R6 = context->R6;
	R7 = context->R7;
	R8 = context->R8;
	//R9 = context->R9;
	PC = context->PC;
	free(context);
}

void clearStack() {
	while (stackPointer) {
		Context* context = stackPointer;
		stackPointer = context->next;
		free(context);
	}
}

int main() {
	while (1) {
		int inifinityLoop = 0;

		// Read L and N
		scanf("%d %d", &L, &N);

		// Check stop condition
		if (!(L | N)) {
			break;
		}

		// Read the operations
		for (PC = 0; PC < L; PC++)
		{
			int index = 0;
			char ch = 0;

			// Read the operation code
			while (1) {
				ch = getc(stdin);
				if ((ch >= 'A') && (ch <= 'Z')) {
					break;
				}
			}
			strBuffer[index++] = ch;
			while (1) {
				ch = getc(stdin);
				if ((ch == ' ') || (ch == '\n') || (ch == '\r')) {
					break;
				}
				strBuffer[index++] = ch;
			}
			strBuffer[index] = '\0';
			program[PC].opCode = getOpCode(strBuffer);
			
			// Read the operators
			if (program[PC].opCode <= OP_CODE_IFLE) {
				// Operator 1
				index = 0;
				while (1) {
					ch = getc(stdin);
					if (((ch >= 'A') && (ch <= 'Z')) || ((ch >= '0') && (ch <= '9'))) {
						break;
					}
				}
				strBuffer[index++] = ch;
				while (1) {
					ch = getc(stdin);
					if ((ch == ',') || (ch == '\n') || (ch == '\r')) {
						break;
					}
					strBuffer[index++] = ch;
				}
				strBuffer[index] = '\0';
				getOpRegAddr(strBuffer, &program[PC], OP_1);

				// Operator 2
				index = 0;
				while (1) {
					ch = getc(stdin);
					if (((ch >= 'A') && (ch <= 'Z')) || ((ch >= '0') && (ch <= '9'))) {
						break;
					}
				}
				strBuffer[index++] = ch;
				while (1) {
					ch = getc(stdin);
					if ((ch == ',') || (ch == '\n') || (ch == '\r')) {
						break;
					}
					strBuffer[index++] = ch;
				}
				strBuffer[index] = '\0';
				getOpRegAddr(strBuffer, &program[PC], OP_2);
			} else if ((program[PC].opCode == OP_CODE_CALL) || (program[PC].opCode == OP_CODE_RET)) {
				// Operator 1
				index = 0;
				while (1) {
					ch = getc(stdin);
					if (((ch >= 'A') && (ch <= 'Z')) || ((ch >= '0') && (ch <= '9'))) {
						break;
					}
				}
				strBuffer[index++] = ch;
				while (1) {
					ch = getc(stdin);
					if ((ch == ',') || (ch == '\n') || (ch == '\r')) {
						break;
					}
					strBuffer[index++] = ch;
				}
				strBuffer[index] = '\0';
				getOpRegAddr(strBuffer, &program[PC], OP_1);
			}
		}

		// Run the program
		R0 = N;
		R1 = 0;
		R2 = 0;
		R3 = 0;
		R4 = 0;
		R5 = 0;
		R6 = 0;
		R7 = 0;
		R8 = 0;
		R9 = 0;
		PC = 0;
		while (PC < L) {
			int* op1Addr = program[PC].op1Addr;
			int* op2Addr = program[PC].op2Addr;

			switch (program[PC].opCode)
			{
			case OP_CODE_MOV:
				*op1Addr = *op2Addr;
				break;

			case OP_CODE_ADD:
				*op1Addr += *op2Addr;
				*op1Addr %= MAX_VALUE;
				break;

			case OP_CODE_SUB:
				*op1Addr -= *op2Addr;
				if (*op1Addr < 0) {
					*op1Addr = (MAX_VALUE + 1 - *op1Addr);
				}
				break;

			case OP_CODE_MUL:
				*op1Addr *= *op2Addr;
				*op1Addr %= MAX_VALUE;
				break;

			case OP_CODE_DIV:
				if (*op2Addr > 0) {
					*op1Addr /= *op2Addr;
				} else {
					inifinityLoop = 1;
					PC = L;
				}
				break;

			case OP_CODE_MOD:
				*op1Addr %= *op2Addr;
				break;

			case OP_CODE_IFEQ:
				if (*op1Addr != *op2Addr) {
					PC++;
					while ((PC < L) && (program[PC].opCode != OP_CODE_ENDIF)) {
						PC++;
					}
				}
				break;

			case OP_CODE_IFNEQ:
				if (*op1Addr == *op2Addr) {
					PC++;
					while ((PC < L) && (program[PC].opCode != OP_CODE_ENDIF)) {
						PC++;
					}
				}
				break;

			case OP_CODE_IFG:
				if (*op1Addr <= *op2Addr) {
					PC++;
					while ((PC < L) && (program[PC].opCode != OP_CODE_ENDIF)) {
						PC++;
					}
				}
				break;

			case OP_CODE_IFL:
				if (*op1Addr >= *op2Addr) {
					PC++;
					while ((PC < L) && (program[PC].opCode != OP_CODE_ENDIF)) {
						PC++;
					}
				}
				break;

			case OP_CODE_IFGE:
				if (*op1Addr < *op2Addr) {
					PC++;
					while ((PC < L) && (program[PC].opCode != OP_CODE_ENDIF)) {
						PC++;
					}
				}
				break;

			case OP_CODE_IFLE:
				if (*op1Addr > *op2Addr) {
					PC++;
					while ((PC < L) && (program[PC].opCode != OP_CODE_ENDIF)) {
						PC++;
					}
				}
				break;

			case OP_CODE_ENDIF:
				// Do nothing
				break;

			case OP_CODE_CALL:
				if (stackPointer &&
					stackPointer->R0 == *op1Addr &&
					stackPointer->PC == PC) {
					clearStack();
					inifinityLoop = 1;
					PC = L;
				} else {
					saveContext();
					R0 = *op1Addr;
					PC = -1;
				}
				break;

			case OP_CODE_RET:
				R9 = *op1Addr;
				if (stackPointer) {
					restoreContext();
				} else {
					PC = L;
				}
				break;

			default:
				break;
			}

			PC++;
		}

		// Write the result
		if (inifinityLoop) {
			printf("*\n");
		} else {
			printf("%d\n", R9);
		}
	}

	return 0;
}