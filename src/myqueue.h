#ifndef MYQUEUE_H
#define MYQUEUE_H

#include <stdbool.h>
#include <limits.h>

#define QUEUE_EMPTY	INT_MIN

typedef struct myq queue;

queue* q_create(int max_size);
bool q_empty(queue* q);
bool q_full(queue* q);
void q_destroy(queue* q);
bool q_enqueue(queue* q, int val);
int q_dequeue(queue* q);
#endif
