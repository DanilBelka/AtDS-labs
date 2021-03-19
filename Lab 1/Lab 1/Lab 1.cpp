﻿#include <iostream>

template <typename T>
class sortedList
{
private:
    struct node
    {
    public:
        T data;
        node* next = nullptr;

        ~node()
        {
            if(next != nullptr)
                delete next;
        }
    };

    node* head = nullptr;
    bool (*comporator)(T, T) = nullptr;
    size_t size = 0;

public:
    sortedList(bool (*compare)(T a, T b))
    {
        comporator = compare;
    }
    ~sortedList()
    {
        if(head != nullptr)
            delete head;
    }


    size_t getSize()
    {
        return size;
    }

    void addElement(T newData)
    {
        if (size == 0)
        {
            head = new node;
            head->data = newData;
            size++;
        }
        else
        {
            node* tempNode = head;
            while (comporator(newData, tempNode->data) && tempNode->next != nullptr)
                tempNode = tempNode->next;

            node* newNode = new node;
            newNode->next = tempNode->next;
            newNode->data = tempNode->data;
            tempNode->next = newNode;
            tempNode->data = newData;

            size++;
        }
    }

    T operator[](unsigned int i)
    {
        node* temp = head;
        for (unsigned int j = 0; j < i; j++)
            temp = temp->next;

        return temp->data;
    }

    int indexOf(T searchData)
    {
        node* temp = head;
        unsigned int counter = 0;

        while (comporator(searchData, temp.data) && temp.next != nullptr)
        {
            counter++;
            temp = temp.next;
        }

        if (temp.data == searchData)
            return counter;
        else
            return -1;
    }
};

int main()
{
    sortedList<int> myList([](int a, int b) { return (a > b); });

    myList.addElement(1);
    for (int i = 0; i < myList.getSize(); i++)
    {
        std::cout << myList[i] << ", ";
    }
    std::cout << std::endl;

    myList.addElement(4);
    for (int i = 0; i < myList.getSize(); i++)
    {
        std::cout << myList[i] << ", ";
    }
    std::cout << std::endl;

    myList.addElement(2);
    for (int i = 0; i < myList.getSize(); i++)
    {
        std::cout << myList[i] << ", ";
    }
    std::cout << std::endl;

    myList.addElement(3);
    for (int i = 0; i < myList.getSize(); i++)
    {
        std::cout << myList[i] << ", ";
    }


    return 0;
}