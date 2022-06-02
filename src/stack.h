#ifndef stack_class
#define stack_class

#include <string>
#include <stdexcept>

namespace my_stack {
    struct StackEl {
        std::string val_;
        StackEl* next_;

        StackEl(std::string val, StackEl* next) : val_(val), next_(next) {};
        ~StackEl() {
            delete next_;
        }

        private:
        StackEl() {};
    };

    struct StackHead {
        StackHead(size_t max) : head_(nullptr), size_(0), capacity_(max) {}
        ~StackHead() {
            delete head_;
        }
        StackEl* Front();
        void Push(std::string val);
        std::string Pop();
        size_t Size() { return capacity_; }
        size_t ContainedNumber() { return size_; }
        
        private:
        StackEl* head_;
        size_t size_;
        size_t capacity_;
    };
}

#endif
