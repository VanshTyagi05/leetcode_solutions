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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>nums;
        ListNode* temp=head;
        while(temp){
            nums.push_back(temp->val);
            temp=temp->next;
        }

        int n=nums.size();
        vector<int>critical;
        for(int i=1;i<n-1;i++){
            if((nums[i]>nums[i-1] && nums[i]>nums[i+1])  || (nums[i]<nums[i-1] && nums[i]<nums[i+1]) ){
                critical.push_back(i);
            }
        }
        int size=critical.size();
        if(size<2)return {-1,-1};
        int max_distance=critical[size-1]-critical[0];
        // for min distance we can iterate over the critical comparing the minimum distance
        int min_distance=INT_MAX;
        for(int i=0;i<size-1;i++){
            min_distance=min(min_distance,critical[i+1]-critical[i]);
        }

        return {min_distance,max_distance};

    }
};