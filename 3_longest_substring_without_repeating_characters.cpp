#include "test.h"

class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        int ret = 0;
        int begin = 0;
        int i = 0;
        unordered_map<char, int> m;
        while(i < s.size())
        {
            char ch = s[i];
            auto it = m.find(ch);
            if(it != m.end() && it->second >= begin)
            {
    //            for(int j = begin; j <= it->second; ++j)
    //                m.erase(s[j]);

                if(ret < i - begin)
                    ret = i - begin ;
                begin = it->second + 1;
            }
            m[ch] = i;
            ++i;
        }
        if(ret < i - begin)
            ret = i - begin;
        return ret;
    }
};


int main()
{
    Solution s;
    cout << s.lengthOfLongestSubstring("abacdb") << endl;
    cout << s.lengthOfLongestSubstring("a") << endl;
    cout << s.lengthOfLongestSubstring("") << endl;
    return 0;
}
