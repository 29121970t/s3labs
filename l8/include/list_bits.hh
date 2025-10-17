#include <iostream>

namespace list_bits {
template <typename T>
struct ListNode {
   public:
    ListNode *prev_, *next_;
    T data_;
    ListNode() : prev_{nullptr}, next_{nullptr}, data_{T()} {}
    ListNode(T& data) : prev_{nullptr}, next_{nullptr}, data_{data} {}
    ListNode(T& data, ListNode* prev, ListNode* next) : prev_{prev}, next_{next}, data_{data} {}
    ListNode(T&& data) : prev_{nullptr}, next_{nullptr}, data_{std::move(data)} {}
    ListNode(T&& data, ListNode* prev, ListNode* next) : prev_{prev}, next_{next}, data_{std::move(data)} {}
};
template <typename T, bool isConst>
class Iterator {
   protected:
    ListNode<T>*anchorPtr_, *current_;
    size_t round_ = 0;
    using dataType = std::conditional_t<isConst, const T, T>;

   public:
    using iterator_category = std::bidirectional_iterator_tag;
    using value_type = T;
    using difference_type = value_type;
    using pointer = value_type*;
    using reference = value_type&;

    friend Iterator<T, !isConst>;

    explicit Iterator(ListNode<T>* anchorPtr, ListNode<T>* current, size_t round)
        : anchorPtr_{anchorPtr}, current_{current}, round_{round} {}
    explicit Iterator(ListNode<T>* current) : anchorPtr_{current}, current_{current} {}
    template<bool WasConst, class = std::enable_if_t<isConst || !WasConst>>
    Iterator(const Iterator<T, WasConst>& rhs) : anchorPtr_{rhs.anchorPtr_}, current_{rhs.current_} {}

    dataType& operator*() { return this->current_->data_; }
    dataType* operator->() { return &(this->current_->data_); }
    friend bool operator==(const Iterator& lhs, const Iterator& rhs)  { return lhs.current_ == rhs.current_ && lhs.round_ == rhs.round_; }
    bool operator!=(Iterator& other) const { return current_ != other.current_ || round_ != other.round_; }
    Iterator& operator--() {
        this->current_ = this->current_->prev_;
        if (this->current_ == this->anchorPtr_) {
            this->round_--;
        }
        return *this;
    }
    Iterator operator--(int) {
        Iterator cop{*this};
        --(*this);
        return cop;
    }
    Iterator& operator++() {
        this->current_ = this->current_->next_;
        if (this->current_ == this->anchorPtr_) {
            this->round_++;
        }
        return *this;
    }
    Iterator operator++(int) {
        Iterator cop{*this};
        ++(*this);
        return cop;
    }
    
};

}  // namespace list_bits
