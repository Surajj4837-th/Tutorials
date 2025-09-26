//Smart pointers

/************************************Summary****************************************
1. Problems with row pointers:
   a. Memory leaks: If the developer forgets to delete the memory allocated to 
      the object then it will lead to memory leaks.
   b. Dangling pointers: If the developer deletes the object memory but forgets to 
      set the pointer to nullptr then it will lead to dangling pointer.
   c. Double deletion: If the developer deletes the same object memory twice then 
      it will lead to undefined behaviour.
   d. Not exception safe: If an exception is thrown after the memory allocation but 
      before the delete statement then it will lead to memory leaks.

2. Smart pointer:
   a. Is an object which stores a pointer to a dynamically allocated (heap) object.
   b. It automatically deletes the object when the smart pointer goes out of scope.

3. Types of smart pointers in C++11:
   a. unique_ptr: Owns the object exclusively. No other smart pointer can point to
      the same object. It cannot be copied but can be moved.
   b. shared_ptr: Multiple smart pointers can point to the same object. It maintains
      a reference count. When the reference count becomes zero then the object is 
      deleted.
   c. weak_ptr: It is a weak reference to an object managed by shared_ptr. It does
      not affect the reference count. It is used to break circular references.
   d. auto_ptr: Deprecated in C++11. Use unique_ptr instead.

4. To use smart pointers include the header <memory>. These are wrapper classes over 
   normal pointers which maintain the object memory cleanup.

5. Pointer arithmetic on smart pointers is not allowed, e.g. --, ++, etc.

6. In C++14, unique_ptr can be created using std::make_unique<T>(args).

7. In C++11, shared_ptr can be created using std::make_shared<T>(args);
***********************************************************************************/