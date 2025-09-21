#include "container.hpp"

// // Default constructor
// Container::Container(size_t capacity)
// {
//     m_capacity = capacity;
//     m_size = 0;
//     m_data = new int[capacity];
// }
// // Copy constructor
// Container::Container(const Container &other)
// {
//     m_data = new int[other.m_capacity];
//     m_capacity = other.m_capacity;
//     m_size = other.m_size;
//     for (size_t i = 0; i < other.get_size(); ++i) {
//         m_data[i] = other.m_data[i];
//     }
// }
// // Destructor
// Container::~Container()
// {
//     delete[] m_data;
// }
// // expand with new capacity
// bool Container::expand(size_t new_capacity)
// {
//     if (new_capacity <= m_capacity) {
//         return false;  // No expansion needed
//     }
//     int* new_data = new int[new_capacity];
//     for (int i = 0 ; i < m_size; i++)
//         new_data[i] = m_data[i];
//     delete[] m_data;
//     m_data = new_data;
//     m_capacity = new_capacity;
//     return true;
// }
// // add new element
// bool Container::add(const int &item)
// {
//     if(m_size == m_capacity)
//         expand(m_size + 2);
//     m_data[m_size++] = item;
//     return true;
// }
// // remove elements
// bool Container::remove_item(const int &item)
// {
//     int index = 0;
//     for (size_t i = 0; i < m_size; ++i)
//     {
//         if(m_data[i] == item)
//         {
//             index = i;
//             break;
//         }
//     }
//     if(m_size == 0)
//         return false;
//     m_data[index] = m_data[m_size-1];
//     m_size--;
//     return true;
// }
// // remove everything
// bool Container::remove_all_items()
// {
//     while(remove_item(m_data[0]));
//     return true;
// }
// // get size
// size_t Container::get_size() const
// {
//     return m_size;
// }
// size_t Container::get_capacity() const
// {
//     return m_capacity;
// }
// int Container::get_data(size_t index) const
// {
//     if(index >= m_size)
//         throw out_of_range("Index out of range");
//     return m_data[index];
// }
// void Container::dummy_init()
// {
//     for (size_t i = 0; i < m_capacity; ++i) {
//         m_data[i] = i;  // Initialize all elements to their index
//     }
//     m_size = 5;
// }
