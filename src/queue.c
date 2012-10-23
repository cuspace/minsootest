#include <stdio.h>
#include "../include/queue.h"

void init_queue(struct queue *q, int filled_q_size)
{
    q->head = 0;
    q->tail = 0;
    q->filled_q_size = filled_q_size;
}

int get_q_length(struct queue *q)
{
    return q->filled_q_size;
}

int get_q_tail(struct queue *q)
{
    return q->tail;
}

int get_q_head(struct queue *q)
{
    return q->head;
}

int get_q_data(struct queue *q, int idx)
{
    return q->data[idx];
}

int is_q_full(struct queue *q)
{
    return q->tail == q->filled_q_size ? 1 : 0;
}

int is_q_empty(struct queue *q)
{
    return q->head == q->tail ? 1 : 0;
}

void update_tail(struct queue *q)
{
    q->tail = q->tail == q->filled_q_size ? 0 : q->tail + 1;
}

void update_head(struct queue *q)
{
    q->head = q->head == q->filled_q_size ? 0 : q->head + 1;
}

int enqueue(struct queue *q, int inData)
{
    if (is_q_full(q))
    {
        return -1;
    }
    
    q->data[q->tail] = inData;
    update_tail(q);
    
    return 0;
}

int dequeue(struct queue *q, int *outData)
{
    if (is_q_empty(q))
    {
        return -1;
    }
    
    *outData = q->data[q->head];
    update_head(q);
    
    return 0;
}
/*
int main(void)
{
    int inNum, outNum;
    struct queue q;
    
    init_queue(&q, 8);
    
    do {
        printf("input number: ");
        scanf("%d", &inNum);
        
        if (inNum > 0) {
            if (enqueue(&q, inNum) < 0)
            {
                printf("queue full!\n");
            }
        }
        else if (inNum == 0) {
            if (dequeue(&q, &outNum) < 0)
            {
                printf("queue empty!\n");
                init_queue(&q, 8);
            }
            else
            {
                printf("[%d]dequeue\n", outNum);
            }
        }
    } while (inNum >=0);
    return 0;
}
*/