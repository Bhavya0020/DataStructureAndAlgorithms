# check if the array is sorted or not
def check_sorted_brute(a):
    for i in range(0, len(a)-1):
        if a[i] > a[i+1]:
            return False
        
    return True

# no need for any other solution