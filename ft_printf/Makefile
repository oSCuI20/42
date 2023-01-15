# source code
SRC_DIR = .
INC_DIR = .

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

# compile and flags
CC = gcc 
AR = ar 
CFLAGS = 
EFLAGS = -c -I$(INC_DIR)/
NAME = libftprintf.a

# destination 
OBJ_DIR = objs
BIN_DIR = .

# objects 
OBJS = $(OBJ_DIR)/ft_printf.o

define BUILD_O 
	@echo "Compiling: $<"
	@mkdir -p $(shell dirname $(firstword $@))
	$(CC) $(CFLAGS) $(EFLAGS) $< -o $@
endef

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c 
	$(BUILD_O)

$(NAME) : $(LIBFT) $(OBJS)
	cp $(LIBFT) $(NAME)
	$(AR) rcs $(NAME) $(LIBFT) $(OBJS)

$(LIBFT):
	make -C $(LIBFT_DIR) all 

all: $(NAME)

clean:
	make -C $(LIBFT_DIR) clean
	rm -Rf $(OBJS)

fclean: clean 
	make -C $(LIBFT_DIR) fclean
	rm -Rf $(NAME)
	rm -Rf $(OBJ_DIR)

re: fclean all