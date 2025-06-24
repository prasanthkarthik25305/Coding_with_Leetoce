class Solution:
    def findKDistantIndices(self, nums: List[int], key: int, k: int) -> List[int]:
        ans=[]
        i=0
        for i in range(len(nums)):
            for j in range(0,len(nums)):
                if(abs(i-j)<=k and nums[j]==key):
                    ans.append(i)
                    break
        return ans 

        