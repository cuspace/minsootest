#include "CppUTest/TestHarness.h"
#include "queue.h"

extern "C" {
    extern void init_queue(struct queue *q);
    extern int get_q_tail(struct queue *q);
    extern int get_q_head(struct queue *q);
    extern int get_q_data(struct queue *q, int idx);
    extern int enqueue(struct queue *q, int inData);
    extern int dequeue(struct queue *q, int *outData);
    extern int is_q_full(struct queue *q);
    extern int is_q_empty(struct queue *q);
}

TEST_GROUP(queue)
{
    void setup()
    {
    }
    void teardown()
    {
    }
};

#define QUEUE_FULL -1
#define QUEUE_EMPTY -1
TEST(queue, ringqBufferQueueTests)
{
    struct queue q;
    //int ret = 0;
    int outData = 0;
    
    //queue length initialization
    init_queue(&q);
    enqueue(&q, 201);
    enqueue(&q, 202);
    enqueue(&q, 203);
    enqueue(&q, 204);
    enqueue(&q, 205);
    enqueue(&q, 206);
    enqueue(&q, 207);
    enqueue(&q, 208);
    dequeue(&q, &outData);
    LONGS_EQUAL(201, outData);
    dequeue(&q, &outData);
    LONGS_EQUAL(202, outData);
    dequeue(&q, &outData);
    LONGS_EQUAL(203, outData);
    dequeue(&q, &outData);
    LONGS_EQUAL(204, outData);
    LONGS_EQUAL(4, get_q_head(&q));
    
    enqueue(&q, 209);
    LONGS_EQUAL(1, get_q_tail(&q));
    LONGS_EQUAL(209, get_q_data(&q, 0));
    enqueue(&q, 210);
    LONGS_EQUAL(2, get_q_tail(&q));
    LONGS_EQUAL(210, get_q_data(&q, 1));
    enqueue(&q, 211);
    LONGS_EQUAL(3, get_q_tail(&q));
    LONGS_EQUAL(211, get_q_data(&q, 2));
    enqueue(&q, 212);
    LONGS_EQUAL(4, get_q_tail(&q));
    LONGS_EQUAL(212, get_q_data(&q, 3));
    
    LONGS_EQUAL(1, is_q_full(&q));
}

TEST(queue, queueFunctions)
{
    struct queue q;
    int ret = 0;
    int outData = 0;
    
    //queue length initialization
    init_queue(&q);
    
    //enqueue 8 items
    enqueue(&q, 101);
    LONGS_EQUAL(1, get_q_tail(&q));
    LONGS_EQUAL(101, get_q_data(&q, 0));
    enqueue(&q, 102);
    LONGS_EQUAL(2, get_q_tail(&q));
    LONGS_EQUAL(102, get_q_data(&q, 1));
    enqueue(&q, 103);
    LONGS_EQUAL(3, get_q_tail(&q));
    LONGS_EQUAL(103, get_q_data(&q, 2));
    enqueue(&q, 104);
    LONGS_EQUAL(4, get_q_tail(&q));
    LONGS_EQUAL(104, get_q_data(&q, 3));
    enqueue(&q, 105);
    LONGS_EQUAL(5, get_q_tail(&q));
    LONGS_EQUAL(105, get_q_data(&q, 4));
    enqueue(&q, 106);
    LONGS_EQUAL(6, get_q_tail(&q));
    LONGS_EQUAL(106, get_q_data(&q, 5));
    enqueue(&q, 107);
    LONGS_EQUAL(7, get_q_tail(&q));
    LONGS_EQUAL(107, get_q_data(&q, 6));

    LONGS_EQUAL(0, is_q_full(&q));
    
    enqueue(&q, 108);
    LONGS_EQUAL(0, get_q_tail(&q));
    LONGS_EQUAL(108, get_q_data(&q, 7));
    
    LONGS_EQUAL(1, is_q_full(&q));
    
    //queue full error return test
    ret = enqueue(&q, 109);
    LONGS_EQUAL(QUEUE_FULL, ret);
 
    //dequeue 8 items
    dequeue(&q, &outData);
    LONGS_EQUAL(1, get_q_head(&q));
    LONGS_EQUAL(101, outData);
    dequeue(&q, &outData);
    LONGS_EQUAL(2, get_q_head(&q));
    LONGS_EQUAL(102, outData);
    dequeue(&q, &outData);
    LONGS_EQUAL(3, get_q_head(&q));
    LONGS_EQUAL(103, outData);
    dequeue(&q, &outData);
    LONGS_EQUAL(4, get_q_head(&q));
    LONGS_EQUAL(104, outData);
    dequeue(&q, &outData);
    LONGS_EQUAL(5, get_q_head(&q));
    LONGS_EQUAL(105, outData);
    dequeue(&q, &outData);
    LONGS_EQUAL(6, get_q_head(&q));
    LONGS_EQUAL(106, outData);
    dequeue(&q, &outData);
    LONGS_EQUAL(7, get_q_head(&q));
    LONGS_EQUAL(107, outData);

    LONGS_EQUAL(0, is_q_empty(&q));
    
    dequeue(&q, &outData);
    LONGS_EQUAL(0, get_q_head(&q));
    LONGS_EQUAL(108, outData);
    
    LONGS_EQUAL(1, is_q_empty(&q));
    
    //queue empty error return test
    ret = dequeue(&q, &outData);
    LONGS_EQUAL(QUEUE_EMPTY, ret);
    
}
