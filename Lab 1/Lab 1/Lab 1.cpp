#include <iostream>

template <typename T>
class sortedList
{
private:
    struct node
    {
    public:
        T data = NULL;
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

    myList.addElement(1);
    printList(&myList);

    myList.addElement(4);
    printList(&myList);

    myList.addElement(2);
    printList(&myList);

    myList.addElement(3);
    printList(&myList);

    myList.addElement(7);
    printList(&myList);

    myList.addElement(4);
    printList(&myList);

    myList.deleteElement(2);
    printList(&myList);

    std::cout << myList.indexOf(3) << '\n';

    return 0;
}