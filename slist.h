//
// Created by sebastian on 9/6/18.
//

#ifndef TYPE_TRAITS_DEVELOP_SLIST_H
#define TYPE_TRAITS_DEVELOP_SLIST_H

#include "iterator.h"
#include <iostream>
using namespace std;

template <class T>
class SListIterator : public Iterator<T> {
public:
    SListIterator() : Iterator<T>() {};
    SListIterator(Node<T> *current) : Iterator<T>(current) {};
    SListIterator<T> operator++(){
        this->current= (this->current)->next;
    };
};

template <typename Tr>
class SList {
public:
    typedef typename Tr::T T;
    typedef typename Tr::Operation Operation;
    typedef SListIterator<T> iterator;

private:
    Node<T>* head;
    Operation cmp;

public:
    SList() {
        head = nullptr;
    };

    bool find(T search, Node<T> **&pointer) {
        //Desktop/linkedList tiene la respuesta correcta
        if (head== nullptr){
            cout << "La lista está vacía." << endl;
            return false;
        }
        else {
            while ((*pointer) != nullptr) //podria haber problema por null
            {
                if (cmp(search, (*pointer)->data)) {
                    if (search == (*pointer)->data) { return true; } //lo encontramos
                    else { pointer = &((*pointer)->next); }

                } else {
                    return false;
                }
            };
            return false; //no lo encontramos, pero tenemos un puntero al next según el operation
        }
    }

    bool insert(T data) {

        if(head== nullptr){
            auto *n2= new Node<T>(data);
            n2->next= nullptr;
            head= n2;
            return true;
        }
        else {
            //True si puede, false si ya estaba el elemento ahí
            Node<T> **n = &head; //solo para crear puntero a puntero a nodo.
            if (find(data, n)) {
                return false;
            } else {
                auto *n2 = new Node<T>(data);
                n2->next = (*n);
                *n = n2;
                return true;
            }
        }

    }




    bool remove(T item) {
        if(head== nullptr){
            cout << "La lista está vacía" << endl;
            return false;
        }
        else {
            auto *n = &head;
            if (find(item, n)) {
                auto temp = (*n);
                (*n) = (*n)->next;
                delete temp;
                return true;
            } else {

                cout << "no se encontró el elemento";
                return false;
            }
        }

    }
    void print(){
        if (head== nullptr){
            cout << "Esta lista está vacía";
        }
        else{
            cout << endl;
            iterator it, it2;
            it= begin();
            it2= end();

            while(it!=it2){
                cout << *it << endl; ++it;
            }
            cout <<*it << endl;
        }

    }

    iterator begin() {
        return iterator(head);
    }

    iterator end() {
        auto temp=head;

        while ((temp->next)!= nullptr){
            temp=temp->next;
        }
        return iterator(temp);
    }

    ~SList() {
        if (head) {
            head->killSelf();
        }
    }

};

#endif //TYPE_TRAITS_DEVELOP_SLIST_H
