#include "Heap.hpp"
#include <iostream>
using namespace std;

// Konstruktor klasy Heap
Heap::Heap(int capacity) : capacity(capacity), size(0) {
    heapArray = new Node[capacity];
}

// Destruktor klasy Heap
Heap::~Heap() {
    delete[] heapArray;
}

// Metoda do wstawiania nowego elementu do kopca
void Heap::insert(int data, int priority) {
    if (size == capacity) {
        cout << "Kopiec jest pełny" << endl;
        return;
    }

    int index = size;
    size++;
    heapArray[index].data = data;
    heapArray[index].priority = priority;
    heapifyUp(index);
}

// Metoda pomocnicza do naprawiania kopca w górę (w kierunku korzenia)
void Heap::heapifyUp(int index) {
    while (index > 0 && heapArray[index].priority > heapArray[(index - 1) / 2].priority) {
        swap(heapArray[index], heapArray[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

// Metoda do usuwania i zwracania elementu o największym priorytecie
int Heap::extractMax() {
    if (size == 0) {
        cout << "Kopiec jest pusty" << endl;
        exit(1);
    }

    int maxData = heapArray[0].data;
    heapArray[0] = heapArray[size - 1];
    size--;
    heapifyDown(0);

    return maxData;
}

// Metoda pomocnicza do naprawiania kopca w dół (w kierunku liści)
void Heap::heapifyDown(int index) {
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;
    int maxIndex = index;

    if (leftChild < size && heapArray[leftChild].priority > heapArray[maxIndex].priority) {
        maxIndex = leftChild;
    }

    if (rightChild < size && heapArray[rightChild].priority > heapArray[maxIndex].priority) {
        maxIndex = rightChild;
    }

    if (maxIndex != index) {
        swap(heapArray[index], heapArray[maxIndex]);
        heapifyDown(maxIndex);
    }
}

// Metoda do zwracania elementu o najwyższym priorytecie
int Heap::peek() const {
    if (size == 0) {
        cout << "Kopiec jest pusty" << endl;
        exit(1);
    }

    return heapArray[0].data;
}

// Metoda do zmiany priorytetu elementu w kopcu
void Heap::modifyKey(int data, int newPriority) {
    for (int i = 0; i < size; i++) {
        if (heapArray[i].data == data) {
            int oldPriority = heapArray[i].priority;
            heapArray[i].priority = newPriority;

            if (newPriority > oldPriority) {
                heapifyUp(i);
            }
            else if (newPriority < oldPriority) {
                heapifyDown(i);
            }
            return;
        }
    }
    cout << "Nie znaleziono podanej wartości." << endl;
}

// Metoda zwracająca aktualny rozmiar kopca
int Heap::getSize() {
    return size;
}
