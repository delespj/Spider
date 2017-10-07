NAME		=	client

SRC		=	main.cpp\
			client.cpp\
			connection.cpp

OBJ		=	$(SRC:.cpp=.o)

CC		=	g++

CPPFLAGS	=	-I ../../../boost/boost_1_65_1/

LIB		=	-L ../../../boost/boost_1_65_1/ABC/lib/ -lboost_system -Wl,-rpath,../../../boost/boost_1_65_1/ABC/lib/

RM		=	rm -f


all:	$(NAME)

$(NAME): $(OBJ)
	$(CC) $(CPPFLAGS) -o $(NAME)  $(SRC) $(LIB)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
