#include "test.h"

/*
 * 0  6
 1 57
 24 8
 3  9


 13579
 24680

 1 5 9
 24680
 3 7

*/

class Solution {
public:
    //不要看做连起来的连起来的倒N，而看作半个倒N
    string convert(string s, int numRows)
    {
        if(s.size() <= 1 || numRows <= 1)
            return s;

        string ret;
        ret.reserve(s.size());
        const int strLen = s.size();
        const int unitCharSize = numRows * 2 - 2;
        const int maxUnitSize = strLen / unitCharSize + 1;


        for(int l = 0; l < numRows; ++l)   //逐行生成
        {
            for(int u = 0; u < maxUnitSize; ++u) //逐列生成
            {
                const int unitBegin = u * unitCharSize;
                if(l == 0)
                {
                    const int i = unitBegin;
                    if(i < strLen)
                        ret.push_back(s[i]);
                }
                else if(l == numRows - 1)
                {
                    const int i = unitBegin + numRows - 1;
                    if(i < strLen)
                        ret.push_back(s[i]);
                }
                else
                {
                    int i1 = unitBegin + l;
                    if(i1 < strLen)
                        ret.push_back(s[i1]);

                    int i2 = unitBegin + unitCharSize - l;
                    if(i2 < strLen)
                        ret.push_back(s[i2]);
                }
            }
        }

        return ret;
    }
};


int main()
{
    Solution s;
    cout << s.convert("0123456789", 4) << endl;
    cout << s.convert("AB", 2) << endl;
    return 0;
}
