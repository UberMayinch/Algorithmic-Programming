import math

def main():
    t = int(input())
    for _ in range(t):
        n = int(input())
        
        
        v = list(map(int, input().split()))

        
        flag = False
        count = 0
        power = 1  

        for i in range(1, n):
            
            if v[i-1] > 1 and v[i] == 1:
                flag = True
                break
            
            log_v_i = math.log2(v[i])
            log_mx = power * math.log2(v[i-1])
            
            if log_mx == 0:
                required_steps = 0
            else:
                if log_v_i < log_mx:
                    required_steps = math.ceil(math.log2(log_mx / log_v_i))
                    count += required_steps
                    power = 2 ** required_steps
                else:
                    power = 1
            
        
        if flag:
            print("-1")
        else:
            print(count)

if __name__ == "__main__":
    main()
