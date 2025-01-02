#   Solved in 6 min
#       just like 3 syntax errors (T/F has to be capitalized, indexing last element of 
#       string is s[-1], forgot () around range)

class Solution:
    def vowelStrings(self, words: List[str], queries: List[List[int]]) -> List[int]:
        def isVowel(c):
            if (c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u'):
                return True
            return False

        result = []
        prefixSum = []
        curSum = 0

        for i in range(len(words)):
            if (isVowel(words[i][0]) and isVowel(words[i][-1])):
                curSum = curSum + 1
            prefixSum.append(curSum)

        for i in range(len(queries)):
            if (queries[i][0] == 0):
                result.append(prefixSum[queries[i][1]])
            else:
                result.append(prefixSum[queries[i][1]] - prefixSum[queries[i][0] - 1])

        return result
