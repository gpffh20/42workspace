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
//				clearerr(stdin);
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
		std::cout << "Contact has been added." << std::endl;
	}
	this->index_++;
//	if (this->index < 0)
//		this->index = 0;
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
			int index_num = std::stoi(index);

			if (index_num < 1 || index_num > this->contact_count_) {
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
// SEARCH
// 특정 연락처 표시
// 저장된 연락처를 색인, 이름, 성, 닉네임의 4개 열 목록으로 표시합니다.
// 이름 및 닉네임.
// 각 열의 너비는 10자여야 합니다. 파이프 문자('|')로 구분합니다.
// 구분합니다. 텍스트는 오른쪽 정렬해야 합니다. 텍스트가 열보다 긴 경우
// 잘라내야 하며 표시 가능한 마지막 문자는 점('')으로 대체해야 합니다.
// 점('.')으로 대체해야 합니다.
// 그런 다음 사용자에게 표시할 항목의 색인을 다시 묻습니다. 인덱스
// 가 범위를 벗어나거나 잘못된 경우 관련 동작을 정의합니다. 그렇지 않으면
// 연락처 정보를 한 줄당 한 필드씩 표시합니다.

// EXIT
// 프로그램이 종료되고 연락처가 영원히 사라집니다!
// - 다른 입력은 모두 삭제됩니다.
// 명령이 올바르게 실행되면 프로그램은 다른 명령을 기다립니다. It
// 사용자가 EXIT를 입력하면 중지됩니다.

