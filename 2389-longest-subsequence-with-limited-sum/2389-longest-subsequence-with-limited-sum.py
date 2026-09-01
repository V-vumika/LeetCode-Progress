class Solution:
    def answerQueries(self, nums: List[int], queries: List[int]) -> List[int]:
        nums.sort()

        prefix = []
        total = 0

        for num in nums:
            total += num
            prefix.append(total)

        from bisect import bisect_right

        ans = []

        for q in queries:
            count = bisect_right(prefix, q)
            ans.append(count)
        return ans
