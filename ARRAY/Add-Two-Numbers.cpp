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
    void sum(ListNode* l1, ListNode* l2, ListNode* cur, int rem,
             ListNode* prev) {
        if (l1 == nullptr && l2 == nullptr && rem == 0) {
            if (rem == 0) {
                delete cur; //new unneeded node. so delete
                prev->next = nullptr; // as deleted new node. so prev.next should be null
                return;
            }
        }
        ListNode* newnode = new ListNode(); //new node to be used in next call
        cur->next = newnode; //used here
        newnode->next = nullptr;
        if (l1 == nullptr && l2 == nullptr && rem != 0) { //if l1,l2 finished but remaning is not 0

            cur->val = rem;
            rem = 0;
            sum(nullptr, nullptr, newnode, rem, cur);
        } else if (l1 == nullptr) {
            cur->val = (rem + l2->val) % 10;
            rem = (rem + l2->val) / 10;
            sum(nullptr, l2->next, newnode, rem, cur);
        } else if (l2 == nullptr) {
            cur->val = (rem + l1->val) % 10;
            rem = (rem + l1->val) / 10;
            sum(l1->next, nullptr, newnode, rem, cur);
        } else if (l1 != nullptr && l2 != nullptr) {
            cur->val = (rem + l1->val + l2->val) % 10;
            rem = (rem + l1->val + l2->val) / 10;
            sum(l1->next, l2->next, newnode, rem, cur);
        }
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode();
        ans->next = nullptr;
        sum(l1, l2, ans, 0, nullptr); //ans is the header of result list.
        return ans;
    }
};