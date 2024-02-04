def can_choose_pokemon(a, s):
    if s == 0:
        return True
    if not a or sum(a) < s:
        return False

    mid = (max(a) + min(a)) // 2
    left = [x for x in a if x <= mid]
    right = [x for x in a if x > mid]

    return can_choose_pokemon(left, s) or can_choose_pokemon(right, s)

t = int(input().strip())
for _ in range(t):
    n, q = map(int, input().strip().split())
    a = list(map(int, input().strip().split()))
    for _ in range(q):
        s = int(input().strip())
        if can_choose_pokemon(a, s):
            print("Yes")
        else:
            print("No")