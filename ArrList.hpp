#pragma once
#include <iostream>
#include "Node.hpp"
using namespace std;

class ArrList {
private:
    Node* array; //Tablica przechowująca elementy
    int size; // Aktualny rozmiar kolejki
    int capacity; // Pojemność tablicy

public:
    ArrList(int capacity);
    ~ArrList();

    void insert(int data, int priority);
    int extractMax();
    int peek() const;
    void modifyKey(int data, int newPriority);
    int getSize();

};