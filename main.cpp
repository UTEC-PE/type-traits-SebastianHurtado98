#include <iostream>

#include <iostream>

#include "slist.h"
#include "dlist.h"

using namespace std;

void testSimpleLinkedList();
void testDoubleLinkedList();

template <typename T>
struct Greater {
    bool operator()(T a, T b) {
        return a >= b; // What would happend without the =?
    }
};

template <typename T>
struct Less {
    bool operator()(T a, T b) {
        return a <= b; // What would happend without the =?
    }
};

struct Integer {
    typedef int T;
    typedef Less<T> Operation;
};

struct Float {
    typedef float T;
    typedef Greater<T> Operation;
};

int main(int argc, char const *argv[]) {

    //Mis pruebas:
    /*
    SList<Integer> integers;
    SList<Float> floats;
    integers.insert(13);
    integers.insert(12);
    integers.insert(15);
    integers.insert(17);
    cout << endl;
    integers.print();
    floats.insert(12.3);
    floats.insert(13.02);
    floats.insert(14.3);
    floats.insert(13.3);
    floats.print();
    cout << endl;
    DList<Integer> numbers;
    numbers.push_front(10);
    numbers.push_front(112);
    numbers.push_front(1212);
    numbers.push_back(11);
    numbers.print();
    numbers.pop_front();
    numbers.pop_back();
    numbers.print();

     */

    testSimpleLinkedList();
    testDoubleLinkedList();




    cin.get();
    return EXIT_SUCCESS;
    }


void testSimpleLinkedList() {
    cout << "Simple Linked List" << endl;

    SList<Integer> integers;
    SList<Float> floats;

    SList<Integer>::iterator ite1;
    SList<Float>::iterator ite2;

    for (int i = 0; i < 5; i++) {
        integers.insert(2 * i + 1);
        floats.insert(20.f / (i + 1.f) + 2.f);
    }

    integers.remove(5);
    floats.remove(7);

    for (ite1 = integers.begin(); ite1 != integers.end(); ++ite1) {
        cout << *ite1 << " ";
    }
    cout << endl;

    for (ite2 = floats.begin(); ite2 != floats.end(); ++ite2) {
        cout << *ite2 << " ";
    }
    cout << endl << endl;
}




void testDoubleLinkedList() {
    cout << "Double Linked List" << endl;

    DList<Integer> integers;
    DList<Integer>::iterator ite;

    for (int i = 0; i < 5; i++) {
        integers.push_front(2 * i + 1);
    }

    ite = integers.begin();
    ++ite;
    cout << *ite << " ";
    ++ite;
    cout << *ite << " ";
    --ite;
    cout << *ite << " ";
    cout << endl << endl;
}