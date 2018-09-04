#include "test.h"


class Solution
{
public:
    string intToRoman(int num)
    {
        struct Item
        {
            string roman;
            int    stage;
        };

        vector<Item> table = 
        {
            {"M", 1000},
            {"CM", 900},
            {"D",  500},
            {"CD", 400},
            {"C",  100},
            {"XC",  90},
            {"L",   50},
            {"XL",  40},
            {"X",   10},
            {"IX",   9},
            {"V",    5},
            {"IV",   4},
            {"I",    1},
        };

        string ret;
        for (const auto& item: table)
        {
            for (auto i = 0; i < num/item.stage; ++i)
                ret.append(item.roman);
            num %= item.stage;
        }

        return ret;
    }

};

int main()
{
    Solution s;
    cout 
    << s.intToRoman(100) << ", "
    << s.intToRoman(3) << ", "
    << s.intToRoman(58) << ", "
    << s.intToRoman(1994) << ", "
    << endl;
}
