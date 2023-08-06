#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

void reverseList(struct ListNode** head) {
    struct ListNode* prev = NULL;
    struct ListNode* current = *head;
    struct ListNode* next;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;
}

bool isPalindrome(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return true;
    }

    struct ListNode* slow = head;
    struct ListNode* fast = head;

    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    struct ListNode* secondHalf = slow->next;
    reverseList(&secondHalf);

    struct ListNode* p1 = head;
    struct ListNode* p2 = secondHalf;

    while (p2 != NULL) {
        if (p1->val != p2->val) {
            reverseList(&secondHalf);
            return false;
        }
        p1 = p1->next;
        p2 = p2->next;
    }
    reverseList(&secondHalf);
    return true;
}

void freeList(struct ListNode* head) {
    struct ListNode* current = head;
    while (current != NULL) {
        struct ListNode* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    struct ListNode* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(2);
    head->next->next->next->next = createNode(1);

    if (isPalindrome(head)) {
        printf("The linked list is a palindrome.\n");
    } else {
        printf("The linked list is NOT a palindrome.\n");
    }

    freeList(head);

    return 0;
}
