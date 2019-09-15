#ifndef FORWARD_H
#define FORWARD_H

#include <vector>
#include "list.h"
#include <algorithm>
#include "iterators/forward_iterator.h"
using namespace std;
template <typename T>
class ForwardList : public List<T> {
public:
    ForwardList() : List<T>() {}

    T front() {
        if ( empty() ) { throw runtime_error("Empty list!"); }
        return this->head->data;
    }
    T back() {
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
        this->tail = temp;
        temp -> data = value;
        temp -> next = nullptr;
        this->nodes++;
    }

    void pop_front() {
        // Esto está mejor, no estás lanzando un throw
        if (!empty())
        {
            Node<T> *temp = this->head->next;
            delete this->head;
            this->head = temp;
            --this->nodes;
        }
    }

    void pop_back()
    {
        // En el caso del pop, no es tan necesario lanzar un throw. Esto es más útil cuando se retorna algo
        if ( empty() ) { throw runtime_error("Empty list!"); }
        else
        {
            Node<T> *temp = this->head;
            while (temp -> next != this->tail)
            {
                temp = temp -> next;
            }
            delete this-> tail;
            this -> tail = temp;
            this->tail->next = nullptr;
            --this->nodes;
        }
    }

    T operator[](int index) {
        // Debería ser mayor e igual a size()
        if (index > size())
            throw runtime_error("Empty list!");
        Node<T> *temp = this->head;
        int i=0;
        while(i<index)
        {
            temp = temp->next ;
            i++;
        }
        return temp->data ;
    }

    bool empty() {
        return (this -> nodes == 0 ? true:false);
    }

    int size() {
        return this->nodes;
    }

    void clear()
    {
        this->head->killSelf(this->nodes);
        this->nodes=0;
        this->head = nullptr;
        this->tail = nullptr;
    }

    void sort() {
        Node<T> *temp = this->head;
        std::vector<T> temp_content(size());
        for(int i = 0; i< size(); i++)
        {
            temp_content[i]=temp -> data;
            temp = temp -> next;
        }
        std::sort(temp_content.begin(), temp_content.end());
        temp= this -> head;
        for (int i = 0; i < size(); i++)
        {
            temp-> data = temp_content[i];
            temp = temp -> next;
        }
        temp_content.erase(temp_content.begin(), temp_content.end());
    }

    void reverse()
    {
        if (size() <= 1)
            return;
        else
            {
            Node<T> *prev_node = nullptr;
            Node<T> *next = nullptr;
            Node<T> *curr_node = this->head;
            while(curr_node != nullptr)
            {
                next = curr_node->next;
                curr_node -> next= prev_node;
                prev_node= curr_node;
                curr_node = next;
            }
            std::swap(this->head, this->tail);
        }
    }

    std::string name() {
        return "Forward List";
    }

    ForwardIterator<T> begin() {
        return ForwardIterator<T> (this->head);
    }

    ForwardIterator<T> end() {
        return ForwardIterator<T> (NULL);
    }
    void merge(ForwardList<T> &list)
    {
        // No es necesario, en un merge no interesa si la otra lista está vacía
        if (list.empty())
        {
            throw runtime_error("Empty list!");
        }
        if (this->nodes == 0)
        {
            this->head = list.head;
        }
        else
        {
            this->head->next = list.tail;
        }
        this->tail = list.tail;
        this->nodes += list.nodes;
    }

};

#endif