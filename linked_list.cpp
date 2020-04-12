//
// Created by Sebastian Knell on 4/11/20.
//
#include "linked_list.h"


utec::first::linked_list_t::linked_list_t(const utec::linked_list_t &other) {
    for (auto i = 0; i < other.size_; i++)
        push_back(other.item(i));
}

utec::linked_list_t &utec::first::linked_list_t::operator=(const utec::linked_list_t &other) {
    if (this == &other) return *this;
    for (auto i = 0; i < other.size_; i++) {
        push_back(other.item(i));
    }
}
/*
utec::first::linked_list_t::linked_list_t(utec::linked_list_t &&other) noexcept {

}

utec::linked_list_t &utec::first::linked_list_t::operator=(utec::linked_list_t &&other) noexcept {
    // TO DO
    return *this;
}
*/
utec::first::linked_list_t::~linked_list_t() {
    auto actual = head_;
    while (size_--) {
        actual = actual->next_;
        delete actual;
    }
    head_ = tail_ = nullptr;
}

void utec::first::linked_list_t::push_front(int value) {
    head_ = new node_t{value, head_};
    if (tail_ == nullptr) tail_ = head_;
    size_++;
}

void utec::first::linked_list_t::push_back(int value) {
    if (head_ == nullptr) {
        head_ = new node_t{value, nullptr};
        if (tail_ == nullptr) tail_ = head_;
    }
    else {
        tail_->next_ = new node_t{value, nullptr};
        tail_ = tail_->next_;
    }
    size_++;
}

void utec::first::linked_list_t::insert(size_t index, int value) {
    if (head_ == nullptr) {
        head_ = new node_t{value, nullptr};
        if (tail_ == nullptr) tail_ = head_;
    }
    else {
        auto actual = head_;
        while (index-- > 1) actual = actual->next_;
        actual->next_ = new node_t{value, actual->next_};
    }
    size_++;
}

void utec::first::linked_list_t::pop_front() {
    if (head_ == tail_) {
        delete head_;
        head_ = tail_ = nullptr;
        size_ = 0;
    }
    else {
        auto next = head_->next_;
        delete head_;
        head_ = next;
        size_--;
    }
}

void utec::first::linked_list_t::pop_back() {
    if (head_ == tail_) {
        delete head_;
        head_ = tail_ = nullptr;
        size_ = 0;
    }
    else {
        auto actual = head_;
        auto i = 0;
        while (i++ < size_ - 1)
            actual = actual->next_;
        tail_ = actual;
        delete actual->next_;
        size_--;
    }
}

void utec::first::linked_list_t::erase(size_t index) {
    if (head_ == tail_) {
        delete head_;
        head_ = tail_ = nullptr;
        size_ = 0;
    }
    else {
        auto actual = head_;
        while (index-- > 1) actual = actual->next_;
        auto to_erase = actual->next_;
        actual->next_ = actual->next_->next_;
        delete to_erase;
    }
    size_--;
}

int &utec::first::linked_list_t::item(size_t index) {
    auto actual = head_;
    while (index--)
        actual = actual->next_;
    return actual->value_;
}

const int &utec::first::linked_list_t::item(size_t index) const {
    auto actual = head_;
    while (index--)
        actual = actual->next_;
    return actual->value_;
}

size_t utec::first::linked_list_t::size() const {
    return size_;
}
