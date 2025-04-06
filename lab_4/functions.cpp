#include "header.h"
#include <iostream>

using namespace std;

Deququququque::Deququququque(int maxsize) : head(nullptr), tail(nullptr), currentSize(0), capacity(maxsize) {}

Deququququque::~Deququququque() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;
    currentSize = 0;
}

bool Deququququque::isEmpty() {
    return currentSize == 0;
}

bool Deququququque::isFull() {
    return currentSize == capacity;
}

void Deququququque::addFront(double num) {
    if (isFull()) {
        cout << "Дек полный." << endl;
        return;
    }
    Node* newNode = new Node(num);
    if (isEmpty()) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    currentSize++;
}

void Deququququque::addBack(double num) {
    if (isFull()) {
        cout << "Дек полный." << endl;
        return;
    }
    Node* newNode = new Node(num);
    if (isEmpty()) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    currentSize++;
}

void Deququququque::deleteFront() {
    if (isEmpty()) {
        cout << "Дек пустой." << endl;
        return;
    }
    Node* temp = head;
    head = head->next;
    if (head == nullptr) {
        tail = nullptr;
    } else {
        head->prev = nullptr;
    }
    delete temp;
    currentSize--;
}

void Deququququque::deleteBack() {
    if (isEmpty()) {
        cout << "Дек пустой." << endl;
        return;
    }
    Node* temp = tail;
    tail = tail->prev;
    if (tail == nullptr) {
        head = nullptr;
    } else {
        tail->next = nullptr;
    }
    delete temp;
    currentSize--;
}

void Deququququque::printALL() {
    if (isEmpty()) {
        cout << "Дек пустой." << endl;
        return;
    }
    cout << "Содержимое дека: nullptr <-> ";
    Node* current = head;
    while (current != nullptr) {
        cout << "[" << current->data << "]";
        if (current->next != nullptr) {
            cout << " <-> ";
        }
        current = current->next;
    }
    cout << " <-> nullptr" << endl;
}