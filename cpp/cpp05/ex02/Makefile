NAME	= AForm
CPP		= c++
CPPFLAGS	= -Wall -Wextra -Werror -std=c++98

SOURCES =	./main.cpp \
			./Bureaucrat.cpp \
			./AForm.cpp \
			./ShrubberyCreationForm.cpp \
			./RobotomyRequestForm.cpp \
			./PresidentialPardonForm.cpp

INCLUDES =	./Bureaucrat.hpp \
			./AForm.hpp \
			./ShrubberyCreationForm.hpp \
			./RobotomyRequestForm.hpp \
			./PresidentialPardonForm.hpp

OBJECTS	= $(SOURCES:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJECTS)  $(INCLUDES)
	@$(CPP) $(CPPFLAGS) $(OBJECTS) -o $(NAME)
	@echo $(CYAN) "⚡︎	[ cpp05/ex02 ]	Ready to run $(NAME)" $(RESET)

%.o: %.cpp
	@$(CPP) $(CPPFLAGS) -c $< -o $@

clean :
	@rm -f $(OBJECTS)
	@echo $(PURPLE) "⚡︎	[ cpp05/ex02 ]	Removed Object files" $(RESET)

fclean : clean
	@rm -f $(NAME)
	@echo $(BLUE) "⚡︎	[ cpp05/ex02 ]	Removed $(NAME)" $(RESET)

re :
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all clean fclean re

RESET	= "\x1b[0m"
GREY	= "\x1b[30m"
RED		= "\x1b[31m"
GREEN	= "\x1b[32m"
YELLOW	= "\x1b[33m"
BLUE	= "\x1b[34m"
PURPLE	= "\x1b[35m"
CYAN	= "\x1b[36m"
WHITE	= "\x1b[37m"