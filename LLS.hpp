#pragma once

#include "Interfaces.hpp"
#include "LinkedList.hpp"
#include <stdlib.h>
#include <stdexcept>

template <typename T>
class LLS : public StackInterface<T> {
private:
    LinkedList<T> list;
public:
    // Constructor
    LLS() {
        list = new LinkedList<T>();
    }

    // Insertion
    void push(const T& item) override {
        addTail(item);
    }

    // Deletion
    T pop() override {
        T item = list->tail->data;
        list->removeTail();
        return item;
    }

    // Access
    T peek() const override {
        T item = list->tail->data;
        return item;
    }

    //Getters
    std::size_t getSize() const noexcept override {
        return list->getCount();
    }
};