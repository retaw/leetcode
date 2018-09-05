#include "test.h"


class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital)
    {
        std::multimap<int, int, std::greater<int>> profits2captial;
        for (auto i = 0u; i < profits.size(); ++i)
            profits2captial.insert({profits[i], capital[i]});

        while (k > 0)
        {
            int oldK = k;
            for (auto iter = profits2captial.begin(); iter != profits2captial.end(); ++iter)
            {
                if (iter->second > w)
                    continue;

                w += iter->first;
                profits2captial.erase(iter);
                --k;
                break;
            }

            if (oldK == k)
                break;
        }

        return w;
    }
};


int main()
{
    vector<tuple<int, int, vector<int>, vector<int>>> datas = 
    {
        {2, 0, {1, 2, 3}, {0, 1, 1}},
        {1, 0, {1, 2, 3}, {1, 1, 2}},
    };
    Solution s;
    for (auto& data : datas)
        cout << s.findMaximizedCapital(std::get<0>(data), std::get<1>(data), std::get<2>(data), std::get<3>(data)) << endl;
    return 0;
}
