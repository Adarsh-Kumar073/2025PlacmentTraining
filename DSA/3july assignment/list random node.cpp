class Solution {
public:
    ListNode* HeadNode;
    Solution(ListNode* head) {
       HeadNode = head;
    }
    int getRandom() {
        int res, len = 1;
        ListNode* list = HeadNode;
        while(list){
            if(rand() % len == 0){
                res = list->val;
            }
            len++;
            list = list->next;
        }
        return res;
    }
};