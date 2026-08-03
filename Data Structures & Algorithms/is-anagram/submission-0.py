class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        count = Counter(s)
        for c in t:
            if c in count:
                count[c] -= 1
            else:
                return False
        
        for _, v in count.items():
            if v > 0:
                return False
        return True