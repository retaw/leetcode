#include "test.h"


class Solution
{
public:
    int romanToInt(string s)
    {
        struct Item
        {
            string roman;
            int    value;
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

        int ret = 0;
        auto i = 0u;
        for (const auto& item: table)
        {
            while (findAt(s, i, item.roman))
            {
                i += item.roman.length();
                ret += item.value;
            }
        }

        return ret;
    }

    bool findAt(const string& s1, string::size_type pos,  const string& s2)
    {
        if (s1.length() < pos + s2.length())
            return false;

        for (auto i = 0u; i < s2.length(); ++i)
        {
            if (s2[i] != s1[pos + i])
                return false;
        }
        return true;
    }

};

int main()
{
    Solution s;
    cout 
    << s.romanToInt("IX") << ", "
    << s.romanToInt("LVIII") << ", "
    << s.romanToInt("MCMXCIV") << ", "
    << endl;
}
