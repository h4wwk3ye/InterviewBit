# https://www.interviewbit.com/problems/repeat-and-missing-number-array/


class Solution:
    # @param A : tuple of integers
    # @return a list of integers
    def repeatedNumber(self, A):
        from collections import Counter

        d = Counter(A)
        a, b = 0, 0
        for i in range(1, len(A) + 1):
            if i not in d:
                b = i
            else:
                if d[i] == 2:
                    a = i
        return (a, b)

