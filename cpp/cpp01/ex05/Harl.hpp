#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <string>

class Harl {
	private:
		void debug();
		void info();
		void warning();
		void error();

	public:
		enum ComplaintsLevel {
			kDebug,
			kInfo,
			kWarning,
			kError
		};

		Harl();
		~Harl();
		void complain(std::string level);
};

#endif
