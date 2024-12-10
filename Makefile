CC = cc
CC_FLAGS = -Wall -Werror -Wextra

# Targets
PUSHSWAP = push_swap


# Source and Object Files
SRC_FILES = push_swap.c\
			k_sort_alg.c\
			pushes.c\
			reverse_rotate.c\
			rotate.c\
			swaps.c 


OBJ_FILES = $(SRC_FILES:%.c=%.o)

# Libft Paths
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a


# Default target
all: $(LIBFT) $(PUSHSWAP)


# Rule to compile .c files into .o files
%.o: %.c
	$(CC) $(CC_FLAGS) -I$(LIBFT_DIR) -c $< -o $@

# Rule to create the executables
$(PUSHSWAP): $(OBJ_FILES) $(LIBFT)
	$(CC) $(CC_FLAGS) $(OBJ_FILES) -L$(LIBFT_DIR) -lft -o $(PUSHSWAP)

# Build Libft (if not already built)
$(LIBFT):
	make -C $(LIBFT_DIR)

# Clean up object files and executables
clean:
	rm -f $(OBJ_FILES)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(PUSHSWAP)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
