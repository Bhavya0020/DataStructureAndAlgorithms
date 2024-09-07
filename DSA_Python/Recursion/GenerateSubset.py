class Subset:
    def __init__(self):
        self.values = []

    def func(self, arr, pos, n, val):
        # base case
        if pos == n:
            self.values.append(val)
            return

        self.func(arr, pos+1, n, val)
        val += arr[pos]
        self.func(arr, pos+1, n, val)
        val -= arr[pos]
        
    def get_list(self):
        return self.values
    



if __name__ == '__main__':
    arr = [2,3]
    pos = 0
    n = len(arr)

    val = 0

    s = Subset()

    s.func(arr, pos, n, val)

    print(s.get_list())
