#include <iostream>
#include <string>

class Megaphone {
public:
    Megaphone(char **messages) : messages(messages) {}

    void PrintMessagesToUpperCase(int ac) const {
        if (ac == 1) {
            std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
            return;
        }

        for (int i = 1; i < ac; i++) {
            std::string message = messages[i];
			for (size_t j = 0; j < message.length(); j++) {
				std::cout << (char)std::toupper(message[j]);
			}
		}
		std::cout << std::endl;
    }

private:
    char **messages;
};

int main(int ac, char **av) {
    Megaphone megaphone(av);
    megaphone.PrintMessagesToUpperCase(ac);
    return 0;
}