// LINK - https://www.pepcoding.com/resources/online-java-foundation/hashmap-and-heap/hashmap-intro/video

// TC = O(1), SC = O(n)
#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    unordered_map<string, int> mp = {{"a", 1}, {"b", 2}, {"c", 3}};
    mp.insert(make_pair("d", 4));
    mp["e"] = 5;
    mp["f"] = 6;
    mp["g"] = 7;

    cout << "a " << mp.at("a") << endl;
    cout << "a " << mp["a"] << endl;
    cout << "a " << mp.find("a")->second << endl;

    for (auto itr = mp.begin(); itr != mp.end(); itr++)
    {
        cout << itr->first << " " << itr->second << endl;
    }

    mp["a"] = 11;
    cout << "a " << mp.at("a") << endl;

    cout << mp.bucket("f") << endl;
    cout << mp.bucket_count() << endl;
    cout << mp.count("a") << endl;
    cout << mp.size() << endl;
    cout << mp.max_size() << endl;
    cout << mp.empty() << endl;
    return 0;
}
