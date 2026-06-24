#include "double_linked_list.h"
#include <iostream>
#include <stdexcept> 

void DoubleLinkedList::init() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}

bool DoubleLinkedList::is_empty() {
    return size == 0;
}

void DoubleLinkedList::add_front(char val) {
    Node* ptr_new = new Node;
    ptr_new->data = val; 
    
    if (is_empty()) {
        head = tail = ptr_new;
        ptr_new->next = ptr_new;
        ptr_new->prev = ptr_new;
    } else {
        ptr_new->next = head;
        ptr_new->prev = tail;
        head->prev = ptr_new;
        tail->next = ptr_new;
        head = ptr_new;
    }
    size++;
}

void DoubleLinkedList::add_back(char val) {
    Node* ptr_new = new Node;
    ptr_new->data = val;
    
    if (is_empty()) {
        head = tail = ptr_new;
        ptr_new->next = ptr_new;
        ptr_new->prev = ptr_new;
    } else {
        ptr_new->prev = tail;
        ptr_new->next = head;
        tail->next = ptr_new;
        head->prev = ptr_new;
        tail = ptr_new;
    }
    size++;
}

void DoubleLinkedList::add_idx(char val, int idx) {
    if (idx < 0 || idx > size) return; 
    
    if (idx == 0) {
        add_front(val);
        return;
    }
    if (idx == size) {
        add_back(val);
        return;
    }
    
    Node* ptr_curr = head;
    for (int i = 0; i < idx - 1; i++) {
        ptr_curr = ptr_curr->next;
    }
    
    Node* ptr_new = new Node;
    ptr_new->data = val;
    
    ptr_new->next = ptr_curr->next;
    ptr_new->prev = ptr_curr;
    
    ptr_curr->next->prev = ptr_new;
    ptr_curr->next = ptr_new;
    size++;
}

void DoubleLinkedList::delete_front() {
    if (is_empty()) return; 
    
    Node* ptr_del = head;
    if (head == tail) { 
        head = tail = nullptr;
    } else {
        head = head->next;
        head->prev = tail; 
        tail->next = head; 
    }
    delete ptr_del;
    size--;
}

void DoubleLinkedList::delete_back() {
    if (is_empty()) return; 
    
    Node* ptr_del = tail;
    if (head == tail) { 
        head = tail = nullptr;
    } else {
        tail = tail->prev;
        tail->next = head; 
        head->prev = tail; 
    }
    delete ptr_del;
    size--;
}

void DoubleLinkedList::delete_idx(int idx) {
    if (idx < 0 || idx >= size || is_empty()) return; 
    
    if (idx == 0) {
        delete_front();
        return;
    }
    if (idx == size - 1) {
        delete_back();
        return;
    }
    
    Node* ptr_del = head;
    for (int i = 0; i < idx; i++) {
        ptr_del = ptr_del->next;
    }
    
    ptr_del->prev->next = ptr_del->next;
    ptr_del->next->prev = ptr_del->prev;
    
    delete ptr_del;
    size--;
}

void DoubleLinkedList::display() {
    if (is_empty()) return;
    
    Node* ptr_curr = head;
    do { 
        std::cout << ptr_curr->data << " ";
        ptr_curr = ptr_curr->next;
    } while (ptr_curr != head); 
    
    std::cout << "\n";
}

char DoubleLinkedList::get(int idx) {
    if (is_empty() || idx < 0 || idx >= size) {
        throw std::out_of_range("Index out of range"); 
    }
    Node* ptr_curr = head;
    for (int i = 0; i < idx; ++i) {
        ptr_curr = ptr_curr->next;
    }
    return ptr_curr->data;
}

void DoubleLinkedList::set(char val, int idx) {
    if (is_empty() || idx < 0 || idx >= size) {
        throw std::out_of_range("Index out of range"); 
    }
    Node* ptr_curr = head;
    for (int i = 0; i < idx; ++i) {
        ptr_curr = ptr_curr->next;
    }
    ptr_curr->data = val;
}

void DoubleLinkedList::clear() {
    if (is_empty()) return;
    
    Node* ptr_curr = head;
    do { 
        Node* ptr_next = ptr_curr->next;
        delete ptr_curr;
        ptr_curr = ptr_next;
    } while (ptr_curr != head); 
    
    head = tail = nullptr;
    size = 0;
}