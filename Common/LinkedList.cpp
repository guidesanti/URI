#include "LinkedList.h"

#include <stdlib.h>

LinkedList* LinkedList_Create() {
	LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
	if (!list) {
		return NULL;
	}

	list->First = NULL;
	list->Count = 0;

	return list;
}

void LinkedList_Destroy(LinkedList* list) {
	if (!list) {
		return;
	}

	LinkedListNode* node = NULL;
	while (list->First) {
		node = list->First;
		list->First = node->Next;
		free(node);
	}

	free(list);
}

LinkedListNode* LinkedList_AddFirst(LinkedList* list, void* data) {
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

LinkedListNode* LinkedList_AddLast(LinkedList* list, void* data) {
	if (!list) {
		return NULL;
	}

	LinkedListNode* newNode = (LinkedListNode*)malloc(sizeof(LinkedListNode));
	if (!newNode) {
		return NULL;
	}
	newNode->Data = data;
	newNode->Next = NULL;

	if (!list->First) {
		list->First = newNode;
	} else {
		LinkedListNode* node = list->First;
		while (node->Next) {
			node = node->Next;
		}
		node->Next = newNode;
	}
	list->Count++;

	return newNode;
}

LinkedListNode* LinkedList_AddBefore(LinkedList* list, LinkedListNode* node, void* data) {
	if ((!list) || (!node)) {
		return NULL;
	}
	
	if (!list->First) {
		return NULL;
	}

	LinkedListNode* newNode = (LinkedListNode*)malloc(sizeof(LinkedListNode));
	if (!newNode) {
		return NULL;
	}
	newNode->Data = data;
	newNode->Next = node;

	if (list->First == node) {
		list->First = newNode;
	} else {
		LinkedListNode* prevNode = list->First;
		while (prevNode->Next && (prevNode->Next != node)) {
			prevNode = prevNode->Next;
		}
		if (!prevNode->Next) {
			free(newNode);
			return NULL;
		}
		prevNode->Next = newNode;
	}

	list->Count++;

	return newNode;
}

LinkedListNode* LinkedList_AddAfter(LinkedList* list, LinkedListNode* node, void* data) {
	if ((!list) || (!node)) {
		return NULL;
	}

	if (!list->First) {
		return NULL;
	}

	LinkedListNode* newNode = (LinkedListNode*)malloc(sizeof(LinkedListNode));
	if (!newNode) {
		return NULL;
	}
	newNode->Data = data;
	newNode->Next = node->Next;

	LinkedListNode* prevNode = list->First;
	while (prevNode && (prevNode != node)) {
		prevNode = prevNode->Next;
	}
	if (!prevNode) {
		free(newNode);
		return NULL;
	}
	node->Next = newNode;

	list->Count++;

	return newNode;
}

void* LinkedList_Remove(LinkedList* list, void* data) {
	if (!list) {
		return NULL;
	}

	if (!list->First) {
		return NULL;
	}

	LinkedListNode* obsoleteNode = NULL;
	if (list->First->Data == data) {
		obsoleteNode = list->First;
		list->First = list->First->Next;
	} else {
		LinkedListNode* prevNode = list->First;
		while (prevNode->Next && (prevNode->Next->Data != data)) {
			prevNode = prevNode->Next;
		}
		if (!prevNode->Next) {
			return NULL;
		}
		obsoleteNode = prevNode->Next;
		prevNode->Next = obsoleteNode->Next;
	}
	void* res = obsoleteNode->Data;
	free(obsoleteNode);
	list->Count--;

	return res;
}

void* LinkedList_RemoveNode(LinkedList* list, LinkedListNode* node) {
	if ((!list) || (!node)) {
		return NULL;
	}

	if (!list->First) {
		return NULL;
	}

	if (list->First == node) {
		list->First = node->Next;
	}
	else {
		LinkedListNode* prevNode = list->First;
		while (prevNode->Next && (prevNode->Next != node)) {
			prevNode = prevNode->Next;
		}
		if (!prevNode->Next) {
			return NULL;
		}
		prevNode->Next = node->Next;
	}
	void* res = node->Data;
	free(node);
	list->Count--;

	return res;
}

void* LinkedList_RemoveFirst(LinkedList* list) {
	if (!list) {
		return NULL;
	}

	if (!list->First) {
		return NULL;
	}

	LinkedListNode* node = list->First;
	list->First = node->Next;
	void* res = node->Data;
	free(node);
	list->Count--;

	return res;
}

void* LinkedList_RemoveLast(LinkedList* list) {
	if (!list) {
		return NULL;
	}

	if (!list->First) {
		return NULL;
	}

	LinkedListNode* obsoleteNode = NULL;
	if (!list->First->Next) {
		obsoleteNode = list->First;
		list->First = NULL;
	} else {
		LinkedListNode* prevNode = list->First;
		while (prevNode->Next->Next != NULL) {
			prevNode = prevNode->Next;
		}
		obsoleteNode = prevNode->Next;
		prevNode->Next = NULL;
	}
	void* res = obsoleteNode->Data;
	free(obsoleteNode);
	list->Count--;

	return res;
}

long LinkedList_Count(LinkedList* list) {
	if (!list) {
		return -1;
	}

	return list->Count;
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

int LinkedList_Contains(LinkedList* list, void* data) {
	if (!list) {
		return 0;
	}

	LinkedListNode* node = list->First;
	while (node) {
		if (node->Data == data) {
			return 1;
		}
		node = node->Next;
	}

	return 0;
}

LinkedListNode* LinkedList_Find(LinkedList* list, void* data, EqualsHandler equals) {
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
	} else
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