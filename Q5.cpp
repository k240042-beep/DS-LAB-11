#include <iostream>
using namespace std;

class StudentHashTable {
private:
    struct Record {
        int roll;
        char name[50];
        bool occupied;
    } table[15];

public:
    StudentHashTable() {
        for(int i = 0; i < 15; i++)
            table[i].occupied = false;
    }

    int hashFunction(int roll) {
        return roll % 15;
    }

    void InsertRecord(int roll, char name[]) {
        int index = hashFunction(roll);
        int attempt = 0;

        while(attempt < 15) {
            int newIndex = (index + attempt * attempt) % 15;

            if(!table[newIndex].occupied) {
                table[newIndex].roll = roll;
                int i = 0;
                while(name[i] != '\0') {  
                    table[newIndex].name[i] = name[i];
                    i++;
                }
                table[newIndex].name[i] = '\0';
                table[newIndex].occupied = true;
                return;
            }
            attempt++;
        }
        cout << "Table Full\n";
    }

    void SearchRecord(int roll) {
        int index = hashFunction(roll);
        int attempt = 0;

        while(attempt < 15) {
            int newIndex = (index + attempt * attempt) % 15;

            if(table[newIndex].occupied && table[newIndex].roll == roll) {
                int i = 0;
                while(table[newIndex].name[i] != '\0') {  
                    cout << table[newIndex].name[i];
                    i++;
                }
                return;
            }
            attempt++;
        }
        cout << "Record not found";
    }
};

int main() {
    StudentHashTable ht;

    char name1[] = {'A','l','i','\0'};
    char name2[] = {'S','a','r','a','\0'};
    char name3[] = {'U','m','e','r','\0'};

    ht.InsertRecord(10, name1);
    ht.InsertRecord(25, name2);
    ht.InsertRecord(40, name3);

    ht.SearchRecord(25);
}
