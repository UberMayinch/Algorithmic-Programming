import math

def main():
    t = int(input().strip())
    
    for _ in range(t):
        n = int(input().strip())
        
        if n == 0:
            print("0")
            continue
        
        v = list(map(int, input().strip().split()))
        
        if len(v) != n:
            print("-1")
            continue
        
        flag = False
        count = 0
        mx = v[0]
        power = 1
        
        for i in range(1, n):
            if v[i] <= 0:
                print("-1")
                flag = True
                break
            
            if mx > 1 and v[i] == 1:
                flag = True
                break
            
            log_v_i = math.log2(v[i])
            log_mx = power * math.log2(mx) if mx > 1 else 0
            
            if log_mx == 0 and log_v_i <= 0:
                power = 1
                continue
            
            if log_v_i <= 0:
                required_steps = float('inf')  
            else:
                required_steps = math.ceil(math.log2(log_mx / log_v_i))
            
            if required_steps < 0:
                required_steps = 0
            
            count += required_steps
            power = 2 ** required_steps
            
            mx = v[i]

        if flag:
            print("-1")
        else:
            print(count)

if __name__ == "__main__":
    main()
