#pragma once
#include <iostream>
#include "Node.hpp"
using namespace std;

class ArrList {
private:
    Node* array; //Tablica przechowuj�ca elementy
    int size; // Aktualny rozmiar kolejki
    int capacity; // Pojemno�� tablicy

public:
    ArrList(int capacity);
    ~ArrList();

    void insert(int data, int priority);
    int extractMax();
    int peek() const;
    void modifyKey(int data, int newPriority);
    int getSize();

};