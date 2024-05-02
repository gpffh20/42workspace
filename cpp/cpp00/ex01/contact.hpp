#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>
#include <iostream>

class Contact {
public:
	Contact();
	~Contact();

	void set_firstname_(std::string firstname);
	void set_lastname_(std::string lastname);
	void set_nickname_(std::string nickname);
	void set_phone_number_(std::string phone_number);
	void set_darkest_secret_(std::string darkest_secret);

	std::string get_firstname_();
	std::string get_lastname_();
	std::string get_nickname_();
	std::string get_phone_number_();
	std::string get_darkest_secret_();

private:
	std::string firstname_;
	std::string lastname_;
	std::string nickname_;
	std::string phone_number_;
	std::string darkest_secret_;
};

#endif