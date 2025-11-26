#include <iostream>
using namespace std;

struct Node {
    char key[50];
    char value[50];
    Node* next;
};

class Dictionary {
private:
    Node* table[100];

public:
    Dictionary() {
        for (int i = 0; i < 100; i++)
            table[i] = NULL;
    }

    int hashFunction(char k[]) {
        int sum = 0;
        for (int i = 0; k[i] != '\0'; i++)
            sum += (int)k[i];
        return sum % 100;
    }

    void Add_Record(char key[], char value[]) {
        int index = hashFunction(key);
        Node* n = new Node;
        int i = 0;
        while (key[i] != '\0') { n->key[i] = key[i]; i++; }
        n->key[i] = '\0';
        i = 0;
        while (value[i] != '\0') { n->value[i] = value[i]; i++; }
        n->value[i] = '\0';
        n->next = NULL;

        if (table[index] == NULL) table[index] = n;
        else {
            Node* temp = table[index];
            while (temp->next != NULL) temp = temp->next;
            temp->next = n;
        }
    }

    void Word_Search(char key[]) {
        int index = hashFunction(key);
        Node* temp = table[index];
        while (temp != NULL) {
            int i = 0;
            bool match = true;
            while (key[i] != '\0' || temp->key[i] != '\0') {
                if (key[i] != temp->key[i]) { match = false; break; }
                i++;
            }
            if (match) {
                cout << "search key " << key << ": " << temp->value << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Key not found!" << endl;
    }

    void Delete_Record(char key[]) {
        int index = hashFunction(key);
        Node* temp = table[index];
        Node* prev = NULL;

        while (temp != NULL) {
            int i = 0;
            bool match = true;
            while (key[i] != '\0' || temp->key[i] != '\0') {
                if (key[i] != temp->key[i]) { match = false; break; }
                i++;
            }
            if (match) {
                if (prev == NULL) table[index] = temp->next;
                else prev->next = temp->next;
                delete temp;
                cout << "key " << key << " deleted successfully !" << endl;
                return;
            }
            prev = temp;
            temp = temp->next;
        }
        cout << "Key not found!" << endl;
    }

    void Print_Dictionary() {
        for (int i = 0; i < 100; i++) {
            if (table[i] != NULL) {
                cout << "index " << i << ": ";
                Node* temp = table[i];
                while (temp != NULL) {
                    cout << "(" << temp->key << ", " << temp->value << ")";
                    if (temp->next != NULL) cout << ", ";
                    temp = temp->next;
                }
                cout << endl;
            }
        }
    }
};

int main() {
    Dictionary d;
    d.Add_Record((char*)"AB", (char*)"FASTNU");
    d.Add_Record((char*)"CD", (char*)"CS");
    d.Add_Record((char*)"EF", (char*)"EE");

    d.Word_Search((char*)"AB");
    d.Delete_Record((char*)"EF");
    d.Print_Dictionary();

    return 0;
}
