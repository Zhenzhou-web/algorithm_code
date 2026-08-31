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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> res={-1,-1};
        vector<int> critical;
        ListNode *q = head;
        ListNode *p = head->next;
        ListNode *m = p->next;

        int pos = 1;
        while(m != nullptr){
            bool isCritical = ( (p->val < m->val && p->val < q->val) || (p->val > m->val && p->val > q->val) );
            if(isCritical){
                critical.push_back(pos);
            }
            q = p;
            p = m;
            m = m->next;
            pos++;
        }
        if(critical.size() < 2){
            return res;
        }
        int minlen = INT_MAX;
        for(int i = 1; i < critical.size(); i++){
            minlen = min(minlen, critical[i] - critical[i-1]);
        }
        int maxlen = critical.back() - critical[0];

        res[0] = minlen;
        res[1] = maxlen;
        return res;
    }
};
