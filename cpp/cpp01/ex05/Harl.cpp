#include "Harl.hpp"

Harl::Harl() {
	std::cout << "=== Harl is started. ===" << std::endl;
}

Harl::~Harl() {
	std::cout << "\n=== Harl is closed. ===" << std::endl;
}

void Harl::debug() {
	std::cout << "debug" << std::endl;
}

void Harl::info() {
	std::cout << "info" << std::endl;
}

void Harl::warning() {
	std::cout << "warning" << std::endl;
}

void Harl::error() {
	std::cout << "error" << std::endl;
}

void Harl::complain(std::string level) {

	void (Harl::*complaints[4])() = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};

	if (level == "DEBUG")
		(this->*complaints[kDebug])();
	else if (level == "INFO")
		(this->*complaints[kInfo])();
	else if (level == "WARNING")
		(this->*complaints[kWarning])();
	else if (level == "ERROR")
		(this->*complaints[kError])();
	else
		std::cout << "Invalid level!" << std::endl;
}

