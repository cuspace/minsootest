#include <stdio.h>
#include "../include/queue.h"

void init_queue(struct queue *q)
{
    q->head = 0;
    q->tail = 0;
    q->filled_q_size = 0;
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
    return (q->filled_q_size == MAX_Q_SIZE);
}

int is_q_empty(struct queue *q)
{
    return (q->filled_q_size == 0);
}

static void update_tail(struct queue *q)
{
    q->tail = ((q->tail+1) % MAX_Q_SIZE);
}

static void update_head(struct queue *q)
{
    q->head = ((q->head+1) % MAX_Q_SIZE);
}

static void increase_filled_q_size(struct queue *q)
{
    q->filled_q_size++;
}

static void decrease_filled_q_size(struct queue *q)
{
    q->filled_q_size--;
}

int enqueue(struct queue *q, int inData)
{
    if (is_q_full(q))
    {
        return -1;
    }
    
    q->data[q->tail] = inData;
    update_tail(q);
    increase_filled_q_size(q);
    
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
    decrease_filled_q_size(q);
    
    return 0;
}
/*
int main(void)
{
    int inNum, outNum;
    struct queue q;
    
    init_queue(&q);
    
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
                init_queue(&q);
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