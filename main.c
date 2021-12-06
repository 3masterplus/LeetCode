#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

Node *createNodeList(int max);

void displayNodeList(Node *head);

Node *deleteRepeatElement(Node *head);

int main() {

    Node *head = createNodeList(5);

    displayNodeList(head);

    head = deleteRepeatElement(head);

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

Node *deleteRepeatElement(Node *head) {

    if (!head) {
        return head;
    }
    Node *tmp = head;

    while (tmp->next != NULL) {
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