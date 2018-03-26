#include <iostream>
using namespace std;

int capacity_Of_array = 0;
int *arr = new int [capacity_Of_array];
int size = 0;

int Get(int i)
{
    if(i < 0 || i > capacity_Of_array)
    {
        cout<<"INDEX OUT OF BOUND EXCEPTION";
        return -1;

    }
    return arr[i];
}

void Set(int i, int val)
{
    if(i < 0 || i > capacity_Of_array)
    {
        cout<<"INDEX OUT OF BOUND EXCEPTION";
        return;
    }
    arr[i] = val;
        
}

void pushBack(int val)
{
    if(size == capacity_Of_array)
    {
        capacity_Of_array = 2 + capacity_Of_array * 2;
        int *temparr = new int[capacity_Of_array];
        for (int i = 0; i<size; i++)
        {
            temparr[i] = arr[i];
        }
        arr = temparr;
    }
    
    arr[size] = val;
    size++;
}

void Insert(int index, int value)
{
    if(size == capacity_Of_array)
    {
        capacity_Of_array = 2 + capacity_Of_array * 2;
        int *temparr = new int[capacity_Of_array];
        for (int i = 0; i<size; i++)
        {
            temparr[i] = arr[i];
        }
        arr = temparr;
    }
    
    for (int i = size; i>index; i--)
    {
        arr[i] = arr[i-1];
    }
    arr[index] = value;
    size++;
}

void Remove(int i) // remove value from the index 'i'
{
    if(i<0 || i > size)
    {
        cout<<"INDEX OUT OF BOUND EXCEPTION";
        return;
    }
    for (int index = i; index < size - 1; index++)
    {
        arr[index] = arr[index + 1];
    }
    size = size - 1;
}

void Display()
{
    for (int i = 0; i<size; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(int argc, const char * argv[])
{
    int i,j;
    
    int index,value;
    int count = 1;
    cout<< "Add the Numbers";
    while (cin>>i)
    {
        pushBack(i);
        count++;
        if(count > 5) break;
    }
    Display();
    /*
    cout<< "Index to Remove";
    while(cin >> j)
    {
        Remove(j);
        Display();
    }
     */
    cout<< "Input the Index then Value";
    while(cin >> index >> value)
    {
        //Remove(j);
        Insert(index, value);
        Display();
    }
    
    return 0;
}



