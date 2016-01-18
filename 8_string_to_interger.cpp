#include "test.h"

class Solution {
public:
    int myAtoi(string str)
    {
        int64_t ret = 0;

        int sign = 1;

        bool discarding = true;

        for(char ch : str)
        {
            if(discarding && (ch == ' ' || ch == '0'))
                continue;

            if(discarding && ch == '-')
            {
                sign = -1;
            }
            else if(discarding && ch == '+')
            {
            }
            else if(ch >= '0' && ch <= '9')
            {
                ret *= 10;
                ret +=  (ch - '0');
            }
            else
            {
                break;
            }

            discarding = false;

            if(ret > 0x7fffffff)
                return sign == 1 ? 0x7fffffff : 0x80000000;
        }

        return sign * ret;
    }
};


int main()
{
    Solution s;
    cout << s.myAtoi("   -123b") << endl;
}
