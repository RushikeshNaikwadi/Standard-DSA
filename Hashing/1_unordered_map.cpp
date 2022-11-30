#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct kvNode {
    string key;
    T val;
    kvNode <T> *next;

    kvNode (string Key, T Val) {
        key = Key;
        val = Val;
        next = NULL;
    }

    ~kvNode() {
        if (next != NULL) {
            delete next;
        }
    }
};

template <typename T>
struct Hashtable {
    int eleCnt = 0;            // Number of elements in Hashtable => Rehashing
    int tabSize = 0;          // Size of Hashtable
    kvNode <T> ** bucList;

    Hashtable (int mS = 11) {
        tabSize = mS;
        bucList = new kvNode<T>* [tabSize];

        for (int i = 0; i < tabSize; i++) {
            bucList[i] = NULL; 
        }
    }

    void reHash() {
        float loadFactor = 1.0 * eleCnt / tabSize; // if loadFactor > 0.7 (threshold val) we do rehashing to maintain TC

        if (loadFactor <= 0.7)
            return;

        kvNode <T> **oldBucList = bucList;
        int oldBucSize = tabSize;

        tabSize = 2 * tabSize;  // Try to keep size as next bigger prime number
        eleCnt = 0;

        bucList = new kvNode<T>* [tabSize];
        for (int i = 0; i < oldBucSize; i++) {
            bucList[i] = NULL;
        }

        for (int i = 0; i < oldBucSize; i++) {
            kvNode <int> *head = oldBucList[i];
            while (head != NULL) {
                insert(head->key, head->val);
                head = head -> next;
            }
            delete oldBucList[i];
        }
        delete [] oldBucList;
    }

    int hashFun (string key) {
        int len = key.size();
        int multiplier = 1;     // will mutliply by prime number to some power everytime to reduce chances of collision, here 37
        
        int hashVal = 0;
        for (int i = 0; i < len; i++) {
            hashVal += (key[i] * multiplier);
            hashVal %= tabSize;

            multiplier *= 37;
            multiplier %= tabSize;
        }

        return hashVal;
    }

    void insert(string key, T val) {
        int hashVal = hashFun(key);

        eleCnt++;
        reHash();

        kvNode <T> *head = new kvNode <T> (key, val);
        head->next = bucList[hashVal];
        bucList[hashVal] = head;
    }

    T search(string key) {
        int hashVal = hashFun(key);
        kvNode <T> *head = bucList[hashVal];
    
        while (head != NULL) {
            if (head->key == key) {
                return head->val;
            }
            head = head->next;
        }

        return -1;
    }

    void deleteEntry (string key) {
        int hashVal = hashFun(key);
        kvNode <T> *cur = bucList[hashVal];
        kvNode <T> *prev = NULL;

        while (cur != NULL) {
            kvNode <T> *next = cur->next;
            if (cur->key == key) {
                if (prev == NULL) {
                    bucList[hashVal] = next;
                } else {
                    prev->next = next;
                }
                return;
            }
            prev = cur;
            cur = next;
        }
    }

    void print() {
        for (int i = 0; i < tabSize; i++) {
            cout << "|" << i << "| -> ";
            kvNode <T> *head = bucList[i];
            while (head != NULL) {
                cout << "[" << head->key << ", " << head->val << "]";
                if (head->next != NULL) cout << " -> ";
                head = head->next;
            }
            cout << endl;
        }
        cout << endl;
    }
};

int main () {
    Hashtable <int> ht(7);
    ht.insert("mango", 100);
    ht.insert("cane", 120);
    ht.insert("kivi", 65);

    ht.print();

    ht.insert("jamun", 40);
    ht.insert("banana", 20);
    ht.insert("apple", 20);
    ht.insert("watermelon", 20);
    ht.insert("guava", 20);

    ht.print();
    
    cout << ht.search("grape") << endl;

    ht.deleteEntry("banana");
    cout << ht.search("apple") << endl;

    return 0;
}