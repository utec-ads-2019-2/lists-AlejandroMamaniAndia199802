#ifndef NODE_H
#define NODE_H

template <typename T>
struct Node
        {
    T data;
    Node<T>* next;
    Node<T>* prev;

    void killSelf(int count)
    {
        if (count > 1) next->killSelf(count-1);
        delete this;
    }
};

#endif