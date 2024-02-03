import bisect

def can_choose_pokemon(n, a, si):
    # Initialize the DP table
    dp = [0] + [-1]*100000

    # Sort the array of Pokemon stats
    a.sort()

    # Calculate the prefix sum of the array
    prefix_sum = [0]*(n+1)
    for i in range(n):
        prefix_sum[i+1] = prefix_sum[i] + a[i]

    # Fill the DP table
    for i in range(1, n+1):
        mid = (a[0] + a[i-1]) // 2
        j = bisect.bisect_right(a, mid, 0, i) - 1
        dp[i] = max(dp[i], prefix_sum[j+1])
        if j+1 < i:
            dp[i] = max(dp[i], dp[j+1] + prefix_sum[i] - prefix_sum[j+1])

    # Answer the queries
    if dp[n] >= si:
        print("YES")
    else:
        print("NO")

# Read the number of test cases
t = int(input().strip())

for _ in range(t):
    # Read the length of the array and the list of numbers
    n, q = map(int, input().strip().split())

    # Read the friendliness stats of the Pokemon
    a = list(map(int, input().strip().split()))

    for _ in range(q):
        # Read the sum of friendliness stats
        si = int(input().strip())

        # Find if the sum can be achieved
        can_choose_pokemon(n, a, si)