/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *sortList(ListNode *head) {
    /*
    if (head == NULL || head->next == NULL) return head;
    ListNode *fast = head;
    ListNode *slow = head;
    while (fast->next != NULL &&
           fast->next->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }
    fast = slow->next;
    slow->next = NULL;
    ListNode *left = sortList(head);
    ListNode *right = sortList(fast);
    return merge(left, right);
    */
    if (head == NULL) return NULL;
    int len = 1;
    ListNode *cur = head;

    while ( (cur = cur->next) ) {
        len++;
    }

    ListNode* *nodeAdrr = new ListNode*[len];

    cur = head;
    for (int i = 0; i < len; i++) {
        nodeAdrr[i] = cur;
        cur = cur->next;
    }

    cur = partition(nodeAdrr, 0, len-1);
    delete []nodeAdrr;
    return cur;

    }

ListNode *partition(ListNode* *nodeAdrr, int begin, int end)
{
    if (begin >= end) return nodeAdrr[end];

    int mid = begin + (end - begin) / 2;

    nodeAdrr[mid]->next = NULL;
    ListNode *left = partition(nodeAdrr, begin, mid);
    ListNode *right = partition(nodeAdrr, mid+1, end);

    return merge(left, right);
}

ListNode* merge(ListNode *a, ListNode*b)
{
    ListNode head(0);
    ListNode *tail = &head;
    while ( a&&b ) {
        /* importance for stability */
        if (a->val <= b->val) {
            tail->next = a;
            a = a->next;
        } else {
            tail->next = b;
            b = b->next;
        }
        tail = tail->next;
    }
    tail->next = a ? a : b;
    return head.next;
}
};
