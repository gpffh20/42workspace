#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;
	
	std::cout << "=========== MY TC ===========" << std::endl;
	Array<int> arr(5);
	std::cout << "Size: " << arr.size() << std::endl;
	for (unsigned int i = 0; i < arr.size(); i++)
		arr[i] = i + 1;
	std::cout << "arr[0]: " << arr[0] << std::endl;
	std::cout << "arr[1]: " << arr[1] << std::endl;
	std::cout << "arr[2]: " << arr[2] << std::endl;
	std::cout << "arr[3]: " << arr[3] << std::endl;
	std::cout << "arr[4]: " << arr[4] << std::endl;
	std::cout << "=============================" << std::endl;
	
	Array<std::string> arrStr(5);
	arrStr[0] = "Hello";
	arrStr[1] = "World";
	arrStr[2] = "This";
	arrStr[3] = "is";
	arrStr[4] = "42";
	std::cout << arrStr[0] << " " << arrStr[1] << " " << arrStr[2] << " " << arrStr[3] << " " << arrStr[4] << std::endl;
    return 0;
}