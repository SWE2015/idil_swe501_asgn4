#include <iostream>

using namespace std;

template <class ItemType>
class QueType
{
    public:
        QueType(int MAX);
        QueType();
        void makeEmpty();
        bool isEmpty() const;
        bool isFull() const;
        void enqueue (ItemType item);
        void dequeue ();
        ~QueType();
    protected:
    private:
        int MAX_ITEMS;
        int rearOfQue;
        int frontOfQue;
        ItemType * items;
};

template <class ItemType>
QueType<ItemType>::QueType(int MAX)
{
    MAX_ITEMS = MAX;
    items = new ItemType[MAX_ITEMS];
    rearOfQue = MAX_ITEMS - 1;
    frontOfQue = MAX_ITEMS -1;
}

// default size is 500
template <class ItemType>
QueType<ItemType>::QueType()
{
    MAX_ITEMS = 500;
    items = new ItemType[MAX_ITEMS];
    rearOfQue = MAX_ITEMS - 1;
    frontOfQue = MAX_ITEMS -1;
}


template <class ItemType>
QueType<ItemType>::~QueType()
{
    delete [] items;
}

template <class ItemType>
void QueType<ItemType>::makeEmpty()
{
    rearOfQue = MAX_ITEMS - 1;
    frontOfQue = MAX_ITEMS -1;
}

template <class ItemType>
bool QueType<ItemType>::isEmpty() const
{
    return (rearOfQue==frontOfQue);
}

template <class ItemType>
bool QueType<ItemType>::isFull() const
{
    return ((rearOfQue+1) % MAX_ITEMS == frontOfQue);
}

template <class ItemType>
void QueType<ItemType>::enqueue (ItemType item)
{
    if (isFull())
        cout << "Queue is full, cannot enque" << endl;
    else{
        rearOfQue = (rearOfQue + 1) % MAX_ITEMS;
        items[rearOfQue] = item;
    }
}

template <class ItemType>
void QueType<ItemType>::dequeue ()
{
    if (isEmpty())
        cout << "Queue is empty, cannot deque" << endl;
    else{
        frontOfQue = (frontOfQue + 1) % MAX_ITEMS;
        cout << items[frontOfQue] << endl;
    }
}

using namespace std;

int main()
{
    QueType <int> a(50);

    a.enqueue(3);
    a.enqueue(7);
    a.enqueue(12);
    cout << "3 items are enqueued" << endl;

    cout << "dequeue first item:" << endl;
    a.dequeue();

    cout << "check isFull: " << a.isFull() << endl;

    cout << "dequeue second item:" << endl;
    a.dequeue();

    cout << "check isEmpty: " << a.isEmpty() << endl;

    cout << "dequeue last item:" << endl;
    a.dequeue();

    cout << "check is empty after last dequeue: " << a.isEmpty() << endl;

    cout << "enqueue one item" << endl;
    a.enqueue(4);

    cout << "check is empty: " << a.isEmpty() << endl;

    a.makeEmpty();
    cout << "check is empty after make empty: " << a.isEmpty() << endl;
}
