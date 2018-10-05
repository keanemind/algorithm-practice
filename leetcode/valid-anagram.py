# https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/882/

class Solution:
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        if len(s) != len(t):
            return False
        counts_s = {}
        counts_t = {}
        for char in s:
            if char in counts_s:
                counts_s[char] += 1
            else:
                counts_s[char] = 1

        for char in t:
            if char in counts_t:
                counts_t[char] += 1
            else:
                counts_t[char] = 1

        for key in counts_s:
            if counts_s[key] != counts_t.get(key):
                return False

        return True