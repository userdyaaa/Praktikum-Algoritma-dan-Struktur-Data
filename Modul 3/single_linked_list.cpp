#include "single_linked_list.h"
#include <iostream>
#include <stdexcept>

void SingleLinkedList::init() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}

bool SingleLinkedList::is_empty() {
    return head == nullptr;
}

void SingleLinkedList::add_front(int val) {
    Node* ptr_new = new Node;
    ptr_new->data = val;
    ptr_new->next = nullptr;
    
    if (is_empty()) {
        head = tail = ptr_new;
        ptr_new->next = head;
    } else {
        ptr_new->next = head;
        tail->next = ptr_new;
        head = ptr_new;
    }
    size++;
}

void SingleLinkedList::add_back(int val) {
    Node* ptr_new = new Node;
    ptr_new->data = val;
    ptr_new->next = nullptr;
    
    if (is_empty()) {
        head = tail = ptr_new;
        ptr_new->next = head;
    } else {
        tail->next = ptr_new;
        ptr_new->next = head;
        tail = ptr_new;
    }
    size++;
}

void SingleLinkedList::add_idx(int val, int idx) {
    if (idx < 0 || idx > size) {
        throw std::out_of_range("Index out of range");
    }
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
    ptr_curr->next = ptr_new;
    size++;
}

void SingleLinkedList::delete_front() {
    if (is_empty()) {
        throw std::out_of_range("List is empty");
    }
    if (head == tail) {
        delete head;
        head = tail = nullptr;
    } else {
        Node* ptr_del = head;
        head = head->next;
        tail->next = head;
        delete ptr_del;
    }
    size--;
}

void SingleLinkedList::delete_back() {
    if (is_empty()) {
        throw std::out_of_range("List is empty");
    }
    if (head == tail) {
        delete head;
        head = tail = nullptr;
    } else {
        Node* ptr_curr = head;
        while (ptr_curr->next != tail) {
            ptr_curr = ptr_curr->next;
        }
        Node* ptr_del = tail;
        tail = ptr_curr;
        tail->next = head;
        delete ptr_del;
    }
    size--;
}

void SingleLinkedList::delete_idx(int idx) {
    if (is_empty()) {
        throw std::out_of_range("List is empty");
    }
    if (idx < 0 || idx >= size) {
        throw std::out_of_range("Index out of range");
    }
    if (idx == 0) {
        delete_front();
        return;
    }
    
    Node* ptr_curr = head;
    for (int i = 0; i < idx - 1; i++) {
        ptr_curr = ptr_curr->next;
    }
    
    if (ptr_curr->next == tail) {
        delete_back();
    } else {
        Node* ptr_del = ptr_curr->next;
        ptr_curr->next = ptr_del->next;
        delete ptr_del;
        size--;
    }
}

void SingleLinkedList::display() {
    if (is_empty()) return;
    Node* ptr_curr = head;
    do {
        std::cout << ptr_curr->data << " ";
        ptr_curr = ptr_curr->next;
    } while (ptr_curr != head);
    std::cout << "\n";
}

int SingleLinkedList::get(int idx) {
    if (is_empty()) {
        throw std::out_of_range("List is empty");
    }
    if (idx < 0 || idx >= size) {
        throw std::out_of_range("Index out of range");
    }
    Node* ptr_curr = head;
    for (int i = 0; i < idx; ++i) {
        ptr_curr = ptr_curr->next;
    }
    return ptr_curr->data;
}

void SingleLinkedList::set(int val, int idx) {
    if (is_empty()) {
        throw std::out_of_range("List is empty");
    }
    if (idx < 0 || idx >= size) {
        throw std::out_of_range("Index out of range");
    }
    Node* ptr_curr = head;
    for (int i = 0; i < idx; ++i) {
        ptr_curr = ptr_curr->next;
    }
    ptr_curr->data = val;
}

void SingleLinkedList::clear() {
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