import math

def main():
    t = int(input())
    for _ in range(t):
        n = int(input())
        v = list(map(int, input().split()))
        
        flag = False
        mx = v[0]
        count = 0

        for i in range(1, n):
            if mx > 1 and v[i] == 1:
                flag = True
                break
            else:
                if v[i] < mx:
                    log_v_i = math.log2(v[i])
                    log_mx = math.log2(mx)
                    required_steps = math.ceil(math.log2(log_mx / log_v_i))
                    count += required_steps
                    v[i] = pow(v[i], pow(2, required_steps))
                mx = v[i]

        if flag:
            print("-1")
        else:
            print(count)

if __name__ == "__main__":
    main()
