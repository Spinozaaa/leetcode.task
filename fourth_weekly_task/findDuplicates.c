/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* findDuplicates(int* nums, int numsSize, int* returnSize) 
{
    int* ret;
    int temp;
    int i;
    
    ret=(int*)malloc((numsSize/2+1)*sizeof(int));
    
    for(i=0;i<numsSize;i++)
    {
        if(nums[i]!=i+1)
        {
            if(nums[nums[i]-1]!=nums[i])
            {
                temp=nums[nums[i]-1];
                nums[nums[i]-1]=nums[i];
                nums[i]=temp;
                i--;
            }
            else if(nums[i])
            {
                ret[*returnSize]=nums[i];
                (*returnSize)++;
                nums[i]=0;
            }

        }
    }
    return ret;
}