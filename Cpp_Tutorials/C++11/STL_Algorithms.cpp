// Algorithms
#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;

void printVec(const std::vector <int> vec)
{
    for(int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << ", " ;
    }
    cout << endl;

}

int main()
{

    //---------------------------------- ----------------------------------
    std::vector<int> vec1{1,2,3,4,5,6};

    //all_of
    cout << "All elements less than 10: " << std::all_of(vec1.cbegin(), vec1.cend(), [](int i){ return i < 10; }) << endl;
    cout << "All elements less than 4: " << std::all_of(vec1.cbegin(), vec1.cend(), [](int i){ return i < 4; }) << endl;

    //any_of
    cout << "Any elements less than 0: " << std::any_of(vec1.cbegin(), vec1.cend(), [](int i){ return i < 0; }) << endl;
    cout << "Any elements less than 4: " << std::any_of(vec1.cbegin(), vec1.cend(), [](int i){ return i < 4; }) << endl;

    //none_of
    cout << "None of the elements less than 0: " << std::none_of(vec1.cbegin(), vec1.cend(), [](int i){ return i < 0; }) << endl;
    cout << "None of the elements less than 4: " << std::none_of(vec1.cbegin(), vec1.cend(), [](int i){ return i < 4; }) << endl;

    //for each
    std::for_each(vec1.begin(), vec1.end(), [](int &n) { n++; });   //increment each element of vec1

    printVec(vec1);

    //count
    const int num_items = std::count(vec1.cbegin(), vec1.cend(), 3);
    cout << "Number of occurances of 3 in vec1: " << num_items << endl;

    //countif
    int count_div2 = std::count_if(vec1.begin(), vec1.end(), [](int i) { return i % 2 == 0; });
    cout << "Number of even values in vec1: " << count_div2 << endl;

    //find
    auto result1 = std::find(vec1.begin(), vec1.end(), 10);
    (result1 != std::end(vec1)) ? cout << "vec1 contains 10." << '\n' : cout << "vec1 does not contain 10." << '\n';

    result1 = std::find(vec1.begin(), vec1.end(), 4);
    (result1 != std::end(vec1)) ? cout << "vec1 contains 4." << '\n' : cout << "vec1 does not contain 4." << '\n';
    
    //find_if
    result1 = std::find_if(vec1.begin(), vec1.end(), [](int i) { return i % 2 == 0; });
    (result1 != std::end(vec1)) ? cout << "vec1 contains even number." << '\n' : cout << "vec1 does not contain even number." << '\n';

    //find_if_not
    result1 = std::find_if_not(vec1.begin(), vec1.end(), [](int i) { return i == 0; });
    (result1 != std::end(vec1)) ? cout << "vec1 does not contain 0." << '\n' : cout << "vec1 contains 0." << '\n';

    //find_end: get the last occurance of a sequence
    std::vector<int> vec2{5,6};
    result1 = std::find_end(vec1.begin(), vec1.end(), vec2.begin(), vec2.end());
    result1 == vec1.end() ? cout << "Sequence not found.\n" : cout << "Sequence found at: " << std::distance(vec1.begin(), result1) << endl;

    //find_first_of: get the first occurance of a sequence
    std::vector<int> vec3{3,4};
    result1 = std::find_first_of(vec1.begin(), vec1.end(), vec3.begin(), vec3.end());
    result1 == vec1.end() ? cout << "Sequence not found.\n" : cout << "Sequence found at: " << std::distance(vec1.begin(), result1) << endl;

    //adjacent_find: find pair of adjacent elements
    std::vector<int> vec4 {0, 1, 2, 3, 40, 40, 41, 41, 5};
 
    auto i1 = std::adjacent_find(vec4.begin(), vec4.end());
 
    if (i1 == vec4.end())
        std::cout << "No matching adjacent elements\n";
    else
        std::cout << "The first adjacent pair of equal elements is at " << std::distance(vec4.begin(), i1) << ", value = " << *i1 << '\n';


    //search
    std::string str1{"Hello, welcome to the C++ tutorial."};
    std::string str2{"C++"};

    std::string::iterator i2 = std::search(str1.begin(), str1.end(), str2.begin(), str2.end());

    if (i2 != str1.end())
        cout << "str2 is present at index " << (i2 - str1.begin()) << endl;
    else
        cout << "str2 is not present in str1" << endl;


    

    //------------------------------------------------------------------------

    return 0;
}
/************************************Summary*****************************************
 
//-------------------Non-modifying sequence operations-------------------

std :: all_of  : Test condition on all elements in range
std :: any_of  : Test if any element in range fulfills condition
std :: none_of : Test if no elements fulfill condition
std :: for_each : Apply function to range
std :: find : Find value in range
std :: find_if : Find element in range
std :: find_if_not : Find element in range (negative condition)
std :: find_end : Find last subsequence in range
std :: find_first_of : Find element from set in range
std :: adjacent_find : Find equal adjacent elements in range
std :: count : Count appearances of value in range
std :: count_if : Return number of elements in range satisfying condition
std :: mismatch : Return first position where two ranges differ
std::equal : Test whether the elements in two ranges are equal
std :: is_permutation : Test whether range is permutation of another
std :: search : Search range for subsequence
std :: search_n : Search range for element

//-------------------Modifying sequence operations-------------------

std :: copy :  Copy range of elements
std :: copy_n : Copy elements
std :: copy_if : Copy certain elements of range
std :: copy_backward : Copy range of elements backward
std::move : Move range of elements
std :: move_backward :  Move range of elements backward
std :: swap : Exchange values of two objects
std ::swap_ranges : Exchange values of two ranges
std :: iter_swap : Exchange values of objects pointed to by two iterators
std ::transform : Transform range
std ::replace : Replace value in range
std ::replace_if : Replace values in range
std :: replace_copy : Copy range replacing value
std :: replace_copy_if : Copy range replacing value
std ::fill : Fill range with value
std :: fill_n : Fill sequence with value
std ::generate : Generate values for range with function
std ::generate_n : Generate values for sequence with function
std ::remove : Remove value from range
std :: remove_if : Remove elements from range
remove_copy : Copy range removing value
remove_copy_if : Copy range removing values
std ::unique : Remove consecutive duplicates in range
std :: unique_copy : Copy range removing duplicates
std ::reverse : Reverse range
std :: reverse_copy : Copy range reversed
std :: rotate : Rotate left the elements in range
std :: rotate_copy : Copy range rotated left
std :: random_shuffle : Randomly rearrange elements in range
std :: shuffle : Randomly rearrange elements in range using generator

//-------------------Partition Operations-------------------

std :: is_partitioned : Test whether range is partitioned
std :: partition : Partition range in two
std :: stable_partition : Partition range in two – stable ordering
partition_copy : Partition range into two
partition_point : Get partition point

//-------------------Sorting-------------------

std :: sort : Sort elements in range
std :: stable_sort : Sort elements preserving order of equivalents
std :: partial_sort : Partially sort elements in range
std :: partial_sort_copy : Copy and partially sort range
std :: is_sorted : Check whether range is sorted
std :: is_sorted_until : Find first unsorted element in range
std :: nth_element : Sort element in range

//---------------Binary search (operating on partitioned/sorted ranges)---------------

std :: lower_bound : Return iterator to lower bound
std :: upper_bound : Return iterator to upper bound
std :: equal_range : Get subrange of equal elements
std :: binary_search : Test if value exists in sorted sequence

//-------------------Merge (operating on sorted ranges)-------------------

std :: merge : Merge sorted ranges
std :: inplace_merge : Merge consecutive sorted ranges
std :: includes : Test whether the sorted range includes another sorted range
std :: set_union : Union of two sorted ranges
std :: set_intersection : Intersection of two sorted ranges
std :: set_difference : Difference of two sorted ranges
std :: set_symmetric_difference : Symmetric difference of two sorted ranges

//-------------------Heap Operations-------------------

std :: push_heap : Push element into heap range
std :: pop_heap : Pop element from heap range
std :: make_heap : Make heap from range
std :: sort_heap : Sort elements of heap
std :: is_heap : Test if range is heap
std :: is_heap_until : Find first element not in heap order
std :: max : Return the largest
std :: minmax : Return smallest and largest elements
std :: min_element : Return smallest element in range
std :: max_element : Return largest element in range
std :: minmax_element : Return smallest and largest elements in range

//-------------------Other Operations-------------------

std :: lexicographical_compare : Lexicographical less-than comparison
std :: next_permutation : Transform range to next permutation
std :: prev_permutation : Transform range to previous permutation

************************************************************************************/