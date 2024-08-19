import math

def main():
    t = int(input())
    for _ in range(t):
        n = int(input())
        v = list(map(int, input().split()))
        
        flag = False
        mx = v[0]
        count = 0

        v = [(v[i], 1) for i in range(n)]  

        for i in range(1, n):
            value, power = v[i]

            if mx > 1 and value == 1:
                flag = True
                break
            else:
                if value ** (2 ** power) < mx:
                    log_v_i = math.log2(value) + power
                    log_mx = math.log2(mx)
                    
                    # Calculate required steps using logarithms and ceiling
                    required_steps = math.ceil(log_mx - log_v_i)
                    count += required_steps
                    power += required_steps
                    v[i] = (value, power)
                    
                mx = value ** (2 ** power)

        if flag:
            print("-1")
        else:
            print(count)

if __name__ == "__main__":
    main()
