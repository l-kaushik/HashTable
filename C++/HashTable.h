#ifndef HASH_TABLE
#define HASH_TABLE

#include <iostream>
#include <vector>

#include "Node.h"

template <typename T, typename U>
class HashTable
{
private:
    std::vector<Node<U> *> array_of_buckets;

public:
    // constructors
    HashTable() : array_of_buckets(10) {}
    HashTable(int size);
    HashTable(size_t size) : array_of_buckets(size) {}

    //insertion
    void insert(T,U);

    // Utility
    int size() { return static_cast<int>(array_of_buckets.size()); }
    auto max_size() { return (array_of_buckets.max_size()); }
};

//<---------------------- Method Declarations ---------------------->

// constructor
template <typename T, typename U>
HashTable<T,U>::HashTable(int size) : array_of_buckets(static_cast<size_t>(size < 1 ? -1 * size : size))
{
    if (size < 1)
        std::cerr << "Warning: "
                  << "size = "
                  << size << " implicitly gets converted to "
                  << -1 * size << '\n';
}

//insertion
template <typename T, typename U>
void HashTable<T, U>::insert(T key, U value)
{
    //function to get index from key

    //implement [] operator to store value
}

#endif