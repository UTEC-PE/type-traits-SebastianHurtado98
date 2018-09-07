//
// Created by sebastian on 9/6/18.
//

#ifndef TYPE_TRAITS_DEVELOP_ITERATOR_H
#define TYPE_TRAITS_DEVELOP_ITERATOR_H
#include "node.h"

template <typename T>
class Iterator {
protected:
    Node<T>* current;

public:
    Iterator() : current(nullptr) {};
    Iterator(Node<T>* current) : current(current) {};

    Iterator<T> operator=(Iterator<T> other){
        current= other.current;
        return other;
    };
    bool operator!=(Iterator<T> other){
        return current!=other.current;
    };
    T operator*(){
        return current->data;
    };
};
#endif //TYPE_TRAITS_DEVELOP_ITERATOR_H
