#pragma once

#include <cstddef>
#include <stdexcept>
#include "Interfaces.hpp"
#include "LinkedList.hpp"
#include <utility>



template <typename T>
class LLDQ : public DequeInterface<T> {
private:
    LinkedList<T> list;

public:
    // Constructor
    LLDQ() {
        list = LinkedList<T>();
    }

    // Core Insertion Operations
    void pushFront(const T& item) override {
        list.addHead(item);
    }
    void pushBack(const T& item) override {
        list.addTail(item);
    }

    // Core Removal Operations
    T popFront() override {
        if (list.getHead() == nullptr) {
            throw std::runtime_error("No elements in the stack");
        }

        T item = list.getHead()->data;
        list.removeHead();
        return item;
    }
    T popBack() override {
        if (list.getHead() == nullptr) {
            throw std::runtime_error("No elements in the stack");
        }

        T item = list.getTail()->data;
        list.removeTail();
        return item;
    }

    // Element Accessors
    const T& front() const override {
        //return list.getHead()->data;
        if (list.getHead() == nullptr) {
            throw std::runtime_error("No elements in the stack");
        }
        T item = list.getHead().data;
        return item;
    }
    const T& back() const override {
        if (list.getHead() == nullptr) {
            throw std::runtime_error("No elements in the stack");
        }
        //return list.getTail()->data;
        T item = list.getTail().data;
        return item;
    }

    // Getter
    std::size_t getSize() const noexcept override {
        return static_cast<std::size_t>(list.getCount());
    }
};






