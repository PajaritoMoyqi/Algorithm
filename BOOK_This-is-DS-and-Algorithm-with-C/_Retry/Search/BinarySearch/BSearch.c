int BinarySearch( int Set[], int length, int target )
{
    int left, right, middle;
    left = 0;
    right = length -1;
    
    while ( left <= right )
    {
        middle = (left + right) / 2;

        if ( target > Set[middle] )
            left = middle + 1;
        else if ( target < Set[middle] )
            right = middle - 1;
        else 
            return middle;
    }
}