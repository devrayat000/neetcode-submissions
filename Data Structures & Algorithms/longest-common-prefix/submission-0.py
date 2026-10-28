class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        n = len(strs)
        prefix = ""

        j = 0
        while j < len(strs[0]):
            for i in range(1, n):
                if strs[0][0:j] != strs[i][0:j]:
                    return strs[0][0:j-1]
            prefix = strs[0][0:j]
            j += 1

        return prefix