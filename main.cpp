
#include <iostream>
#include <vector>
#include <list>
using namespace std;

const int SIZE = 17;

// Mid-Square Hash Function
int hashFunction(int key)
{
    int square = key * key;

    // Extract middle two digits
    int middle = (square / 10) % 100;

    return middle % SIZE;
}

// Insert key into hash table
void insertKey(vector<list<int>>& table, int key)
{
    int index = hashFunction(key);

    table[index].push_back(key);

    cout << "Key " << key
         << " inserted at index " << index << endl;
}

// Display hash table
void displayTable(vector<list<int>>& table)
{
    cout << "\nFINAL HASH TABLE\n";

    for (int i = 0; i < SIZE; i++)
    {
        cout << i << " : ";

        if (table[i].empty())
        {
            cout << "NULL";
        }
        else
        {
            for (int key : table[i])
            {
                cout << key << " -> ";
            }

            cout << "NULL";
        }

        cout << endl;
    }
}

int main()
{
    // Personalized dataset
    vector<int> data = {
        97, 10, 23, 36, 49,
        62, 75, 88, 1, 14,
        27, 40, 53, 66, 79,
        92, 5, 18, 31, 44
    };

    vector<list<int>> table(SIZE);

    cout << "HASH TABLE IMPLEMENTATION\n";
    cout << "PRN: 202501100097\n";
    cout << "Hash Method: Mid-Square\n";
    cout << "Collision Method: Separate Chaining\n";

    cout << "\nINSERTION PROCESS\n";

    for (int key : data)
    {
        insertKey(table, key);
    }

    displayTable(table);

    return 0;
}
