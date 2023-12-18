// LINK - https://www.pepcoding.com/resources/online-java-foundation/hashmap-and-heap/hashmap-official/ojquestion

// TC = O(1), SC = O(1)
#include <iostream>
#include <functional>
#include <forward_list>
#include <utility>
#include <vector>
#include <string>
using namespace std;

template <typename K, typename V>
class HashMap
{
private:
    class HMNode
    {
    public:
        K key;
        V value;
        HMNode(K key, V value)
        {
            this->key = key;
            this->value = value;
        }
    };

    int map_size;
    vector<forward_list<HMNode *>> buckets;

    int hashFunction(K key)
    {
        hash<K> hash;
        int hv = hash(key);
        return abs(hv) % buckets.size();
    }

    HMNode *getNodeWithinBucket(K key, int bi)
    {
        for (HMNode *node : buckets[bi])
        {
            if (node->key == key)
            {
                return node;
            }
        }
        return NULL;
    }

    void rehash()
    {
        vector<forward_list<HMNode *>> old_buckets = buckets;
        buckets.resize(buckets.size() * 2);
        map_size = 0;

        for (auto &&list : old_buckets)
        {
            for (auto &&node : list)
            {
                put(node->key, node->value);
            }
        }
    }

public:
    HashMap()
    {
        buckets.resize(4);
        map_size = 0;
    }
    void
    put(K key, V val)
    {
        int bi = hashFunction(key);
        HMNode *node = getNodeWithinBucket(key, bi);

        if (node != NULL)
        {
            node->value = val;
        }
        else
        {
            HMNode *newNode = new HMNode(key, val);
            buckets[bi].push_front(newNode);
            map_size++;
        }

        double lambda = size() * 1.0 / buckets.size();
        if (lambda > 2.0)
        {
            rehash();
        }
    }

    V get(K key)
    {
        int bi = hashFunction(key);
        HMNode *node = getNodeWithinBucket(key, bi);

        if (node != NULL)
        {
            return node->value;
        }
        return V();
    }

    bool containsKey(K key)
    {
        int bi = hashFunction(key);
        HMNode *node = getNodeWithinBucket(key, bi);

        if (node != NULL)
        {
            return true;
        }
        return false;
    }

    V remove(K key)
    {
        int bi = hashFunction(key);
        HMNode *node = getNodeWithinBucket(key, bi);

        if (node != NULL)
        {
            V val = node->value;
            buckets[bi].remove(node);
            map_size--;
            return val;
        }
        return V();
    }

    vector<K> keyset()
    {
        vector<K> keys;
        for (auto &&list : buckets)
        {
            for (auto &&node : list)
            {
                keys.push_back(node->key);
            }
        }
        return keys;
    }

    int size()
    {
        return map_size;
    }

    void display()
    {
        cout << "Display Begins" << endl;
        for (int bi = 0; bi < buckets.size(); bi++)
        {
            cout << "Bucket" << bi << " ";
            for (HMNode *node : buckets[bi])
            {
                cout << node->key << "@" << node->value << " ";
            }
            cout << "." << endl;
        }
        cout << "Display Ends" << endl;
    }
};

int main()
{

    HashMap<string, int> map;
    string str;
    cin >> str;

    while (str != "quit")
    {
        if (str == "put")
        {
            string key;
            cin >> key;
            int val;
            cin >> val;
            map.put(key, val);
        }
        else if (str == "get")
        {
            string key;
            cin >> key;
            int val = map.get(key);
            if (val)
            {
                cout << val << endl;
            }
            else
            {
                cout << "null" << endl;
            }
        }

        else if (str == "containsKey")
        {
            string key;
            cin >> key;
            map.containsKey(key) ? cout << "true" << endl : cout << "false" << endl;
        }
        else if (str == "remove")
        {
            string key;
            cin >> key;
            int val = map.remove(key);
            if (val)
            {
                cout << val << endl;
            }
            else
            {
                cout << "null" << endl;
            }
        }
        else if (str == "size")
        {
            cout << map.size() << endl;
        }
        else if (str == "keyset")
        {
            for (auto &&key : map.keyset())
            {
                cout << key << " ";
            }
            cout << endl;
        }
        else if (str == "display")
        {
            map.display();
        }

        cin >> str;
    }

    return 0;
}