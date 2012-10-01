int maxarr(int arr[], int length)
{
    int i = 0;
    int max_val = 0;
    
    max_val = arr[0];
    for (i = 1; i < length; i++)
    {
        if (arr[i] > max_val)
        {
            max_val = arr[i];
        }
    }
    return max_val;
}

int max2int(int a, int b)
{
    return (a > b) ? a : b;
}

int max3int(int a, int b, int c)
{
    //int max = 0;
    /*
	if (a > b)
    {
        if (a > c)
        {
            max = a;
        }
        else
        {
            max = c;
        }
        
        //max = (a > c) ? a : c;
    }
    else
    {
        if (b > c)
        {
            max = b;
        }
        else
        {
            max = c;
        }
        
        //max = (b > c) ? b : c;
    }
    */
    //max = (a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c);
	//return max;
    return (a > b) ? max2int(a, c) : max2int(b, c);
}
