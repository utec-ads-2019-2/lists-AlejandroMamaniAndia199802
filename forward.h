#ifndef FORWARD_H
#define FORWARD_H

#include <vector>
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
                this-> tail-> next = temp;
            }
            temp -> data = value;
            this->nodes++;
        }

        void pop_front() {
            if ( empty() ) { throw runtime_error("Empty list!"); }
            else
                {
                Node<T> *temp;
                temp = this->head;
                this ->head  = this->head ->next;
                delete temp;
                --this->nodes;
            }

        }

        void pop_back() {
            if ( empty() ) { throw runtime_error("Empty list!"); }
            else
                {
                Node<T> *temp = this -> head;
                while (temp -> next != this->tail)
                {
                    temp = temp -> next;
                }
                delete this -> tail;
                this -> tail -> next = nullptr;
                this -> nodes--;
            }
        }

        T operator[](int index)
        {
            if (index > size()) { throw runtime_error("Empty list!"); }
            else
                {
                Node<T> *temp;
                temp = this->head;
                int i = 0;
                while (i <= index)
                {
                    temp = temp->next;
                    i++;
                }
                return temp->data;
            }
        }

        bool empty() {
            return (this -> nodes == 0 ? true:false);
        }

        int size()
        {
            return this -> nodes;
        }

        void clear()
        {
            this -> nodes = 0;
           this -> head -> killSelf(this-> nodes);
           this -> head = nullptr;
           this -> tail = nullptr;

        }

        void sort()
        {
           Node<T> *temp = this -> head;
           std::vector<T> temp_content;
           temp_content.size()=size();
           for(int i = 0; i< size(); i++)
           {
               temp_content[i]=temp -> data;
               temp = temp -> next;
           }
           sort(temp_content.begin(), temp_content.end());
           temp= this -> head;
            for (int i = 0; i < size(); i++)
            {
                temp-> data = temp_content[i];
                temp = temp -> next;
            }
            delete[] temp_content;
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