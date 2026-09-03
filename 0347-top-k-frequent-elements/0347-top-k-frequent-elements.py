class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        
        freq = {}
        
        for num in nums:
            freq[num] = freq.get(num, 0) + 1
        
        arr = list(freq.items())
        
        arr.sort(key=lambda x: x[1], reverse=True)
        
        ans = []
        
        for i in range(k):
            ans.append(arr[i][0])
        
        return ans