#include "LinkedList.h"

#include <stdlib.h>

static LinkedListNode* LinkedList_CreateNode(int data);

LinkedList* LinkedList_Create() {
	LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
	if (!list) {
		return NULL;
	}

	list->First = NULL;
	list->Size = 0;

	return list;
}

int LinkedList_Destroy(LinkedList* list) {
	if (!list) {
		return -1;
	}

	LinkedListNode* node = NULL;
	while (list->First) {
		node = list->First;
		list->First = node->Next;
		free(node);
	}

	free(list);

	return 0;
}

int LinkedList_InsertBeginning(LinkedList* list, int data) {
	if (!list) {
		return -1;
	}

	LinkedListNode* newNode = LinkedList_CreateNode(data);
	if (!newNode) {
		return -1;
	}

	newNode->Next = list->First;
	list->First = newNode;

	list->Size++;

	return 0;
}

int	LinkedList_InsertAt(LinkedList* list, int data, int index) {
	if (!list || (index < 0) || (index > list->Size)) {
		return -1;
	}

	LinkedListNode* newNode = LinkedList_CreateNode(data);
	if (!newNode) {
		return -1;
	}

	if (index == 0) {
		newNode->Next = list->First;
		list->First = newNode;
	} else {
		int aux = 0;
		LinkedListNode* node = list->First;
		for (aux = 0; aux < (index - 1); aux++) {
			node = node->Next;
		}
		newNode->Next = node->Next;
		node->Next = newNode;
	}

	list->Size++;

	return 0;
}

int LinkedList_RemoveBeginning(LinkedList* list) {
	if (!list) {
		return -1;
	}

	LinkedListNode* obsoleteNode = list->First;
	if (obsoleteNode) {
		list->First = obsoleteNode->Next;
		free(obsoleteNode);
		list->Size--;
	}

	return 0;
}

int LinkedList_RemoveAt(LinkedList* list, int index) {
	if (!list || (index < 0) || (index >= list->Size)) {
		return -1;
	}

	if (list->Size > 0) {
		LinkedListNode* node = list->First;
		if (index == 0) {
			list->First = node->Next;
			free(node);
		}
		else {
			int aux = 0;
			for (aux = 0; aux < (index - 1); aux++) {
				node = node->Next;
			}
			LinkedListNode* obsoleteNode = node->Next;
			node->Next = obsoleteNode->Next;
			free(obsoleteNode);
		}

		list->Size--;
	}

	return 0;
}

int LinkedList_Remove(LinkedList* list, int data) {
	if (!list) {
		return -1;
	}

	if (list->Size > 0) {
		LinkedListNode* node = list->First;
		if (node->Data == data) {
			list->First = node->Next;
			free(node);
			list->Size--;
		}
		else {
			while (node->Next) {
				if (node->Next->Data == data) {
					LinkedListNode* obsoleteNode = node->Next;
					node->Next = obsoleteNode->Next;
					free(obsoleteNode);
					list->Size--;
					break;
				}
				node = node->Next;
			}
		}
	}

	return 0;
}

int LinkedList_Contains(LinkedList* list, int data) {
	if (!list) {
		return -1;
	}

	LinkedListNode* node = list->First;
	while (node) {
		if (node->Data == data) {
			return 0;
		}
		node = node->Next;
	}

	return -1;
}

int LinkedList_Find(LinkedList* list, int data, LinkedListNode** outNode) {
	if (!list || !outNode) {
		return -1;
	}

	(*outNode) = NULL;

	LinkedListNode* node = list->First;
	while (node) {
		if (node->Data == data) {
			(*outNode) = node;
			return 0;
		}
		node = node->Next;
	}

	return -1;
}

static LinkedListNode* LinkedList_CreateNode(int data) {
	LinkedListNode* newNode = (LinkedListNode*)malloc(sizeof(LinkedListNode));
	if (newNode) {
		newNode->Data = data;
		newNode->Next = NULL;
	}

	return newNode;
}