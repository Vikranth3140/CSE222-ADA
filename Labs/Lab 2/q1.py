# Input
N = int(input())
x = list(map(int, input().split()))
y = list(map(int, input().split()))

# Combine x and y into a list of tuples (x, y)
containers = [(x[i], y[i]) for i in range(N)]

# Sort containers based on capacities (yi) in descending order
containers.sort(key=lambda c: c[1], reverse=True)

# Initialize variables
min_containers = 0
effort = 0

# Iterate through containers
for juice, capacity in containers:
    if juice > 0:
        min_containers += 1
        # Find other containers with available space
        for i in range(N):
            if containers[i][0] < containers[i][1] and juice > 0:
                transfer_amount = min(juice, containers[i][1] - containers[i][0])
                containers[i] = (containers[i][0] + transfer_amount, containers[i][1])
                juice -= transfer_amount
                effort += transfer_amount

# Output minimum containers and effort
print(min_containers, effort)