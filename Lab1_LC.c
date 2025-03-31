/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode* temp = head;
    int count = 1;
    while (temp->next != NULL) {
        count++;
        temp = temp->next;
    }
    struct ListNode* temp1;
    struct ListNode* temp2 = head;
    if(count == n){
        head = temp2->next;
        return head;
    }
    for (int i = 0; i <(count - n - 1) && temp2->next != NULL; i++) {
        temp2 = temp2->next;
    }
    if (temp2->next == NULL) {
        head = NULL;
        return head;
    } else {
        temp1 = temp2->next;
        temp2->next = temp2->next->next;
        free(temp1);
        return head;
    }
}