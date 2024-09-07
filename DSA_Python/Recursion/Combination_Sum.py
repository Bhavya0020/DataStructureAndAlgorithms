class combination:
    def __init__(self) -> None:
        self.ans = []

    def func(self, arr, i, target, path):
        if target <= 0 or i >= len(arr):
            if target == 0:
                self.ans.append(path.copy())
            return
        
        path.append(arr[i])
        self.func(arr, i+1, target - arr[i], path)
        path.pop()
        
        self.func(arr, i+1, target, path)

    def get_ans(self):
        return self.ans
    
if __name__ == '__main__':
    # arr = [2,3,6,7]

    # path = []
    # target = 7

    arr = [10,1,2,7,6,1,5]
    path = []
    target = 8

    c = combination()

    c.func(arr, 0, target, path)

    ans = c.get_ans()

    for a in ans:
        print(a)

