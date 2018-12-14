CC 				= gcc

CFLAGS			= -Wall -Wextra -Werror

EXEC1			= checker

EXEC2			= push_swap

LIB_HEADER_PATH	= libs/libft/includes/

SRC1_PATH		= check/src/
HEADER1_PATH	= check/includes/
OBJ1_PATH		= check/obj/

SRC2_PATH		= swap/src/
HEADER2_PATH	= swap/includes/
OBJ2_PATH		= swap/obj/

SRC1_NAME		= checker.c \
				  get_next_line.c \
				  operations.c \
				  push.c \
				  reverse.c \
				  rotate.c \
				  stack.c \
				  swap.c

SRC2_NAME		= insertion_sort.c \
				  operations.c \
				  push.c \
				  push_swap.c \
				  reverse.c \
				  rotate.c \
				  sort.c \
				  stack.c \
				  swap.c

OBJ1_NAME		= $(SRC1_NAME:.c=.o)

OBJ2_NAME		= $(SRC2_NAME:.c=.o)

LIB_HEADER 		= $(addprefix -I, $(LIB_HEADER_PATH))

SRC1			= $(addprefix $(SRC1_PATH), $(SRC1_NAME))
OBJ1			= $(addprefix $(OBJ1_PATH), $(OBJ1_NAME)) 
HEADER1			= $(addprefix -I, $(HEADER1_PATH))

SRC2			= $(addprefix $(SRC2_PATH),$(SRC2_NAME))
OBJ2			= $(addprefix $(OBJ2_PATH), $(OBJ2_NAME)) 
HEADER2			= $(addprefix -I,$(HEADER2_PATH))

LIB_PATH		= libs/libft/
LIB_NAME		= libft.a
LIB		 		= $(addprefix $(LIB_PATH), $(LIB_NAME))

RED 			= \033[31m
GREEN			= \033[32m
END 			= \033[0m

all: $(LIB_NAME) $(EXEC1) $(EXEC2)

$(LIB_NAME):
	@echo "$(RED)COMPILING LIBRARY...$(END)"
	@make -C $(LIB_PATH)
	@echo "$(GREEN)LIBRARY READY$(END)"

$(EXEC1): $(OBJ1)
	@$(CC) $(CFLAGS) -o $(EXEC1) $(OBJ1) $(LIB)
	@echo "$(GREEN)CHECKER READY$(END)"

$(EXEC2): $(OBJ2)
	@$(CC) $(CFLAGS) -o $(EXEC2) $(OBJ2) $(LIB)
	@echo "$(GREEN)PUSH_SWAP READY$(END)"


$(OBJ1_PATH)%.o: $(SRC1_PATH)%.c
	@mkdir -p $(OBJ1_PATH)	
	@$(CC) -c $(CFLAGS) $(HEADER1) $(LIB_HEADER) -o $@ -c $<

$(OBJ2_PATH)%.o: $(SRC2_PATH)%.c
	@mkdir -p $(OBJ2_PATH)	
	@$(CC) -c $(CFLAGS) $(HEADER2) $(LIB_HEADER) -o $@ -c $<

clean:
	@make clean -C $(LIB_PATH)
	@rm -rf $(OBJ1_PATH) $(OBJ2_PATH)

fclean: clean
	@make fclean -C $(LIB_PATH)
	@rm -rf $(EXEC1) $(EXEC2)

re: fclean all

.PHONY: all clean fclean re
