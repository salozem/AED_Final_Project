#include "Lista.hpp"

template<class T>
class HashTable {
    struct Entity {
        std::string key;
        T value;
        Entity(std::string key, T value) : key(key), value(value) {}
    };
    Lista<Entity>** ht;
    size_t bucketSize;
    std::function<void(Entity)> show;
public:
    HashTable(std::function<void(T)> show, size_t capacity) : bucketSize(capacity) {
        ht = new Lista<Entity>*[capacity];
        for (size_t i = 0; i < bucketSize; ++i)
            ht[i] = nullptr;
        this->show = [&show](Entity e) -> void {
            show(e.value);
        };
    }

    void insert(std::string key, T value) {
        size_t index = HashFunction(key);
        if (!ht[index])
            ht[index] = new Lista<Entity>(this->show);
        ht[index]->pushBack(Entity(key, value));
    }
    void print() {
        for (size_t i = 0; i < bucketSize; ++i) {
            std::cout << "\nIndex " << i << "\n";
            if (ht[i])
                ht[i]->print();
        }
    }
private:
    size_t HashFunction(std::string key) {
        size_t p = 0;
        for (size_t i = 0; i < key.length(); ++i) {
            int asciiValue = key[i];
            p += pow(asciiValue, i + 1);
        }
        return p % bucketSize;
    }
    // En hash tables sin listas
    size_t cuadraticProbing(size_t index) {
        size_t p = 1;
        size_t currentIndex = index;
        while (ht[index] != nullptr) {
            currentIndex = index;
            currentIndex += pow(p, 2);
            if (currentIndex >= bucketSize)
                currentIndex %= bucketSize;
        }
        return currentIndex;
    }
};