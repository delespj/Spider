NAME		=	server

SRC		=	main.cpp \
			server.cpp \
			session.cpp \
			Record.cpp

OBJ		=	$(SRC:.cpp=.o)

CC		=	g++

CPPFLAGS	=	-I /opt/local/lib/boost_1_65_1/ -g -std=c++11

LIB		=	-L /opt/local/lib/boost_1_65_1/stage/lib/ -lboost_system -Wl,-rpath,/opt/local/lib/boost_1_65_1/stage/lib/

RM		=	rm -f


all:	$(NAME)

$(NAME): $(OBJ)
	$(CC) $(CPPFLAGS) -o $(NAME) $(SRC) $(LIB)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
