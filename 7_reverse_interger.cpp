#include "test.h"

class Solution {
public:
    int reverse(int x) 
    {
        int64_t ret = 0;
        while(x != 0)
        {
            ret *= 10;
            ret += x % 10;

            if(ret != (int)ret)  //题目要求溢出时返回0
                return 0;

            x = x / 10;

        }
        return ret;
    }
};


int main()
{
    Solution s;
    cout << s.reverse(-32465) << endl;
    cout << s.reverse(1534236469) << endl; //溢出测试
}
