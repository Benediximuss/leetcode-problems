#include <iostream>
#include <vector>

using namespace std;

class MyHashMap {
public:
    MyHashMap()
        : hashArray(pow(10, 6) + 1, -1)
    {}

    void put(int key, int value) {
        this->hashArray[key] = value;
    }

    int get(int key) {
        return this->hashArray[key];
    }

    void remove(int key) {
        this->hashArray[key] = -1;
    }

private:
    vector<int> hashArray;
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */