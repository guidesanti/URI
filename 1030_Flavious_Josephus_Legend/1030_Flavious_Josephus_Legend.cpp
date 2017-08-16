#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode ListNode;

struct ListNode
{
	int value;
	ListNode* prev;
	ListNode* next;
};

void Add(int value)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->value = value;
	if (last)
	{
		node->prev = last;
		node->next = first;
		first->prev = node;
		last->next = node;
	}
	else
	{
		node->prev = node;
		node->next = node;
		first = node;
		last = node;
	}
	count++;
}

void Remove(ListNode* node)
{
	if (count > 1)
	{
		node->prev->next = node->next;
		node->next->prev = node->prev;
	}
	count--;
	delete node;
}

ListNode* first = NULL;
ListNode* last = NULL;
int count = 0;

int main()
{
	int NC = 0;	// The number of test cases
	int i = 0;	// Loop control

	// Read the number of test cases
	scanf("%d", &NC);

	for (i = 1; i <= NC; i++)
	{
		int n = 0;
		int k = 0;

		// Read n and k
		scanf("%d %d", &n, &k);

		// Initialize
		first = NULL;
		last = NULL;
		for (i = 1; i <= n; i++)
		{
			Add(i);
		}

		// Find the last one
		ListNode* current = first;
		for (i = 1; i < n; i++)
		{
			current = current->next;
		}
		while (count)
		{
			ListNode* node = current;
			for (i = 0; i < n; i++)
			{
				current = current->next;
			}
		}

		// Write the output
		printf("Case %d: %d\n", i, ?);
	}

	return 0;
}