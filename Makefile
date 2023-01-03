# NAMES
NAME1 		=	push_swap
NAME2		=	checker
LIB_A 		=	libft.a
NAME_A		=	ft

#  PATHS
L_PATH		= 	./libft
S_PATH1		=	./srcs/push_swap
S_PATH2		=	./srcs/checker
S_PATH12	=	./srcs/common
I_PATH		=	./includes

# COMPILER, FLAGS AND SOURCES
CC 			=	gcc 
LEAKS		=	-g3 -fsanitize=address
FLAGS		=	-Wall -Wextra -Werror 
SRC1 		=	$(wildcard $(S_PATH1)/*.c)
SRC2 		=	$(wildcard $(S_PATH2)/*.c)
SRC12 		=	$(wildcard $(S_PATH12)/*.c)
LIB_NAME	=	$(L_PATH)/$(LIB_A)
O_SRC1		=	$(SRC1:.c=.o)
O_SRC2		=	$(SRC2:.c=.o)
O_SRC12		=	$(SRC12:.c=.o)

# COLORS
RESET 		=	\033[0m
RED			=	\033[0;31m
GREEN		=	\033[0;32m
YELLOW		=	\033[0;33m
CYAN		=	\033[0;36m

# RULES
all			:	$(NAME1) $(NAME2)

$(NAME1)	:	$(LIB_NAME) $(O_SRC1) $(O_SRC12)
				@printf  "$(YELLOW)  Compiling program:  $(NAME1).....$(RESET)"
				@${CC} ${FLAGS} $(LEAKS) -I$(I_PATH) $(O_SRC1) $(O_SRC12) -L $(L_PATH) -l $(NAME_A) -o ./$(NAME1)
				@echo "$(GREEN)  SUCCESS !$(RESET)"

$(NAME2)	:	$(LIB_NAME) $(O_SRC2) $(O_SRC12)
				@printf "$(YELLOW)  Compiling program:  $(NAME2).......$(RESET)"
				@${CC} ${FLAGS} $(LEAKS) -I$(I_PATH) $(O_SRC2) $(O_SRC12) -L $(L_PATH) -l $(NAME_A) -o ./$(NAME2)
				@echo "$(GREEN)  SUCCESS !$(RESET)"

$(LIB_NAME)	:		
				@printf "$(YELLOW)  Compiling library: $(LIB_A)........$(RESET)"
				@$(MAKE) --no-print-directory -C $(L_PATH)
				@echo "$(GREEN)  SUCCESS !$(RESET)"

.c.o		:	
				@$(CC) -c $< -o $(<:.c=.o)

clean		:
				@echo "$(YELLOW)  Deleting object files........$(RESET)\c"
# The end (\c) works to delete (\n) at the end in the echo command
				@$(MAKE) --no-print-directory clean -C $(L_PATH) 
				@rm -f $(O_SRC1) $(O_SRC2) $(O_SRC12)
				@echo "$(CYAN) all object files DELETED!$(RESET)"

fclean		:	clean
				@printf "$(YELLOW)  Deleting binary files........$(RESET)"
				@$(MAKE) --no-print-directory fclean -C $(L_PATH)
				@printf "$(CYAN) $(LIB_A) DELETED !$(RESET)"
				@rm -f $(NAME1)
				@printf "$(CYAN), $(NAME1) DELETED !$(RESET)"
				@rm -f $(NAME2)
				@echo "$(CYAN), $(NAME2) DELETED !$(RESET)"

re			:	fclean all

.PHONY		:	all clean fclean re test