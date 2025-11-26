#include <iostream>
using namespace std;

struct Node {
    char key[50];
    char value[50];
    Node* next;
};

class HashTable {
private:
    Node* table[10];

public:
    HashTable() {
        for(int i = 0; i < 10; i++)
            table[i] = NULL;
    }

    int hashFunc(char s[]) {
        int sum = 0;
        for(int i=0; s[i] != '\0'; i++)
            sum += (int)s[i];
        return sum % 10;
    }

    void copyString(char dest[], char src[]) {
        int i = 0;
        while(src[i] != '\0') {
            dest[i] = src[i];
            i++;
        }
        dest[i] = '\0';
    }

    void insert(char key[], char value[]) {
        int index = hashFunc(key);
        Node* n = new Node;

        copyString(n->key, key);
        copyString(n->value, value);
        n->next = NULL;

        if(table[index] == NULL)
            table[index] = n;
        else {
            Node* temp = table[index];
            while(temp->next != NULL)
                temp = temp->next;
            temp->next = n;
        }

        cout << "[hint: key is " << key << "]" << endl;
    }

    void print() {
        for(int i = 0; i < 10; i++) {
            cout << "Bucket " << i << ": ";
            Node* temp = table[i];
            if(temp == NULL) {
                cout << "empty";
            }
            while(temp != NULL) {
                cout << "(" << temp->key << ", " << temp->value << ")";
                if(temp->next != NULL) cout << " -> ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

int main() {
    HashTable myhash;

    myhash.insert((char*)"A", (char*)"aaaaa");
    myhash.insert((char*)"B", (char*)"bbbbb");
    myhash.insert((char*)"C", (char*)"ccccc");
    myhash.insert((char*)"A", (char*)"zzzzz");

    myhash.print();

    return 0;
}
