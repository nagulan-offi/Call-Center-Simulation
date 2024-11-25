#include <stdio.h>
#include <stdlib.h>

typedef struct Call {
    int call_id;
    struct Call* next;
} Call;

typedef struct Queue {
    Call* front;
    Call* rear;
    int size;
} Queue;
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    q->size = 0;
    return q;
}
Call* createCall(int call_id) {
    Call* newCall = (Call*)malloc(sizeof(Call));
    newCall->call_id = call_id;
    newCall->next = NULL;
    return newCall;
}
void enqueue(Queue* q, int call_id) {
    Call* newCall = createCall(call_id);
    if (q->rear == NULL) {
        q->front = q->rear = newCall;
    } else {
        q->rear->next = newCall;
        q->rear = newCall;
    }
    q->size++;
    printf("Call %d added to the queue.\n", call_id);
}
int dequeue(Queue* q) {
    if (q->front == NULL) {
        printf("No calls in the queue.\n");
        return -1;
    }
    int call_id = q->front->call_id;
    Call* temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    q->size--;
    printf("Call %d answered and removed from the queue.\n", call_id);
    return call_id;
}
int isEmpty(Queue* q) {
    return q->front == NULL;
}
void printQueue(Queue* q) {
}