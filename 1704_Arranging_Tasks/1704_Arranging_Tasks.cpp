#include <stdio.h>
#include <stdlib.h>

#define MAX_HOURS	(1000)

typedef struct Task Task;

struct Task {
	int		v;
	int		t;
	Task*	next;
};

Task* tasks;
int N = 0;
int H = 0;
int V[MAX_HOURS];
int result = 0;
int i = 0;

Task* CreateTask(int v, int t) {
	Task* newTask = (Task*)malloc(sizeof(Task));
	newTask->v = v;
	newTask->t = t;
	newTask->next = NULL;
	return newTask;
}

void AddTask(Task* task) {
	if (!tasks) {
		tasks = task;
	} else if (tasks->v < task->v) {
		task->next = tasks;
		tasks = task;
	} else {
		Task* currTask = tasks;
		while (currTask->next) {
			if (currTask->next->v < task->v) {
				task->next = currTask->next;
				currTask->next = task;
				break;
			}
			currTask = currTask->next;
		}
		if (!currTask->next) {
			currTask->next = task;
		}
	}
}

void RemoveTask() {
	if (tasks) {
		Task* task = tasks;
		tasks = tasks->next;
		free(task);
	}
}

int main() {
	while (scanf("%d %d", &N, &H) != EOF) {
		// Read each task information and allocate it on the best position
		for (i = 0; i < N; i++) {
			int v = 0;
			int t = 0;
			scanf("%d %d", &v, &t);
			t--;
			AddTask(CreateTask(v, t));
		}

		// Reset data and controls
		result = 0;
		for (i = 0; i < H; i++) {
			V[i] = 0;
		}

		// Calculate the result
		while (tasks) {
			for (i = tasks->t; i >= 0; i--) {
				if (!V[i]) {
					V[i] = 1;
					break;
				}
			}
			if (i < 0) {
				result += tasks->v;
			}
			RemoveTask();
		}

		// Write the result
		printf("%d\n", result);
	}

	return 0;
}