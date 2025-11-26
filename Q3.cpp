#include <iostream>
#include <list>
using namespace std;

class Hash {
    int size;
    list<int>* table;

public:
    Hash(int s) {
        size = s;
        table = new list<int>[size];
    }

    int hashFunc(int key) {
        return key % size;
    }

    void insertItem(int key) {
        int idx = hashFunc(key);
        table[idx].push_back(key);
    }

    void deleteItem(int key) {
        int idx = hashFunc(key);
        table[idx].remove(key);
    }

    bool searchItem(int key) {
        int idx = hashFunc(key);
        for (int x : table[idx]) {
            if (x == key) return true;
        }
        return false;
    }

    void display() {
        for (int i = 0; i < size; i++) {
            cout << i << ": ";
            for (int x : table[i]) cout << x << " ";
            cout << endl;
        }
    }
};

int main() {
    Hash h(10);

    h.insertItem(12);
    h.insertItem(22);
    h.insertItem(42);
    h.insertItem(52);

    h.display();

    h.deleteItem(22);

    cout << h.searchItem(42) << endl;

    h.display();
}
