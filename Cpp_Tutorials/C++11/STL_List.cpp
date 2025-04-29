// List
#include <iostream>
#include <list>

using std::cout;
using std::endl;

// function for printing the elements in a list
void showlist(std::list<int> g)
{
    std::list<int>::iterator it;
    for (it = g.begin(); it != g.end(); ++it)
        cout << '\t' << *it;
    cout << '\n';
}

int main()
{

    //----------------------------------Basic operations----------------------------------
    std::list<int> list_var{12,45,8,6, 23,7,87,6,54};   //Initialize list
 
    cout << "List: ";
    showlist(list_var);

    cout << "list.front() : " << list_var.front() << endl;
    cout << "list.back() : " << list_var.back() << endl;

    cout << "list.pop_front() : ";
    list_var.pop_front();
    showlist(list_var);

    cout << "list.pop_back() : ";
    list_var.pop_back();
    showlist(list_var);

    cout << "list.reverse() : ";
    list_var.reverse();
    showlist(list_var);

    cout << "list.sort(): ";
    list_var.sort();
    showlist(list_var);

    cout << endl;

    //------------------------------------------------------------------------

    return 0;
}
/************************************Summary*****************************************
1. front(): 	    Returns the value of the first element in the list.

2. back(): 	        Returns the value of the last element in the list.

3. push_front(g): 	Adds a new element ‘g’ at the beginning of the list.

4. push_back(g): 	Adds a new element ‘g’ at the end of the list.

5. pop_front():	    Removes the first element of the list, and reduces the size of the 
                    list by 1.

6. pop_back(): 	    Removes the last element of the list, and reduces the size of the 
                    list by 1.

7. begin():	        returns an iterator pointing to the first element of the list.

8. end():	        returns an iterator pointing to the theoretical last element which 
                    follows the last element.

9. rbegin():        returns a reverse iterator which points to the last element of the 
                    list.

10. rend():         returns a reverse iterator that points to the position before the 
                    beginning of the list.

11. cbegin(): 	    returns a constant random access iterator which points to the 
                    beginning of the list.

12. cend():         returns a constant random access iterator which points to the end 
                    of the list.

13. crbegin(): 	    returns a constant reverse iterator which points to the last element 
                    of the list i.e reversed beginning of the container.

14. crend():        returns a constant reverse iterator which points to the theoretical 
                    element preceding the first element in the list i.e. the reverse end 
                    of the list.

15. empty(): 	    returns whether the list is empty(1) or not(0).

16. insert():	    inserts new elements in the list before the element at a specified 
                    position.

17.erase():	        removes a single element or a range of elements from the list.

18. assign():	    assigns new elements to the list by replacing current elements and 
                    resizing the list.

19. remove():	    removes all the elements from the list, which are equal to a given 
                    element.

20. remove_if():	Used to remove all the values from the list that correspond true to 
                    the predicate or condition given as a parameter to the function.

21. reverse():	    Reverses the list.

22. size():	        Returns the number of elements in the list.

23. resize():	    Used to resize a list container.

24. sort():	        Sorts the list in increasing order.

25. max_size(): 	Returns the maximum number of elements a list container can hold.

26. unique():	    Removes all duplicate consecutive elements from the list.

27. emplace_front():    used to insert a new element into the list container, and the 
                        new element is added to the beginning of the list. 

28. emplace_back():     used to insert a new element into the list container, and the 
                        new element is added to the end of the list.

29. clear():        used to remove all the elements of the list container, thus making 
                    it size 0.

30. operator=	    This operator is used to assign new contents to the container by 
                    replacing the existing contents.

31. swap():	        This function is used to swap the contents of one list with another 
                    list of the same type and size.

32. splice():	    Used to transfer elements from one list to another.

33. merge():	    Merges two sorted lists into one.

34. emplace():	    Extends the list by inserting a new element at a given position.

************************************************************************************/