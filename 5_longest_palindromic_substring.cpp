#include "test.h"

//这个算法合格，没有超时，但是非常的慢
//正在研究一个时间O(n)的算法
class Solution {
public:
    inline bool isPalindrome(const char* s, int begin, int size)
    {
        const int half = size / 2;
        const int rbegin = begin + size - 1;
        for(int i = 0; i < half; ++i)
        {
            if(s[begin + i] != s[rbegin - i])
                return false;
        }
        return true;
    }

    string longestPalindrome(string s)
    {
        const int size = s.size();
        for(int subSize = s.size(); subSize > 0; --subSize)
        {
            for(int subBegin = 0; subBegin <= size - subSize; ++subBegin)
            {
                if(isPalindrome(s.data(), subBegin, subSize))
                    return s.substr(subBegin, subSize);
            }
        }
        return "";
    }
};


int main()
{
    Solution s;
    string text = "eabbaa";
    cout << s.longestPalindrome(text) << endl;
}
