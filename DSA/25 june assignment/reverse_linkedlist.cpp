class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next){
            return head;
        }
        ListNode* current= head;
         ListNode* prev= nullptr;
         ListNode* forward;
        while(current!= nullptr){
            forward = current->next;
            current->next= prev;
            prev= current;
            current= forward;
        }
    return prev;
        
    }
};