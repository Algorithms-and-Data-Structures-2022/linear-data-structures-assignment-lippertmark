#include "assignment/array_stack.hpp"
#include "assignment/dynamic_array.hpp"

#include <algorithm>  // copy, fill
#include <stdexcept>  // invalid_argument (НЕЛЬЗЯ ИСПОЛЬЗОВАТЬ)
using namespace std;
namespace assignment {

  ArrayStack::ArrayStack(int capacity) {

    // выбрасываем ошибку, если указана неположительная емкость стека
    if (capacity <= 0) {
      throw std::invalid_argument("capacity is not positive");
    }

    capacity_ = capacity;
    data_ = new int[capacity];
    fill(data_, data_+capacity, 0);
  }

  ArrayStack::~ArrayStack() {
    // Write your code here ...
  }

  void ArrayStack::Push(int value) {
    if (size_ == capacity_){
      Resize(capacity_+kCapacityGrowthCoefficient);
      data_[size_] = value;
      size_+=1;
    }
    else{
      data_[size_] = value;
      size_+=1;
    }
  }

  bool ArrayStack::Pop() {
    if (size_ == 0){
      return false;
    }
    else{
      size_-=1;
      return true;
    }
  }

  void ArrayStack::Clear() {
    size_ = 0;
  }

  std::optional<int> ArrayStack::Peek() const {
    if (size_ == 0){
      return std::nullopt;
    }
    else {
        return data_[size_-1];
    };

  }

  bool ArrayStack::IsEmpty() const {
    return size_ == 0;
  }

  int ArrayStack::size() const {
    return size_;
  }

  int ArrayStack::capacity() const {
    return capacity_;
  }

  bool ArrayStack::Resize(int new_capacity) {
    if (new_capacity<= capacity_){
      return false;
    }
    int* old = data_;
    data_ = new int[new_capacity];
    for(int i = 0;i<new_capacity;i++){
      if (i<capacity_){
        data_[i] = old[i];
      }
      else{
        data_[i] = 0;
      }

    }
    delete[] old;
    capacity_= new_capacity;
    return true;
  }

  // ДЛЯ ТЕСТИРОВАНИЯ
  ArrayStack::ArrayStack(const std::vector<int>& values, int capacity) {

    size_ = static_cast<int>(values.size());
    capacity_ = capacity;

    data_ = new int[capacity]{};

    std::copy(values.data(), values.data() + size_, data_);
  }

  std::vector<int> ArrayStack::toVector(std::optional<int> size) const {

    if (capacity_ == 0 || data_ == nullptr) {
      return {};
    }

    if (size.has_value()) {
      return {data_, data_ + size.value()};
    }

    return {data_, data_ + capacity_};
  }

}  // namespace assignment
