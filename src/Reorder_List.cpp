
class Solution
{
public:
    /*************************************
    void reorderList(ListNode *head) {
        ListNode *prev = head;
        ListNode *cur = head;
        int len = 0;
        for ( ; cur != nullptr; len++, cur = cur->next );
        if (len < 2) return;
        ListNode* *addrArr = new ListNode*[len];
        for ( len = 0, cur = head; cur != nullptr; len++, cur = cur->next) {
            addrArr[len] = cur;
        }
        int begin = 0;
        int end = len - 1;
        while ( begin < end ) {
            prev->next = addrArr[end];
            addrArr[end]->next = addrArr[++begin];
            if (begin == end) {
                addrArr[end]->next = nullptr;
                break;
            }
            addrArr[--end]->next = nullptr;
            prev = addrArr[begin];
        }
    }
    ***********************************/
    void reorderList(ListNode *head)
    {
        if ( head == nullptr ) return;
        ListNode *slow = head;
        ListNode *fast = head;
        while ( fast && fast->next ) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *mid = slow->next;
        slow->next = nullptr;
        ListNode *right = reverseList( mid );
        ListNode *left = head;
        ListNode *tmp;
        while ( left && right ) {
            mid = left->next;
            left->next = right;
            tmp = right->next;
            right->next = mid;
            right = tmp;
            left = mid;
        }

    }

    ListNode* reverseList(ListNode *head)
    {
        if ( head == nullptr ) return nullptr;
        ListNode buf(0);
        ListNode *prev = &buf;
        ListNode *cur = head;
        ListNode *tmp;
        while ( cur ) {
            tmp = cur;
            cur = cur->next;
            tmp->next = prev->next;
            prev->next = tmp;
        }
        return prev->next;
    }
};
