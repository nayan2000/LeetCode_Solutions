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
    int length(ListNode* A){
        int count = 0;
        while(A != NULL){
            count++;
            A = A -> next;
        }
        return count;
    }
    ListNode* rotateRight(ListNode* A, int k) {
        if(!A) return A;

        int len = length(A);
        if(k > len) k = k % len;
        if(k == 0 || k == len) return A;
        
        ListNode* prev = NULL, *temp1 = A, *temp2 = A;
        int travel = len - k;
        while(travel--){
            prev = temp1;
            temp1 = temp1 -> next;
        }
        prev -> next = NULL;

        A = temp1;
        while(temp1 -> next != NULL)
            temp1 = temp1 -> next;
        temp1 -> next = temp2;

        return A;
        
    }
};