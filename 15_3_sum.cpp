#include "test.h"


class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums)
	{
		vector<vector<int>> ret;

		if (nums.size() < 3)
			return ret;

		sort(nums.begin(), nums.end());

		for (auto i = 0u; i < nums.size() - 2; )
		{
			if (nums[i] > 0)
				break;

			auto j = i + 1;
			auto k = nums.size() - 1; 
			while (j < k)
			{
				auto sum = nums[i] + nums[j] + nums[k];

				if (sum == 0)
				{
					ret.push_back({nums[i], nums[j++], nums[k--]});

					//in the current while loop, i is constant, so make sure the next nums[j] is not equal to the current one
					while (nums[j] == nums[j - 1] && j < k)
						++j; 

					//the same operation for k with the same reason
					while (nums[k] == nums[k + 1] && j < k)
						--k;
				}
				else
					sum < 0 ? ++j : --k;
			}

			//make sure the next nums[i] is not equal to the current one
			++i;
			while (nums[i - 1] == nums[i] && i < j )
				++i;
		}
		return ret;
	}
};



int main()
{
	vector<vector<int>> datas = 
	{
		{-1, 0, 1, 2, -1, -4},
		{0, 0 , 0},
		{0, 0 , 0, 0},
		{-2,0,1,1,2},
		{-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6},
		{},
	};
	Solution s;
	for (auto& data : datas)
		cout << s.threeSum(data) << endl;
	return 0;
}
