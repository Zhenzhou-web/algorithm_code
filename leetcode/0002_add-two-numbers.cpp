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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *p=l1,*q=l2;
        int a=0,b=0;
        ListNode *l3=new ListNode(0);
        ListNode *m=l3;
        while(p!=nullptr||q!=nullptr||b!=0){
            if(p==nullptr && q==nullptr){
                // 只剩进位
                a = b % 10;
                b = b / 10;
            }
            else if(p==nullptr){
                a=(q->val+b)%10;
                b=(q->val+b)/10;
                q=q->next;
            }
            else if(q==nullptr){
                a=(p->val+b)%10;
                b=(p->val+b)/10;
                p=p->next;
            }
            else {
                a=(p->val+q->val+b)%10;
                b=(p->val+q->val+b)/10;
                p=p->next;
                q=q->next;
            }
            l3->next=new ListNode(a);
            l3=l3->next;
        }
        return m->next;
    }
};
