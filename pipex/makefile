NAME = pipex
CC = gcc
# := will expand one time
# = expanded whenever used, and is recursived so gcc can also be a variable that refer to even another variable

# LIBFT_PATH	= ./libft
# LIBFT_A	= $(LIBFT_PATH)/libft.a

LIBFTPRINTF_PATH	= ./libftprintf
LIBFTPRINTF_A	= $(LIBFTPRINTF_PATH)/libftprintf.a
#libft.a is copied LIBFTinto this archive

SRC_DIR = ./src/
OBJ_DIR = ./obj/

CFLAGS = -Wall -Wextra -Werror -g3

MAKE = make

RM = rm -rf

SRC_FILES	= main.c helpers.c paths.c pids.c

OBJ_FILES	= ${SRC_FILES:.c=.o}
SRC			= $(addprefix $(SRC_DIR),$(SRC_FILES))
OBJ			= $(addprefix $(OBJ_DIR),$(OBJ_FILES))
#prefix adds will result in ./src/main.c (and same for all other files in src)

$(NAME): $(OBJ) $(LIBFTPRINTF_A)
	$(CC) -o $(NAME) $^

all: $(NAME)

clean:
	@$(RM) $(OBJ_DIR)

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) fclean -C ./libftprintf

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(MAKE) all -C ./libftprintf
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -o $@ -c $^

#-p will print rules and variable values
#^ is all prereq and < is first prereq
# if several prerequities, the first depends on date on the second, and if the first is older, the instructions below will be executed. The default value for .LIBPATTERNS is ‘lib%.so lib%.a’
#$@ - The file name of the target. which will be directory + x.o

re: fclean all

.PHONY:		all clean fclean re
#Because the rm command does not create a file named clean, probably no such file will ever exist. Therefore, the rm command will be executed every time you say ‘make clean’.