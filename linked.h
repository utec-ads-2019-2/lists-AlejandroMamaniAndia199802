#ifndef LINKED_H
#define LINKED_H

#include "list.h"
#include "node.h"
#include "iterators/bidirectional_iterator.h"

template <typename T>
class LinkedList : public List<T> {
    public:
        LinkedList() : List<T>() {}

        T front()
        {
            return this->head->data;

        }

        T back( )
        {
            return this->tail->data;
        }

        void push_front(T value)
        {
            Node<T> temp;
            temp->data=value;
            temp->next=this->head;
            this->head=temp;
        }

        void push_back(T value)
        {
            Node<T> temp;
            temp->data=value;
            temp->next=this->tail;
            this->tail=temp;
        }

        void pop_front()
        {
            Node<T> temp;
            this-> head = temp;
            this ->head = this->head->next;
            delete temp;
        }

        void pop_back()
        {
            if(empty()= true)
            {
                this->head= nullptr;
                this->tail= nullptr;
            }
            else{
                    Node<T> temp;
                    this-> tail = temp;
                    this ->tail = this->tail->previous;
                    this->tail-> next = nullptr;
                    delete temp;
            }
        }

        T operator[](int index)
        {

        }

        bool empty()
        {
            return !(this->head->data);
        }

        int size()
        {
<<<<<<< HEAD
            Node<T> *current;
            Node<T> *previous;
            current=this->head;
=======
            Node<T> *current=this->head;
>>>>>>> 1505a097c2daea5b951d6758d9e56851492aa2e0
            int cont = 0;
            while(current!=NULL)
            {
                current=current->next;
                cont++;
            }
           return cont;
        }

        void clear()
        {
            // TODO
        }

        void sort()
        {
            // TODO
        }
    
        void reverse()
        {
            // TODO
        }

        string name()
        {
            return "Linked List";
        }

        BidirectionalIterator<T> begin() {
            // TODO
        }

	    BidirectionalIterator<T> end() {
            // TODO
        }

        void merge(LinkedList<T> list) {
            // TODO
        }
};

#endif
