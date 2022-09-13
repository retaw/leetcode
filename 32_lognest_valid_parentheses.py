class Solution:
    def longestValidParentheses(self, s: str) -> int:
        longest = 0
        curLong = 0
        l = [(')',-1)]
        for i in range(0, len(s)):
            #print("*", l)
            c = s[i]
            
                
            if l[-1][0] == "(" and c == ")":
                l.pop()
                #print("#", l, i, l[-1][1])
                curLong = i - l[-1][1]
                if curLong > longest:
                    longest = curLong
            else:
                l.append((c,i))
    
        return longest

