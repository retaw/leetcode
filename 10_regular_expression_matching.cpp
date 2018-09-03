#include "test.h"

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        return match(s, 0, p, 0);
    }

    bool match(const string& s, unsigned int i, const string& p, unsigned int j)
    {
        const char eof = 0;
        char s1 = i < s.length() ? s[i] : eof;
        char p1 = j < p.length() ? p[j] : eof;
        char p2 = j + 1 < p.length() ? p[j + 1] : eof;

        if (s1 == eof)
        {
            if (p1 == eof)
                return true;
			
            if (p2 == '*')
               return match(s, i, p, j + 2);
           
            return false;
        }

        if (p1 == s1 || p1 == '.')
        {
            return p2 == '*' ? (match(s, i + 1, p, j) || match(s, i, p, j + 2)): match(s, i + 1, p, j + 1);
        }
        else
        {
            return p2 == '*' ? match(s, i, p, j + 2) : false;
        }

        return true;
    }
};


int main()
{
    Solution s;
    cout
    << s.isMatch("", "c*c*") << " "
    << s.isMatch("aaa", "a*a") << " "
    << s.isMatch("abc", "ab.*") << " "
    << s.isMatch("abc", "ab.*") << " "
    << s.isMatch("abccccc", "abc.*") << " "
    << s.isMatch("abccccc", "abc.*d") << " "
    << endl;

}
