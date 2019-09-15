#ifndef FORWARD_ITERATOR_H
#define FORWARD_ITERATOR_H

#include "../iterator.h"

template <typename T>
class ForwardIterator : public Iterator<T> {
public:
    ForwardIterator() : Iterator<T>() {};
    ForwardIterator(Node<T> *node) : Iterator<T>(node) {};

    ForwardIterator<T> operator=(ForwardIterator<T> other) {
        // En general aquí deberías retornar *this;
        return this->current = other.current;

    }

    bool operator!=(ForwardIterator<T> other) {
        // Estás comparando la dirección que apunta a un puntero?
        return &(this->current) != &(other.current);
    }

    ForwardIterator<T> operator++() {
        // Bastaría con ignorar el caso, no es necesario un throw
        if (!this->current) throw;
        this->current = this->current->next;
        return (*this);
    }

    T operator*()
    {
        return this->current->data;
    }
};

#endif