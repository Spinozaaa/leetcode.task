#include <stdio.h>
#include <stdlib.h>
/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define Size 9

int** threeSum(int*nums,int numsSize, int* returnSize);
void sort(int*nums,int low,int high);



int main(int argc,char const *argv[])
{
	int num[Size]={1,-2,-2,4,5,3,-7,0,9};
	int i,j;
	int** re=NULL;
	int reSize=0;
	int* preSize=&reSize;

	printf("hhh\n");
	sort(num,0,Size-1);

	for(i=0;i<Size;i++)
		printf("%d**",num[i]);
	printf("\n");

	re=threeSum(num,Size,preSize);

	printf("%d\n",*preSize);
	for(i=0;i<*preSize;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%d**",re[i][j]);
		}
		printf("\n");
	}
	printf("\n");
		
		
	


	return 0;
}

int** threeSum(int* nums, int numsSize, int* returnSize)
{
	int low,high=numsSize-1;
	int i,j=0;
	int sums;
	int** re;

	sort(nums,0,numsSize-1);


	re=(int**)malloc(numsSize*numsSize*sizeof(int*));

	for(i=0;i<numsSize-2;i++)
	{
		if(i>0&&nums[i]==nums[i-1])
			continue;

		low=i+1;
		high=numsSize-1;
		
		sums=-nums[i];
		
		while(low<high)
		{
			if(nums[low]+nums[high]==sums)
			{
				re[j]=(int*)malloc(3*sizeof(int));
				re[j][0]=nums[i];
				re[j][1]=nums[low];
				re[j][2]=nums[high];
				j++;

				do
				low++;
				while(nums[low]==nums[low-1]);
				do
				high--;
				while(nums[high]==nums[high+1]);
			}
			else if(nums[low]+nums[high]>sums)
			{
				high--;printf("hhh\n");
			}
			else
			{
				low++;
			}
		}
	}

	*returnSize=j;


	return re;
}
void sort(int*nums,int low,int high)
{
	int i=low,j=high;
	int key=i;
	int temp;

	if(low>=high)
		return;

	//printf("%d##%d\n",i,j);
	
	while(i!=j)
	{
		for(;nums[j]>=nums[key]&&i<j;j--);
		for(;nums[i]<=nums[key]&&i<j;i++);

		temp=nums[j];
		nums[j]=nums[i];
		nums[i]=temp;
	}

	nums[j]=nums[key];
	nums[key]=temp;

	sort(nums,low,i-1);
	sort(nums,i+1,high);

	return;
}