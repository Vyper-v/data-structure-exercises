#ifndef LISTADT_HPP
  #define LISTADT_HPP

    typedef unsigned int index_type;
    typedef unsigned int size_type;

    template <class value>
    class ListADT
    {
    public:
      virtual size_type size() = 0;
      // Gets list size
      virtual bool isEmpty() = 0;
      // 	Checks if list is empty
      virtual bool contains(value) = 0;
      // Checks if value exists in list.
      virtual void addToHead(value) = 0;
      // Add value on top of list.
      virtual void addToTail(value) = 0;
      // Add value on bottom of list.
      virtual void emplace(value, index_type) = 0;
      // Inserts value at position, shifting existing elements to the right.
      virtual value get(index_type) = 0;
      // Gets value by position.
      virtual void set(value, index_type) = 0;
      // Sets value by position.
      virtual void removeIndex(index_type) = 0;
      // Removes value by position.
      virtual void removeValue(value) = 0;
      // Removes all values that match.
      virtual void clear() = 0;
      // Clears list of all values.
    };
#endif // !LISTADT_HPP