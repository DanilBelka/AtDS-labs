#include <iostream>

template <typename T>
class sortedList
{
public:

    struct node
    {
    public:
        T data;
        node* next;
    };

    myList(T newData = NULL)
    {
        data = newData;
    }
    ~myList()
    {

    }

private:
    bool* compare;
};

int main()
{

    return 0;
}