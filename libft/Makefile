# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebanderas <edbander@student.42malaga.      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/29 21:56:15 by ebanderas         #+#    #+#              #
#    Updated: 2022/12/05 07:23:37 by ebanderas        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# source code
SRC_DIR = .
INC_DIR = .

# compile and flags
CC = gcc
AR = ar
CFLAGS = -Wall -Werror -Wextra
EFLAGS = -c -I$(INC_DIR)/
NAME = libft.a

# destination
OBJ_DIR = .
BIN_DIR = bin

# rules
OBJS = $(OBJ_DIR)/ft_atoi.o \
			 $(OBJ_DIR)/ft_bzero.o \
			 $(OBJ_DIR)/ft_isalnum.o \
			 $(OBJ_DIR)/ft_isalpha.o \
			 $(OBJ_DIR)/ft_isascii.o \
			 $(OBJ_DIR)/ft_isdigit.o \
			 $(OBJ_DIR)/ft_isprint.o \
			 $(OBJ_DIR)/ft_calloc.o \
			 $(OBJ_DIR)/ft_memchr.o \
			 $(OBJ_DIR)/ft_memcmp.o \
			 $(OBJ_DIR)/ft_memcpy.o \
			 $(OBJ_DIR)/ft_memmove.o \
			 $(OBJ_DIR)/ft_memset.o \
			 $(OBJ_DIR)/ft_strchr.o \
			 $(OBJ_DIR)/ft_strlcat.o \
			 $(OBJ_DIR)/ft_strlcpy.o \
			 $(OBJ_DIR)/ft_strlen.o \
			 $(OBJ_DIR)/ft_strncmp.o \
			 $(OBJ_DIR)/ft_strnstr.o \
			 $(OBJ_DIR)/ft_strrchr.o \
			 $(OBJ_DIR)/ft_tolower.o \
			 $(OBJ_DIR)/ft_toupper.o \
			 $(OBJ_DIR)/ft_strdup.o \
			 $(OBJ_DIR)/ft_substr.o \
			 $(OBJ_DIR)/ft_strjoin.o \
			 $(OBJ_DIR)/ft_strtrim.o \
 			 $(OBJ_DIR)/ft_split.o \
			 $(OBJ_DIR)/ft_itoa.o \
			 $(OBJ_DIR)/ft_strmapi.o \
			 $(OBJ_DIR)/ft_striteri.o \
			 $(OBJ_DIR)/ft_putchar_fd.o \
			 $(OBJ_DIR)/ft_putstr_fd.o \
			 $(OBJ_DIR)/ft_putendl_fd.o \
			 $(OBJ_DIR)/ft_putnbr_fd.o

OBJS_BONUS = $(OBJ_DIR)/ft_lstadd_back.o \
			 			 $(OBJ_DIR)/ft_lstadd_front.o \
			 			 $(OBJ_DIR)/ft_lstclear.o \
			 			 $(OBJ_DIR)/ft_lstdelone.o \
			 			 $(OBJ_DIR)/ft_lstiter.o \
			 			 $(OBJ_DIR)/ft_lstlast.o \
			 			 $(OBJ_DIR)/ft_lstmap.o \
			 			 $(OBJ_DIR)/ft_lstnew.o \
			 			 $(OBJ_DIR)/ft_lstsize.o

define BUILD_O
	@echo "Compiling: $<"
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(EFLAGS) $< -o $@
endef

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	$(BUILD_O)

$(NAME): $(OBJS)
	$(AR) rcs $(NAME) $(OBJS)
	@echo "Finish libft compilation"

all: $(NAME)

clean:
	rm -Rf $(OBJS)
	rm -Rf $(OBJS_BONUS)

fclean: clean
	rm -Rf $(NAME)

re: fclean all

bonus: $(OBJS_BONUS)
	$(AR) rcs $(NAME) $(OBJS_BONUS)
