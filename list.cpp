#include "list.h"
#include "node.h"
List::List() : size(0) {
    sentinel_head = new Node(true);
    sentinel_tail = new Node(true);
    sentinel_head->next = sentinel_tail;
    sentinel_tail->prev = sentinel_head;
}

List::~List() {
    while (size > 0) {
        delete_tail();
    }
    delete sentinel_head;
    delete sentinel_tail;
}

void List::insert(int v) {
    Node* newNode = new Node(v, sentinel_tail, sentinel_tail->prev);
    sentinel_tail->prev->next = newNode;
    sentinel_tail->prev = newNode;
    size++;
}

int List::delete_tail() {
    if (size == 0) {
        return 0; 
    }
    Node* lastNode = sentinel_tail->prev;
    int value = lastNode->get_value();
    lastNode->prev->next = sentinel_tail;
    sentinel_tail->prev = lastNode->prev;
    delete lastNode;
    size--;
    return value;
}

int List::get_size() {
    return size;
}

Node* List::get_head() {
    return sentinel_head;
}
