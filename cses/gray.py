def gray(n):
    if(n == 1):
        return ["1", "0"];
    else:
        ans = []
        arr = gray(n-1);
        for bv in arr:
            ans.append("1"+bv)
        for bv in reversed(arr):
            ans.append("0"+bv)
        return ans

n = int(input())
ans=gray(n)
for k in ans:
    print(k)
