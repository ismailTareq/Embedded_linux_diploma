#ifndef __container_hpp__
#define __container_hpp__
#include <iostream>

using namespace std;

template <typename T>
class Container {
    static const int DEFAULT_CAPACITY = 10;
private:
    size_t m_capacity;
    size_t m_size;
    T *m_data;
public:
    Container<T>(size_t capacity = DEFAULT_CAPACITY);
    Container<T>(const Container<T> &other);
    ~Container();
    size_t get_size() const;
    size_t get_capacity() const;
    T get_data(size_t index) const;
    bool add(const T &item);
    bool remove_item(const T &item);
    bool expand(size_t new_capacity);
    bool remove_all_items();
    void dummy_init();
};
template <typename T>
inline ostream& operator<<(ostream& os, const Container<T>& obj)
{
    os << "container : [ size : " << obj.get_size() << ", capacity : " << obj.get_capacity() << ", elements : ";
    for (size_t i = 0; i < obj.get_size(); ++i) {
        os << obj.get_data(i);
    }
    os << " ]";
    return os;
}

// Default constructor
template <typename T>
Container<T>::Container(size_t capacity)
{
    m_capacity = capacity;
    m_size = 0;
    m_data = new T[capacity];
}
// Copy constructor
template <typename T>
Container<T>::Container(const Container &other)
{
    m_data = new T[other.m_capacity];
    m_capacity = other.m_capacity;
    m_size = other.m_size;
    for (size_t i = 0; i < other.get_size(); ++i) {
        m_data[i] = other.m_data[i];
    }
}
// Destructor
template <typename T>
Container<T>::~Container()
{
    delete[] m_data;
}
// expand with new capacity
template <typename T>
bool Container<T>::expand(size_t new_capacity)
{
    if (new_capacity <= m_capacity) {
        return false;  // No expansion needed
    }
    T* new_data = new T[new_capacity];
    for (int i = 0 ; i < m_size; i++)
        new_data[i] = m_data[i];
    delete[] m_data;
    m_data = new_data;
    m_capacity = new_capacity;
    return true;
}
// add new element
template <typename T>
bool Container<T>::add(const T &item)
{
    if(m_size == m_capacity)
        expand(m_size + 2);
    m_data[m_size++] = item;
    return true;
}
// remove elements
template <typename T>
bool Container<T>::remove_item(const T &item)
{
    int index = 0;
    for (size_t i = 0; i < m_size; ++i)
    {
        if(m_data[i] == item)
        {
            index = i;
            break;
        }
    }
    if(m_size == 0)
        return false;
    m_data[index] = m_data[m_size-1];
    m_size--;
    return true;
}
// remove everything
template <typename T>
bool Container<T>::remove_all_items()
{
    while(remove_item(m_data[0]));
    return true;
}
// get size
template <typename T>
size_t Container<T>::get_size() const
{
    return m_size;
}
// get capacity
template <typename T>
size_t Container<T>::get_capacity() const
{
    return m_capacity;
}
// get data
template <typename T>
T Container<T>::get_data(size_t index) const
{
    if(index >= m_size)
        throw out_of_range("Index out of range");
    return m_data[index];
}
template <typename T>
void Container<T>::dummy_init()
{
    for (size_t i = 0; i < m_capacity; ++i) {
        m_data[i] = i;  // Initialize all elements to their index
    }
    m_size = 5;
}

#endif // !__container_hpp__

