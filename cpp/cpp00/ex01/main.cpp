#include "PhoneBook.hpp"

int main() {
	PhoneBook phonebook;
	std::string command;

	while (!std::cin.eof()) {
		std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, command);
		if (command == "EXIT" || std::cin.eof()) {
			std::cin.clear();
//			clearerr(stdin);
//			continue ;
			break ;
		}
		else if (command == "ADD")
			phonebook.AddContact();
		else if (command == "SEARCH")
			phonebook.SearchContact();
		else
			std::cout << "Invalid command!" << std::endl;
	}
	return (0);
}