#include "Array.hpp"
#include <iostream>
#include <string>

int main(void)
{
    std::cout << "=== Testing Array class template ===" << std::endl;
    
    std::cout << "\n1. Testing default constructor:" << std::endl;
    Array<int> empty_array;
    std::cout << "Empty array size: " << empty_array.size() << std::endl;
    
    std::cout << "\n2. Testing parameterized constructor:" << std::endl;
    Array<int> int_array(5);
    std::cout << "Int array size: " << int_array.size() << std::endl;
    
    std::cout << "\n3. Testing element access and modification:" << std::endl;
    for (unsigned int i = 0; i < int_array.size(); i++) {
        int_array[i] = i * 10;
        std::cout << "int_array[" << i << "] = " << int_array[i] << std::endl;
    }
    
    std::cout << "\n4. Testing copy constructor:" << std::endl;
    Array<int> copied_array(int_array);
    std::cout << "Copied array size: " << copied_array.size() << std::endl;
    for (unsigned int i = 0; i < copied_array.size(); i++) {
        std::cout << "copied_array[" << i << "] = " << copied_array[i] << std::endl;
    }
    
    // Test 5: Assignment operator
    std::cout << "\n5. Testing assignment operator:" << std::endl;
    Array<int> assigned_array;
    assigned_array = int_array;
    std::cout << "Assigned array size: " << assigned_array.size() << std::endl;
    for (unsigned int i = 0; i < assigned_array.size(); i++) {
        std::cout << "assigned_array[" << i << "] = " << assigned_array[i] << std::endl;
    }
    
    std::cout << "\n6. Testing with different data types:" << std::endl;
    Array<std::string> string_array(3);
    string_array[0] = "Hello";
    string_array[1] = "World";
    string_array[2] = "C++";
    
    for (unsigned int i = 0; i < string_array.size(); i++) {
        std::cout << "string_array[" << i << "] = " << string_array[i] << std::endl;
    }
    
    std::cout << "\n7. Testing exception handling:" << std::endl;
    try {
        std::cout << "Trying to access out of bounds index..." << std::endl;
        int_array[10] = 100; // This should throw an exception
    } catch (const std::out_of_range& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    
    try {
        std::cout << "Trying to access negative index..." << std::endl;
        int_array[-1] = 100; // This should also throw an exception
    } catch (const std::out_of_range& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    
    std::cout << "\n8. Testing const array access:" << std::endl;
    const Array<int> const_array(int_array);
    std::cout << "Const array size: " << const_array.size() << std::endl;
    for (unsigned int i = 0; i < const_array.size(); i++) {
        std::cout << "const_array[" << i << "] = " << const_array[i] << std::endl;
    }
    
    std::cout << "\n9. Testing self-assignment:" << std::endl;
    int_array = int_array;
    std::cout << "Self-assignment completed successfully" << std::endl;
    std::cout << "Array size after self-assignment: " << int_array.size() << std::endl;
    
    std::cout << "\n=== All tests completed successfully! ===" << std::endl;
    
    return 0;
}
