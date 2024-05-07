#include <iostream>
#include <fstream>
#include <chrono>
#include <cstdlib> // Dodano do uzycia funkcji exit()
#include "ArrList.hpp"
#include "Heap.hpp"

using namespace std;
using namespace std::chrono;

class Timer {
private:
    time_point<steady_clock> start_time;
    time_point<steady_clock> end_time;
public:
    void start() {
        start_time = steady_clock::now();
    }

    void stop() {
        end_time = steady_clock::now();
    }

    double elapsed_milliseconds() const {
        return duration<double, std::milli>(end_time - start_time).count();
    }
};

void run() {
    ArrList pq(1000000); // Utworzenie instancji klasy ArrList o pojemnosci 1000000

    Timer timer;
    int choice = 0;
    while (choice != 3) {
        cout << "Wybierz strukture dla kolejki priorytetowej:" << endl;
        cout << "1. Tablica dynamiczna" << endl;
        cout << "2. Kopiec" << endl;
        cout << "3. Wyjdz" << endl;

        cin >> choice;
        system("cls");
        switch (choice) {
        case 1: {
            Structure* wsk = &pq; // Utworzenie wskaznika do klasy ArrList
            int choice1 = 0;
            while (choice1 != 7) {
                cout << "1. Dodaj element e o priorytecie p" << endl;
                cout << "2. Usuniecie i zwrocenie elementu o najwiekszym priorytecie" << endl;
                cout << "3. Zwrocenie (podejrzenie) elementu o najwiekszym priorytecie" << endl;
                cout << "4. Zmiana priorytetu elementu e na p" << endl;
                cout << "5. Zwrocenie rozmiaru" << endl;
                cout << "6. Wyjdz" << endl;
                cout << "7. Wygenerowanie losowych liczb:" << endl;

                cin >> choice1;

                switch (choice1) {
                case 1: {
                    system("cls");
                    int data;
                    int priority;
                    cout << "Podaj element: ";
                    cin >> data;
                    cout << "Podaj priorytet: ";
                    cin >> priority;
                    timer.start();
                    wsk->insert(data, priority);
                    timer.stop();
                    cout << "Czas wykonania operacji: " << timer.elapsed_milliseconds() << " ms" << endl;
                    break;
                }
                case 2: {
                    system("cls");
                    timer.start();
                    wsk->extractMax();
                    timer.stop();
                    cout << "Czas wykonania operacji: " << timer.elapsed_milliseconds() << " ms" << endl;
                    break;
                }
                case 3: {
                    system("cls");
                    timer.start();
                    //wsk->peek();
                    timer.stop();
                    cout << "Czas wykonania operacji: " << timer.elapsed_milliseconds() << " ms" << endl;
                    break;
                }
                case 4: {
                    system("cls");
                    int data;
                    int newPriority;
                    cout << "Podaj element: ";
                    cin >> data;
                    cout << "Podaj nowy priorytet: ";
                    cin >> newPriority;
                    timer.start();
                    wsk->modifyKey(data, newPriority);
                    timer.stop();
                    cout << "Czas wykonania operacji: " << timer.elapsed_milliseconds() << " ms" << endl;
                    break;
                }
                case 5: {
                    system("cls");
                    timer.start();
                    wsk->getSize();
                    timer.stop();
                    cout << "Czas wykonania operacji: " << timer.elapsed_milliseconds() << " ms" << endl;
                    break;
                }
                case 6: {
                    system("cls");
                    break;
                }
                case 7: {
                    system("cls");
                    int dataCount;
                    cout << "Podaj liczbe danych do wygenerowania (od 1 do 1000000): ";
                    cin >> dataCount;
                    wsk->generateRandomNumbers(dataCount);
                    break;
                }
                }
            }
            break;
        }
        case 2: {
            Heap heap(1000000); // Utworzenie instancji klasy Heap o pojemności 1000000
            Structure* wsk = &heap; // Utworzenie wskaźnika do klasy Heap
            int choice1 = 0;
            while (choice1 != 7) {
                cout << "1. Dodaj element e o priorytecie p" << endl;
                cout << "2. Usuniecie i zwrocenie elementu o najwiekszym priorytecie" << endl;
                cout << "3. Zwrocenie (podejrzenie) elementu o najwiekszym priorytecie" << endl;
                cout << "4. Zmiana priorytetu elementu e na p" << endl;
                cout << "5. Zwrocenie rozmiaru" << endl;
                cout << "6. Wyjdz" << endl;
                cout << "7. Wygenerowanie losowych liczb:" << endl;

                cin >> choice1;

                switch (choice1) {
                case 1: {
                    system("cls");
                    int data;
                    int priority;
                    cout << "Podaj element: ";
                    cin >> data;
                    cout << "Podaj priorytet: ";
                    cin >> priority;
                    timer.start();
                    wsk->insert(data, priority);
                    timer.stop();
                    cout << "Czas wykonania operacji: " << timer.elapsed_milliseconds() << " ms" << endl;
                    break;
                }
                case 2: {
                    system("cls");
                    timer.start();
                    wsk->extractMax();
                    timer.stop();
                    cout << "Czas wykonania operacji: " << timer.elapsed_milliseconds() << " ms" << endl;
                    break;
                }
                case 3: {
                    system("cls");
                    timer.start();
                    wsk->peek();
                    timer.stop();
                    cout << "Czas wykonania operacji: " << timer.elapsed_milliseconds() << " ms" << endl;
                    break;
                }
                case 4: {
                    system("cls");
                    int data;
                    int newPriority;
                    cout << "Podaj element: ";
                    cin >> data;
                    cout << "Podaj nowy priorytet: ";
                    cin >> newPriority;
                    timer.start();
                    wsk->modifyKey(data, newPriority);
                    timer.stop();
                    cout << "Czas wykonania operacji: " << timer.elapsed_milliseconds() << " ms" << endl;
                    break;
                }
                case 5: {
                    system("cls");
                    timer.start();
                    wsk->getSize();
                    timer.stop();
                    cout << "Czas wykonania operacji: " << timer.elapsed_milliseconds() << " ms" << endl;
                    break;
                }
                case 6: {
                    system("cls");
                    break;
                }
                case 7: {
                    system("cls");
                    int dataCount;
                    cout << "Podaj liczbe danych do wygenerowania (od 1 do 1000000): ";
                    cin >> dataCount;
                    wsk->generateRandomNumbers(dataCount);
                    break;
                }
                }
            }
            break;
        }

        case 3: {
            return;
            break;
        }
        }
    }
}

int main() {
    run();
    return 0;
}
