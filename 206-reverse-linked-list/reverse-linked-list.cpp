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
    ListNode *prev,*n;
    ListNode* rec(ListNode *curr){
      if(curr==NULL) return prev;
      else{
        n=curr->next;
        curr->next=prev;
        prev=curr;
        curr=n;
       // n->next=prev;
        return rec(curr);
        
      }
    }
public:
    ListNode* reverseList(ListNode* head) {
        prev=NULL;
        return rec(head);
    }
};