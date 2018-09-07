//
// Created by sebastian on 9/6/18.
//

#ifndef TYPE_TRAITS_DEVELOP_DLIST_H
#define TYPE_TRAITS_DEVELOP_DLIST_H



#include "iterator.h"
#include <iostream>
using namespace std;

template <typename T>
class DListIterator : public Iterator<T> {
public:
    DListIterator() : Iterator<T>() {};
    DListIterator(Node<T> *current) : Iterator<T>(current) {};
    DListIterator<T> operator++(){
        this->current= (this->current)->next;
    };
    DListIterator<T> operator--(){
        this->current= (this->current)->prev;
    };
};

template <typename Tr>
class DList {
public:
    typedef typename Tr::T T;
    typedef DListIterator<T> iterator;

private:
    Node<T>* head;
    Node<T>* tail;

public:
    DList() {
        head = tail = nullptr;
    };

    void push_front(T data) {
        auto *n2= new Node<T>(data);
        if (head== nullptr){
            n2->next= nullptr;
            n2->prev= nullptr;
            head= n2;
            tail=n2;
        }
        else{
            n2->next= head;
            head->prev= n2;
            n2->prev= nullptr;
            head= n2;
        }
    }

    void print(){
        auto temp=head;
        while (temp!= nullptr){
            cout << temp->data << endl;
            temp= temp->next;
        }

    }

    void push_back(T data) {
        auto *n2= new Node<T>(data);
        if (head== nullptr){
            n2->next= nullptr;
            n2->prev= nullptr;
            head= n2;
            tail= n2;
        }
        else{
            n2->prev= tail;
            tail->next= n2;
            n2->next= nullptr;
            tail= n2;
        }
    }

    void pop_front() {
        if (head== nullptr){
            cout << "Lista vacia" << endl;
        }
        else {
            auto temp = head;
            head = head->next;
            head->prev = nullptr;
            delete temp;
        }
    }
    void pop_back() {
        if (head== nullptr){
            cout << "Lista vacia" << endl;
        }
        else {
            auto temp = tail;
            tail = tail->prev;
            tail->next= nullptr;
            delete temp;
        }
    }

    iterator begin() {
        return iterator(head);
    }

    iterator end() {

        return iterator(tail);
    }

    ~DList() {
        if (head) {
            head->killSelf();
        }
    }
};


#endif //TYPE_TRAITS_DEVELOP_DLIST_H
