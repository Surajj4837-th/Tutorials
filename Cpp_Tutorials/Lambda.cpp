//Lambda
#include <iostream>
#include <vector>
#include <algorithm>


using std::cout;
using std::endl;
using std::vector;

void printVector(vector<int> v)
{
    // lambda expression to print vector
    std::for_each(v.begin(), v.end(), [](int i)
        {
            std::cout << i << " ";
        });
    cout << endl;
}

int main()
{

    //Basic lambda function
    auto lmbda = []() {
        //body 
        cout << "Hello World" << endl;
    };

    /*
    Above lambda is equivalent to
    void lmbda()
    {

    }
    */

    //Just like normal function, invoke the lambda function as normal funtion
    lmbda();

    //Passing parameters
    auto add = [](int a, int b) {
        cout << "Sum = " << a + b << endl;
    };

    /*
    Above lambda is equivalent to
    void add(inta, int b)
    {

    }
    */

    add(10, 11);

    //Lambda with return types
    //1. Implicit return - compiler will identify the return type when there is only 1 
    //   return statement. In the above examples the return type is implicit.
    //2. Explicit return - Required when there are multiple return types. 

    //In following snippet notice -> double, it explicitly defines the return type as 
    //double. So no matter what type of value is returned by the various return statements, 
    //they are all explicitly converted to double type.
    auto operation = [](int a, int b, std::string op) -> double {
        if (op == "sum") {
            // returns integer value
            return a + b;
        }
        else {
            // returns double value
            return (a + b) / 2.0;
        }
    };

    /*
    Above lambda is equivalent to
    double operation(int a, int b, std::string op)
    {

    }
    */

    int num1 = 1;
    int num2 = 2;

    // find the sum of num1 and num2
    auto sum = operation(num1, num2, "sum");
    cout << "Sum = " << sum << endl;

    // find the average of num1 and num2
    auto avg = operation(num1, num2, "avg");
    cout << "Average = " << avg << endl;


    //Lambda Function Capture Clause
    //1. Capture by value
    int initial_sum = 100;

    // capture initial_sum by value
    auto add_to_sum = [initial_sum](int num) {
        return initial_sum + num;
    };

    int final_sum = add_to_sum(78);
    cout << "100 + 78 = " << final_sum << endl;

    // In case we want to capture all local variables by value then we can use [=].
    // [a, &b] : capture a by value and b by reference
    // [&] : capture all external variables by reference


    //2. Lambda Capture by Reference
    
    int num = 0;
    // [&num] captures num by reference
    auto increment_by_one = [&num]() {
        cout << "Incrementing num by 1.\n";
        num++;
    };

    // invoke lambda function
    increment_by_one();



    //Lambda Function as Argument in STL Algorithm
	vector<int> nums = { 1, 2, 3, 4, 5, 8, 10, 12 };

	int even_count = count_if(nums.begin(), nums.end(), [](int num) {
		return num % 2 == 0;
		});

    cout << "There are " << even_count << " even numbers.";

    //Lambda expression is passed as 3rd argumentand returns true if num is even
    
    //Another example of the STL and Lambda function.
    vector<int> v{ 4, 1, 3, 5, 2, 3, 1, 7 };

    //printVector(v);

    return 0;

}
/************************************Summary*****************************************
1. C++ 11 allows to write an inline function which can be used for short snippets of
   code that are not going to be reused and not worth naming.

2. Syntax:
   [capture clause] (parameters) -> return-type
    {
      definition of method
    }

3. Generally return-type in lambda expression are evaluated by compiler itself and we
   don't need to specify that explicitly and -> return-type part can be ignored but
   in some complex case as in conditional statement, compiler can't make out the return
   type and we need to specify that.

4. A lambda expression can have more power than an ordinary function by having access
   to variables from the enclosing scope.

5. We can capture external variables from the enclosing scope in three ways :
      Capture by reference
      Capture by value
      Capture by both (mixed capture)
************************************************************************************/