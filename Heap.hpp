#pragma once
#include "Node.hpp"

class Heap {
private:
    Node* heapArray; // Tablica przechowująca kopiec
    int capacity; // Pojemność kopca
    int size; // Aktualny rozmiar kopca

public:
    Heap(int capacity);
    ~Heap();

    void insert(int data, int priority);
    int extractMax();
    int peek() const;
    void modifyKey(int data, int newPriority);
    int getSize();

private:
    void heapifyUp(int index);
    void heapifyDown(int index);
};
