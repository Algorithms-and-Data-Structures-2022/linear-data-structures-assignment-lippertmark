#include "assignment/linked_list.hpp"
using namespace std;
namespace assignment {

  LinkedList::~LinkedList() {

    // эквивалентно очистке списка
    LinkedList::Clear();
  }

  void LinkedList::Add(int value) {
    if (front_ != nullptr) {
      size_ += 1;
      Node* curr = new Node(value);
      back_->next = curr;
      back_ = curr;
    } else {
      front_ = new Node(value);
      back_ = new Node(value);

      size_ += 1;
    }
  }

  bool LinkedList::Insert(int index, int value) {
    if (index == 0) {
      if (front_ == nullptr) {
        Add(value);
      } else {
        Node* second = front_;
        front_ = new Node(value, second);
        size_ += 1;
      }
      return true;
    } else if (index == size_) {
      Add(value);
      return true;
    } else if (index > 0 && index < size_) {
      Node* curr = front_;
      int ind = 0;
      while (curr != nullptr) {
        if (ind + 1 == index) {
          Node* n = new Node(value, curr->next);
          curr->next = n;
          break;
        }
        ind += 1;
        curr = curr->next;
      }
      size_ += 1;
      return true;
    } else {
      return false;
    }
  }

  bool LinkedList::Set(int index, int new_value) {
    Node* curr = FindNode(index);
    if (curr == nullptr) {
      return false;
    } else {
      curr->value = new_value;
      return true;
    }
  }

  std::optional<int> LinkedList::Remove(int index) {
    if (index == 0) {
      if (front_ == nullptr){
        return std::nullopt;
      }
      size_ -= 1;
      int ans = front_->value;
      front_ = front_->next;
      return ans;

    }
    else if (index < 0 || index >= size_) {
      return std::nullopt;
    }
    else {
      Node* pred = FindNode(index-1);
      auto ans = pred->next->value;
      pred->next = pred->next->next;
      size_-=1;
      return ans;
    }
    return std::nullopt;
  }

  void LinkedList::Clear() {
    for (Node* curr = front_; curr != nullptr; /* */) {
      Node* node_to_remove = curr;
      curr = curr->next;
      delete node_to_remove;
    }
    front_ = 0;
    back_ = 0;
    size_ = 0;
  }

  std::optional<int> LinkedList::Get(int index) const {
    Node* curr = front_;
    int c = 0;
    while (curr != nullptr) {
      if (c == index) {
        return curr->value;
      }
      c += 1;
      curr = curr->next;
    }
    return std::nullopt;
  }

  std::optional<int> LinkedList::IndexOf(int value) const {
    Node* curr = front_;
    int index = 0;
    while (curr != nullptr) {
      if (curr->value == value) {
        return index;
      }
      curr = curr->next;
      index++;
    }
    return std::nullopt;
  }

  bool LinkedList::Contains(int value) const {
    if (IndexOf(value) != std::nullopt) {
      return true;
    }
    return false;
  }

  bool LinkedList::IsEmpty() const {
    return front_ == nullptr;
  }

  int LinkedList::size() const {
    return size_;
  }

  std::optional<int> LinkedList::front() const {
    if (front_ != nullptr) {
      return front_->value;
    }
    return std::nullopt;
  }

  std::optional<int> LinkedList::back() const {
    if (back_ != nullptr) {
      return back_->value;
    }
    return std::nullopt;
  }

  Node* LinkedList::FindNode(int index) const {
    Node* curr = front_;
    if (index < 0 || index >= size_) {
      return nullptr;
    }
    int c = 0;
    while (curr != nullptr) {
      if (c == index) {
        return curr;
      }
      c += 1;
      curr = curr->next;
    }
    return nullptr;
  }

  // ДЛЯ ТЕСТИРОВАНИЯ
  LinkedList::LinkedList(const std::vector<int>& values) {

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

  std::vector<int> LinkedList::toVector() const {

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