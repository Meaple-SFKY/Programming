/*
 * @lc app=leetcode.cn id=1 lang=c
 *
 * [1] 两数之和
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
	*returnSize = 2;
	int* p = (int *) malloc (2 * sizeof(int));
	for (int i = 0; i < numsSize; i++) {
		for (int j = 0; j < numsSize; j++) {
			if (i != j) {
				if (nums[i] + nums[j] == target) {
					p[0] = i;
					p[1] = j;
					return p;
				}
			}
		}
	}
	return p;
}
// @lc code=end

