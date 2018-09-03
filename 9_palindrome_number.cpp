#include "test.h"


class Solution
{
public:
    bool isPalindrome(int x)
    {
        if(x < 0)
            return false;
        if(x < 10)
            return true;
        if(x % 10 == 0)
            return false;
        int y = 0;
        while(x > y)
        {
            int tmp = x % 10;
            x = x / 10;
            if(x == y)
                return true;

            y *= 10;
            y += tmp;

            if(x == y)
                return true;
        }
        return false;
    }
};


int main()
{
    Solution s;
    cout << 
    s.isPalindrome(121)  << ", " <<
    s.isPalindrome(122)  << ", " <<
    s.isPalindrome(1221) << endl;
}
