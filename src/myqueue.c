#include <stdio.h>
#include <stdlib.h>
#include "myqueue.h"

struct myq {
	int *values;
	int head;
	int tail;
	int num_entries;	// this helps to check for empty or full
	int size;
};

queue* q_create(int max_size)
{
	queue *q = malloc(sizeof(queue));
	q->size = max_size;
	q->values = malloc(sizeof(int) * q->size);
	q->num_entries = 0;
	q->head = q->tail = 0;
	return q;
}

bool q_empty(queue* q)
{
	return (q->num_entries == 0);
}

bool q_full(queue* q)
{
	return (q->num_entries == q->size);
}

void q_destroy(queue* q)
{
	free(q->values);
	free(q);
}

bool q_enqueue(queue* q, int val)
{
	if (q_full(q)) {
		return false;
	}

	q->values[q->tail] = val;
	q->num_entries++;
	q->tail = (q->tail + 1) % q->size;
	return true;
}

int q_dequeue(queue* q)
{
	if (q_empty(q)) {
		return QUEUE_EMPTY;
	}
	int result = q->values[q->head];
	q->head = (q->head + 1) % q->size;
	q->num_entries--;
	return result;
}

/*
int main()
{
	queue *q1 = q_create(5);

	q_enqueue(q1, 56);
	q_enqueue(q1, 78);
	q_enqueue(q1, 23);
	q_enqueue(q1, 988);
	q_enqueue(q1, 13);
	q_enqueue(q1, 2);

	int tmp;

	while ((tmp = q_dequeue(q1)) != QUEUE_EMPTY) {
		printf("t = %d\n", tmp);
	}

	q_destroy(q1);
	return 0;
}
*/
