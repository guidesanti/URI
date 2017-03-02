#ifndef __QUEUE_H__
#define __QUEUE_H__

typedef int QueueDataType;

#define QUEUE_OK			(0)
#define QUEUE_EMPTY			(1)
#define QUEUE_OUT_OF_MEMORY	(2)
#define QUEUE_NULL_ARG		(3)

// Data
typedef struct QueueElement QueueElement;
typedef struct Queue Queue;

// Operations
Queue* Queue_Create();
int Queue_Destroy(Queue* queue);
int Queue_Clear(Queue* queue);
int Queue_Enqueue(Queue* queue, QueueDataType data);
int Queue_Dequeue(Queue* queue, QueueDataType data);
int Queue_Size(Queue* queue, int* size);

#endif __QUEUE_H__