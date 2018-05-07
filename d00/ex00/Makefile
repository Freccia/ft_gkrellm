#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfabbro <>                                 +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/07 15:13:37 by lfabbro           #+#    #+#              #
#    Updated: 2018/05/07 15:57:40 by lfabbro          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		= megaphone

SRC_NAME	= megaphone.cpp

LIB_NAME	= #-lft

SRC_PATH	= #./srcs/
OBJ_PATH	= ./objs/
LIB_PATH	=
INC_PATH	=

SRC			= $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ			= $(SRC:.cpp=.o)
LIB 		= $(addprefix -L, $(LIB_PATH))
INC 		= $(addprefix -I ,$(INC_PATH))

CPP			= clang++
CPPFLAGS	= -Wall -Wextra -Werror

RED			= \033[31;44m
GREEN		= \033[32;44m
ENDC		= \033[0m

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): #$(OBJ)
	$(CPP) $(CPPFLAGS) $(INC) $(SRC) -o $(NAME) #$(LIB) $(LIB_NAME)
	@printf "$(GREEN) Make $(NAME) $(ENDC)\n"

%.o: %.c
	$(CPP) $(CPPFLAGS) -o $@ -c $< $(INC)

clean:
	@printf "$(RED) Removing $(NAME) objects $(ENDC)\n"
	@rm -rfv $(OBJ) $(OBJ_PATH)

fclean: clean
	@printf "$(RED) Removing $(NAME) executables $(ENDC)\n"
	@rm -fv $(NAME)

re: fclean
	@make all
