#include "test.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {

    struct ListNode
    {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };

public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode* head = nullptr;
        ListNode** pl = &head;
        int carry = 0;
        while(l1 != nullptr || l2 != nullptr || carry > 0)
        {
            *pl = new ListNode(carry);
            if(l1 != nullptr)
            {
                (*pl)->val += l1->val;
                l1 = l1->next;
            }
            if(l2 != nullptr)
            {
                (*pl)->val += l2->val;
                l2 = l2->next;
            }

            carry = (*pl)->val / 10;
            (*pl)->val = (*pl)->val % 10;

            pl = &((*pl)->next);
        }

        return head;
    }


    ListNode* makeList(vector<int> nums)
    {
        ListNode* head = nullptr;
        ListNode** cur = &head;
        for(auto n : nums)
        {
            (*cur) = new ListNode(n);
            cur = &((*cur)->next);
        }
        return head;
    }


    void printList(ListNode* l)
    {
        while(l != nullptr)
        {
            cout << l->val << " -> ";
            l = l->next;
        }
        cout << "null" << endl;
    }

};


int main()
{
    Solution s;
    auto l1 = s.makeList({2,4,5});
    auto l2 = s.makeList({5,6,4});
    s.printList(l1);
    s.printList(l2);

    auto ret = s.addTwoNumbers(l1, l2);
    s.printList(ret);
}
