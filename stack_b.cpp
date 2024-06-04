#include "stack_b.h"
#include <stdexcept>
#include <iostream>
using namespace std;
Stack_B::Stack_B() {
    size = 0;
    capacity = 1024;
    stk = new int[capacity];
    try {
        stk = new int[capacity];
    } catch (bad_alloc& e) {
        throw runtime_error("Out of Memory");
    }
}

Stack_B::~Stack_B() {
    delete[] stk;
}

void Stack_B::push(int data) {
    if (size >= capacity) {
        capacity *= 2;
        try{int* newStk = new int[capacity];
        for (int i = 0; i < size; ++i) {
            newStk[i] = stk[i];
        }
        delete[] stk;
        stk = newStk;} catch(bad_alloc& e) {
            throw runtime_error("Out of Memory");
        }

    }
    stk[size++] = data;
}

int Stack_B::pop() {
    if (size == 0) {
        throw runtime_error("Empty Stack");
    }
    int popped = stk[--size];
    if (size <= capacity / 4 && capacity > 1024) {
        capacity /= 2;
        int* newStk = new int[capacity];
        for (int i = 0; i < size; ++i) {
            newStk[i] = stk[i];
        }
        delete[] stk;
        stk = newStk;
    }

    return popped;
}

int Stack_B::get_element_from_top(int idx) {
    if (idx >= size || idx < 0) {
        throw runtime_error("Index out of range");
    }
    return stk[size - 1 - idx];
}

int Stack_B::get_element_from_bottom(int idx) {
    if (idx >= size || idx < 0) {
        throw runtime_error("Index out of range");
    }
    return stk[idx];
}

void Stack_B::print_stack(bool top_or_bottom) {
    if (top_or_bottom==1) {
        if (size == 0) {
            cout << "Stack is empty." << endl;
        } else {
            cout << "Stack from the top:" << endl;
            for (int i = 0; i <size; ++i) {
                cout << stk[i] << endl;
            }
        }
    } else {
        if (size == 0) {
            cout << "Stack is empty." << endl;
        } else {
            cout << "Stack from the bottom:" << endl;
            for (int i = 0; i < size; ++i) {
                cout << stk[size-i-1] << endl;
            }
        }
    }
}

int Stack_B::add() {
    if (size < 2) {
        throw runtime_error("Not Enough Arguments");
    }
    float num2 = pop();
    float num1 = pop();
    push(num1 + num2);
    return stk[size - 1];
}

int Stack_B::subtract() {
    if (size < 2) {
        throw runtime_error("Not Enough Arguments");
    }
    float num2 = pop();
    float num1 = pop();
    push(num1 - num2);
    return stk[size - 1];
}

int Stack_B::multiply() {
    if (size < 2) {
        throw runtime_error("Not Enough Arguments");
    }
    float num2 = pop();
    float num1 = pop();
    push(num1 * num2);
    return stk[size - 1];
}

int Stack_B::divide() {
    if (size < 2) {
        throw runtime_error("Not Enough Arguments");
    }
    float num2 = pop();
    float num1 = pop();
    if (num2 == 0) {
        throw runtime_error("Divide by Zero Error");
    }
    if (num1/num2 < 0){
        push(num1/num2 -1);
    } else{
        push(num1 / num2);
    }
    
    return stk[size - 1];
}

int* Stack_B::get_stack() {
    return stk;
}

int Stack_B::get_size() {
    return size;
}
