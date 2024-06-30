//@author eylony1403@gmail.com

#pragma once

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include "Node.hpp"

template <typename T>
class InOrderIterator
{
private:
    std::vector<Node<T> *> inOrderList;

public:
    InOrderIterator(Node<T> *root)
    {
        std::stack<Node<T> *> s;
        Node<T> *curr = root;

        while (curr != nullptr || !s.empty())
        {
            // Reach the leftmost Node of the curr Node
            while (curr != nullptr)
            {
                s.push(curr);

                if (curr->get_children().empty())
                {
                    break;
                }

                curr = curr->get_child(0);
            }

            curr = s.top();
            s.pop();

            // Visit the node
            inOrderList.push_back(curr);

            // Now visit the right subtree
            if (curr->get_children().size() == 2)
            {
                curr = curr->get_child(1);
            }
            else
            {
                curr = nullptr;
            }
        }

        inOrderList.push_back(nullptr);
    }

    const T &operator*() const
    {
        // return *pointer_to_current_node;
        return inOrderList.front()->get_value();
    }

    const Node<T> *operator->() const
    {
        return inOrderList.front();
    }

    // ++i;
    InOrderIterator &operator++()
    {
        //++pointer_to_current_node;
        inOrderList.erase(inOrderList.begin());
        return *this;
    }

    // i++;
    // Usually iterators are passed by value and not by const& as they are small.
    const InOrderIterator operator++(int)
    {
        InOrderIterator tmp = *this;
        inOrderList.erase(inOrderList.begin());
        return tmp;
    }

    bool operator==(const InOrderIterator &rhs) const
    {
        // Directly compare the vectors for equality
        return inOrderList == rhs.inOrderList;
    }

    bool operator!=(const InOrderIterator &rhs) const
    {
        // Use the corrected operator== for comparison
        return !(*this == rhs);
    }
}; // END OF CLASS ITERATOR

template <typename T>
class PreOrderIterator
{
private:
    std::vector<Node<T> *> preOrderList;

public:
    PreOrderIterator(Node<T> *root)
    {
        std::stack<Node<T> *> s;
        Node<T> *curr = root;

        while (curr != nullptr || !s.empty())
        {
            // Reach the leftmost Node of the curr Node
            while (curr != nullptr)
            {
                s.push(curr);
                preOrderList.push_back(curr);

                if (curr->get_children().empty())
                {
                    break;
                }

                curr = curr->get_child(0);
            }

            curr = s.top();
            s.pop();

            // Visit the node

            // Now visit the right subtree
            if (curr->get_children().size() == 2)
            {
                curr = curr->get_child(1);
            }
            else
            {
                curr = nullptr;
            }
        }

        preOrderList.push_back(nullptr);
    }

    const T &operator*() const
    {
        // return *pointer_to_current_node;
        return preOrderList.front()->get_value();
    }

    const Node<T> *operator->() const
    {
        return preOrderList.front();
    }

    // ++i;
    PreOrderIterator &operator++()
    {
        //++pointer_to_current_node;
        preOrderList.erase(preOrderList.begin());
        return *this;
    }

    // i++;
    // Usually iterators are passed by value and not by const& as they are small.
    const PreOrderIterator operator++(int)
    {
        InOrderIterator tmp = *this;
        preOrderList.erase(preOrderList.begin());
        return tmp;
    }

    bool operator==(const PreOrderIterator &rhs) const
    {
        // Directly compare the vectors for equality
        return preOrderList == rhs.preOrderList;
    }

    bool operator!=(const PreOrderIterator &rhs) const
    {
        // Use the corrected operator== for comparison
        return !(*this == rhs);
    }
}; // END OF CLASS ITERATOR

template <typename T>
class PostOrderIterator
{
private:
    std::vector<Node<T> *> postOrderList;

public:
    PostOrderIterator(Node<T> *root)
    {
        std::stack<Node<T> *> s1, s2;
        Node<T> *curr = root;

        if (curr != nullptr)
            s1.push(curr);

        while (!s1.empty())
        {
            curr = s1.top();
            s1.pop();
            s2.push(curr);

            // Push left and right children of removed item to s1
            if (!curr->get_children().empty())
            {
                if (curr->get_children().size() >= 1)
                    s1.push(curr->get_child(0));
                if (curr->get_children().size() == 2)
                    s1.push(curr->get_child(1));
            }
        }

        // Collect the nodes from s2 to postOrderList
        while (!s2.empty())
        {
            postOrderList.push_back(s2.top());
            s2.pop();
        }

        postOrderList.push_back(nullptr); // Assuming you want to keep a nullptr at the end for some reason
    }

    const T &operator*() const
    {
        // return *pointer_to_current_node;
        return postOrderList.front()->get_value();
    }

    const Node<T> *operator->() const
    {
        return postOrderList.front();
    }

    // ++i;
    PostOrderIterator &operator++()
    {
        //++pointer_to_current_node;
        postOrderList.erase(postOrderList.begin());
        return *this;
    }

    // i++;
    // Usually iterators are passed by value and not by const& as they are small.
    const PostOrderIterator operator++(int)
    {
        InOrderIterator tmp = *this;
        postOrderList.erase(postOrderList.begin());
        return tmp;
    }

