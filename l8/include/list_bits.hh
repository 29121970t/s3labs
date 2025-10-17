#include <iostream>
#include <iterator>
namespace list_bits {
template <typename T>
struct ListNode {
   public:
    ListNode *prev_ = nullptr;
    ListNode *next_ = nullptr;
    T data_;
    ListNode() :  data_{T()} {}
    explicit ListNode(T& data) :  data_{data} {}
    explicit ListNode(T& data, ListNode* prev, ListNode* next) : prev_{prev}, next_{next}, data_{data} {}
    explicit ListNode(T&& data) : data_{std::move(data)} {}
    ListNode(T&& data, ListNode* prev, ListNode* next) : prev_{prev}, next_{next}, data_{std::move(data)} {}
};
template <typename T, bool isConst>

class Iterator  {
   private:
    ListNode<T>*anchorPtr_;
    ListNode<T> *current_;
    size_t round_ = 0;
    using dataType = std::conditional_t<isConst, const T, T>;

   public:
    using iterator_category = std::bidirectional_iterator_tag;
    using value_type = T;
    using difference_type = std::ptrdiff_t;
    using pointer = value_type*;
    using reference = value_type&;

    friend Iterator<T, !isConst>;
    Iterator() = default;
    explicit Iterator(const Iterator& other) = default;
    explicit Iterator(ListNode<T>* anchorPtr, ListNode<T>* current, size_t round)
        : anchorPtr_{anchorPtr}, current_{current}, round_{round} {}
    explicit Iterator(ListNode<T>* current) : anchorPtr_{current}, current_{current} {}

    template<bool WasConst, class = std::enable_if_t<isConst || !WasConst>>
    Iterator(const Iterator<T, WasConst>& rhs) : anchorPtr_{rhs.anchorPtr_}, current_{rhs.current_} {}

    dataType& operator*() const { return this->current_->data_; }
    dataType* operator->() { return &(this->current_->data_); }

    friend bool operator==(const Iterator& lhs, const Iterator& rhs)  { return lhs.current_ == rhs.current_ && lhs.round_ == rhs.round_; }

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
static_assert(std::bidirectional_iterator<Iterator<int, false>>);
}  // namespace list_bits
