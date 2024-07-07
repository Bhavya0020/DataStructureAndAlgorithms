# Find largest in an array
# approach -1 - brute - Time: O(N log N)
def find_largest_brute(a):
    a.sort()
    return a[len(a)-1]
# approach-2 - better - O(N)
def find_largest(a):
    largest = a[0]
    for i in range(0, len(a)):
        if a[i] > largest:
            largest = a[i]

    return largest

# Q2. Find second largest
# approach-1 - O(N log N + N)
def find_sec_largest_brute(a):
    n = len(a)
    a.sort()
    i = n-1
    largest = a[n-1]
    while i > 0:
        if a[i] != largest:
            return a[i]
        
        i -= 1

    return -1

# better - O(N + N)
def find_sec_largest_better(a):
    # pass-1 to find largest
    largest = a[0]
    for i in range(1, len(a)):
        if a[i] > largest:
            largest = a[i]

    # pass-2 to find second largest
    ans = -1
    for i in range(0, len(a)):
        if a[i] > ans and a[i] != largest:
            ans = a[i]

    return ans

# optimal - O(N)
def find_sec_largest_optimal(a):
    largest = a[0]
    sec = -1
    for i in range(1, len(a)):
        if a[i] > largest:
            sec = largest
            largest = a[i]
        elif a[i] > sec and a[i] != largest:
            sec = a[i]

    return sec

if __name__ == '__main__':
    a = [3, 2, 1, 5, 4]
    print(f"find largest element in array {a}")
    print('brute_force:', find_largest_brute(a))
    print('optimal', find_largest(a))

    b = [1, 2, 7, 7, 5]
    print(f"find second largest element in array {b}")
    print('brute_force:', find_sec_largest_brute(b))
    print('Better:', find_sec_largest_better(b))
    print('optimal', find_sec_largest_optimal(b))

