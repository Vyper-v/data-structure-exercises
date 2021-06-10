#include "../ListADT.hpp"
#include "Node.hpp"
#ifndef DOUBLYLINKED_HPP
#define DOUBLYLINKED_HPP

template <class value>
class DoublyLinked
{
private:
  Node<value>* Head;
  Node<value>* Tail;
  size_type size;
public:
  DoublyLinked();
  ~DoublyLinked();
  size_type size();
  bool isEmpty();
  bool contains(value);
  void addToHead(value);
  void addToTail(value);
  void emplace(value, index_type);
  value get(index_type);
  void set(value, index_type);
  void removeIndex(index_type);
  void removeValue(value);
  void clear();
};
#endif // !DOUBLYLINKED_HPP