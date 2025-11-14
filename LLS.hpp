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
        list = LinkedList<T>();
    }

    // Insertion
    void push(const T& item) override {
        list.addTail(item);
    }

    // Deletion
    T pop() override {
        if (list.getHead() != nullptr) {
            T item = list.getTail()->data;
            list.removeTail();
            return item;
        }
        if (list.getCount() == 0) {
            throw std::out_of_range("No elements in the stack");
        }


    }

    // Access
    T peek() const override {
        T item = list.getTail()->data;
        return item;
    }

    //Getters
    std::size_t getSize() const noexcept override {
        return list.getCount();
    }
};