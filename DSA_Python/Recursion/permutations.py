class permutation:
    def __init__(self) -> None:
        self.ans = []

    def func(self, s, i, n, temp):
        if i == n:
            self.ans.append(temp.copy())

            return
        
        for c in s:
            