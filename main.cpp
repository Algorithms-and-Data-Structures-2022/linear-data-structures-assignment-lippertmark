#include <iostream>  // cout

#include "assignment/dynamic_array.hpp"  // DynamicArray
#include "assignment/linked_list.hpp"    // LinkedList
#include "assignment/array_stack.hpp"    // ArrayStack
#include "assignment/linked_queue.hpp"   // LinkedQueue

using std::cout;
using namespace std;

int main(int argc, char **argv) {

  // Пример. Создание пустого динамического массива.
  assignment::DynamicArray array(5);
  cout << array.capacity() << endl;
  cout<<"before:"<<array.size()<<array.capacity()<<endl;
  cout << array.Insert(0, 4) << endl;
  cout<<"after:"<<array.size()<<array.capacity()<<endl;
  cout << "2-" << array.Get(2).value() << endl;
  cout << "3-" << array.Get(3).value() << endl;
  cout << "4-" << array.Get(4).value() << endl;
  cout << "5-" << array.Get(5).value() << endl;

  return 0;
}
