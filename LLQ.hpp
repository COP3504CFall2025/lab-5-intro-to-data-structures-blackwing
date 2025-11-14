#pragma once

#include "Interfaces.hpp"
#include "LinkedList.hpp"
#include <stdlib.h>
#include <stdexcept>

template <typename T>
class LLQ : public QueueInterface<T> {
private:
    LinkedList<T> list;
public:
    // Constructor
    LLQ() {
        list = LinkedList<T>();
    }

    // Insertion
    void enqueue(const T& item) override {
        list.addTail(item);
    }

    // Deletion
    T dequeue() override {
        if (list.getHead() == nullptr) {
            throw std::runtime_error("No elements in the stack");
        }

        T item = list.getHead()->data;
        list.removeHead();
        return item;
    }

    // Access
    T peek() const override {
        if (list.getHead() == nullptr) {
            throw std::runtime_error("No elements in the stack");
        }
        T item = list.getHead()->data;
        return item;
    }

    // Getter
    std::size_t getSize() const noexcept override {
        return static_cast<std::size_t>(list.getCount());
    }

};