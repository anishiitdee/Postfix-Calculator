#include "stack_a.h"
#include <iostream>
#include <stdexcept>
#include<cmath>
using namespace std;
Stack_A::Stack_A() {
    size = 0;
}

void Stack_A::push(int data) {
    if (size >= 1024) {
        throw runtime_error("Stack Full");
    }
    stk[size++] = data;
}

int Stack_A::pop() {
    if (size == 0) {
        throw runtime_error("Empty Stack");
    }
    return stk[--size];
}

int Stack_A::get_element_from_top(int idx) {
    if (idx >= size || idx < 0) {
        throw runtime_error("Index out of range");
    }
    return stk[size - 1 - idx];
}

int Stack_A::get_element_from_bottom(int idx) {
    if (idx >= size || idx < 0) {
        throw runtime_error("Index out of range");
    }
    return stk[idx];
}

void Stack_A::print_stack(bool top_or_bottom) {
    if (top_or_bottom==1) {
        for (int i = 0; i <= size -1 ; ++i) {
            cout << stk[i] << endl;
        }
    } else {
        for (int i = 0; i < size; ++i) {
            cout << stk[size-i-1] << endl;
        }
    }
}

int Stack_A::add() {
    if (size < 2) {
        throw runtime_error("Not Enough Arguments");
    }
    int num2 = pop();
    int num1 = pop();
    push(num1 + num2);
    return stk[size - 1];
}

int Stack_A::subtract() {
    if (size < 2) {
        throw runtime_error("Not Enough Arguments");
    }
    int num2 = pop();
    int num1 = pop();
    push(num1 - num2);
    return stk[size - 1];
}

int Stack_A::multiply() {
    if (size < 2) {
        throw runtime_error("Not Enough Arguments");
    }
    int num2 = pop();
    int num1 = pop();
    push(num1 * num2);
    return stk[size - 1];
}

int Stack_A::divide() {
    if (size < 2) {
        throw runtime_error("Not Enough Arguments");
    }
    float num1 = pop();
    float num2 = pop();
    if (num1 == 0) {
        throw runtime_error("Divide by Zero Error");
    }
    
    push(floor(num2 / num1));
    return stk[size - 1];
}

int* Stack_A::get_stack() {
    return stk;
}

int Stack_A::get_size() {
    return size;
}