//
// Created by Sebastian Knell on 4/11/20.
//
#include "linked_list.h"


utec::first::linked_list_t::linked_list_t(const utec::linked_list_t &other) {

}

utec::linked_list_t &utec::first::linked_list_t::operator=(const utec::linked_list_t &other) {
    return *this;
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
    } else {
        tail_ = new node_t{value, nullptr};
        auto actual = head_;
        auto i = size_-1;
        while (i) {
            actual = actual->next_;
            i--;
        }
        actual->next_ = tail_;
    }
    size_++;
}

void utec::first::linked_list_t::insert(size_t index, int value) {

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

}

void utec::first::linked_list_t::erase(size_t index) {

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
