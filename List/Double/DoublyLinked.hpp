#include "../ListADT.hpp"
#include "Node.hpp"
#ifndef DOUBLYLINKED_HPP
#define DOUBLYLINKED_HPP

template <class value>
class DoublyLinked : public ListADT<value>
{
private:
  Node<value>* Head;
  Node<value>* Tail;
  size_type Size;
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

template <class value>
DoublyLinked<value>::DoublyLinked()
{
  this->Size = 0;
  Head = nullptr;
  Tail = Head;
}

template <class value>
DoublyLinked<value>::~DoublyLinked()
{
  clear();
}
template <class value>
size_type DoublyLinked<value>::size()
{
  return this->Size;
}
template <class value>
bool DoublyLinked<value>::isEmpty()
{
  return this->Size == 0;
}

template <class value>
bool DoublyLinked<value>::contains(value data)
{
  Node<value> *temp = Head;
  while (temp != nullptr)
  {
    if(temp->data == data) return true;
    temp = temp->next;
  }
  return false;
}

template <class value>
void DoublyLinked<value>::addToHead(value data)
{
  if (this->isEmpty())
  {
   Head = new Node<value>;
   Head->data = data;
   Tail = Head;
  }
  else
  {
  Node<value> *temp = new Node<value>;
  temp->data = data;
  temp->next = Head;
  temp->prev = nullptr;
  Head->prev = temp;
  Head = temp;
  }
  this->Size++;
}

template <class value>
void DoublyLinked<value>::addToTail(value data)
{
  if (this->isEmpty())
  {
   Head = new Node<value>;
   Head->data = data;
   Tail = Head;
  }
  else
  {
  Node<value> *temp = new Node<value>;
  temp->data = data;
  temp->next = nullptr;
  temp->prev = Tail;
  Tail->next = temp;
  Tail = temp;
  }
  this->Size++;
}

template <class value>
void DoublyLinked<value>::emplace(value data, index_type index)
{
  if (this->isEmpty())
  {
   Head = new Node<value>;
   Head->data = data;
   Tail = Head;
  }
  else if (index == 0)
  {
    return addToHead(data);
  }
  else
  {
  Node<value> *aux = Head;
  Node<value> *temp = new Node<value>;
  temp->data = data;
  for (index_type i = 0; i < this->Size; i++)
  {
    if (i == index)
    {
      Node<value> *prevNode = aux->prev; // apuntamos al nodo anterior

      // creamos el enlace de la derecha
      temp->next = aux;
      aux->prev = temp;
      // creamos el enlace de la izquierda
      temp->prev = prevNode;
      prevNode->next = temp;
      break;
    }
    aux = aux->next;
  }
  this->Size++;
}
}
template <class value>
value DoublyLinked<value>::get(index_type index)
{
  Node<value> *aux = Head;
  for (size_type i = 0; i < this->Size; i++)
  {
    if(i == index) {break;}
    aux = aux->next;
  }
  return aux->data;
}

template <class value>
void DoublyLinked<value>::set(value data, index_type index)
{
  Node<value> *aux = Head;
  for (size_type i = 0; i < this->Size; i++)
  {
    if(i == index) break;
    aux = aux->next;
  }
  aux->data = data;
}

template <class value>
void DoublyLinked<value>::removeIndex(index_type index)
{
  if (this->isEmpty())
    return;

  Node<value> *aux = Head;
  for (size_type i = 0; i < this->Size; i++)
  {
    //caso 1:cuando se quiere eliminar la primera posicion
    //caso 2: cuando se quiere eliminar la ultima posicionail = Tail->prev;
    //caso 3: cuando se quiere eliminar una posicion entre medio
    if (index == 0)
    {

      Head = Head->next;
      delete aux;
      this->Size--;
    }
    else if (index == this->Size - 1)
    {

      delete aux;
      this->Size--;
    }
    else if(i == index)
      {
        Node<value> *prevNode = aux->prev;
        Node<value> *nextNode = aux->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;

        delete aux;
        this->Size--;
      }
    aux = aux->next;
  }
}

template <class value>
void DoublyLinked<value>::removeValue(value data)
{
  for (size_type i = 0; i < this->Size; i++)
  {
    if (this->get(i) == data)
    {
      removeIndex(i);
    }
  }
}

template <class value>
void DoublyLinked<value>::clear()
{
  while (Head != nullptr)
  {
    Node<value>* aux = Head;
    Head = Head->next;
    delete aux;
  }
  Tail = Head;
  Size = 0;
}

#endif // !DOUBLYLINKED_HPP