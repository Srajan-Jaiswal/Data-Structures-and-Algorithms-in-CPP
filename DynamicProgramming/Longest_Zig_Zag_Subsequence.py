#!/usr/bin/env python
# coding: utf-8

# In[11]:


def zig_zag_subseq(arr,n):
    
    dp = [[1 for i in range(2)] for i in range(n)]
    ans = 1
    for i in  range(1,n):
        for j in range(i):
            if(arr[j]<arr[i] and dp[i][0] < dp[j][1]+1):
                dp[i][0]=dp[j][1]+1
            elif(arr[j]>arr[i] and dp[i][1] < dp[j][0]+1):
                dp[i][1]=dp[j][0]+1
        if(ans < max(dp[i][1],dp[i][0])):
            ans = max(dp[i][1],dp[i][0])
    return ans
        
arr=[int(input()) for i in range(int(input()))]
n = len(arr)
print(zig_zag_subseq(arr,n))


# In[ ]:




