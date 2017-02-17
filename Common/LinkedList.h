#pragma once

#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#include <stdio.h>

typedef struct LinkedListNode {
	int				Data;
	LinkedListNode* Next;
} LinkedListNode;

typedef struct {
	LinkedListNode* First;
	int				Size;
} LinkedList;

LinkedList*	LinkedList_Create();
int	LinkedList_Destroy(LinkedList* list);
int	LinkedList_InsertBeginning(LinkedList* list, int data);
int	LinkedList_InsertAt(LinkedList* list, int data, int index);
int LinkedList_RemoveBeginning(LinkedList* list);
int LinkedList_RemoveAt(LinkedList* list, int index);
int LinkedList_Remove(LinkedList* list, int data);
int LinkedList_Contains(LinkedList* list, int data);
int LinkedList_Find(LinkedList* list, int data, LinkedListNode** node);

#endif __LINKED_LIST_H__