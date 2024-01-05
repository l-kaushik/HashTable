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
    void insert(T key,U value);

    //core functions
    std::size_t hashing(T key); //return index

    //getters
    U getValue(T key);  //@return value

    // Utility
    auto size() { return (array_of_buckets.size()); }
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
    array_of_buckets[hashing(key)] = new Node<U>(value); // try to use smart pointers

    //implement [] operator to store value
}

//core functions

template <typename T, typename U>
std::size_t HashTable<T, U>::hashing(T key)
{
    //TODO: int and int64_t both are different, so implement accordingly
    if(typeid(T) == typeid(int))    //! imagine T as int for now
    {
        // index
        return static_cast<std::size_t>(key) % size();
    }
    return 1;
}

//getters
template <typename T, typename U>
U HashTable<T, U>::getValue(T key)
{
    //get index from hashing function
    return array_of_buckets[hashing(key)]->getValue();
}


#endif