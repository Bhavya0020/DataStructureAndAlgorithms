# brute force - O(Nlogn + N), O(N)
def remove_dup_brute(a):
    s = set()

    for i in range(0, len(a)):
        if a[i] not in s:
            s.add(a[i])
    i = 0
    for ele in s:
        a[i] = ele
        i += 1

    return a

# optimal
def remove_dup_optimal(a):
    j = 1
    for i in range(1, len(a)):
        if a[i] != a[i-1]:
            a[j] = a[i]
            j += 1

    return a


if __name__ == '__main__':
    a = [1,1,2,2,2,3,3]
    print(remove_dup_brute(a))
    print(remove_dup_optimal(a))