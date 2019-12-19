/*================================================================
 *   Copyright (C) 2019 belonging to YangZhengQing. All rights reserved.
 *   
 *   文件名称：msa.c
 *   创 建 者：YangZhengQing
 *   创建日期：2019年12月19日
 *   描    述：滑窗算法
 *
 *================================================================*/


#include "msa.h"

int main(int argc,char *argv)
{
	int nums[] = {-2,1,-3,4,-1,1,2,-5,4};
	int nums_len = sizeof(nums)/sizeof(nums[0]);
	printf("nums_len=%d\n",nums_len);
	printf("maxSum = %d\n",maxSubArray(nums,nums_len));
	return 0;
}

int maxSubArray(int* nums, int numsSize){


	int sum = 0;
	int maxSum = 0;
	int start = 0;
	int is_minus = 1;//默认数组全为负
	int i ;

	/*数组中只有一个元素*/
	if(numsSize == 1)
	{
		maxSum = nums[0];
	}


	/*判断数组中是否全为负数，如果有正数则从第一个正数开始求和*/
	for(i = 0;i < numsSize;i++)
	{
		if(nums[i] > 0)
		{
			start = i;
			is_minus = 0;//数组中不全为负
			break;
		}
	}
	/*数组中全为负数的情况*/
	if(is_minus)
	{
		/*通过排序找出最大的，返回*/
		maxSum = nums[0];
		for(i = 0;i < numsSize;i++)
		{
			maxSum = (maxSum>nums[i])?maxSum:nums[i];
		}
	}

	else
	{
		for(i = start;i < numsSize;i++)
		{
			printf("strat=%d\n",start);
			sum = sum + nums[start];

			printf("sum=%d\n",sum);
			if(sum <= 0)
			{
				sum = 0;
			}
			else
			{
				maxSum = (sum > maxSum)?sum:maxSum;
			}
			start++;
		}

	}

	return maxSum;

}


/*
   int maxSubArray(int* nums, int numsSize){
   int i;
   int isAllMinus = 1;
   int maxNum = -100000000;
   int start, end;
   int sum = 0;

   if (numsSize == 0) {
   return 0;
   }
   if (numsSize == 1) {
   return nums[0];
   }
   for (i = 0; i < numsSize; i++) {
   if (nums[i] > 0) {
   isAllMinus = 0;
   break;
   }
   }

   if (isAllMinus == 1) {
   for (i = 0; i < numsSize; i++) {
   maxNum = (maxNum > nums[i]) ? maxNum : nums[i];
   }
   return maxNum;
   }

   for (i = 0; i < numsSize; i++) {
   if (nums[i] > 0) {
   start = i;
   break;
   }
   }
   printf("start = %d", start);
   if (numsSize - 1 == start) {
   printf("a");
   return nums[start];
   }

   end = start;
   sum = 0;
   while (end < numsSize) {
   sum += nums[end];
   if (sum > maxNum) {
   printf("%d", sum);
   maxNum = sum;
   } else if (sum <= 0) {
   start = end;
   sum = 0;
   }
   end++;
   }
   return maxNum;
   }
 */

