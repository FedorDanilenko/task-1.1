#include "stack.h"

using namespace my_stack;

StackEl* StackHead::Front() {
    return head_;
}

void StackHead::Push(std::string val) {
    if (++size_ > capacity_) throw std::runtime_error("Error: push attempt on a full stack");
    StackEl* new_head = new StackEl{val, head_};
    head_ = new_head;
}

std::string StackHead::Pop() {
    if (head_ == nullptr) throw std::runtime_error("Error: pop attempt on an empty stack");
    --size_;
    std::string ret_val = head_->val_;
    StackEl* old_head = head_;
    head_ = head_->next_;
    old_head->next_ = nullptr;
    delete old_head;
    return ret_val;
}
