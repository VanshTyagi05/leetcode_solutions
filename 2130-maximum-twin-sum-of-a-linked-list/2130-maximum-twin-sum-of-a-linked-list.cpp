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
    int pairSum(ListNode* head) {
        vector<int>nodes;
        ListNode* temp=head;
        while(temp){
            nodes.push_back(temp->val);
            temp=temp->next;
        }
        int start=0;
        int end=nodes.size()-1;
        int maxsum=INT_MIN;
        while(start<end){
            maxsum=max(maxsum,nodes[start]+nodes[end]);
            start++;
            end--;

        }

        return maxsum;
    }
};