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

            delete comporator;
        }
    };

    node* head = nullptr;
    bool (*comporator)(T, T) = nullptr;
    size_t size = 0;

public:
    myList(bool (*compare)(T, T))
    {
        comporator = compare;
    }
    ~myList()
    {
        if(head != nullptr)
            delete head;
    }


    size_t getSize()
    {
        return size;
    }
};

int main()
{

    return 0;
}