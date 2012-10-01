#include <stdio.h>

int main(void)
{
    int inNum;
    
    do {
        printf("input number: ");
        scanf("%d", &inNum);
        
        if (inNum > 0) {
            //printf("[%d]enqueue\n", inNum);
        }
        else if (inNum == 0) {
            printf("[%d]dequeue\n", inNum);
        }
    } while (inNum >=0);
    return 0;
}
