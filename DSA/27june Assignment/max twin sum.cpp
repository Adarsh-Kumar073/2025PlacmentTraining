class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = nullptr;
        
        while (curr != nullptr) {
            next = curr->next;  
            curr->next = prev; 
            prev = curr;       
            curr = next;
        }
        
        return prev; 
    }

    int pairSum(ListNode* head) {
        if(!head){
            return 0;
        }
        if(!head->next->next){
            return (head->val + head->next->val);
        }
        ListNode* temp= head;
        int i=1;
        while(temp->next!= nullptr){
            temp= temp->next;
            i++;
        }
        int j=i/2;
        temp= head;
        while(--j){
            temp= temp->next;
        }
        ListNode* head2= temp->next;
        temp->next= nullptr;
        ListNode* second =reverseList(head2);
         i=0;
         while(second!= nullptr){
            j= head->val + second->val;
            if(j>i){
                i=j;
            }
            head= head->next;
            second= second->next;
         }
     
        return i;
    }
};