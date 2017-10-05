NAME		=	crypt

SRC		=	crypt.cpp \
			main.cpp


CC		=	g++

CPPFLAGS	=	-I /openssl/include/openssl/

LIB		=	-lcrypto

RM		=	rm -f


all:	$(NAME)

$(NAME): $(OBJ)
	$(CC) $(CPPFLAGS) -o $(NAME)  $(SRC) $(LIB)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
