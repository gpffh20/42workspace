#include <iostream>
#include <string>

class Megaphone {
public:
	Megaphone(char **messages);
	~Megaphone();

	void PrintMessagesToUpperCase(int ac) const;

private:
	char **messages_;
};

Megaphone::Megaphone(char **messages) :   messages_(messages) {}

Megaphone::~Megaphone() {}

void Megaphone::PrintMessagesToUpperCase(int ac) const {
	if (ac == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return;
	}

	for (int i = 1; i < ac; i++) {
		std::string message = messages_[i];
		for (size_t j = 0; j < message.length(); j++) {
			std::cout << static_cast<char>(std::toupper(message[j]));
		}
	}
	std::cout << std::endl;
}

int main(int ac, char **av) {
    Megaphone megaphone(av);
    megaphone.PrintMessagesToUpperCase(ac);
    return 0;
}