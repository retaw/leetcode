#include "test.h"


class Solution {
public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> ret;
        if (digits.empty())
            return ret;

        std::vector<std::vector<std::string>> digit2chars = 
        {
            {"a", "b", "c"}, 
            {"d", "e", "f"}, 
            {"g", "h", "i"}, 
            {"j", "k", "l"}, 
            {"m", "n", "o"}, 
            {"p", "q", "r", "s"}, 
            {"t", "u", "v"}, 
            {"w", "x", "y", "z"},
        };

        ret.push_back("");

        for (auto i = 0u; i < digits.size(); ++i)
        {
            vector<string> newRet;
            auto items = digit2chars[digits[i] - '2'];
            for (auto r : ret)
                for (auto item : items)
                    newRet.push_back(r + item);
            ret = newRet;
        }
        return ret;
    }
};

static int x = []()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

int main()
{
    vector<string> datas = 
    {
        "23",
    };
    Solution s;
    for (auto& data : datas)
        cout << s.letterCombinations(data) << endl;
    return 0;
}
