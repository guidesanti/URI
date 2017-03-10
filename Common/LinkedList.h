#pragma once

#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

typedef struct LinkedListNode LinkedListNode;
typedef struct LinkedList LinkedList;

typedef int (*EqualsHandler)(void* obj1, void* obj2);

struct LinkedListNode {
	void*				Data;
	LinkedListNode*		Next;
};

struct LinkedList {
	LinkedListNode*	First;
	int				Count;
};

LinkedList*		LinkedList_Create();
void			LinkedList_Destroy(LinkedList* list);
LinkedListNode*	LinkedList_AddFirst(LinkedList* list, void* data);
LinkedListNode*	LinkedList_AddLast(LinkedList* list, void* data);
LinkedListNode* LinkedList_AddBefore(LinkedList* list, LinkedListNode* node, void* data);
LinkedListNode* LinkedList_AddAfter(LinkedList* list, LinkedListNode* node, void* data);
void*			LinkedList_Remove(LinkedList* list, void* data);
void*			LinkedList_RemoveNode(LinkedList* list, LinkedListNode* node);
void*			LinkedList_RemoveFirst(LinkedList* list);
void*			LinkedList_RemoveLast(LinkedList* list);
long			LinkedList_Count(LinkedList* list);
void			LinkedList_Clear(LinkedList* list);
int				LinkedList_Contains(LinkedList* list, void* data);
LinkedListNode* LinkedList_Find(LinkedList* list, void* data, EqualsHandler equals);

#endif __LINKED_LIST_H__