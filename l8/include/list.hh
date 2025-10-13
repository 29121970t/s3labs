#pragma once
#include <memory>
namespace {
template <typename T>
class Node {
   private:
    Node *next_, *prev_;
    T data_;

   public:
    Node(T &data, Node *next = nullptr, Node *prev = nullptr) : data_{data}, next_{next}, prev_{prev} {};
    Node(T &&data, Node *next = nullptr, Node *prev = nullptr) : data_{std::move(data)}, next_{next}, prev_{prev} {};

    ~Node() = default;
    Node(Node &) = default;
    Node(Node &&) = default;

    Node &operator=(Node &) = default;
    Node &operator=(Node &&) = default;

    Node &linkFront(Node &next) {
        this->next_ = &next;
        next.prev_ = this;
        return next;
    }
};
}  // namespace

template <typename T, typename alloc_t = std::allocator<T>>
class CircleList {
   private:
    size_t size_;
    std::allocator<T> allocator_{};
    std::unique_ptr<Node<T>> ring_ptr_;
   public:
    CircleList() : size_{0}, ring_ptr_{nullptr} {}
    CircleList(size_t size) : size_{size}, ring_ptr_{static_cast<* Node<T>>(allocator_.allocate(sizeof(Node<T>)))} {
        
    }

    ~CircleList(){};
    // CircleList(CircleList &);
    // CircleList(CircleList &&);

    // CircleList &operator=(CircleList &);
    // CircleList &operator=(CircleList &&);

    // bool isEmpty();
    // size_t size();
    // void swap(CircleList &, CircleList &);
    // void pushFront(T &);
    // void pushBack(T &);
    // void pushFront(T &&);
    // void pushBack(T &&);
    // T popFront();
    // T popBack();
    // auto operator<=>(CircleList &);
    // bool operator==(CircleList &);

    // // begin, end

    // void insert(T &);
    // void insert(T &&);
    // void erace(size_t);
    // void clear();
};