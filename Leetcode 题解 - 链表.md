# Leetcode 题解 - 链表

##   删除排序链表中的重复元素

83. Remove Duplicates from Sorted List (Easy)

 [力扣](https://leetcode-cn.com/problems/intersection-of-two-linked-lists/description/)

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

Node *createNodeList(int max);

void displayNodeList(Node *head);

Node *deleteRepeatElement(Node *head);

Node *deleteRepeatEle(Node *head);

int main() {

    Node *head = createNodeList(5);

    displayNodeList(head);

    head = deleteRepeatEle(head);

    printf("\n");
    printf("\n");
    displayNodeList(head);

    return 0;
}


Node *createNodeList(int max) {
    Node *head = (Node *) malloc(sizeof(Node));

    Node *p = head;

    for (int i = 1; i < max; i++) {
        Node *tmp = (Node *) malloc(sizeof(Node));
        if (i == 2) {
            tmp->data = 1;
        } else {
            tmp->data = i;
        }
        tmp->next = NULL;
        p->next = tmp;
        p = tmp;
    }
    return head;
}

void displayNodeList(Node *head) {
    Node *p = head->next;
    while (p != NULL) {
        printf("%d \n", p->data);
        p = p->next;
    }
}

/**
 * 直接法.
 *
 * @param head
 * @return
 */
Node *deleteRepeatElement(Node *head) {

    if (!head) {
        return head;
    }
    Node *tmp = head;

    while (tmp->next != NULL) {
        //如果当前节点的data部分等于下一节点的data部分,则说明是重复节点直接进行删除
        if (tmp->data == tmp->next->data) {
            Node *delete = tmp->next;
            tmp->next = tmp->next->next;
            free(delete);
        } else {
            tmp = tmp->next;
        }
    }
    return head;
}

/**
 * 递归的方式
 * @param head
 * @return
 */
Node *deleteRepeatEle(Node *head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    /* 删除挂接在头节点后面的更短的链表中的重复元素 */
    head->next = deleteRepeatEle(head->next);

    /* 原链表的头节点与后面挂接的更短的删除重复元素的链表的头节点值相同，
       则头节点也删除，否则将处理后的更短的链表挂在原链表的头节点的后面 */

    return head->data == head->next->data ? head->next : head;
}

```