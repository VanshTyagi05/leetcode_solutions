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
    ListNode* deleteMiddle(ListNode* head) {
         int totalnodes=0;
        
        ListNode *temp=head;
        while(temp){
            totalnodes++;
            temp=temp->next;
        }
        if(totalnodes==1){
         return NULL;
        }
        int x=totalnodes/2;
       
        ListNode *curr=head;
        ListNode *prev=NULL;
         while(x>0){
            prev=curr;
            curr=curr->next;
            x--;}
       // deleting this curr node
    //    if(prev->next!=NULL){
    //     prev->next=curr->next;
    //    }
     prev->next=curr->next;
     delete curr;

     return head;

    }
};