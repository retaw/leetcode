#include "test.h"


class Solution {
public:
    string longestCommonPrefix(const vector<string>& strs)
    {
        string ret = "";

        if (strs.empty())
            return ret;

        if (strs.size() == 1)
            return strs[0];

        for (auto p = 0u; p < strs[0].length(); ++p)
        {
            char c = strs[0][p];
            for (auto i = 1u; i < strs.size(); ++i)
            {
                if (p >= strs[i].length())
                    return ret;
                
                if (c != strs[i][p])
                    return ret;
            }   
            ret.append(1, c);
        }

        return ret;
    }
};


int main()
{
    Solution s;

    cout << s.longestCommonPrefix({"123ab0", "12ab1", "12ab2"}) << endl;
    cout << s.longestCommonPrefix({"123ab0", "123ab", "123ab2"}) << endl;
    return 0;
}
