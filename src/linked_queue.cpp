#include "assignment/linked_queue.hpp"

namespace assignment {

  LinkedQueue::~LinkedQueue() {

    // эквивалентно очистке очереди
    LinkedQueue::Clear();
  }

  void LinkedQueue::Enqueue(int value) {
    if (back_ == nullptr){
      front_ = new Node(value, nullptr);
      back_ = front_;
      size_+=1;
    }
    else{
      back_->next = new Node(value, nullptr);
      back_ = back_->next;
      size_+=1;
    }
  }

  bool LinkedQueue::Dequeue() {

    if (front_ == nullptr){
      return false;
    }
    else {
      front_ = front_->next;
      size_ -= 1;
      return true;
    }
  }

  void LinkedQueue::Clear() {
    if (size_ == 0){
      front_ = nullptr;
      back_ = nullptr;
    }
    else{
      Node* curr = front_;
      Node* pred = front_;
      while (curr != nullptr){
        pred = curr;
        curr = curr->next;
        delete pred;
      }
      front_ = nullptr;
      back_ = nullptr;
      size_ = 0;
    }



  }

  std::optional<int> LinkedQueue::front() const {
    if (front_ != nullptr){
      return front_->value;
    }
    return std::nullopt;
  }

  std::optional<int> LinkedQueue::back() const {
    if (back_ != nullptr){
      return back_->value;
    }
    return std::nullopt;
  }

  bool LinkedQueue::IsEmpty() const {
    return size_ == 0;
  }

  int LinkedQueue::size() const {
    return size_;
  }

  // ДЛЯ ТЕСТИРОВАНИЯ
  LinkedQueue::LinkedQueue(const std::vector<int>& values) {

    if (values.empty()) {
      return;
    }

    auto* curr_node = new Node(values.front());
    front_ = curr_node;

    for (int index = 1; index < values.size() - 1; ++index) {
      curr_node->next = new Node(values[index]);
      curr_node = curr_node->next;
    }

    if (values.size() == 1) {
      back_ = front_;
    } else {
      curr_node->next = new Node(values.back());
      back_ = curr_node->next;
    }

    size_ = static_cast<int>(values.size());
  }

  std::vector<int> LinkedQueue::toVector() const {
    if (front_ == nullptr || size_ == 0) {
      return {};
    }

    std::vector<int> array;
    array.reserve(size_);

    for (auto* node = front_; node != nullptr; node = node->next) {
      array.push_back(node->value);
    }

    return array;
  }

}  // namespace assignment