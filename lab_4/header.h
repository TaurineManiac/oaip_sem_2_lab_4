#ifndef LAB_4_HEADER_H
#define LAB_4_HEADER_H

struct Node {
    double data;
    Node* prev;
    Node* next;

    Node(double value) : data(value), prev(nullptr), next(nullptr) {}
};

class Deququququque {
private:
    Node* head;
    Node* tail;
    int currentSize;
    int capacity;

public:
    Deququququque(int maxsize);
    ~Deququququque();

    bool isFull();
    bool isEmpty();

    void addFront(double num);
    void addBack(double num);
    void deleteFront();
    void deleteBack();
    void printALL();
};

#endif // LAB_4_HEADER_H