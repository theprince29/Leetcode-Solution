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
    void push(ListNode** headr,int new_data)
    {
        ListNode* new_node = new ListNode(new_data);
        new_node->next = (*headr);
        (*headr) = new_node;
    }
    
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        vector<int>v;
        
        while(list1 != NULL)
        {
            v.push_back(list1->val);
            list1 =list1->next;
        }
        while(list2 != NULL)
        {
            v.push_back(list2->val);
            list2 =list2->next;
        }
        
        ListNode* head=NULL;
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        for(int i =0 ;i<v.size();i++)
        {
            push(&head,v[i]);
        }
        
        return head;
    }
};