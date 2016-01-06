#include "test.h"


class Solution {
public:
    
    //O(n2) runtime, O(1) space
    vector<int> twoSum_v1(vector<int>& nums, int target)
    {
        vector<int> ret(2);
        for(int i = 0u; i < nums.size(); ++i)
        {
            for(int j = i; j < nums.size(); ++j)
            {
                if(i != j && nums[i] + nums[j] == target)
                {
                    ret[0] = i + 1;
                    ret[1] = j + 1;
                    break;
                }
            }
        }

        return ret;
    }

    //O(n) runtime, O(n) space 
    vector<int> twoSum_v2(vector<int>& nums, int target)
    {
        vector<int> ret(2);
        unordered_map<int, int> t;
        for(auto i = 0; i < nums.size(); ++i)
        {
            auto it = t.find(target - nums[i]);
            if(it != t.end())
            {
                ret[0] = i + 1 < it->second ? i + 1 : it->second;
                ret[1] = i + 1 > it->second ? i + 1 : it->second;
                break;
            }
            t[nums[i]] = i + 1;
        }

        return ret;
    }

    vector<int> twoSum(vector<int>& nums, int target)
    {
        return twoSum_v1(nums, target);
    }
};


int main()
{
    vector<int> nums = {0, 4, 3, 0};
    Solution s;
    cout << s.twoSum(nums, 0) << endl;
}

