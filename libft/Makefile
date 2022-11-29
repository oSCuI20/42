# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebanderas <edbander@student.42malaga.      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/29 21:56:15 by ebanderas         #+#    #+#              #
#    Updated: 2022/11/29 23:54:13 by ebanderas        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# source code
SRC_DIR = src
INC_DIR = headers

# compile and flags
CC = gcc
AR = ar
CFLAGS = -Wall -Werror -Wextra
EFLAGS = -c -I$(INC_DIR)/
NAME = libft.a

# destination 
OBJ_DIR = obj
BIN_DIR = bin

# rules 
OBJS = $(OBJ_DIR)/ft_string_manipulation.o \
       $(OBJ_DIR)/ft_string_search.o \
       $(OBJ_DIR)/ft_string_validation.o \
       $(OBJ_DIR)/ft_string_utils.o

define BUILD_O
	@echo "Compiling: $<"
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(EFLAGS) $< -o $@
endef

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	$(BUILD_O)

$(NAME): $(OBJS)
	$(AR) r $(NAME) $(OBJS)
	@echo "Finish libft compilation"

all: $(NAME)

clean:
	rm -Rf $(OBJ_DIR)/*

fclean:
	rm -Rf $(OBJ_DIR)
	rm -Rf $(NAME)

re: fclean all
