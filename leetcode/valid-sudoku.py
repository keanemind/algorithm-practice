# https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/769/
class Solution:
    def __init__(self):
        self.rows = [set() for _ in range(9)]
        self.cols = [set() for _ in range(9)]
        self.boxes = [set() for _ in range(9)]

    def isValidSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """
        for i, row in enumerate(board):
            for j, num in enumerate(row):
                if not self.addNum(num, i, j):
                    return False
        return True
    
    def addNum(self, num, i, j):
        if num == '.':
            return True

        # Check for duplicates
        if num in self.rows[i]:
            return False
        if num in self.cols[j]:
            return False
        box_idx = ((j // 3) * 3) + (i // 3)
        if num in self.boxes[box_idx]:
            return False

        # Add to sets
        self.rows[i].add(num)
        self.cols[j].add(num)
        self.boxes[box_idx].add(num)
        return True
