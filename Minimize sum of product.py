def minValue( a, b, n):
        # Your code goes here
        a = sorted(a)
        b = sorted(b,reverse=True)
        s = 0
        for i in range(n):
            s += a[i] * b[i]
        return s

if __name__ == "__main__":
    a = [3,1,1]
    b = [6,5,4]
    n=len(a)
    print(minValue(a,b,n))
#output = 23
