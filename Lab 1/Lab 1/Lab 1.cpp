#include <iostream>

template <typename T>
class sortedList
{
public:
    myList(T newData = NULL)
    {
        head = new node();
        head->data = newData;
        size++;
    }
    ~myList()
    {

    }

private:
    node* head = nullptr;
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