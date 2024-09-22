#ifndef HASH_TABLE
#define HASH_TABLE

#include <iostream>
#include <type_traits>
#include <vector>
#include <utility> // for std::pair
#include <iomanip>

#include "Node.h"

/*
    TODO:
    *maybe use of smart pointers
    *dynamic resizing(rehashing)
    *each key should be unique
*/

template <typename T, typename U>
class HashTable
{
private:
    std::vector<Node<std::pair<T, U>> *> array_of_buckets;
    
    //helper functions for insertion
    std::size_t hashingHelper(T key, std::true_type);
    std::size_t hashingHelper(T key, std::false_type);

public:
    // constructors
    HashTable() : array_of_buckets(10) {}
    HashTable(int size);
    HashTable(size_t size) : array_of_buckets(size) {}

    // destructor
    ~HashTable();

    // insertion
    void insert(T key, U value);
 
    // core functions
    std::size_t hashing(T key); // return index;

    // getters
    auto getValue(T key); //@return value

    // Utility
    auto size() { return (array_of_buckets.size()); }
    auto max_size() { return (array_of_buckets.max_size()); }

    //other
    void display();
};

//<---------------------- Method Declarations ---------------------->

// constructor
template <typename T, typename U>
HashTable<T, U>::HashTable(int size) : array_of_buckets(static_cast<size_t>(size < 1 ? std::abs(size) : size))
{
    if (size < 1)
        std::cerr << "Warning: "
                  << "size = "
                  << size << " implicitly gets converted to "
                  << -1 * size << '\n';
}

// destructor
template <typename T, typename U>
HashTable<T, U>::~HashTable()
{
    for(auto &i: array_of_buckets){
        delete i;
        i = nullptr;
    }
}

// insertion
template <typename T, typename U>
void HashTable<T, U>::insert(T key, U value)
{
    // function to get index from key
    std::size_t index {hashing(key)};

    // check if place is already equipped
    if(array_of_buckets[index] == nullptr)
        array_of_buckets[index] = new Node<std::pair<T, U>>({key, value}); // try to use smart pointers
    else{
        // append a node
        Node<std::pair<T, U>> *temp {new Node<std::pair<T, U>>({key, value})};
        temp->setNextNode(array_of_buckets[index]);
        array_of_buckets[index] = temp;      
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
auto HashTable<T, U>::getValue(T key)
{
    // get index from hashing function
    std::size_t index {hashing(key)};

    Node<std::pair<T, U>> *temp {array_of_buckets[index]};

    //TODO: raise an error if first/key not found
    while(temp->getValue().first != key && temp != nullptr)
    {
        temp = temp->getNextNode();
    }

    if(temp != nullptr)
        return temp->getValue().second;
    else
        return 0;   //TODO: raise an error here too
}

// other
template <typename T, typename U>
void HashTable<T, U>::display()
{
    for(auto &i: array_of_buckets)
    {
        while(i != nullptr)
        {
            std::cout<<std::setw(6)<<i->getValue().first<<std::setw(10)<<i->getValue().second<<'\n';
            i = i->getNextNode();
        }
    }
}

#endif