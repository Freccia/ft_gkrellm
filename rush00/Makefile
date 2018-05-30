#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfabbro <>                                 +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/13 12:26:19 by lfabbro           #+#    #+#              #
#    Updated: 2018/05/30 17:30:25 by lfabbro          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		= ft_retro

SRC_NAME	= ft_retro.cpp Player.cpp

LIB_NAME	= -lncurses #-lft

SRC_PATH	= #./srcs/
OBJ_PATH	= ./objs/
LIB_PATH	=
INC_PATH	=

SRC			= $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ			= $(SRC:.cpp=.o)
LIB 		= $(addprefix -L, $(LIB_PATH))
INC 		= $(addprefix -I ,$(INC_PATH))

CPP			= clang++
CPPFLAGS	= -Wall -Wextra -Werror #-std=c++11

RED			= \033[31;44m
GREEN		= \033[32;44m
ENDC		= \033[0m

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): #$(OBJ)
	$(CPP) $(CPPFLAGS) $(INC) $(SRC) -o $(NAME) $(LIB_NAME) #$(LIB)
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
