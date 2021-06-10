#ifndef NODE_HPP
  #define NODE_HPP
    template<typename value>
    struct Node
    {
      value data;
      Node* next;
    };
        
#endif // !NODE_HPP