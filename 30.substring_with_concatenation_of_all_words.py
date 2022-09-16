from typing import List
class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        None



if __name__ == "__main__":
    def kmp(s, p):
        None


    def calcNext(p):
        n = [0]
        i = 1
        j = 0
        while i < len(p):
            if p[i] == p[j]:
                i += 1
                j += 1
                n.append(j)
            else:
                if j == 0:
                    n.append(0)
                    i += 1
                else:
                    j = n[j] - 1
        return n
 

    p = "ababac"
    p = "wordgoodgoodgoodbestword"
    print(calcNext(p))
