#include "test.h"


class Solution
{
public:
	int maxArea(const vector<int>& height)
    {
	    uint32_t left = 0;
		uint32_t right = height.size() - 1;
        uint32_t theMaxArea = 0;
        while (left < right)
        {
            uint32_t width = right - left;
            uint32_t minHeight = height[left] < height[right] ? height[left++] : height[right--];
            uint32_t area = minHeight * width;
            if (theMaxArea < area)
                theMaxArea = area;
        }

        return theMaxArea;
	}
};


//本次好奇, 看了一下那些运行时间最短的提交
//发现一个搞竞赛的人用来刷运行速度的奇技淫巧, 
//大概是干掉标准的iostream的同步保证，
//提交时带上这个， 就是效率第一梯队打败100%的玩家了，
//玩竞赛的人好无聊的说~~
static int x = []()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();


int main()
{
    Solution s;
    cout 
    << s.maxArea({1,8,6,2,5,4,8,3,7}) << ", "
    << s.maxArea({1,2}) << ", "
    << endl;
}
