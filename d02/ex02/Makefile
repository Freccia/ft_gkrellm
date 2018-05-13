#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfabbro <>                                 +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/13 12:26:19 by lfabbro           #+#    #+#              #
#    Updated: 2018/05/13 15:33:51 by lfabbro          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		= fixed
TEST		= test_fixed

SRC_NAME	= main.cpp Fixed.cpp
TEST_NAME	= test.cpp Fixed.cpp

LIB_NAME	= #-lft

SRC_PATH	= #./srcs/
OBJ_PATH	= ./objs/
LIB_PATH	=
INC_PATH	=

SRC			= $(addprefix $(SRC_PATH),$(SRC_NAME))
SRC_TEST	= $(addprefix $(SRC_PATH),$(TEST_NAME))
OBJ			= $(SRC:.cpp=.o)
LIB 		= $(addprefix -L, $(LIB_PATH))
INC 		= $(addprefix -I ,$(INC_PATH))

CPP			= clang++
CPPFLAGS	= -Wall -Wextra -Werror #-std=c++11

RED			= \033[31;44m
GREEN		= \033[32;44m
ENDC		= \033[0m

.PHONY: all clean fclean re test

all: $(NAME)

$(NAME): #$(OBJ)
	$(CPP) $(CPPFLAGS) $(INC) $(SRC) -o $(NAME) #$(LIB) $(LIB_NAME)
	@printf "$(GREEN) Make $(NAME) $(ENDC)\n"

test:
	$(CPP) $(CPPFLAGS) $(INC) $(SRC_TEST) -o $(TEST) #$(LIB) $(LIB_NAME)
	@printf "$(GREEN) Make $(TEST) $(ENDC)\n"

%.o: %.c
	$(CPP) $(CPPFLAGS) -o $@ -c $< $(INC)

clean:
	@printf "$(RED) Removing $(NAME) objects $(ENDC)\n"
	@rm -rfv $(OBJ) $(OBJ_PATH)

fclean: clean
	@printf "$(RED) Removing $(NAME) and $(TEST) executables $(ENDC)\n"
	@rm -fv $(NAME) $(TEST)

re: fclean
	@make all
