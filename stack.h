#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
class Stack : private std::vector<T>
{
public:
    Stack();
    ~Stack();
    bool empty() const;
    size_t size() const;
    void push(const T& item);
    void pop();  // throws std::underflow_error if empty
    const T& top() const; // throws std::underflow_error if empty
    // Add other members only if necessary
};
template <typename T>
Stack<T>::Stack(){ 
}
template <typename T>
Stack<T>::~Stack(){ 

}

template <typename T>
bool Stack<T>::empty() const{
    return this->empty();
}

template <typename T>
size_t Stack<T>::size() const{
    return this->size();
}

template <typename T>
void Stack<T>::push(const T& item){
    this->push_back(item);
    return;

}

template <typename T>
void Stack<T>::pop(){
    if(this->empty()){
        std::underflow_error("empty stack");
    }
    this->pop_back();
    return;
}

template <typename T>
const T& Stack<T>::top() const{
    if(this->empty()){
        std::underflow_error("empty stack");
    }
    return this->back();

}

#endif