import sys
sys.setrecursionlimit(1500)

max_num_digits = 20
dp = [[[[[-1 for _ in range(9)] for _ in range(2)] for _ in range(2)] for _ in range(max_num_digits)] for _ in range(max_num_digits)]

def reset():
    global dp
    dp = [[[[[-1 for _ in range(9)] for _ in range(2)] for _ in range(2)] for _ in range(max_num_digits)] for _ in range(max_num_digits)]

def dfs(c, x=0, y=11, lead=1, z=False, modsum=0):
    c_str = str(c)
    if dp[x][y][lead][z][modsum] != -1:
        return dp[x][y][lead][z][modsum]
    if x == len(c_str):
        return modsum == 0

    limit = 9
    dig = int(c_str[x])
    if not z:
        limit = dig

    dp[x][y][lead][z][modsum] = 0
    for xth_digit in range(limit + 1):
        if xth_digit == 7: 
            continue  # No 7s allowed
        if not lead and xth_digit == y: 
            continue
        new_modsum = (modsum + xth_digit) % 9
        if z:
            dp[x][y][lead][z][modsum] += dfs(c, x + 1, xth_digit, xth_digit == 0 and lead, True, new_modsum)
        else:
            dp[x][y][lead][z][modsum] += dfs(c, x + 1, xth_digit, xth_digit == 0 and lead, xth_digit < limit, new_modsum)
    return dp[x][y][lead][z][modsum]

def main():
    n, m = map(int, input().split())
    reset()
    total = dfs(m)
    reset()
    torem = dfs(n - 1)
    total -= torem
    print(total)

if __name__ == "_main_":
    main()