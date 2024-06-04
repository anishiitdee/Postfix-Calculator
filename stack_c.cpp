#include "stack_c.h"
#include "list.h"
#include <stdexcept>
#include <cmath>
#include<iostream>
using namespace std;

Stack_C::Stack_C() {
    stk = new List();
    try {
        stk = new List();
    } catch (bad_alloc& e) {
        throw runtime_error("Out of Memory");
    }
}

Stack_C::~Stack_C() {
    delete stk;
}

void Stack_C::push(int data) {
    stk->insert(data);
}

int Stack_C::pop() {
    if (stk->get_size()==0){throw runtime_error("Empty Stack");}
    return stk->delete_tail();
}

int Stack_C::get_element_from_top(int idx) {
    int stackSize = stk->get_size();
    if (idx >= stackSize ) {
        throw runtime_error("Index out of range");
    }
    
    Node* node = stk->get_head()->next;
    int elementsToSkip = stackSize - 1 - idx;
    while(elementsToSkip--) {
        node = node->next;
    }
    
    return node->get_value();
}

int Stack_C::get_element_from_bottom(int idx) {
    if (idx >= stk->get_size() ) {
        throw runtime_error("Index out of range");
    }
    Node* node = stk->get_head()->next;
    while(idx--) {
        node = node->next;
    }
    return node->get_value();
}

void Stack_C::print_stack(bool top_or_bottom) {
    if (top_or_bottom) {
        Node* current = stk->get_head()->next;
        while (!current->is_sentinel_node()) {
            cout << current->get_value() << " ";
            current = current->next;
        }
    } else {
        Node* current = stk->get_head()->prev;
        while (!current->is_sentinel_node()) {
            cout << current->get_value() << " ";
            current = current->prev;
        }
    }
    cout << endl;
}


int Stack_C::add() {
    if (stk->get_size() < 2) {
        throw runtime_error("Not Enough Arguments");
    }
    int num2 = pop();
    int num1 = pop();
    push(num1 + num2);
    return (num1 + num2 );
}

int Stack_C::subtract() {
    if (stk->get_size() < 2) {
        throw runtime_error("Not Enough Arguments");
    }
    int num2 = pop();
    int num1 = pop();
    push(num1 - num2);
    return num1-num2;
}

int Stack_C::multiply() {
    if (stk->get_size() < 2) {
        throw std::runtime_error("Not Enough Arguments");
    }
    int num2 = pop();
    int num1 = pop();
    push(num1 * num2);
    return num1 * num2 ;
}

int Stack_C::divide() {
    if (stk->get_size() < 2) {
        throw runtime_error("Not Enough Arguments");
    }
    int num2 = pop();
    int num1 = pop();
    if (num2 == 0) {
        throw runtime_error("Divide by Zero Error");
    }
    push(floor(static_cast<double>(num1) / num2));
    return floor(static_cast<double>(num1) / num2) ;
}

List* Stack_C::get_stack() {
    return stk;
}

int Stack_C::get_size() {
    return stk->get_size();
}