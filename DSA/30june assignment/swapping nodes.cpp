class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
         ListNode* node1= head;
          ListNode* node2= head;
          int i=1;
          ListNode* current= head;
          while(current->next!= nullptr){
            i++;
            current= current->next;
          }
          int j= i-k+1;
          while(--k){
            node1= node1->next;
          }
          while(--j){
            node2= node2->next;
          }
          swap(node1->val, node2->val);
         
          return head;
    }
};