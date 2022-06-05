CC = gcc

NAME = demineur

SRC = main.c			\
	  functions_basic.c

OBJ =  $(SRC:.c=.o)

CFLAGS += -W -Wall -Werror

RM = rm -f

$(NAME):        $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

all: $(NAME)
