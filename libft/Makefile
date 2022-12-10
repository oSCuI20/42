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
SRC_DIR = src
INC_DIR = src/_inc

# compile and flags
CC = gcc
AR = ar
CFLAGS = -Wall -Werror -Wextra
EFLAGS = -c -I$(INC_DIR)/
NAME = libft.a

# freak mode
COM_COLOR   = \033[0;34m
OBJ_COLOR   = \033[0;36m
OK_COLOR    = \033[0;32m
ERROR_COLOR = \033[0;31m
WARN_COLOR  = \033[0;33m
NO_COLOR    = \033[m

OK_STRING    = "[OK]"
ERROR_STRING = "[ERROR]"
WARN_STRING  = "[WARNING]"
COM_STRING   = "Compiling"

# destination
OBJ_DIR = objs
BIN_DIR = bin

# rules
OBJS = $(OBJ_DIR)/conversion/ft_atoi.o \
			 $(OBJ_DIR)/conversion/ft_itoa.o \
			 $(OBJ_DIR)/conversion/ft_split.o \
			 $(OBJ_DIR)/conversion/ft_strmapi.o \
			 $(OBJ_DIR)/memory/ft_bzero.o \
			 $(OBJ_DIR)/memory/ft_calloc.o \
			 $(OBJ_DIR)/memory/ft_memchr.o \
			 $(OBJ_DIR)/memory/ft_memcmp.o \
			 $(OBJ_DIR)/memory/ft_memcpy.o \
			 $(OBJ_DIR)/memory/ft_memmove.o \
			 $(OBJ_DIR)/memory/ft_memset.o \
			 $(OBJ_DIR)/puts/ft_putchar_fd.o \
			 $(OBJ_DIR)/puts/ft_putstr_fd.o \
			 $(OBJ_DIR)/puts/ft_putendl_fd.o \
			 $(OBJ_DIR)/puts/ft_putnbr_fd.o \
			 $(OBJ_DIR)/string/ft_strchr.o \
			 $(OBJ_DIR)/string/ft_strlcat.o \
			 $(OBJ_DIR)/string/ft_strlcpy.o \
			 $(OBJ_DIR)/string/ft_strlen.o \
			 $(OBJ_DIR)/string/ft_strncmp.o \
			 $(OBJ_DIR)/string/ft_strnstr.o \
			 $(OBJ_DIR)/string/ft_strrchr.o \
			 $(OBJ_DIR)/string/ft_tolower.o \
			 $(OBJ_DIR)/string/ft_toupper.o \
			 $(OBJ_DIR)/string/ft_strdup.o \
			 $(OBJ_DIR)/string/ft_substr.o \
			 $(OBJ_DIR)/string/ft_strjoin.o \
			 $(OBJ_DIR)/string/ft_strtrim.o \
			 $(OBJ_DIR)/string/ft_striteri.o \
			 $(OBJ_DIR)/validate/ft_isalnum.o \
			 $(OBJ_DIR)/validate/ft_isalpha.o \
			 $(OBJ_DIR)/validate/ft_isascii.o \
			 $(OBJ_DIR)/validate/ft_isdigit.o \
			 $(OBJ_DIR)/validate/ft_isprint.o \
			 $(OBJ_DIR)/list/ft_lstadd_back.o \
 			 $(OBJ_DIR)/list/ft_lstadd_front.o \
 			 $(OBJ_DIR)/list/ft_lstclear.o \
 			 $(OBJ_DIR)/list/ft_lstdelone.o \
 			 $(OBJ_DIR)/list/ft_lstiter.o \
 			 $(OBJ_DIR)/list/ft_lstlast.o \
 			 $(OBJ_DIR)/list/ft_lstmap.o \
 			 $(OBJ_DIR)/list/ft_lstnew.o \
 			 $(OBJ_DIR)/list/ft_lstsize.o

define BUILD_O
	@echo "Compiling: $<"
	@mkdir -p $(shell dirname $(firstword $@))
	@$(CC) $(CFLAGS) $(EFLAGS) $< -o $@
endef

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	$(BUILD_O)

$(NAME): $(OBJS)
	@$(AR) rcs $(NAME) $(OBJS)
	@echo '       '
	@echo '      ─▄▄▀▀█▀▀▄▄'  "$(WARN_COLOR)$(NAME)$(NO_COLOR)";
	@echo '      ▐▄▌─▀─▀─▐▄▌'
	@echo '      ──█─▄▄▄─█──▄▄'
	@echo '      ──▄█▄▄▄█▄─▐──▌'
	@echo '      ▄█▀█████▐▌─▀─▐'
	@echo '      ▀─▄██▀██▀█▀▄▄▀'
	@echo '       '

all: $(NAME)

clean:
	rm -Rf $(OBJS)

fclean: clean
	rm -Rf $(NAME)
	rm -Rf $(OBJ_DIR)

re: fclean all
