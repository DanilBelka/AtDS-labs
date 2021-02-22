#include <iostream>

template <typename T>
class sortedList
{
public:
    myList(bool (*compare)(T))
    {
        comporator = compare;
    }
    ~myList()
    {

    }


    size_t getSize()
    {
        return size;
    }


private:
    node* head = nullptr;
    bool (*comporator)(T) = nullptr;
    size_t size = 0;

    struct node
    {
    public:
        T data;
        node* next = nullptr;
    };
};

int main()
{

    return 0;
}