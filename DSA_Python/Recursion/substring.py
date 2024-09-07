class substring:
    def __init__(self) -> None:
        self.ans = []

    def func(self, s, i, n, path):
        if i >= n:
            self.ans.append(path)
            return
        
        