class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) {
            return head; 
        }
        
         int len=1;
        ListNode* tail=head;
      
        while(tail->next != NULL){
            tail=tail->next;
            len++;
        }
         if(k>len){
        k=k%len;
        if(k==0){
            return head;
        }

        }
        if(k <= len){
            k=len-k;
            if(k==0){
            return head;
        }
        }
     ListNode* current=head;
      int i=1;
      while(i<k && current!= nullptr){
        current= current->next;
        i++;
      }
      ListNode* temp= current->next;
      tail->next= head;
      current->next= nullptr;
      head= temp;

        return head;
    }
};