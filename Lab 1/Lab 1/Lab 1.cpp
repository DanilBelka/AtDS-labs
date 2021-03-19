#include <iostream>

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
        node tempNode = this.head;
        while (comporator(newData, tempNode.data) && tempNode.next != nullptr)
            tempNode = tempNode.next;

        T tempData = tempNode.data;
        tempNode.data = newData;
        node* newNode = new node;
        newNode.data = tempData;
        newNode.next = tempNode.next;
        tempNode.next = newNode;
    }

    T operator[](unsigned int i)
    {
        node* temp = head;
        for (unsigned int j = 0; j < i; j++)
            temp = temp.next;

        return temp.data;
    }

    int indexOf(T searchData)
    {
        node temp = this.head;
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

    std::cout << myList[0] << '\n';

    return 0;
}