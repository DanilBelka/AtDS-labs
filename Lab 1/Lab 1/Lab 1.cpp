﻿#include <iostream>

template <typename T>
class sortedList
{
private:
    //structure for elements of list
    struct node
    {
    public:
        T data = NULL;
        node* next = nullptr;

        //recursive destructor
        ~node()
        {
            if(next != nullptr)
                delete next;
        }
    };

    node* head = nullptr;               //first element of list
    bool (*comporator)(T, T) = nullptr; //function pointer for sorting
    size_t size = 0;

public:
    sortedList(bool (*compare)(T a, T b))
    {
        comporator = compare;
    }
    ~sortedList()
    {
        delete head;
    }


    size_t getSize()
    {
        return size;
    }

    void addElement(T newData)
    {
        //better is not to touch this method :|
        if (size == 0)
        {
            head = new node;
            head->data = newData;
            head->next = nullptr;
            size++;
        }
        else
        {
            node* tempNode = head;
            
            if (comporator(newData, head->data))
            {
                node* newNode = new node;
                newNode->next = head->next;
                newNode->data = head->data;

                head->next = newNode;
                head->data = newData;
            }
            else
            {
                while (!comporator(tempNode->data, newData) && tempNode->next != nullptr)
                    tempNode = tempNode->next;
                if (tempNode->next != nullptr)
                {
                    while (tempNode->next != nullptr)
                    {
                        if (comporator(newData, tempNode->next->data))
                            break;
                        else
                            tempNode = tempNode->next;
                    }
                        

                    node* newNode = new node;
                    newNode->next = tempNode->next;
                    newNode->data = newData;

                    tempNode->next = newNode;
                }
                else
                {
                    node* newNode = new node;
                    newNode->data = newData;
                    tempNode->next = newNode;
                }
                
            }

            size++;
        }
    }

    void deleteElement(unsigned int index)
    {
        if (index < size)
        {
            if (index == 0)
            {
                node* toDelete = head;
                head = head->next;

                toDelete->next = nullptr;
                delete toDelete;
            }
            else if (index == size - 1)
            {
                node* toDelete = head;
                for (unsigned int i = 0; i <= index; i++)
                    toDelete = toDelete->next;

                delete toDelete;
            }
            else
            {
                node* toDelete = head;
                node* prev = nullptr;
                for (unsigned int i = 0; i < index; i++)
                {
                    prev = toDelete;
                    toDelete = toDelete->next;
                }

                prev->next = toDelete->next;
                toDelete->next = nullptr;

                delete toDelete;
            }
        }

        size--;
    }

    //there is not link T cause there is only getter must be
    T operator[](unsigned int i)
    {
        node* temp = head;
        for (unsigned int j = 0; j < i; j++)
            temp = temp->next;

        return temp->data;
    }

    // if there is no such element returns -1
    int indexOf(T searchData)
    {
        node* tempNode = head;
        unsigned int index = -1;
        while (tempNode != nullptr)
        {
            if (tempNode->data == searchData)
            {
                index++;
                break;
            }
            else
            {
                tempNode = tempNode->next;
                index++;
            }
        }

        return index;
    }

    void cleanList()
    {
        delete head->next;
        head = nullptr;
        size = 0;
    }

    bool isEmpty() { return (size == 0) ? true : false; }

    sortedList<T>* copyReverse()
    {
        sortedList<T>* L1 = new sortedList([](int a, int b) {return (a > b); });
        for (unsigned int i = 0; i < this->getSize(); i++)
            L1->addElement((*this)[i]);

        return L1;
    }
};

template <typename T>
void printList(sortedList<T>* list)
{
    for (unsigned int i = 0; i < list->getSize(); i++)
        std::cout << (*list)[i] << ", ";
    std::cout << std::endl;
}

int main()
{
    sortedList<int> myList([](int a, int b) { return (a > b); });


    myList.addElement(1); // 1
    printList(&myList);

    myList.addElement(4); // 4, 1
    printList(&myList);

    myList.addElement(2); // 4, 2, 1
    printList(&myList);

    myList.addElement(3); // 4, 3, 2, 1
    printList(&myList);

    myList.addElement(7); // 7, 4, 3, 2, 1
    printList(&myList);

    myList.addElement(4); // 7, 4, 4, 3, 2, 1
    printList(&myList);

    myList.deleteElement(2); // 7, 4, 3, 2, 1
    printList(&myList);

    std::cout << myList.indexOf(3) << '\n'; // 2
    std::cout << myList.indexOf(7) << '\n'; // 0
    std::cout << myList.indexOf(1) << '\n'; // 4

    //myList.cleanList();
    std::cout << myList.isEmpty();
    std::cout << '\n';

    sortedList<int> L1 = *(myList.copyReverse());
    printList(&L1);


    return 0;
}