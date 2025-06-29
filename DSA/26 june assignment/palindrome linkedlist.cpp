class Solution {
public:
   ListNode* reverse( ListNode* &head){
    if(!head || !head->next){
        return head;
    }
    ListNode* curr= head;
    ListNode* prev= nullptr;
    ListNode* forward;
    while(curr!=nullptr){
        forward = curr->next;
        curr->next= prev;
        prev= curr;
        curr= forward;

    }
    return prev;
   }
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next){
            return true;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next!=nullptr && fast->next->next!= nullptr){
            slow = slow->next;
            fast= fast->next->next;

        }
        ListNode* l2= slow->next;
        slow->next= nullptr;
        ListNode* head2=reverse(l2);
        while(head2!= nullptr){
            if(head->val!= head2->val){
                return false;
            }
            head= head->next;
            head2= head2->next;

        }
        
        return true;
        
    }
};