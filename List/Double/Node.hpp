#ifndef NODE_HPP
  #define NODE_HPP
    template<typename value>
    struct Node
    {
      value data;
      Node* next;
      Node* prev;
    };
        
#endif // !NODE_HPP