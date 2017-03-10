#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constraints
#define MAX_PRODUCT_NAME_LENGTH	(51)	// The maximum product name length considering the trailing 0 char

// Data structures
typedef struct Product* LinkedListDataType;
typedef struct LinkedListNode LinkedListNode;
typedef struct LinkedList LinkedList;

typedef int (*EqualsHandler)(LinkedListDataType obj1, LinkedListDataType obj2);

struct LinkedListNode {
	LinkedListDataType	Data;
	LinkedListNode*		Next;
};

struct LinkedList {
	LinkedListNode*	First;
	int				Count;
};

typedef struct Product Product;

struct Product {
	char	name[MAX_PRODUCT_NAME_LENGTH];
	float	price;
};

// Data
int N = 0;							// The number of trips to the market
int M = 0;							// The number of products in the market list
int P = 0;							// The number of products in the shopping list
LinkedList* marketList = NULL;		// The market product list
float		result = 0.0;			// The result
int i = 0;							// Loop control

// Functions
LinkedList* LinkedList_Create() {
	LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
	if (!list) {
		return NULL;
	}

	list->First = NULL;
	list->Count = 0;

	return list;
}

LinkedListNode* LinkedList_AddFirst(LinkedList* list, LinkedListDataType data) {
	if (!list) {
		return NULL;
	}

	LinkedListNode* newNode = (LinkedListNode*)malloc(sizeof(LinkedListNode));
	if (!newNode) {
		return NULL;
	}
	newNode->Data = data;
	newNode->Next = list->First;
	list->First = newNode;
	list->Count++;

	return newNode;
}

LinkedListNode* LinkedList_Find(LinkedList* list, LinkedListDataType data, EqualsHandler equals) {
	if (!list) {
		return NULL;
	}

	if (equals) {
		LinkedListNode* node = list->First;
		while (node) {
			if (equals(node->Data, data)) {
				return node;
			}
			node = node->Next;
		}
	}
	else
	{
		LinkedListNode* node = list->First;
		while (node) {
			if (node->Data == data) {
				return node;
			}
			node = node->Next;
		}
	}

	return NULL;
}

void LinkedList_Clear(LinkedList* list) {
	if (!list) {
		return;
	}

	LinkedListNode* node = list->First;
	LinkedListNode* obsoleteNode = list->First;
	while (node) {
		obsoleteNode = node;
		node = node->Next;
		free(obsoleteNode);
	}
	list->First = NULL;
	list->Count = 0;
}

int ProductEquals(Product* p1, Product* p2) {
	if (strcmp(p1->name, p2->name) == 0) {
		return 1;
	}

	return 0;
}

int LinkedList_RemoveFirst(LinkedList* list) {
	if (!list) {
		return 0;
	}

	if (!list->First) {
		return 0;
	}

	LinkedListNode* node = list->First;
	list->First = node->Next;
	free(node);
	list->Count--;

	return 1;
}

int main() {
	marketList = LinkedList_Create();

	// Read the number of trips to the market
	scanf("%d", &N);

	while (N--) {
		result = 0.0;

		// Read the number of products in the market list
		scanf("%d", &M);

		// Read the products of the market list
		for (i = 0; i < M; i++) {
			Product* product = (Product*)malloc(sizeof(Product));
			scanf("%s %f", &(product->name), &(product->price));
			LinkedList_AddFirst(marketList, product);
		}

		// Read the number of products in the shopping list
		scanf("%d", &P);

		// Read the products of the shopping list
		for (i = 0; i < P; i++) {
			Product product;
			int amount = 0;
			scanf("%s %d", &product.name, &amount);
			LinkedListNode* node = LinkedList_Find(marketList, &product, ProductEquals);
			if (node) {
				result += (amount * node->Data->price);
			}
		}

		// Clear the market list
		LinkedList_Clear(marketList);

		// Print the result
		printf("R$ %.2f\n", result);
	}

	return 0;
}