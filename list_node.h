#ifndef FORWARD_LIST_CONTAINER_FORWARD_LIST_NODE_H
#define FORWARD_LIST_CONTAINER_FORWARD_LIST_NODE_H

# include<memory>
namespace Container
{

    template <typename T> class forward_list; // forward declare
    template<typename T> class forward_list_iterator; // forward declare

    template<typename T>
    class forward_list_node
    {
        friend class forward_list_iterator<T>;
        friend class forward_list<T>;
    public:
        using value_type = T;
        using reference = value_type&;
        using const_reference = const value_type&;
        using _forward_list_node = typename Container::forward_list_node<T>;
        using _node_pointer = typename Container::forward_list_node<T>*;

    private:
        value_type _value;
        _node_pointer _next;
        explicit forward_list_node(const_reference value = value_type{}, _node_pointer next = nullptr) : _value(value), _next(next) {};
        ~forward_list_node() = default;
    };
}

#endif //FORWARD_LIST_CONTAINER_FORWARD_LIST_NODE_H