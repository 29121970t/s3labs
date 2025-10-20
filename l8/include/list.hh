#pragma once
#include <execution>
#include <iostream>
#include <memory>

#include "list_bits.hh"
namespace cList {

template <typename T, typename Allocator = std::allocator<list_bits::ListNode<T>>>
class CircleList {
   private:
    using Node = list_bits::ListNode<T>;
    size_t size_;
    [[no_unique_address]]
    Allocator allocator_{};
    Node* ringPtr_ = nullptr;

   public:
    using alocator_type = Allocator;
    using value_type = T;
    using reference = CircleList&;
    using pointer = CircleList*;
    using allocTraits_ = std::allocator_traits<Allocator>;
    using iterator = list_bits::Iterator<T>;
    using const_iterator = list_bits::Iterator<const T>;

    friend std::ostream& operator<<(std::ostream& os, const CircleList& obj) {
        os << '[';
        for (size_t i = 0; i < obj.size_; i++) {
            os << obj[i] << " ";
        }
        os << ']';
        return os;
    }

    friend auto operator<=>(const CircleList& lhs, const CircleList& rhs) { return lhs.size_ <=> rhs.size_; }
    friend bool operator==(const CircleList& lhs, const CircleList& rhs) {
        if (lhs.size_ != rhs.size_) return false;
        for (size_t i = 0; i < lhs.size_; i++) {
            if (lhs[i] != rhs[i]) return false;
        }
        return true;
    }

   public:
    CircleList() : size_{0} {}

    explicit CircleList(size_t size) : size_{size} {
        if (size_ == 0) return;
        ringPtr_ = allocator_.allocate(1);
        allocTraits_::construct(allocator_, ringPtr_);
        Node* current = ringPtr_;
        for (size_t i = 1; i < size_; ++i) {
            Node* newNode = allocator_.allocate(1);
            allocTraits_::construct(allocator_, newNode);
            current->next_ = newNode;
            newNode->prev_ = current;
            current = newNode;
        }
    }
    ~CircleList() { erase(); };
    CircleList(CircleList& other) : size_{other.size_}, ringPtr_{allocator_.allocate(1)} {
        allocTraits_::construct(allocator_, ringPtr_, other[0]);
        if (size_ == 1) {
            ringPtr_->next_ = ringPtr_;
            ringPtr_->prev_ = ringPtr_;
        }
        Node* current = ringPtr_;
        for (size_t i = 1; i < size_; ++i) {
            Node* newNode = allocator_.allocate(1);
            allocTraits_::construct(allocator_, newNode, other[i]);
            current->next_ = newNode;
            newNode->prev_ = current;
            current = newNode;
        }
        ringPtr_->prev_ = current;
        current->next_ = ringPtr_;
    }
    CircleList(CircleList&& other) noexcept : size_{other.size_}, ringPtr_{other.ringPtr_} { other.ringPtr_ = nullptr; }

    CircleList& operator=(CircleList& other) {
        *this = CircleList(other);
        return *this;
    }
    CircleList& operator=(CircleList&& other) noexcept {
        if (&other == this) return *this;
        size_ = other.size_;
        allocator_ = std::move(other.allocator_);
        ringPtr_ = other.ringPtr_;
        other.ringPtr_ = nullptr;
        return *this;
    }

    bool isEmpty() const { return size_ == 0; }
    size_t size() const { return size_; }
    CircleList& swap(CircleList& other) noexcept {
        CircleList tmp{std::move(other)};
        other = std::move(*this);
        *this = std::move(tmp);
        return *this;
    }
    void pushFront(T& data) {
        pushBack(data);
        if (size_ != 1) {
            ringPtr_ = ringPtr_->prev_;
        }
    }
    void pushBack(T& data) {
        Node* tmpPtr = allocator_.allocate(1);
        allocTraits_::construct(allocator_, tmpPtr, data);
        if (size_ != 0) {
            tmpPtr->next_ = ringPtr_;
            tmpPtr->prev_ = ringPtr_->prev_;
            ringPtr_->prev_->next_ = tmpPtr;
            ringPtr_->prev_ = tmpPtr;
        } else {
            ringPtr_ = tmpPtr;
            ringPtr_->next_ = ringPtr_;
            ringPtr_->prev_ = ringPtr_;
        }
        size_++;
    }
    void pushFront(T&& data) {
        pushBack(std::move(data));
        if (size_ != 1) {
            ringPtr_ = ringPtr_->prev_;
        }
    }

    void pushBack(T&& data) {
        Node* tmpPtr = allocator_.allocate(1);
        allocTraits_::construct(allocator_, tmpPtr, std::move(data));
        if (size_ != 0) {
            tmpPtr->next_ = ringPtr_;
            tmpPtr->prev_ = ringPtr_->prev_;
            ringPtr_->prev_->next_ = tmpPtr;
            ringPtr_->prev_ = tmpPtr;
        } else {
            ringPtr_ = tmpPtr;
            ringPtr_->next_ = ringPtr_;
            ringPtr_->prev_ = ringPtr_;
        }
        size_++;
    }

    T popFront() {
        ringPtr_ = ringPtr_->next_;
        return popBack();
    }
    T popBack() {
        if (size_ == 0) throw std::length_error("Circle list is empty");
        Node* tmpPtr = ringPtr_->prev_;

        ringPtr_->prev_ = tmpPtr->prev_;
        tmpPtr->prev_->next_ = ringPtr_;

        T data = tmpPtr->data_;
        allocTraits_::destroy(allocator_, tmpPtr);
        return data;
    }

    T& operator[](const size_t index) const {
        Node* tmp = ringPtr_;
        for (size_t i = 0, count = index % size_; i < count; i++) {
            tmp = tmp->next_;
        }
        return tmp->data_;
    }
    const T& operator[](const size_t index, const int) const {
        Node* tmp = ringPtr_;
        for (size_t i = 0, count = index % size_; i < count; i++) {
            tmp = tmp->next_;
        }
        return tmp->data_;
    }
    void insert(const size_t index, T& data) {
        if (index >= size_) throw std::invalid_argument("Index out of range");
        this->operator[](index) = data;
    }
    void insert(const size_t index, T&& data) { this->operator[](index) = std::move(data); }
    T& at(size_t index) {
        if (index >= size_) throw std::invalid_argument("Index out of range");
        return this->operator[](index);
    }
    const T& at(size_t index, int) {
        if (index >= size_) throw std::invalid_argument("Index out of range");
        return this->operator[](index);
    }

    iterator begin() { return iterator(ringPtr_); }
    iterator end() {
        if (size_ == 0) return iterator(ringPtr_);
        return iterator(ringPtr_, ringPtr_, 1);
    }

    void erase() {
        if (!ringPtr_) return;
        Node* current = ringPtr_;
        for (size_t i = 0; i < size_; i++) {
            Node* tmp = current->next_;
            allocTraits_::destroy(allocator_, current);
            allocator_.deallocate(current, 1);
            current = tmp;
        }
        size_ = 0;
    };
};
}  // namespace cList
