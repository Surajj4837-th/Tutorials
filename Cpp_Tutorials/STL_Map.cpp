// Map
#include <iostream>
#include <map>

using std::cout;
using std::endl;

int main()
{

    //---------------------------------- ----------------------------------
    // Create a map of strings to integers
    std::map<std::string, int> map1;

    // Insert some values into the map1
    map1["one"] = 1;
    map1["two"] = 2;
    map1["three"] = 3;

    // Get an iterator pointing to the first element in the map1
    std::map<std::string, int>::iterator it = map1.begin();

    // Iterate through the map1 till the end and print the elements
    while (it != map1.end())
    {
        std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
        ++it;
    }

    // Print the size of the map1
    std::cout << "Size of map1: " << map1.size() << std::endl;


    //insert elements in map1 using std::pair 
    map1.insert(std::pair<std::string, int>("four", 4));
    map1.insert(std::pair<std::string, int>("five", 5));
    map1.insert(std::pair<std::string, int>("six", 6));
    map1.insert(std::pair<std::string, int>("six", 66));    //

    //insert using []
    map1["seven"] = 7;
    
    it = map1.begin();
    while (it != map1.end())
    {
        std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
        ++it;
    }


    //assign elements from an object to another
    std::map<std::string, int> map2(map1.begin(), map1.end());

    //find key "three", find() return an iterator to the item
    cout << map2.find("three")->second << endl;
    cout << map2.find("ten")->second << endl;   //find non-existent key

    //delete entry with key 6
    int num = map2.erase("six");
    cout << "erase(\"six\") : " << num << " removed \n";

    //------------------------------------------------------------------------

    return 0;
}
/************************************Summary*****************************************
1. Maps are associative containers that store elements in a mapped fashion. Each element 
   has a key value and a mapped value. 

2. No two mapped values can have the same keys.

3. Map does not accept duplicate keys.

4. Capacity
        empty:      checks whether the container is empty

        size:       returns the number of elements

        max_size:   returns the maximum possible number of elements

5. Modifiers
        clear:      clears the contents

        insert:     inserts elements or nodes

        insert_range:   inserts a range of elements

        insert_or_assign:   inserts an element or assigns to the current element if 
                            the key already exists

        emplace:    constructs element in-place

        emplace_hint:   constructs elements in-place using a hint

        try_emplace:    inserts in-place if the key does not exist, does nothing if 
                        the key exists
                        
        erase:      erases elements

        swap:       swaps the contents

        extract:    extracts nodes from the container

        merge:      splices nodes from another container

6. Lookup
        count:      returns the number of elements matching specific key

        find:       finds element with specific key

        contains:   checks if the container contains element with specific key

        equal_range:    returns range of elements matching a specific key

        lower_bound:    returns an iterator to the first element not less than the 
                        given key

        upper_bound:    returns an iterator to the first element greater than the 
                        given key

7. Observers
        key_comp:       returns the function that compares keys

        value_comp:     returns the function that compares keys in objects of type 
                        value_type

************************************************************************************/