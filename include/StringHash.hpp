//StringHash class, Private members of a string array,
//an array
#include <string>
#ifndef STRINGHASH_HPP
#define STRINGHASH_HPP

class StringHash{
private:    
    int size;
    std::string* table;
    int count;

    int getNextPrime(int n) const;
    bool isPrime(int n) const;
    int hash(const std::string &item) const;
    void grow();
    
    static const std::string EMPTY;
    static const std::string DELETED;
public:
    //constructor/destruction
    StringHash(int startSize = 11);
    ~StringHash();

    void addItem(const std::string &item);
    bool findItem(const std::string &item) const;
    void removeItem(const std::string &item);
    std::string displayTable() const;
};

#endif