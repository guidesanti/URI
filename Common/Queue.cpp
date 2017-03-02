#include "queue.h"
#include <stdlib.h>

struct QueueElement {
	QueueDataType	data;
	QueueElement*	next;
};

struct Queue {
	QueueElement*	first;
	QueueElement*	last;
	int				size;
};

Queue* Queue_Create() {
	Queue* queue = (Queue*)malloc(sizeof(Queue));

	if (!queue) {
		return NULL;
	}

	queue->first = NULL;
	queue->last = NULL;
	queue->size = 0;

	return queue;
}

int Queue_Destroy(Queue* queue) {
	if (!queue) {
		return QUEUE_NULL_ARG;
	}

	while (queue->first) {
		QueueElement* queueElement = queue->first;
		queue->first = queue->first->next;
		free(queueElement);
	}
	free(queue);

	return QUEUE_OK;
}

int Queue_Clear(Queue* queue) {
	if (!queue) {
		return QUEUE_NULL_ARG;
	}

	while (queue->first) {
		QueueElement* queueElement = queue->first;
		queue->first = queue->first->next;
		free(queueElement);
	}
	queue->first = NULL;
	queue->last = NULL;
	queue->size = 0;

	return QUEUE_OK;
}

int Queue_Enqueue(Queue* queue, QueueDataType data) {
	if (!queue) {
		return QUEUE_NULL_ARG;
	}

	QueueElement* queueElement = (QueueElement*)malloc(sizeof(QueueElement));
	if (!queueElement) {
		return QUEUE_OUT_OF_MEMORY;
	}

	queueElement->data = data;
	queueElement->next = NULL;

	if (queue->first == NULL) {
		queue->first = queueElement;
		queue->last = queueElement;
	} else {
		queue->last->next = queueElement;
		queue->last = queueElement;
	}
	queue->size++;

	return QUEUE_OK;
}

int Queue_Dequeue(Queue* queue, QueueDataType data) {
	if (!queue) {
		return QUEUE_NULL_ARG;
	}

	// TODO
}

int Queue_Size(Queue* queue, int* size) {
	if ((!queue) || (!size)) {
		return QUEUE_NULL_ARG;
	}

	*size = queue->size;

	return QUEUE_OK;
}