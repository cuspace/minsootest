void swap2int(int *a, int *b)
{
	int tmp;
	tmp = *b;
	*b = *a;
	*a = tmp;
}

void swapArrWithIdx(int arr[], int i, int j)
{
    int tmp;
    
    tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}