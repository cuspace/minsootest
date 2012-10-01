#include <stdio.h>

void rotate_right(int arr[], int s, int t)
{
    int last = arr[t];
    int i;
    
    for (i = t; i > s; i--)
    {
        arr[i] = arr[i-1];
    }
    arr[s] = last;
}

void rotate_left(int arr[], int s, int t)
{
    int first = arr[s];
    int i;
    
    for (i = s; i < t; i++)
    {
        arr[i] = arr[i+1];
    }
    arr[t] = first;
}

int get_rotated_right_idx(int cur_idx, int s, int t, int k)
{
    return ((cur_idx+k) < (t+1)) ? cur_idx+k : (cur_idx+k)-(t+1)+s;
}

void last_k_backup(int arr[], int last[], int s, int t, int k)
{
    int i, j;
    
    for (j = 0, i = t+1-k; i < t+1; i++) {
        last[j++] = arr[i];
    }
}

void rotate_rightk(int arr[], int s, int t, int k)
{
    int last[k];
    int i, j, ri;
    int backupStartIdx = t+1-k;
    
    last_k_backup(arr, last, s, t, k);
    
    //printf("last[0]=%d, last[1]=%d\n", last[0], last[1]);
    
    for (j = 0, i = s; i < t+1; i++) {
        ri = get_rotated_right_idx(i, s, t, k);
        if (i >= backupStartIdx) {
            arr[ri] = last[j++];
        }
        else {
            arr[ri] = arr[i];
        }
        //printf("%d: %d\n", ri, arr[ri]);
    }
}