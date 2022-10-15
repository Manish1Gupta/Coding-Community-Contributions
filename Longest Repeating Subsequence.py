class Solution:
    
    def longestCommonSubsequence(self, text1, text2):
        
        dp = [[0] * (len(text1)+1) for i in range(len(text2)+1)]        
        
        for i in range(1,len(text2)+1):
            for j in range(1,len(text1)+1):
                
                if text2[i-1] == text1[j-1] and i != j:
                    dp[i][j] = dp[i-1][j-1] + 1
                    
                else:
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1])
        
        # print(dp)
        return dp[len(text2)][len(text1)]
        
        
    def LongestRepeatingSubsequence(self, str):
        # Code here
        return self.longestCommonSubsequence(str, str)


if __name__ == '__main__':
    T=int(input())
    for i in range(T):
        str = input()
        ob = Solution()
        ans = ob.LongestRepeatingSubsequence(str)
        print(ans)
