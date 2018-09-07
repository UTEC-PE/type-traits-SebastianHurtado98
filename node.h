//
// Created by sebastian on 9/6/18.
//

#ifndef TYPE_TRAITS_DEVELOP_NODE_H
#define TYPE_TRAITS_DEVELOP_NODE_H

template <typename T>
struct Node {
    T data;
    Node<T>* next;
    Node<T>* prev;

    Node(T data) : data(data) {
        next = prev = nullptr;
    };

    void killSelf();
};

template <typename T>
void Node<T>::killSelf() {
    if (next) {
        next->killSelf();
    }

    delete this;
}
#endif //TYPE_TRAITS_DEVELOP_NODE_H
