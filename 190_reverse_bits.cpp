#include "test.h"

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ret = 0;
        uint32_t c = 1;
        uint32_t m = c << 31; 
        for (uint32_t i = 0; i < 32; ++i)
        {
            if ( (n & c) > 0)
                ret |= m;

            m >>= 1;
            c <<= 1;
        }
        return ret;
    }   
};

int main()
{
    Solution s;
    cout << 4294967293 << " -> " << s.reverseBits(4294967293) << endl;
}
