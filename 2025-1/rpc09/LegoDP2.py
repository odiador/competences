def count_sequences(n, k):
    MOD = 10**9 + 7

    # We'll use a space-optimized approach with just two rows
    prev_row = [0] * (k + 1)

    # Base case: first cube can be placed anywhere
    for j in range(1, k + 1):
        prev_row[j] = 1

    # Fill the dp table
    for i in range(2, n + 1):
        curr_row = [0] * (k + 1)
        for j in range(1, k + 1):
            # Previous cube at j-1
            if j > 1:
                curr_row[j] = (curr_row[j] + prev_row[j-1]) % MOD

            # Previous cube at j (stacked)
            curr_row[j] = (curr_row[j] + prev_row[j]) % MOD

            # Previous cube at j+1
            if j < k:
                curr_row[j] = (curr_row[j] + prev_row[j+1]) % MOD

        prev_row = curr_row

    # Sum up all possible final positions for the nth cube
    result = sum(prev_row[1:]) % MOD

    return result

# Calculate for n=4, k=3
print(f"Result for n=4, k=3: {count_sequences(4, 3)}")

# Calculate for n=100, k=200
print(f"Result for n=100, k=200: {count_sequences(100, 200)}")
