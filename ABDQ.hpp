#pragma once

#include <cstddef>
#include <stdexcept>
#include "Interfaces.hpp"
#include <utility>
#include <iostream>

template <typename T>
class ABDQ : public DequeInterface<T> {
private:
    T* data_;                 // underlying dynamic array
    std::size_t capacity_;    // total allocated capacity
    std::size_t size_;        // number of stored elements
    std::size_t front_;       // index of front element
    std::size_t back_;        // index after the last element (circular)

    static constexpr std::size_t SCALE_FACTOR = 2;

public:
    // Big 5
    ABDQ() {
        capacity_ = 4;
        size_ = 0;
        front_ = 0;
        back_ = 0;
        data_ = new T[capacity_];
    }
    explicit ABDQ(std::size_t capacity) {
        capacity_ = capacity;
        size_ = 0;
        front_ = 0;
        back_ = 0;
        data_ = new T[capacity_];
    }
    ABDQ(const ABDQ& other) {
        capacity_ = other.capacity_;
        size_ = other.size_;
        front_ = other.front_;
        back_ = other.back_;
        data_ = new T[capacity_];
        for (size_t i = 0; i < size_; i++) {
            data_[i] = other.data_[i];
        }
    }
    ABDQ(ABDQ&& other) noexcept {
        capacity_ = other.capacity_;
        size_ = other.size_;
        front_ = other.front_;
        back_ = other.back_;
        data_ = other.data_;

        other.data_ = nullptr;
        other.size_ = 0;
        other.capacity_ = 0;
        other.front_ = 0;
        other.back_ = 0;
    }
    ABDQ& operator=(const ABDQ& other) {
        if (this == &other) {
            return *this;
        }

        delete[] data_;

        capacity_ = other.capacity_;
        size_ = other.size_;
        front_ = other.front_;
        back_ = other.back_;
        data_ = new T[capacity_];

        for (size_t i = 0; i < size_; i++) {
            data_[i] = other.data_[i];
        }
        return *this;

    }
    ABDQ& operator=(ABDQ&& other) noexcept {
        if (this == &other) {
            return *this;
        }

        delete[] data_;

        capacity_ = other.capacity_;
        size_ = other.size_;
        front_ = other.front_;
        back_ = other.back_;
        data_ = other.data_;

        other.data_ = nullptr;
        other.size_ = 0;
        other.capacity_ = 0;
        other.front_ = 0;
        other.back_ = 0;

        return *this;

    }
    ~ABDQ() {
        delete[] data_;
        capacity_ = 0;
        size_ = 0;
        front_ = 0;
        back_ = 0;
        data_ = nullptr;
    }

    // Insertion
    void pushFront(const T& item) override {
        if (size_ == capacity_) {
            ensureCapacity();
        }
        T temp1 = data_[0];
        T temp2;
        size_++;
        for (size_t i = 1; i < size_; i++) {
            temp2 = data_[i];
            data_[i] = temp1;
            temp1 = temp2;
        }
        data_[0] = item;
    }
    void pushBack(const T& item) override {
        if (size_ == capacity_) {
            ensureCapacity();
        }
        data_[size_] = item;
        size_++;
    }

    // Deletion
    T popFront() override {
        if (size_ == 0) {
            throw std::runtime_error("No elements in the Deque");
        }

        T firstElement = data_[0];
        size_--;
        for (size_t i = 1; i < size_ + 1; i++) {
            data_[i-1] = data_[i];
        }
        if (size_ <= (capacity_ / 4)) {
            shrinkIfNeeded();
        }
        return firstElement;
    }
    T popBack() override {
        if (size_ == 0) {
            throw std::runtime_error("No elements in the deque");
        }

        T lastElement = data_[size_ - 1];
        size_--;

        if (size_ <= (capacity_ / 4)) {
            shrinkIfNeeded();
        }
        return lastElement;
    }
    void shrinkIfNeeded() {
        capacity_ /= SCALE_FACTOR;
    }

    // Access
    const T& front() const override {
        if (size_ == 0) {
            throw std::runtime_error("No elements in the Deque");
        }
        return data_[0];
    }
    const T& back() const override {
        if (size_ == 0) {
            throw std::runtime_error("No elements in the Deque");
        }
        return data_[size_ - 1];
    }

    // Getters
    std::size_t getSize() const noexcept override {
        return size_;
    }
    void ensureCapacity() {
        capacity_ *= SCALE_FACTOR;
        T* new_array = new T[capacity_];
        for (size_t i = 0; i < size_; i++) {
            new_array[i] = data_[i];
        }
        delete[] data_;
        data_ = new_array;
    }
    bool isEmpty();
    bool isFull();

    void print() {
        for (std::size_t i = 0; i < capacity_; i++) {
            std::cout << data_[i] << " ";
        }
        std::cout << std::endl;
    }

};

