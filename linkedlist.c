#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int content;
    struct Node* next;
} Node;

typedef struct {
    Node* begin;
    Node* end;
} Linkedlist;

Node* NewNode(int value) {
    Node* new = NULL;
    new = (Node*)malloc(sizeof(Node));

    if (new != NULL) {
        new->content = value;
        new->next = NULL;
    }

    return new;
}

Linkedlist NewList(int firstValue) {
    Linkedlist list;
    Node* first = NewNode(firstValue);
    list.begin = first;
    list.end = first;

    return list;
}

void addToList(Linkedlist* list,int value, int last) {
    Node* node = NewNode(value);
    node->content = value;

    if (last) {
        node->next = NULL; 
        list->end->next = node;
        list->end = node; 
        return;
    }

    node->next = list->begin;
    list->begin = node;

}

void iterateList(Linkedlist list, int (*function)(int)) {
    Node* actual = list.begin;
    while (actual != NULL) {
        function(actual->content);
        actual = actual->next;
        // printf("%d", actual->content);
    }
}

int printValue(int n) { printf(" %d ", n); return n; }

int main() {

    int cedula[] = {3,0,4,6,5,2,1,5}; 
    int size = sizeof(cedula)/sizeof(int);

    Linkedlist list = NewList(cedula[0]);

    for (int i=1; i<size; i++) {
        addToList(&list, cedula[i], 1);
    }

    iterateList(list, &printValue);
}