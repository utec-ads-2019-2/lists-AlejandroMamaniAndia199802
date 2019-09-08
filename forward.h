#ifndef FORWARD_H
#define FORWARD_H

#include "list.h"
#include "iterators/forward_iterator.h"

template <typename T>
class ForwardList : public List<T>
        {
    public:
        ForwardList() : List<T>() {}

        T front( )
        {
            if ( empty() ) { throw runtime_error("Empty list!"); }
            return this->head->data;
        }

        T back()
        {
            if ( empty() ) { throw runtime_error("Empty list!"); }
            return this->tail->data;
        }

        void push_front(T value) {
            Node<T> *temp = new Node<T>;
            if ( empty() )
            {
                this -> head = temp;
                this -> tail = temp;
                temp -> next = nullptr;
            }
            else
                {

                    temp -> next = this -> head;
                    this-> head = temp;
            }
            temp -> data = value;
            this->nodes++;

        }

        void push_back(T value) {
            Node<T> *temp = new Node<T>;
            if ( empty() )
            {
                this -> head = temp;
                this -> tail = temp;
                temp -> next = nullptr;
            }
            else
            {

                temp -> next = this -> tail;
                this -> tail = temp;
            }
            temp -> data = value;
            this->nodes++;



        }

        void pop_front() {
            if ( empty() ) { throw runtime_error("Empty list!"); }
            else{
                Node<T> *temp;
                temp = this->head;
                this ->head  = this->head ->next;
                delete temp;
                --this->nodes;
            }

        }

        void pop_back() {
            if ( empty() ) { throw runtime_error("Empty list!"); }
            Node<T> *temp;
            temp = this->tail;

        }

        T operator[](int index) {
            // TODO
        }

        bool empty() {
            if (this->head== nullptr)
            {
                return true;
            }
            return false;
        }

        int size() {

        }

        void clear() {
            Node<T>* temp;
            while (this->head != nullptr) {
                temp = this->head->next;
                delete this->head;
                this->head = temp;
            }
            this->head = NULL;
            this->tail = NULL;
        }

        void sort() {
            // TODO
        }
    
        void reverse() {
            // TODO
        }

        string name() {
            return "Forward List";
        }

        ForwardIterator<T> begin() {
            // TODO
        }

	    ForwardIterator<T> end() {
            // TODO
        }

        void merge(ForwardList<T> list) {
            // TODO
        }
};

#endif