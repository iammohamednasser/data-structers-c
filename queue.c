#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// cyclic queue using
// array implementation

typedef struct {
    int* base;
    int rear;
    int front;
    int size;
} queue_t;

queue_t* create_queue(int size) {
    queue_t* qu;
    qu = (queue_t*)malloc(sizeof(qu));
    qu->base = (int*)malloc((size+1)*sizeof(int));
    qu->rear = 0;
    qu->front = 0;
    qu->size = size;
    return qu;
}

int is_empty(queue_t* qu) {
    return (qu->rear == qu->front);
}

int dequeue(queue_t* qu) {
    if (is_empty(qu)) exit(1);
    int temp;
    temp = qu->front;
    qu->front = (qu->front +1)%(qu->size+1);
    return qu->base[temp];
}

int is_full(queue_t* qu) {
    return ((qu->rear +1)%(qu->size+1) == qu->front);
}

void enqueue(queue_t* qu, int x) {
    if (is_full(qu) == 1) exit(1);
    qu->base[qu->rear] = x;
    qu->rear = (qu->rear +1)%(qu->size+1);
}

int length(queue_t* qu) {
    return abs(qu->rear - qu->front);
}

int main() {
    printf("data structures");
    return 0;
}