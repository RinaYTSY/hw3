#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <iostream>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  std::vector<T> data;
  PComparator comp;
  int mh;
  /// Add whatever helper functions and data members you need below

};
template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c){
  comp=c; 
  mh=m;
}
template <typename T, typename PComparator>
Heap<T,PComparator>::~Heap(){
  while(!empty()){
    data.pop_back();
  }
 
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item){
  data.push_back(item);
  int i=data.size()-1;
  while(comp(data[i],data[(i-1)/mh])){
    std::swap(data[i],data[(i-1)/mh]);
    i=(i-1)/mh;
  }
  return;
}


// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){

    throw std::underflow_error("empty heap");
    // ================================
    // throw the appropriate exception ???????????
    // ================================


  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return data[0];
}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    throw std::underflow_error("empty stack");
    // ================================
    // throw the appropriate exception
    // ================================


  }
  int s=data.size();
  std::swap(data[0], data[s-1]);
  data.pop_back();

  int p = 0;
  int pindex=0;
  T prio=data[0];
  while(p<data.size()){
    if(mh*p+1>data.size()-1){
      return;
    }
    
    if(mh*p+1==data.size()-1){//no right child, left child is the last element
        prio=data[mh*p+1];
        pindex=(mh*p)+1;
    }
    else if(mh*p+1<data.size()){
      prio=data[mh*p+1];
      pindex=(mh*p)+1;
       for(int i=1; i<mh; i++){
         if((mh*p)+i<data.size()-1){
            if(comp(data[(mh*p)+i+1],prio)){
               prio=data[(mh*p)+i+1];
               pindex=(mh*p)+i+1;
               }
            }
          }
    }
    if(comp(prio,data[p])){
          std::swap(data[pindex], data[p]);
          p=pindex;
        }
        else{
          break;
        }}   
        return;    
  }

template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const{
  return data.empty();
}

template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const{
  return data.size();
}




#endif

