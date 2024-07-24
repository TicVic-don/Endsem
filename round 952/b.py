def solve():
    n, k = map(int, input().split())
    permutation = list(range(1, n + 1))

    # Calculate initial sum of absolute differences
    sum_abs_diffs = sum(abs(i - (n - i + 1)) for i in range(1, n + 1))

    # Handle invalid cases (odd k or insufficient sum)
    if k % 2 == 1 or sum_abs_diffs < k:
        print("NO")
    else:
        print("YES")
        ind = 0
        N = n

        # Adjust the permutation to reach sum k
        while k > (N - 1) * 2:
            permutation[ind], permutation[n - ind - 1] = permutation[n - ind - 1], permutation[ind]  # Swap elements
            k -= (N - 1) * 2
            N -= 2
            ind += 1

        k //= 2
        permutation[ind], permutation[ind + k] = permutation[ind + k], permutation[ind]  # Final swap for exact k

        # Print the resulting permutation
        print(*permutation)  # Unpack the list for efficient printing

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        solve()
