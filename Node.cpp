#include "Node.hpp"


template<typename T> Node<T>::Node(T data) : _data(data) 
{

}

template<typename T> Node<T>::~Node()
{
    for (auto child : _children)
    {
        delete child;
    }
}

template<typename T> void Node<T>::addChild(Node<T> child)
{
    _children.push_back(child);
}

template<typename T> void Node<T>::removeChild(Node<T> child)
{
    for (size_t i = 0; i < _children.size(); i++)
    {
        if (_children[i] == child)
        {
            long int index = static_cast<long int>(i);
            _children.erase(_children.begin() + index);
            return;
        }
    }
}

template<typename T> T Node<T>::getData()
{
    return _data;
}

template<typename T> Node<T> Node<T>::getChild(int index)
{
    if (index < 0 || index >= _children.size())
    {
        throw std::out_of_range("Index out of range");
    }
    size_t i = static_cast<size_t>(index);
    return _children[i];
}

template<typename T> std::vector<Node<T>> Node<T>::getChildren()
{
    return _children;
}