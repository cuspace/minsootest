#define MAX_Q_SIZE 8
struct queue {
    int head;
    int tail;
    int filled_q_size;
    int data[MAX_Q_SIZE];
};