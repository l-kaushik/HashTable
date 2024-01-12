#ifndef HASH_TABLE
#define HASH_TABLE

#include <iostream>
#include <type_traits>
#include <vector>

#include "Node.h"

template <typename T, typename U>
class HashTable
{
private:
    std::vector<Node<U> *> array_of_buckets;
    
    //helper functions for insertion
    std::size_t hashingHelper(T key, std::true_type);
    std::size_t hashingHelper(T key, std::false_type);

public:
    // constructors
    HashTable() : array_of_buckets(10) {}
    HashTable(int size);
    HashTable(size_t size) : array_of_buckets(size) {}

    // insertion
    void insert(T key, U value);
 
    // core functions
    std::size_t hashing(T key); // return index;

    // getters
    U getValue(T key); //@return value

    // Utility
    auto size() { return (array_of_buckets.size()); }
    auto max_size() { return (array_of_buckets.max_size()); }
};

//<---------------------- Method Declarations ---------------------->

// constructor
template <typename T, typename U>
HashTable<T, U>::HashTable(int size) : array_of_buckets(static_cast<size_t>(size < 1 ? -1 * size : size))
{
    if (size < 1)
        std::cerr << "Warning: "
                  << "size = "
                  << size << " implicitly gets converted to "
                  << -1 * size << '\n';
}

// insertion
template <typename T, typename U>
void HashTable<T, U>::insert(T key, U value)
{
    // function to get index from key
    std::size_t index {hashing(key)};

    // check if place is already equipped
    if(array_of_buckets[index] == nullptr)
        array_of_buckets[index] = new Node<U>(value); // try to use smart pointers
    else{
        // added value in next node
        Node<U> *temp = array_of_buckets[index];
        while(temp->getNextNode() != nullptr)
        {
            temp = temp->getNextNode();
        }
        temp->setNextNode(new Node<U>(value));
    }

    // implement [] operator to store value
}

// core functions
template <typename T, typename U>
std::size_t HashTable<T, U>::hashing(T key)
{
    return hashingHelper(key, std::is_arithmetic<T>{});
}

//helper functions
template <typename T, typename U>
std::size_t HashTable<T, U>::hashingHelper(T key, std::true_type) {
    return static_cast<std::size_t>(key) % size();
}

template <typename T, typename U>
std::size_t HashTable<T, U>::hashingHelper(T key, std::false_type) {
    std::size_t alpha_count{};
    for(auto &i: key)
        alpha_count += static_cast<std::size_t>(i);

    return alpha_count % size();
}

// getters
template <typename T, typename U>
U HashTable<T, U>::getValue(T key)
{
    // get index from hashing function
    return array_of_buckets[hashing(key)]->getValue();
}

#endif