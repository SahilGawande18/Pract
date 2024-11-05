def knapsack(capacity,weight,values,num_items):
    
    dp=[]
    for i in range(num_items+1):
        dp.append([0]* (capacity+1))
    
    
    for i in range(1,num_items+1):
        for w in range(1,capacity+1):
            
            if weight[i-1]<=w:
                dp[i][w]=max(dp[i-1][w], values[i-1]+dp[i-1][w-weight[i-1]])
            else:
                dp[i][w]=dp[i-1][w]
    
    return dp[num_items][capacity]


capacity=10
weight=[2,2,4,5]
values=[3,7,2,9]
num_items=len(weight)

max_profit = knapsack(capacity, weight, values, num_items)
print(f"Maximum Profit Earned: {max_profit}")