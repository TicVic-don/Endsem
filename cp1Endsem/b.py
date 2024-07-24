MOD = int(1e8 + 7)

def multiply(a, b):
    n = len(a)
    c = [[0] * n for _ in range(n)]
    for i in range(n):
        for j in range(n):
            for k in range(n):
                c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % MOD
    return c

def power(base, exp):
    if exp == 1:
        return base
    half = power(base, exp // 2)
    result = multiply(half, half)
    if exp % 2 == 1:
        result = multiply(result, base)
    return result

def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    t = int(data[0])
    index = 1
    results = []
    
    for _ in range(t):
        k = int(data[index])
        index += 1
        
        trans = [
            [0, 1, 1, 1], 
            [1, 0, 1, 1], 
            [1, 1, 0, 1], 
            [1, 1, 1, 0]
        ]
        
        result = power(trans, k)
        results.append(result[0][0])
    
    for res in results:
        print(res)

if _name_ == "_main_":
    main()