#include <iostream>
using namespace std;

template <class T>
class linklist                //template of linked list
{
private:
    struct link
    {
						//internal structure with data
        T data;
        link *next;
        ~link() noexcept
        {
            if(next)
            {
            delete next;
            cout << "link deleted" << endl;
            }

        }
    };
    link *first;
    link *last = nullptr;

public:
    linklist(): first(nullptr), last(first){}
    linklist(const T& x)
    {
        first = new link;
        first->data = x;
        last = first;
    };

/*    linklist(const linklist<T>& x) noexcept
    {

        {
            addlink(temp->data);
            temp = temp->next;
        }
    }*/

    ~linklist() noexcept
    {
        if(first)
        {
            delete first;
        cout << "first deleted" << endl;
        }
    }

   /* link<T> next()
    {
        if(first)
            return first->next;
        else
            return nullptr;
    }
*/
    void addlink(const T& d)
    {
        if(!first)
        {
            first = new link;
            first->data = d;
            first->next = nullptr;
            last = first;
        }
        else
        {
        link *newlink = new link;
        newlink->data = d;
        newlink->next = nullptr;
        last->next = newlink;
        last = newlink;
        }
    }
    void removelink(uint32_t pos)
    {
        if(pos == 0)
        {
            auto temp=first;
            first=first->next;
            temp->next=nullptr;
            delete temp;

        }
        else
        {
            auto temp = first;
            auto removedEl = first->next;
            for (uint32_t i = 0; i < pos - 1; ++i)
            {
                temp = temp->next;
                removedEl = removedEl->next;
                if(!removedEl)
                {
                    throw std::range_error("Error: call for element outside the list");
                }
            }
            temp->next=removedEl->next;
            removedEl->next=nullptr;
            if(removedEl == last)
            {
                last=temp;
            }
            delete removedEl;
        }
    }
    void editlink(int pos, const T& new_data)
    {

    }
    void print() const noexcept
    {
        auto temp = first;
        for(int32_t i = 0; temp!=nullptr; ++i)
        {
        cout << temp->data << ' ';
        temp = temp->next;
        }
    }

    T operator[](uint32_t pos) const
    {
        auto temp = first;
        for(uint32_t i = 0; i < pos; ++i)
        {
            temp = temp->next;
            if (!temp)
            {
                throw std::range_error("Error: call for element outside the list");
            }
        }
        return temp->data;
    }
};

int main()
{
    linklist<int> l;
    l.addlink(1);
    l.addlink(16);
    l.addlink(20);
    l.addlink(24);
    l.addlink(27);
    l.addlink(29);
    l.print();
    try
    {
    l.removelink(0);
    l.removelink(3);
    l.print();
    }
    catch(const std::exception& e){cout << e.what() << endl;}
    return 0;
}

