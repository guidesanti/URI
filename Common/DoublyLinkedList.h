#ifndef __DOUBLY_LINKED_LIST_H__
#define __DOUBLY_LINKED_LIST_H__

#include <stdio.h>
#include <stdlib.h>

// Constants
#define DOUBLY_LINKED_LIST_OK					(0)
#define DOUBLY_LINKED_LIST_OUT_OF_MEMORY		(1)
#define DOUBLY_LINKED_LIST_NULL_ARG				(2)

#define DOUBLY_LINKED_LIST_FALSE				(0)
#define DOUBLY_LINKED_LIST_TRUE					(1)

// Type definitions
typedef int DoublyLinkedListDataType;
typedef struct DoublyLinkedListNode DoublyLinkedListNode;
typedef struct DoublyLinkedList DoublyLinkedList;

struct DoublyLinkedListNode {
	DoublyLinkedListDataType	data;
	DoublyLinkedListNode*		prev;
	DoublyLinkedListNode*		next;
};

struct DoublyLinkedList {
	DoublyLinkedListNode*	first;
	DoublyLinkedListNode*	last;
	int						count;
};

/* ----------------------------------------------------------------------------------------- */
/* Cronstruction / destruction                                                               */
/* ----------------------------------------------------------------------------------------- */

/**
 * Creates a new doubly linked list.
 *
 * Returns:
 *	NULL if memory could not be allocated for the list.
 *	A pointer to the new created list if success.
 */
DoublyLinkedList* DoublyLinkedList_Create() {
	DoublyLinkedList* list = (DoublyLinkedList*)malloc(sizeof(DoublyLinkedList));
	if (!list) {
		return NULL;
	}

	list->first = NULL;
	list->last = NULL;
	list->count = 0;

	return list;
}

/**
 * Destroy a doubly linked list previously created by DoublyLinkedList_Create().
 * 
 * If the list pointer is NULL nothing is done.
 */
void DoublyLinkedList_Destroy(DoublyLinkedList* list) {
	if (list) {
		DoublyLinkedListNode* node = list->first;
		while (node) {
			DoublyLinkedListNode* obsoleteNode = node;
			node = node->next;
			free(obsoleteNode);
		}
		list->first = NULL;
		list->last = NULL;
		list->count = 0;
		free(list);
	}
}

/* ----------------------------------------------------------------------------------------- */
/* Observation                                                                               */
/* ----------------------------------------------------------------------------------------- */

/**
 * Gets the first node of the list.
 *
 * Returns:
 *	If the list is not empty returns a pointer to the first node of the list.
 *	Otherwise returns NULL;
 */
DoublyLinkedListNode* DoublyLinkedList_First(DoublyLinkedList* list) {
	if (!list) {
		return NULL;
	}

	return list->first;
}

/**
 * Gets the last node of the list.
 */
DoublyLinkedListNode* DoublyLinkedList_Last(DoublyLinkedList* list) {
	if (!list) {
		return NULL;
	}

	return list->last;
}

/**
 * Gets the number of nodes in the list.
 */
int DoublyLinkedList_Count(DoublyLinkedList* list) {
	if (!list) {
		return 0;
	}

	return list->count;
}

/**
 * Determines whether a value is in the list.
 */
int DoublyLinkedList_Cotains(DoublyLinkedList* list, DoublyLinkedListDataType data) {
	if (!list) {
		return DOUBLY_LINKED_LIST_FALSE;
	}

	DoublyLinkedListNode* node = list->first;
	while (node) {
		if (node->data == data) {
			return DOUBLY_LINKED_LIST_TRUE;
		}
		node = node->next;
	}

	return DOUBLY_LINKED_LIST_FALSE;
}

/**
 * Finds the first node that contains the specified value.
 */
DoublyLinkedListNode* DoublyLinkedList_Find(DoublyLinkedList* list, DoublyLinkedListDataType data) {
	if (!list) {
		return NULL;
	}

	DoublyLinkedListNode* node = list->first;
	while (node) {
		if (node->data == data) {
			return node;
		}
		node = node->next;
	}

	return NULL;
}

/**
 * Gets the node at the specified index.
 */
DoublyLinkedListNode* DoublyLinkedList_NodeAt(DoublyLinkedList* list, int index) {
	if ((!list) || (index < 0) || (index >= list->count)) {
		return NULL;
	}

	int i = 0;
	DoublyLinkedListNode* node = list->first;
	while (node) {
		if (i == index) {
			return node;
		}
		i++;
		node = node->next;
	}

	return NULL;
}

/* ----------------------------------------------------------------------------------------- */
/* Mutation                                                                                  */
/* ----------------------------------------------------------------------------------------- */

/**
 * Adds a new node containing the specified value before the specified existing node in the list.
 */
