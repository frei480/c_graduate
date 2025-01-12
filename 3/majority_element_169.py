class Solution:
    def majorityElement(self, nums: list[int]) -> int:
        buckets: list[int] = [0] * (max(nums) + 1)
        for x in nums:
            buckets[x] += 1
        for i, n in enumerate(buckets):
            if n > len(nums) / 2:
                return i
        return -1


test = Solution()
Case1 = [3, 2, 3]
print(test.majorityElement(Case1))

Case2 = [2, 2, 1, 1, 1, 2, 2]
print(test.majorityElement(Case2))
