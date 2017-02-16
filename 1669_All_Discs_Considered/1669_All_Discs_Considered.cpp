#include <stdio.h>

typedef struct Node Node;
typedef struct ListNode ListNode;
typedef struct Control Control;

struct ListNode {
	Node*		node;
	ListNode*	next;
};

struct Node {
	int			disk;
	int			weight;
	ListNode*	nodes;
	Node*		prev;
	Node*		next;
};

struct Control {
	Node	nodes[100000];
	Node*	disk[2];
	int		d1;
	int		d2;
	int		changes;
};

// Input
int N1 = 0;
int N2 = 0;
int N = 0;
int D = 0;
int x = 0;
int y = 0;

// Control
ListNode listNodePool[100000];
int listNodePoolIndex = 0;
int i = 0;
int j = 0;
Control ctrl[2];

void AddNode(Control* ctrl, int x, int y) {
	int xDisk = 0;
	int yDisk = 0;

	(x < N1) ? (xDisk = 0) : (xDisk = 1);
	(y < N1) ? (yDisk = 0) : (yDisk = 1);

	ctrl->nodes[x].disk = xDisk;
	ctrl->nodes[y].disk = yDisk;
	ctrl->nodes[x].disk = xDisk;
	ctrl->nodes[y].disk = yDisk;
	
	// Package x
	if (ctrl->nodes[x].weight < 0) {
		ctrl->nodes[x].weight = 1;
		
		ctrl->nodes[x].prev = NULL;
		ctrl->nodes[x].next = ctrl->disk[xDisk];
		if (ctrl->nodes[x].next) {
			ctrl->nodes[x].next->prev = &(ctrl->nodes[x]);
		}
		ctrl->disk[xDisk] = &(ctrl->nodes[x]);
	} else {
		ctrl->nodes[x].weight++;
	}
	// Sort the packe x list
	Node* node = &(ctrl->nodes[x]);
	while (node->next) {
		Node* prev = node->prev;
		Node* next = node->next;
		if (node->weight > node->next->weight) {
			if (prev) {
				prev->next = next;
				next->prev = prev;
				node->next = next->next;
				if (node->next) {
					node->next->prev = node;
				}
			} else {
				node->next = next->next;
				if (node->next) {
					node->next->prev = node;
				}
				next->prev = NULL;
				next->next = node;
				ctrl->disk[xDisk] = next;
			}
		} else {
			break;
		}
	}

	// Package y
	if (ctrl->nodes[y].weight < 0) {
		ctrl->nodes[y].weight = 0;
		ctrl->nodes[y].prev = NULL;
		ctrl->nodes[y].next = ctrl->disk[yDisk];
		if (ctrl->nodes[y].next) {
			ctrl->nodes[y].next->prev = &(ctrl->nodes[y]);
		}
		ctrl->disk[yDisk] = &(ctrl->nodes[y]);
	}
	
	ListNode* listNode = &(listNodePool[listNodePoolIndex++]);
	listNode->node = &(ctrl->nodes[x]);
	listNode->next = ctrl->nodes[y].nodes;
	ctrl->nodes[y].nodes = listNode;
}

void RemoveNode(Control* ctrl, Node* node) {
	int res = 0;

	ListNode* listNode = node->nodes;
	while (listNode) {
		ListNode* nextListNode = listNode->next;
		listNode->node->weight--;
		listNode = nextListNode;
	}

	if (ctrl->disk[0] == node) {
		ctrl->disk[0] = node->next;
		if (ctrl->disk[0]) {
			ctrl->disk[0]->prev = NULL;
		}
	} else if (ctrl->disk[1] == node) {
		ctrl->disk[1] = node->next;
		if (ctrl->disk[1]) {
			ctrl->disk[1]->prev = NULL;
		}
	} else {
		Node* prev = node->prev;
		Node* next = node->next;
		node->prev = node->next;
		if (node->next) {
			node->next = node->prev;
		}
	}

	if (node->disk == 0) {
		ctrl->d1--;
	} else {
		ctrl->d2--;
	}

	node->weight = -1;
	node->nodes = NULL;
	node->prev = NULL;
	node->next = NULL;
}

int main() {
	for (i = 0; i < 100000; i++) {
		ctrl[0].nodes[i].weight = -1;
		ctrl[0].nodes[i].nodes = NULL;
		ctrl[0].nodes[i].prev = NULL;
		ctrl[0].nodes[i].next = NULL;
		ctrl[1].nodes[i].weight = -1;
		ctrl[1].nodes[i].nodes = NULL;
		ctrl[1].nodes[i].prev = NULL;
		ctrl[1].nodes[i].next = NULL;
	}

	while (1) {
		// Read N1, N2 and D
		scanf("%d %d %d", &N1, &N2, &D);
		N = (N1 + N2);
		ctrl[0].d1 = N1;
		ctrl[0].d2 = N2;
		ctrl[1].d1 = N1;
		ctrl[1].d2 = N2;

		// Check stop condition
		if (!(N1 | N2 | D)) {
			break;
		}

		// Reset list node pool index
		listNodePoolIndex = 0;

		// Read all dependency specs
		for (i = 0; i < D; i++) {
			scanf("%d %d", &x, &y);
			x--;
			y--;
			AddNode(&(ctrl[0]), x, y);
			AddNode(&(ctrl[1]), x, y);
		}

		for (i = 0; 2 < 1; i++) {
			int currentDisk = i;
			if (currentDisk == 0) {
				ctrl[i].d1 = 0;
			} else {
				ctrl[i].d2 = 0;
			}
			ctrl[i].changes = 2;
			while (ctrl[i].disk[0] || ctrl[i].disk[1]) {
				//Node* prevNode = ctrl[i].disk[currentDisk];
				Node* node = ctrl[i].disk[currentDisk];
				while (node) {
					int aux = 0;
					if (node->weight == 0) {
						Node* next = node->next;
						//RemoveNode(&ctrl[i], prevNode, node);
						RemoveNode(&ctrl[i], node);
						//node = prevNode->next;
						node = next;
						aux++;
					} else {
						//prevNode = node;
						node = node->next;
					}

					if (!node) {
						if (!aux) {
							break;
						}

						aux = 0;
						//prevNode = ctrl[i].disk[currentDisk];
						node = ctrl[i].disk[currentDisk];
					}
				}

				if (ctrl[i].disk[0] == NULL && ctrl[i].disk[1] == NULL) {
					break;
				}

				ctrl[i].changes++;
				currentDisk = ((currentDisk + 1) % 2);
			}

			if ((currentDisk == 0 && ctrl[i].d2 > 0) ||
				(currentDisk == 1 && ctrl[i].d1 > 0)) {
				ctrl[i].changes++;
			}
		}

		// Write the output
		if (ctrl[0].changes < ctrl[1].changes) {
			printf("%d\n", ctrl[0].changes);
		} else {
			printf("%d\n", ctrl[1].changes);
		}
	}

	return 0;
}