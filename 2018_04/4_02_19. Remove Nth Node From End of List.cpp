/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(n < 0) return nullptr;

        int nCount = 0;
        int listSize = 0;

        ListNode *ptrOne = head;
        ListNode *ptrTwo = head;

        while(ptrOne)
        {
            listSize++;
            ptrOne = ptrOne->next;
        }

        nCount = listSize - n;

        if(nCount==0) return head->next; // [1,2] -> [2]

        // gets a node one before to-be-deleted node
        for(int i = 0; i<nCount - 1; i++)
        {
            ptrTwo = ptrTwo->next;
        }

        // delete nth node
        ptrTwo->next = ptrTwo->next->next;
        //delete ptrTwo->next;

        return head;

    }
};