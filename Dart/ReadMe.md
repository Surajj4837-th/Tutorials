# Dart Programming Course
[Dart Tutorial for Beginners (2024) | Learn Flutter Dart Programming in 6 Hours with Practical by WsCube Tech](https://www.youtube.com/watch?v=71xacArT_70)

## Installation
Dart: [SDK](https://dart.dev/get-dart)  
IDE: [VS Code](https://code.visualstudio.com/download)  
VS Code extensions: [Dart language support and debugger](https://marketplace.visualstudio.com/items?itemName=Dart-Code.dart-code)  


## Notes
After going through the course it was found that there are minor differences between Dart and C++. So if C++ is known then Dart has only following changes in it.
1. File extension: .dart.
2. Print function: stdout.write("");  
   The print() statement brings the cursor to the next line while stdout.write() don't bring the cursor to the next line, it remains in the same line.
3. Read user input: stdin.readLineSync("");  
   By default takes a string value. Use a parsing function to convert to other data types.
4. Non-null assertion operator: User input null check by adding `!` operator after the readLineSync command. This check is used to let the compiler know that there is a guarantee of user input.
5. Nullable check: `?`. Used when the input can be null.
7. Datatypes: int, string, double, bool, var(datatype is automatically determined).
8. Operators: Arithmetic, ternary, logical. Similar to C++.
10. Integer and string inbuilt functions.
11. Collections: Set of objects. Dart has built-in support for list, set, and map collections.
12. List: Static and dynamic. Stores items in an ordered way. List functions: add, remove, removeAt, contains, length, isEmpty, isNotEmpty, insert, insertAll, first, last, reversed, etc.
13. Sets: Stores data in an unordered way. Can store unique items only. Set function: add, isEmpty, isNotEmpty, last, first, length, contains, elementAt, etc.
14. Maps: Stores data in an unordered way. Key and value pairs are used. The key is always unique, values can be repeated. Use the `dynamic` keyword to store multiple kinds of data types of value. Map functions: add, isEmpty, isNotEmpty, remove, addAll, etc.
15. Conditional statement: if, else.
16. Switch case.
17. Loops: for, while, do while.
18. Variables in print statement are to be appended by $ sign. for ex. `print("Your name is $name");`
19. OOPs: 
    1.  Classes
    2.  Objects
    3.  Abstraction
    4.  Encapsulation
    5.  Inheritance
20. Named parameters: You can assign parameters as per their names, neglecting the sequence of parameters, as seen in Python. Use of the `required` keyword in function definition.
21. Positional parameters: Regular parameters as used in C++.
22. Inheritance: Types:
    1.  Single level.
    2.  Multi-level.
    3.  Hierarchical level.
23. Extend: Keyword to extend properties of parent to the child class. Keyword to show inheitance.
24. Super constructor: constructor of parent class.
25. Getter and setter: used to get and set a value of variable.
26. Abstract classes.
27. Exception handling: Try and On blocks are used. Types:
    1.  Format exception.
    2.  Div by zero.
    3.  IO exception.
28. Typedef: used for creating user-defined function or alias.
29. Generics: collection in Dart(map, list, set) are heterogeneous structures that can store different types of variables by using the `dynamic` keyword in the declaration. If any datatype is mentioned in the collection variable declaration then the variable will not take other type values as input. This makes the collection variable homogeneous.
30. Callable classes: Use of `call()` function.
31. Async and await keywords: synchronous programming allows execution of instructions in a sequence, asynchronous programming provides non-sequential code execution, parallel programming comes under asynchronous type. Await functionality makes the program wait to bring data from the server.

## Program Sequence
1. [dart_application_2.dart](/lib/dart_application_2.dart) : Hello world.
2. [addition.dart](/lib/addition.dart)
3. [datatypes.dart](/lib/datatypes.dart)
4. [integer_operations.dart](/lib/integer_operations.dart)
5. [list.dart](/lib/list.dart)
6. [set.dart](/lib/set.dart)
7. [inheritance.dart](/lib/inheritance.dart )