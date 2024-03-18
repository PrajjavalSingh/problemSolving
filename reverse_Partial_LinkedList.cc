//https://leetcode.com/problems/reverse-linked-list-ii/

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

    // ListNode* reverse( ListNode* head )
    // {

    // }

    ListNode* reverseBetween(ListNode* head, int left, int right) 
    {
        if ( !head || !head->next )
            return head;
        
        int counter = 1;
        ListNode* h1 = head;
        ListNode* h2 = nullptr;
        while( counter != left )
        {
            counter++;
            h2 = h1;
            h1 = h1->next;
        }
        
        ListNode* first = h1;
        ListNode* second = h1->next;
        counter++;
        while( second && counter <= right )
        {
            ListNode* temp = second->next;
            second->next = first;
            first = second;
            second = temp;
            counter++;
        }

        if ( h2 )
            h2->next = first;
        else 
            head = first;

        if ( h1 )
            h1->next = second;

        
        return head;        
    }
};
