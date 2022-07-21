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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* pointer = head;
        ListNode* r = NULL;
        ListNode* l = NULL;
        ListNode* first = NULL;
        ListNode* subpre = NULL;
        int index =0;
        while(pointer!=NULL){
            index++;
            if(index == left-1) l = pointer;
            if(index == left ){
                first = pointer;
                subpre = pointer;
            }
            if(index > left && index < right){
                (*pointer).next = subpre;
                subpre = pointer;
            }
            if(index == right){
                (*l).next = pointer;
            }
            if(index == right + 1){
                (*first).next = pointer;
                break;
            }
            pointer = (*pointer).next;
        }
        return head;
    }
};
