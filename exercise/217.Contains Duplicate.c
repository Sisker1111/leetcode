int compare( const void* a, const void* b)
{
     int int_a = * ( (int*) a );
     int int_b = * ( (int*) b );

     if ( int_a == int_b ) return 0;
     else if ( int_a < int_b ) return -1;
     else return 1;
}

bool containsDuplicate(int* nums, int numsSize){
    qsort( nums,numsSize, sizeof(int), compare );
    for(int i=0;i<numsSize-1;i++){
        if(nums[i]==nums[i+1])
            return true;
    }
    return false;

}