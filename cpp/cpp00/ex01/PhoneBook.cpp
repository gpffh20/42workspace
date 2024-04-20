#include "PhoneBook.hpp"
# include <iomanip>

const std::string question_[PhoneBook::kNumAttrs] = {
		"Enter first name: ",
		"Enter last name: ",
		"Enter nickname: ",
		"Enter phone number: ",
		"Enter darkest secret: "
};

const PhoneBook::SetterFunction setters[PhoneBook::kNumAttrs] = {
		&Contact::set_firstname_,
		&Contact::set_lastname_,
		&Contact::set_nickname_,
		&Contact::set_phone_number_,
		&Contact::set_darkest_secret_
};

PhoneBook::PhoneBook() {
	std::cout << "=== PhoneBook is started. ===" << std::endl;
	this->index_ = 0;
	this->contact_count_ = 0;
}

PhoneBook::~PhoneBook() {
	std::cout << "\n=== PhoneBook is closed. ===" << std::endl;
}

void PhoneBook::AddContact() {
	std::string attr;

	std::cout << "--- [ADD CONTACT] ---" << std::endl;

	if (this->index_ >= MAX_CONTACTS) {
		std::cout << "Phonebook is full!" << std::endl;
		std::cout << "Oldest contact (";
		std::cout << this->contacts_[this->index_ % MAX_CONTACTS].get_firstname_();
		std::cout << " ";
		std::cout << this->contacts_[this->index_ % MAX_CONTACTS].get_lastname_();
		std::cout << ") will be overwritten." << std::endl;
	}

	for (int i = kFirstName; i < kNumAttrs; i++) {
		while (true) {
			std::cout << question_[i];
			std::getline(std::cin, attr);
			if (std::cin.eof()) {
				std::cin.clear();
				return;
			}
			else if (attr.empty()) {
				std::cout << " cannot be empty!" << std::endl;
				continue ;
			}
			else {
				(this->contacts_[this->index_ % MAX_CONTACTS].*(setters[i]))(attr);
				break ;
			}
		}
	}
	if (this->contact_count_ < MAX_CONTACTS) {
		this->contact_count_++;
	}
	std::cout << "Contact has been added." << std::endl;
	this->index_++;
}

void PhoneBook::SearchContact() {
	std::string index;

	std::cout << "--- [SEARCH CONTACT] ---" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|     Index| FirstName|  LastName|  Nickname|" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;

	this->PrintPhoneBook();
	std::cout << "---------------------------------------------" << std::endl;

	while (true) {
		if (this->contact_count_ == 0) {
			break;
		}
		std::cout << "Enter the index to search: ";
		std::getline(std::cin, index);
		if (std::cin.eof()) {
			std::cin.clear();
			return;
		}
		else if (index.empty()) {
			std::cout << "Index cannot be empty!" << std::endl;
			continue;
		}
		else {
			if (index.length() != 1 || static_cast<char>(index[0]) < '1' || static_cast<char>(index[0]) > this->contact_count_ + '0') {
				std::cout << "Please enter a number from 1 to ";
				std::cout << this->contact_count_ << "!" << std::endl;
				continue;
			}
			else {
				this->PrintContact(std::stoi(index) - 1);
				break;
			}
		}
	}
}

void PhoneBook::PrintPhoneBook() {
	for (int i = 0; i < this->contact_count_; i++) {
		std::cout << "|";
		std::cout << std::setw(10) << i + 1;
		std::cout << "|";
		this->PrintUnderTen(this->contacts_[i].get_firstname_());
		std::cout << "|";
		this->PrintUnderTen(this->contacts_[i].get_lastname_());
		std::cout << "|";
		this->PrintUnderTen(this->contacts_[i].get_nickname_());
		std::cout << "|" << std::endl;
	}
}

void PhoneBook::PrintUnderTen(std::string str) {
	if (str.length() > 10)
		std::cout << std::setw(9) << str.substr(0, 9) << ".";
	else
		std::cout << std::setw(10) << str;
}

void PhoneBook::PrintContact(int index) {
	std::cout << "[Contact #" << index + 1 << "]" << std::endl;
	std::cout << "First name: " << this->contacts_[index].get_firstname_() << std::endl;
	std::cout << "Last name: " << this->contacts_[index].get_lastname_() << std::endl;
	std::cout << "Nickname: " << this->contacts_[index].get_nickname_() << std::endl;
	std::cout << "Phone number: " << this->contacts_[index].get_phone_number_() << std::endl;
	std::cout << "Darkest secret: " << this->contacts_[index].get_darkest_secret_() << std::endl;
}