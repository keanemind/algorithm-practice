# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")
import copy

def solution_old(S, K):
    # write your code in Python 3.6
    cnt = 0
    ls = list(S)
    to_del = []
    for i, char in enumerate(ls):
        if char == '-':
            to_del.append(i)

    for idx in to_del:
        del ls[idx]

    split = [[]]
    ls_cpy = ls.copy()
    for char in reversed(ls_cpy):
        cnt += 1
        split[-1].insert(0, ls.pop(-1).upper())
        if cnt == K:
            split.append([])

    return '-'.join([''.join(grp) for grp in split])

def solution(S, K):
    ls = list(S.replace('-', ''))
    split = [[]]
    cnt = 0
    for _ in range(len(ls)):
        cnt += 1
        split[-1].insert(0, ls.pop(-1).upper())
        if cnt == K:
            split.append([])
            cnt = 0

    return '-'.join(reversed([''.join(grp) for grp in split if grp]))

print(solution("24A0r74k", 5))
print(solution("24A0r74k", 4))
print(solution("24-A0r7-4k", 4))
print(solution("24-A0r7-4k", 3))
print(solution("24-A0r7-4k", 2))
print(solution("24-A0r7-4k", 1))
