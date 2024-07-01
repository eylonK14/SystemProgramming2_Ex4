//@author eylony1403@gmail.com

#pragma once

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

template <typename T>
class Node
{

public:
#include "Node.hpp"

    Node(T data) : _data(data)
    {
    }

    ~Node()
    {
        _children.clear();
    }

    void add_child(Node<T> *child)
    {
        if (std::find(child->_children.begin(), child->_children.end(), this) == child->_children.end())
        {
            _children.push_back(child);
        }
    }

    void remove_child(Node<T> *child)
    {
        if (std::find(this->_children.begin(), this->_children.end(), child) == this->_children.end())
        {
            throw std::invalid_argument("Not contains that child");
        }

        for (size_t i = 0; i < _children.size(); i++)
        {
            if (_children[i]->get_value() == child->get_value())
            {
                long int index = static_cast<long int>(i);
                _children.erase(_children.begin() + index);
                return;
            }
        }
    }

    const T &get_value() const
    {
        return _data;
    }

    Node<T> *&get_child(int index)
    {
        if (index < 0 || index >= _children.size())
        {
            throw std::out_of_range("Index out of range");
        }
        size_t i = static_cast<size_t>(index);
        return _children[i];
    }

    std::vector<Node<T> *> &get_children()
    {
        return _children;
    }

    bool operator==(const Node<T> &other) const
    {
        return _data == other._data;
    }

    bool operator!=(const Node<T> &other) const
    {
        return !(this == &other);
    }

    void drawNode(sf::RenderWindow &window, int depth, int x, int y)
    {
        // Draw filled circle (white)
        sf::CircleShape circle(35.f);
        circle.setFillColor(sf::Color::White);
        circle.setPointCount(1000);
        circle.setOutlineColor(sf::Color::Black);
        circle.setOutlineThickness(2.f);
        circle.setPosition(x, y);
        circle.setOrigin(circle.getRadius(), circle.getRadius());
        window.draw(circle);

        sf::Font font;
        font.loadFromFile("28 Days Later.ttf");

        // Display node value in the center
        sf::Text text;
        text.setFont(font);
        text.setString(std::to_string(this->_data));
        text.setCharacterSize(20);
        text.setFillColor(sf::Color::Black);
        sf::FloatRect textRect = text.getLocalBounds();
        text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
        text.setPosition(x, y);
        window.draw(text);

        // Draw lines to children
        float childYOffset = 110; // Adjust vertical offset for child nodes
        for (size_t i = 0; i < this->_children.size(); ++i)
        {
            int p = static_cast<int>(i);
            int s = static_cast<int>(this->_children.size());
            float childX = x + (p * (2 * 35.f + 50)) - (s * (35.f + 25)) + 60; // Adjust spacing
            float childY = y + childYOffset;
            sf::Vertex line[] = {sf::Vertex(sf::Vector2f(x, y + 35), sf::Color::Black), sf::Vertex(sf::Vector2f(childX, childY + 20), sf::Color::Black)};
            window.draw(line, 2, sf::Lines);
            this->_children[i]->drawNode(window, depth + 1, childX, childY);
        }
    }

private:
    T _data;
    std::vector<Node<T> *> _children;
};
