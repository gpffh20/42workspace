NAME	= Materia
CPP		= c++
CPPFLAGS	= -Wall -Wextra -Werror -std=c++98

SOURCES =	./main.cpp \
			./AMateria.cpp \
			./Cure.cpp \
			./Ice.cpp \
			./MateriaSource.cpp \
			./Character.cpp \

INCLUDES =	./AMateria.hpp \
			./Cure.hpp \
			./Ice.hpp \
			./IMateriaSource.hpp \
			./ICharacter.hpp \
			./MateriaSource.hpp \
			./Character.hpp \

OBJECTS	= $(SOURCES:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJECTS)  $(INCLUDES)
	@$(CPP) $(CPPFLAGS) $(OBJECTS) -o $(NAME)
	@echo $(CYAN) "⚡︎	[ cpp04/ex03 ]	Ready to run $(NAME)" $(RESET)

%.o: %.cpp
	@$(CPP) $(CPPFLAGS) -c $< -o $@

clean :
	@rm -f $(OBJECTS)
	@echo $(PURPLE) "⚡︎	[ cpp04/ex03 ]	Removed Object files" $(RESET)

fclean : clean
	@rm -f $(NAME)
	@echo $(BLUE) "⚡︎	[ cpp04/ex03 ]	Removed $(NAME)" $(RESET)

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