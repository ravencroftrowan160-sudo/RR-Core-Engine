#include "StringHash.hpp"
#include <sstream>   // for displayTable()

const std::string StringHash::EMPTY = "_empty_";
const std::string StringHash::DELETED = "_deleted_";

//Constructor with every variable initiallized
StringHash::StringHash(int startSize) {
    if (startSize < 11)
        size = 11;
    else
        size = startSize;

    table = new std::string[size];
    count = 0;

    for (int i = 0; i < size; i++) {
        table[i] = EMPTY;
    }
}

StringHash::~StringHash(){
    delete[] table;
}

bool StringHash::isPrime(int n) const{
    if (n <= 1) return false;
    if (n <= 3) return true;
    if(n % 2 == 0 || n % 3 == 0){
        return false;
    }
    for(int i = 5; i * i <= n; i += 6){
        if(n % i == 0 || n % (i + 2) == 0){
            return false;
        }   
    }
    return true;
}

int StringHash::getNextPrime(int n) const {
    while (!isPrime(n)) {
        n++;
    }
    return n;
}

std::string StringHash::displayTable() const {
    std::ostringstream out;

    for (int i = 0; i < size; i++) {
        out << table[i] << "\n";
    }

    return out.str();
}

int StringHash::hash(const std::string &item) const {
    long hashValue = 0;

    for (char c : item) {
        hashValue *= 128;
        hashValue += static_cast<unsigned char>(c);
        hashValue %= size;
    }

    return static_cast<int>(hashValue);
}

void StringHash::grow(){
    int oldSize = size;
    size = getNextPrime(oldSize * 2);
    count = 0;

    //save old arrays
    std::string* oldTable = table;

    //Allocate new arrays
    table = new std::string[size];

    //Initiallize new arrays
    for(int i = 0; i < size; i++){
        table[i] = EMPTY;
    }
    

    // Reinsert all valid items
    for (int i = 0; i < oldSize; i++) {
        if (oldTable[i] != EMPTY && oldTable[i] != DELETED) {
            addItem(oldTable[i]);
        }
    }

    // Delete old arrays
    delete[] oldTable;
}

bool StringHash::findItem(const std::string &item) const {
    int index = hash(item);

    for (int i = 0; i < size; i++) {
        int probe = (index + i) % size;

        if (table[probe] == EMPTY)
            return false;

        if (table[probe] == item)
            return true;
    }
    return false;
}

void StringHash::removeItem(const std::string &item) {
    int index = hash(item);

    for (int i = 0; i < size; i++) {
        int probe = (index + i) % size;

        if (table[probe] == EMPTY)
            return;

        if (table[probe] == item) {
            table[probe] = DELETED;
            count--;
            return;
        }
    }
}

void StringHash::addItem(const std::string &item) {
    if (findItem(item))
        return;

    if (count > size / 2) {
        grow();
    }

    int index = hash(item);
    int firstDeleted = -1;

    for (int i = 0; i < size; i++) {
        int probe = (index + i) % size;

        if (table[probe] == EMPTY) {
            if (firstDeleted != -1)
                table[firstDeleted] = item;
            else
                table[probe] = item;

            count++;
            return;
        }

        if (table[probe] == DELETED && firstDeleted == -1) {
            firstDeleted = probe;
        }
    }

    if (firstDeleted != -1) {
        table[firstDeleted] = item;
        count++;
    }
}