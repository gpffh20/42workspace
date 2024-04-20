#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#define MAX_CONTACTS 8

#include "Contact.hpp"

//#include <iostream>
#include <string>

class PhoneBook {
	private:
		int index_;
		int contact_count_;
		Contact contacts_[MAX_CONTACTS];

	public:
		typedef void (Contact::*SetterFunction)(std::string);
		enum ContactAttributes {
			kFirstName,
			kLastName,
			kNickname,
			kPhoneNumber,
			kDarkestSecret,
			kNumAttrs
		};
		PhoneBook();
		~PhoneBook();
		void AddContact();
		void SearchContact();
		void PrintPhoneBook();
		void PrintUnderTen(std::string str);
		void PrintContact(int index);

//		const std::string question_[kNumAttrs];
};

#endif
