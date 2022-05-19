/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* c1 = l1;
        ListNode* c2 = l2;
        ListNode* C = nullptr;
        ListNode* root = nullptr;
        int carry = 0;
        while(c1 != nullptr || c2 != nullptr)
        {
            int val1 = 0;
            int val2 = 0;
            
            //take first number
            if(c1 != nullptr)
            {
                val1 = c1->val;
                c1 = c1->next;
            }
            
            //take second number
            if(c2 != nullptr)
            {
                val2 = c2->val;
                c2 = c2->next;
            }
            
            //add both
            int nSum = val1 + val2 + carry;
            int val = nSum;
            
            //check for carry
            if(nSum > 9)
            {
                val = nSum % 10;
                carry = nSum / 10;
            }
            else
            {
                carry = 0;
            }
            
            //add into list
            ListNode* n = new ListNode(val);
            if(C == nullptr)
            {
                C = n;
                root = n;
            }
            else
            {
                C->next = n;
                C = n;
            }
        }
        
        //after processing all if there is carry present then add it into list
        if(carry != 0)
        {
            ListNode* n = new ListNode(1);
            C->next = n;
        }
        
        return root;
    }
};
