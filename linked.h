#ifndef LINKED_H
#define LINKED_H

#include <string>
#include <algorithm>
#include "list.h"
#include "node.h"
#include "iterators/bidirectional_iterator.h"
using namespace std;
template <typename T>
class LinkedList : public List<T> {
    public:
        LinkedList() : List<T>() {}

    T front() {
        if ( empty() ) { throw; }
        return this->head->data;
    }
    T back()
    {
        if ( empty() ) { throw; }
        return this->tail->data;
    }


    void push_front(T value)
    {
        Node<T> *tempNode = new Node<T>();
        if (empty())
        {
            this->head = tempNode;
            this->tail = tempNode;
        }
        else
        {
            tempNode->next = this->head;
            this->head->prev = tempNode;
            this->head = tempNode;
        }
        tempNode->data = value;
        ++this->nodes;
    }



    void push_back(T value)
    {
        Node<T> *tempNode = new Node<T>();
        if (empty())
        {
            this->head = tempNode;
            this->tail = tempNode;
        }
        else
        {
            this->tail->next = tempNode;
            tempNode->prev = this->tail;
            this->tail = tempNode;
        }
        tempNode->data = value;
        ++this->nodes;
    }

    void pop_front() {
        if (!empty())
        {
            Node<T> *tempNode = this->head->next;
            delete this->head;
            this->head = tempNode;
            this->head->prev = nullptr;
            --this->nodes;
        }
    }

    void pop_back()
    {
        if (!empty())
        {
            Node<T> *tempNode = this->tail->prev;
            delete this->tail;
            this->tail = tempNode;
            this->tail->next = nullptr;
            --this->nodes;
        }
    }

    T operator[](int index) {
        if (index > size())
            throw;
        Node<T> *tempNode = this->head;
        for (int i = 0; i < index; i++)
            tempNode = tempNode->next ;
        return tempNode->data ;
    }

    bool empty() {
        return (this->nodes == 0 ? true : false);
    }

    int size() {
        return this->nodes;
    }

    void clear() {
        this->head->killSelf(this->nodes);
        this->head = nullptr;
        this->tail = nullptr;
        this->nodes = 0;
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
    void reverse() {
        if (size() <= 1) return;
        Node<T> *prevNode = nullptr;
        Node<T> *currNode = this->head;
        Node<T> *tempNode;
        for (int i = 0; i < size(); i++)
        {
            tempNode= currNode -> next;
            currNode -> next = prevNode;
            currNode -> prev = tempNode;
            prevNode = currNode;
            currNode = tempNode;
        }
        std::swap(this->head, this->tail);
    }

    string name() {
        return "Linked List";
    }

    BidirectionalIterator<T> begin() {
        return BidirectionalIterator<T> (this->head);
    }

    BidirectionalIterator<T> end() {
        return BidirectionalIterator<T> (NULL);
    }

    void merge(LinkedList<T> &list) {
        if (list.empty()) return;
        if (size() == 0)
            this->head = list.head;
        else
        {
            this->tail->next = list.head;
            list.head->prev = this->tail;
        }
        this->tail = list.tail;
        this->nodes += list.nodes;
    }
};

#endif
