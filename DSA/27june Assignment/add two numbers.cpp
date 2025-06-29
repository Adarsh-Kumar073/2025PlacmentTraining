class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1){
            return l2;
        }
        if(!l2){
            return l1;
        }
       
        ListNode* head= new ListNode(0);
        ListNode*prev= head;
        int carry=0;
        while(l1!= nullptr && l2!= nullptr){
            int i= (l1->val + l2->val)+ carry;
           if(i>=10){
            i=i%10;
            carry=1;
           }
           else{
            carry=0;
           }
           ListNode* temp= new ListNode(i);
           prev->next= temp;
           prev= temp;
            l1= l1->next;
            l2= l2->next;
        }
        while(l1!= nullptr){
             int i= (l1->val)+ carry;
           if(i>=10){
            i=i%10;
            carry=1;
           }
           else{
            carry=0;
           }
           ListNode* temp= new ListNode(i);
           prev->next= temp;
           prev= temp;
            l1= l1->next;
        }
        while(l2!= nullptr){
             int i= ( l2->val)+ carry;
           if(i>=10){
            i=i%10;
            carry=1;
           }
           else{
            carry=0;
           }
           ListNode* temp= new ListNode(i);
           prev->next= temp;
           prev= temp;
            l2= l2->next;
        }
        if(carry==1){
           ListNode* temp= new ListNode(carry);
           prev->next= temp;
           prev= temp;  
        }
        return head->next;
    }
};