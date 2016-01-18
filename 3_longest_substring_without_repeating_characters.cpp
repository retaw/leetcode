#include "test.h"

class Solution {
public:
    /*
    int lengthOfLongestSubstring(string s)
    {
        int ret = 0;
        int subStrBegin = 0;
        int i = 0;
        unordered_map<char, int> m; //用已出现过的字符索引的hash表，重复的字符记录最后出现的位置
        const int size = s.size();
        while(i < size)
        {
            char ch = s[i];
            auto it = m.find(ch);
            if(it != m.end() && it->second >= subStrBegin) //出现过且在本字符串内
            {
                if(ret < i - subStrBegin)
                    ret = i - subStrBegin ;
                subStrBegin = it->second + 1;
            }
            m[ch] = i;
            ++i;
        }
        if(ret < i - subStrBegin)
            ret = i - subStrBegin;
        return ret;
    }
*/
    int lengthOfLongestSubstring(string s)
    {
        int ret = 0;
        int subStrBegin = 0;
        int lastPosOfChar[256]; //用已出现过的字符索引的表, 下标为字符，值为出现位置
        for(int i = 0; i < 256; ++i)
            lastPosOfChar[i] = -1;

        const int size = s.size();
        for(int i = 0; i < size; ++i)
        {
            int ch = s[i];
            if(lastPosOfChar[ch] >= subStrBegin) //已经出现过且在子本字符串内
            {
                if(ret < i - subStrBegin)
                    ret = i - subStrBegin ;
                subStrBegin = lastPosOfChar[ch] + 1;
            }
            lastPosOfChar[ch] = i;
        }
        if(ret < size - subStrBegin)
            ret = size - subStrBegin;
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
