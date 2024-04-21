#include <fstream>
#include <iostream>

//Create a program that takes three parameters in the following order:
// a filename and two strings, s1 and s2.
//It will open the file <filename> and copies its content into a new file
//<filename>.replace, replacing every occurrence of s1 with s2.
//Using C file manipulation functions is forbidden and will be considered cheating. All
//the member functions of the class std::string are allowed, except replace. Use them
//wisely!
//Of course, handle unexpected inputs and errors. You have to create and turn in your
//own tests to ensure your program works as expected.



// 인자 3개 받기 : 파일이름, s1, s2

int main() {
	std::string filename;
	std::string s1;
	std::string s2;
	std::string line;
	std::string new_line;
	std::ifstream file;
	std::ofstream new_file;

	std::cout << "Enter a filename: ";
	std::getline(std::cin, filename);
	file.open(filename.c_str());
	if (!file.is_open()) {
		std::cout << "File not found." << std::endl;
		return 1;
	}
	std::cout << "Enter a string s1: ";
	std::getline(std::cin, s1);
	std::cout << "Enter a string s2: ";
	std::getline(std::cin, s2);

	new_file.open(filename.append(".replace").c_str());
	if (!new_file.is_open()) {
		std::cout << "Failed to create a new file." << std::endl;
		return 1;
	}
	while (std::getline(file, line)) {
		new_line = line;
		size_t pos = 0;
		while ((pos = new_line.find(s1, pos)) != std::string::npos) {
			new_line.replace(pos, s1.length(), s2);
			pos += s2.length();
		}
		new_file << new_line << std::endl;
	}
	file.close();
	new_file.close();
	return 0;
}