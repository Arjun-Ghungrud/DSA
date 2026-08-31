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
        if(!head || !head->next || !head->next->next){
            return {-1,-1};
        }
        ListNode*temp=head->next;
        ListNode*prev=head;
        vector<int>nums;
        int count=2;
        while(temp->next!=NULL){
            if(temp->val>prev->val && temp->val>temp->next->val)nums.push_back(count);
            else if(temp->val<prev->val && temp->val<temp->next->val)nums.push_back(count);
            prev=temp;
            temp=temp->next;
            count++;
        }
        if(nums.size()<2){
            return {-1,-1};
        }
        int n=nums.size();
        int maxval=nums[n-1]-nums[0];
        int minval=INT_MAX;
        for(int i=1;i<n;i++){
            int sub=nums[i]-nums[i-1];
            minval=min(minval,sub);
        }
        return {minval,maxval};
    }
};