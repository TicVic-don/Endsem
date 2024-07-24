def calculate_ways(k, modulus):
    if k == 1:
        return 0
    elif k == 2:
        return 3
    return (pow(3, k-2, modulus) * 2) % modulus

MOD = 10**8 + 7

def main():
    t = int(input())
    results = []
    for _ in range(t):
        k = int(input())
        results.append(calculate_ways(k, MOD))
    
    for result in results:
        print(result)

if _name_ == "_main_":
    main()