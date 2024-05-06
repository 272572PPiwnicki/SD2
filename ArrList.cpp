#include "ArrList.hpp"
using namespace std;

// Konstruktor klasy ArrList
ArrList::ArrList(int capacity) : capacity(capacity), size(0) {
	array = new Node[capacity];
}


// Destruktor klasy ArrList
ArrList::~ArrList()
{
	delete[] array;
}


//Metoda do dodania nowego elementu o określonym priorytecie
void ArrList::insert(int data, int priority)
{
	if (size == capacity)
	{
		cout << "Kolejka jest pełna" << endl;
		return;
	}

	int index = size;
	size++;
	array[index].data = data;
	array[index].priority = priority;


	//Naprawa kolejności po wstawieniu
	while (index > 0 and array[index].priority > array[index - 1].priority)
	{
		swap(array[index], array[index - 1]);
		index--;
	}
}

//Metoda do usuwania i zwracania elementu o najwyższym priorytecie
int ArrList::extractMax()
{
	if (size == 0) {
		cout << "Kolejka jest pusta" << endl;
		exit(1);;
	}

	int maxData = array[0].data;

	// Przesuwanie tablicy w dół
	for (int i = 1; i < size; i++) {
		array[i - 1].data = array[i].data;
	}
	size--;

	return maxData;
}


//Metoda do zwracania elementu o największym priorytecie
int ArrList::peek() const
{
	if (size == 0)
	{
		cout << "Kolejka jest pusta" << endl;
		exit(1);
	}

	return array[0].data;
}

//Metoda do zmiany priorytetu
void ArrList::modifyKey(int data, int newPriority) {
	for (int i = 0; i < size; i++) {
		if (array[i].data == data) {
			int oldPriority = array[i].priority;
			array[i].priority = newPriority;

			// Naprawa kolejności w kolejce po zmianie priorytetu
			if (newPriority > oldPriority) {
				int index = i;
				while (index > 0 && array[index].priority > array[(index - 1) / 2].priority) {
					swap(array[index], array[(index - 1) / 2]);
					index = (index - 1) / 2;
				}
			}
			else if (newPriority < oldPriority) {
				int index = i;
				while (index < size - 1 && array[index].priority < array[index + 1].priority) {
					swap(array[index], array[index + 1]);
					index++;
				}
			}
			return;
		}
	}
	cout << "Nie znaleziono podanej wartosci." << endl;
}

//Metoda zwracająca wielkość kolejki
int ArrList::getSize()
{
	return size;
}
