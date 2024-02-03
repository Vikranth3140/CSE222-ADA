# Python code funderstanding the minimum energy required to convert a string to a string with all characters in alphabetical order
# and the Logic

def min_energy(s, char='a'):
    if len(s) == 1:
        return 0 if s[0] == char else 1

    mid = len(s) // 2
    cnt_left = s[:mid].count(char)
    cnt_right = s[mid:].count(char)

    return min(mid - cnt_left + min_energy(s[mid:], chr(ord(char) + 1)),
               mid - cnt_right + min_energy(s[:mid], chr(ord(char) + 1)))

l = []
t = int(input())
for _ in range(t):
    n = int(input())
    s = input()
    energy = min_energy(s)
    l.append(energy if energy <= n else -1)


print(*l, sep='\n')