#include "test.h"

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        const int size1 = nums1.size();
        const int size2 = nums2.size();
        const int size = nums1.size() + nums2.size();

        if(size == 0)
            return 0;

        const int boundary = size / 2;

        int mergedSize = 0;
        int n1 = 0;
        int n2 = 0;

        int i = 0;
        int j = 0;

        while(mergedSize <= boundary)
        {
            //这几个if-else的判断方式比下面注释块中的版本的快了4ms --！
            //
            if(j >= size2)      //nums2已空
            {
                n1 = n2;
                n2 = nums1[i++];
            }
            else if(i >= size1) //num1已空
            {
                n1 = n2;
                n2 = nums2[j++];
            }
            else
            {
                if(nums1[i] < nums2[j])
                {
                    n1 = n2;
                    n2 = nums1[i++];
                }
                else
                {
                    n1 = n2;
                    n2 = nums2[j++];
                }
            }
            mergedSize++;

            /*
            if(i < size1 && j < size2)
            {
                if(nums1[i] < nums2[j])
                {
                    n1 = n2;
                    n2 = nums1[i++];
                }
                else
                {
                    n1 = n2;
                    n2 = nums2[j++];
                }
            }
            else
            {
                if(i < size1)
                {
                    n1 = n2;
                    n2 = nums1[i++];
                }
                else
                {
                    n1 = n2;
                    n2 = nums2[j++];
                }
            }
            */
        }

        return (size % 2 > 0) ? n2 : (n1 + n2) / 2.0;

        //return ((size % 2) > 0) ? n2 : (n1 + n2) / 2.0; 这个版本比上面的慢了足足12ms，感觉leetcode的编译器有点玄学了
    }
};


int main()
{
    vector<int> nums1 = {1,2,3};
    vector<int> nums2 = {2};
    Solution s;
    cout << s.findMedianSortedArrays(nums1, nums2) << endl;
}
