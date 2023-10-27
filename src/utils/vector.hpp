// Self implementation of
// the Vector Class in C++
#pragma once

#include <algorithm>
#include <functional>
#include <iostream>
#include <random>

namespace toyc {
template <typename T>
class Vector {
  // arr is the integer pointer
  // which stores the address of our vector
  T* arr;

  // capacity is the total storage
  // capacity of the vector
  int capacity;

  // current is the number of elements
  // currently present in the vector
  int current;

 public:
  // Default constructor to initialise
  // an initial capacity of 1 element and
  // allocating storage using dynamic allocation
  Vector() {
    arr = new T[1];
    capacity = 1;
    current = 0;
  }
  // destructor to deallocate storage allocated by dynamic allocation
  // to prevent memory leak
  ~Vector() { delete[] arr; }

  // Function to add an element at the last
  void push(T data) {
    // if the number of elements is equal to the
    // capacity, that means we don't have space to
    // accommodate more elements. We need to double the
    // capacity
    if (current == capacity) {
      T* temp = new T[2 * capacity];

      // copying old array elements to new array
      for (int i = 0; i < capacity; i++) {
        temp[i] = arr[i];
      }

      // deleting previous array
      delete[] arr;
      capacity *= 2;
      arr = temp;
    }

    // Inserting data
    arr[current] = data;
    current++;
  }

  // function to add element at any index
  void push(T data, int index) {
    // if index is equal to capacity then this
    // function is same as push defined above
    if (index == capacity)
      push(data);
    else
      arr[index] = data;
  }

  // function to extract element at any index
  T get(int index) {
    // if index is within the range
    if (index < current) return arr[index];
    throw std::runtime_error("index out of range");
  }

  // function to delete last element
  void pop() { current--; }

  // function to get size of the vector
  size_t size() { return current; }

  // function to get capacity of the vector
  int getCapacity() { return capacity; }

  void randomize() {
    // std::cout << size() << capacity << std::endl;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::shuffle(arr, arr + size(), gen);
    // for (int k = 0; k < size(); k++) {
    //   int r = k + rand() % (size() - k);  // careful here!
    //   std::swap(arr[k], arr[r]);
    // }
  }

  void sort(std::function<bool(const T&, const T&)> cmpFunc) {
    std::sort(arr, arr + size(), cmpFunc);
  }
};
}  // namespace toyc