    bool operator==(const PostOrderIterator &rhs) const
    {
        // Directly compare the vectors for equality
        return postOrderList == rhs.postOrderList;
    }

    bool operator!=(const PostOrderIterator &rhs) const
    {
        // Use the corrected operator== for comparison
        return !(*this == rhs);
    }
}; // END OF CLASS ITERATOR

template <typename T>
class BFSIterator
{
private:
    std::vector<Node<T> *> bfsList;

public:
    BFSIterator(Node<T> *root)
    {
        std::queue<Node<T> *> q;
        Node<T> *curr = root;
        q.push(curr);

        while (!q.empty() && curr != nullptr)
        {
            curr = q.front();
            q.pop();
            bfsList.push_back(curr);

            for (size_t i = 0; i < curr->get_children().size(); i++)
            {
                q.push(curr->get_child(i));
            }
        }

        bfsList.push_back(nullptr); // Assuming you want to keep a nullptr at the end for some reason
    }

    const T &operator*() const
    {
        // return *pointer_to_current_node;
        return bfsList.front()->get_value();
    }

    Node<T> *operator->() const
    {
        return bfsList.front();
    }

    // ++i;
    BFSIterator &operator++()
    {
        //++pointer_to_current_node;
        bfsList.erase(bfsList.begin());
        return *this;
    }

    // i++;
    // Usually iterators are passed by value and not by const& as they are small.
    const BFSIterator operator++(int)
    {
        InOrderIterator tmp = *this;
        bfsList.erase(bfsList.begin());
        return tmp;
    }

    bool operator==(const BFSIterator &rhs) const
    {
        // Directly compare the vectors for equality
        return bfsList == rhs.bfsList;
    }

    bool operator!=(const BFSIterator &rhs) const
    {
        // Use the corrected operator== for comparison
        return !(*this == rhs);
    }
}; // END OF CLASS ITERATOR

template <typename T>
class DFSIterator
{
private:
    std::vector<Node<T> *> dfsList;

public:
    DFSIterator(Node<T> *root)
    {
        // Create a stack for DFS
        std::stack<Node<T> *> stack;

        // Push the current source node.
        Node<T> *curr = root;
        stack.push(curr);

        while (!stack.empty() && curr != nullptr)
        {
            curr = stack.top();
            stack.pop();
            dfsList.push_back(curr);

            if (curr->get_children().size() >= 1)
            {
                for (int i = curr->get_children().size() - 1; i >= 0; i--)
                {
                    std::size_t s = static_cast<std::size_t>(i);
                    stack.push(curr->get_child(s));
                }
            }
        }

        dfsList.push_back(nullptr); // Assuming you want to keep a nullptr at the end for some reason
    }

    const T &operator*() const
    {
        // return *pointer_to_current_node;
        return dfsList.front()->get_value();
    }

    const Node<T> *operator->() const
    {
        return dfsList.front();
    }

    // ++i;
    DFSIterator &operator++()
    {
        //++pointer_to_current_node;
        dfsList.erase(dfsList.begin());
        return *this;
    }

    // i++;
    // Usually iterators are passed by value and not by const& as they are small.
    const DFSIterator operator++(int)
    {
        InOrderIterator tmp = *this;
        dfsList.erase(dfsList.begin());
        return tmp;
    }

    bool operator==(const DFSIterator &rhs) const
    {
        // Directly compare the vectors for equality
        return dfsList == rhs.dfsList;
    }

    bool operator!=(const DFSIterator &rhs) const
    {
        // Use the corrected operator== for comparison
        return !(*this == rhs);
    }
}; // END OF CLASS ITERATOR

template <typename T>
class HeapIterator
{
private:
    std::vector<Node<T> *> heapList;

public:
    HeapIterator(Node<T> *root)
    {
        if (root != nullptr)
        {
            for (auto it = BFSIterator<T>(root); it != BFSIterator<T>(nullptr); ++it)
            {
                heapList.push_back(it.operator->());
            }

            std::make_heap(heapList.begin(), heapList.end());
        }

        heapList.push_back(nullptr); // Assuming you want to keep a nullptr at the end for some reason
    }

    const T &operator*() const
    {
        // return *pointer_to_current_node;
        return heapList.front()->get_value();
    }

    const Node<T> *operator->() const
    {
        return heapList.front();
    }

    // ++i;
    HeapIterator &operator++()
    {
        //++pointer_to_current_node;
        heapList.erase(heapList.begin());
        return *this;
    }

    // i++;
    // Usually iterators are passed by value and not by const& as they are small.
    const HeapIterator operator++(int)
    {
        InOrderIterator tmp = *this;
        heapList.erase(heapList.begin());
        return tmp;
    }

    bool operator==(const HeapIterator &rhs) const
    {
        // Directly compare the vectors for equality
        return heapList == rhs.heapList;
    }

    bool operator!=(const HeapIterator &rhs) const
    {
        // Use the corrected operator== for comparison
        return !(*this == rhs);
    }
}; // END OF CLASS ITERATOR