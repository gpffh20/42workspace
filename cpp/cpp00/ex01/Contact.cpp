#include "Contact.hpp"

Contact::Contact() {}

Contact::~Contact() {}

void Contact::set_firstname_(std::string firstname) {
	this->firstname_ = firstname;
}

void Contact::set_lastname_(std::string lastname) {
	this->lastname_ = lastname;
}

void Contact::set_nickname_(std::string nickname) {
	this->nickname_ = nickname;
}

void Contact::set_phone_number_(std::string phone_number) {
	this->phone_number_ = phone_number;
}

void Contact::set_darkest_secret_(std::string darkest_secret) {
	this->darkest_secret_ = darkest_secret;
}

std::string Contact::get_firstname_() {
	return (this->firstname_);
}

std::string Contact::get_lastname_() {
	return (this->lastname_);
}

std::string Contact::get_nickname_() {
	return (this->nickname_);
}

std::string Contact::get_phone_number_() {
	return (this->phone_number_);
}

std::string Contact::get_darkest_secret_() {
	return (this->darkest_secret_);
}