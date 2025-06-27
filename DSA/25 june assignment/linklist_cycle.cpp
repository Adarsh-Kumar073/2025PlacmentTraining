class Solution {
public:
    bool hasCycle(ListNode *head) {
        if( head== nullptr || head->next== nullptr ){
            return false;
        }
        ListNode* temp1= head;
        ListNode* temp2= head->next;
       while(temp2!= nullptr &&temp2->next!=nullptr ){
       if (temp1 == temp2) {
                return true;
            }
            temp1 = temp1->next;
            temp2 = temp2->next->next;
       }
      return false; 
    }
};