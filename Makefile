##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

GPP			=	g++

RM			=	rm -rf

NAME		=	abstractVM

COMPILEFLAG	=	-Wall -Wextra

INCLUDE		=	-Iinclude/

CPPFLAGS    =	$(COMPILEFLAG) $(INCLUDE)

SRC			=	src/Main.cpp					\
				src/abstractVM.cpp				\
				src/Operand.cpp					\
				src/Factory.cpp					\
				src/Int16.cpp					\
				src/Int8.cpp					\
				src/Int32.cpp					\
				src/Float.cpp					\
				src/Double.cpp					\
				src/BigDecimal.cpp				\
				src/Exception.cpp

SRC_TESTS	=	tests/test_abstractVM.cpp		\
				tests/test1.cpp					\
				src/Parser.cpp					\
				src/abstractVM.cpp				\
				src/Operand.cpp

OBJ			=	$(SRC:.cpp=.o)

all:
	@make --no-print-directory $(NAME)

$(NAME):	$(OBJ)
	@echo -e "\033[01m\033[31mLinking ...\033[00m"
	@$(GPP) $(OBJ) -o $(NAME) $(CPPFLAGS) $(CPPFLAGS)
	@echo -e "\033[01m\033[32mStandard compilation done => ${NAME}\033[00m"
#	@make tests_run

clean:
	@$(RM) vgcore.* src/vgcore.*
	@$(RM) src/*.o unit_tests *.gcno *.gcda
	@echo -e "\033[01m\033[31mRemoving useless files ...\033[00m"

fclean:	clean
	@$(RM) $(NAME)
	@echo -e "\033[01m\033[31mRemoving libraries and binary : {${NAME}} ...\033[00m"

re:	fclean
	@make all --no-print-directory

tests_run:
	@g++ -o unit_tests $(SRC_TESTS) --coverage -lcriterion -Iinclude/
	@./unit_tests
	@gcovr
	@gcovr -b

.PHONY:	all clean fclean re
