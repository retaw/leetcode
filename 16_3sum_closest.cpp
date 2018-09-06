#include "test.h"


class Solution {
public:
    int abs(int a)
    {
        return a < 0 ? -a : a;
    }
    int threeSumClosest(vector<int>& nums, int target)
    {
        if (nums.size() < 3)
            return 0;

        auto ret = nums[0] + nums[1] + nums[2];
        if (nums.size() == 3)
            return ret;

        sort(nums.begin(), nums.end());

        auto i = 0u;
        while (i < nums.size() - 2)
        {
            auto j = i + 1;
            auto k = nums.size() - 1;
            while (j < k)
            {
                auto tmp = nums[i] + nums[j] + nums[k];

                auto oldDist = ret - target;
                auto dist = tmp - target;

                if (abs(oldDist) > abs(dist))
                    ret = tmp;

                if (dist == 0)
                    return tmp;

                dist > 0 ? --k : ++j;
            }

            if (nums[i] > target)
                return ret;

            ++i;
        }
        return ret;
    }
};



int main()
{
    vector<tuple<vector<int>, int>> datas = 
    {
        //{{1,1,1,0},100},
        {{0,2,1,-3}, 1},
    };
    Solution s;
    for (auto& data : datas)
        cout << s.threeSumClosest(std::get<0>(data), std::get<1>(data)) << endl;
    return 0;
}