// template<typename T>
// ABDQ<T>::ABDQ() {
//     size_ = 0;
//     capacity_ = 4;
//     data_ = new T[capacity_];
//     front_ = 0;
//     back_ = 0;
// }
//
// template<typename T>
// ABDQ<T>::ABDQ(std::size_t capacity) {
//     size_ = 0;
//     capacity_ = capacity;
//     data_ = new T[capacity_];
//     front_ = 0;
//     back_ = 0;
// }
//
// template<typename T>
// ABDQ<T>::ABDQ(const ABDQ& other) {
//     this->capacity_ = other.capacity_;
//     this->size_ = other.size_;
//     this->data_ = new T[this->capacity_];
//     this->front_ = other.front_;
//     this->back_ = other.back_;
//
//     for (size_t i = 0; i < other->size_; i++) {
//         this->data_[i] = other->data_[i];
//     }
// }
//
// template<typename T>
// ABDQ<T>::ABDQ(ABDQ &&other) noexcept {
//     this->data_ = other.data_;
//     this->capacity_ = other.capacity_;
//     this->size_ = other.size_;
//     this->front_ = other.front_;
//     this->back_ = other.back_;
//
//     other.data = nullptr;
//     other.capacity_ = 0;
//     other.size_ = 0;
//     other.front_ = 0;
//     other.back_ = 0;
// }
//
// template<typename T>
// ABDQ<T>& ABDQ<T>::operator=(ABDQ &&other) noexcept {
//     if (this == &other) {
//         return *this;
//     }
//
//     delete[] data_;
//
//     this->data_ = other.data_;
//     this->capacity_ = other.capacity_;
//     this->size_ = other.size_;
//     this->front_ = other.front_;
//     this->back_ = other.back_;
//
//     other.data = nullptr;
//     other.capacity_ = 0;
//     other.size_ = 0;
//     other.front_ = 0;
//     other.back_ = 0;
//     return *this;
// }
//
// template<typename T>
// ABDQ<T>& ABDQ<T>::operator=(const ABDQ& other) {
//
//     if (this == &other) {
//         return *this;
//     }
//
//     delete[] data_;
//
//     this->data_ = new T[other.capacity_];
//     this->capacity_ = other.capacity_;
//     this->size_ = other.size_;
//     this->front_ = other.front_;
//     this->back_ = other.back_;
//
//     for (size_t i = 0; i < other->size_; i++) {
//         this->data_[i] = other->data_[i];
//     }
//     return *this;
// }
//
// template<typename T>
// ABDQ<T>::~ABDQ() {
//     delete data_;
//     data_ = nullptr;
//     capacity_ = 0;
//     size_ = 0;
//     front_ = 0;
//     back_ = 0;
// }
//
// template<typename T>
// std::size_t ABDQ<T>::getSize() const noexcept {
//     return this->size_;
// }
//
// // learned from https://www.youtube.com/watch?v=8sjFA-IX-Ww&t=251s
// template<typename T>
// void ABDQ<T>::pushBack(const T &item) {
//
//     if (isFull() == true) {
//         ensureCapacity();
//     }
//     else if (isEmpty() == true) {
//         front_ += 1;
//     }
//     back_ = (back_ + 1) % this->capacity_;
//     data_[back_] = item;
//     // if (this->back_ == this->capacity_) {
//     //     ensureCapacity();
//     // }
//     // data_[this->back_] = item;
//     // this->back_ = (this->back_ + 1) % this->capacity_;
// }
//
// // template<typename T>
// // void ABDQ<T>::pushFront(const T &item) {
// //     if (this->front_ == this->back_) {
// //         throw new std::runtime_error("Oopsie! Too small");
// //     }
// //     data_[this->front_] = item;
// //     this->front_ = (this->front_ + 1) % this->capacity_;
// // }
//
// // template<typename T>
// // const T& ABDQ<T>::back() const {
// //     return this->data_[this->back_];
// // }
//
// // template<typename T>
// // const T& ABDQ<T>::front() const {
// //     return this->data_[this->front_];
// // }
//
// // template<typename T>
// // T ABDQ<T>::popBack() {
// //
// // }
//
// // Learned from https://www.youtube.com/watch?v=8sjFA-IX-Ww&t=251s
// template<typename T>
// void ABDQ<T>::ensureCapacity() {
//     std::size_t newCapacity = this->capacity_ * SCALE_FACTOR;
//     T* new_data = new T[newCapacity];
//
//     std::size_t i = 0;
//     std::size_t j = front_;
//
//     do {
//         new_data[i++] = data_[j];
//         j = (j + 1) % newCapacity;
//     } while (j != this->front_);
//
//     front_ = 0;
//     back_ = capacity_;
//     // for (std::size_t i = 0; i < this->size_; i++) {
//     //     new_data[i] = this->data_[i];
//     // }
//     this->capacity_ = newCapacity;
//     delete[] this->data_;
//     this->data_ = new_data;
// }
//
// // Learned from https://www.youtube.com/watch?v=8sjFA-IX-Ww&t=251s
// template<typename T>
// bool ABDQ<T>::isEmpty() {
//     if (front_ == 0) {
//         return true;
//     }
//     return false;
// }
//
// // Learned from https://www.youtube.com/watch?v=8sjFA-IX-Ww&t=251s
// template<typename T>
// bool ABDQ<T>::isFull() {
//     if ((back_ + 1) % this->capacity_ == front_) {
//         return true;
//     }
//     return false;
// }
//
//














