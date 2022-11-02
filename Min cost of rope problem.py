import heapq
def minCost(arr,n) :
    
        # code here
        if n ==1:
            return 0
        s = 0
        heapq.heapify(arr)
        while len(arr) > 1:
            i_sum = 0
            a = heapq.heappop(arr)
            b =  heapq.heappop(arr)
            i_sum = a+b
            s += i_sum
            heapq.heappush(arr,i_sum)
        return s

if __name__ == "__main__":
    arr = [4,3,7,6,9]
    n = len(arr)
    print(minCost(arr,n))

#output = 62