//int DoublyLinkedList_AddBefore(DoublyLinkedList* list, DoublyLinkedListNode* node, DoublyLinkedListDataType data);

/**
 * Adds a new node containing the specified value after the specified existing node in the list.
 */
//int DoublyLinkedList_AddAfter(DoublyLinkedList* list, DoublyLinkedListNode* node, DoublyLinkedListDataType data);

/**
 * Adds a new node containing the specified data at the start of the list.
 */
int DoublyLinkedList_AddFirst(DoublyLinkedList* list, DoublyLinkedListDataType data) {
	if (!list) {
		return DOUBLY_LINKED_LIST_NULL_ARG;
	}

	DoublyLinkedListNode* node = (DoublyLinkedListNode*)malloc(sizeof(DoublyLinkedListNode));
	if (!node) {
		return DOUBLY_LINKED_LIST_OUT_OF_MEMORY;
	}

	node->data = data;
	node->prev = NULL;
	node->next = list->first;
	list->first = node;
	if (!list->last) {
		list->last = node;
	}
	list->count++;

	return DOUBLY_LINKED_LIST_OK;
}

/**
 * Adds a new node containing the specified data at the end of the list.
 */
int DoublyLinkedList_AddLast(DoublyLinkedList* list, DoublyLinkedListDataType data) {
	if (!list) {
		return DOUBLY_LINKED_LIST_NULL_ARG;
	}

	DoublyLinkedListNode* node = (DoublyLinkedListNode*)malloc(sizeof(DoublyLinkedListNode));
	if (!node) {
		return DOUBLY_LINKED_LIST_OUT_OF_MEMORY;
	}

	node->data = data;
	node->prev = list->last;
	node->next = NULL;
	if (!list->first) {
		list->first = node;
	}
	list->last = node;
	list->count++;

	return DOUBLY_LINKED_LIST_OK;
}

//int DoublyLinkedList_AddAt(DoublyLinkedList* list, int index, DoublyLinkedListDataType data);

/**
 * Removes the first occurrence of the specified value from the list.
 */
int DoublyLinkedList_Remove(DoublyLinkedList* list, DoublyLinkedListDataType data) {
	if (!list) {
		return DOUBLY_LINKED_LIST_NULL_ARG;
	}

	DoublyLinkedListNode* node = list->first;
	while (node) {
		if (node->data == data) {
			if (list->count == 1) {
				list->first = NULL;
				list->last = NULL;
			} else {
				if (list->first == node) {
					list->first = list->first->next;
					list->first->prev = NULL;
				} else if (list->last == node) {
					list->last = list->last->prev;
					list->last->next = NULL;
				} else {
					node->prev->next = node->next;
					node->next->prev = node->prev;
				}
			}
			list->count--;
			free(node);
			return DOUBLY_LINKED_LIST_TRUE;
		}
	}

	return DOUBLY_LINKED_LIST_FALSE;
}

/**
 * Removes the node at the start of the list.
 */
int DoublyLinkedList_RemoveFirst(DoublyLinkedList* list) {
	if (!list) {
		return DOUBLY_LINKED_LIST_NULL_ARG;
	}

	if (list->count == 0) {
		return DOUBLY_LINKED_LIST_FALSE;
	}

	DoublyLinkedListNode* node = list->first;
	if (list->count == 1) {
		list->first = NULL;
		list->last = NULL;
	} else {
		list->first = list->first->next;
		list->first->prev = NULL;
	}
	list->count--;
	free(node);

	return DOUBLY_LINKED_LIST_TRUE;
}

/**
* Removes the node at the end of the list.
*/
int DoublyLinkedList_RemoveLast(DoublyLinkedList* list) {
	if (!list) {
		return DOUBLY_LINKED_LIST_NULL_ARG;
	}

	if (list->count == 0) {
		return DOUBLY_LINKED_LIST_FALSE;
	}

	DoublyLinkedListNode* node = list->last;
	if (list->count == 1) {
		list->first = NULL;
		list->last = NULL;
	} else {
		list->last = list->last->prev;
		list->last->next = NULL;
	}
	list->count--;
	free(node);

	return DOUBLY_LINKED_LIST_TRUE;
}

//int DoublyLinkedList_RemoveAt(DoublyLinkedList* list, int index);

/**
 * Removes all nodes from the list.
 */
void DoublyLinkedList_Clear(DoublyLinkedList* list) {
	if (list) {
		DoublyLinkedListNode* node = list->first;
		while (node) {
			DoublyLinkedListNode* obsoleteNode = node;
			node = node->next;
			free(obsoleteNode);
		}
		list->first = NULL;
		list->last = NULL;
		list->count = 0;
	}
}

#endif __DOUBLY_LINKED_LIST_H__