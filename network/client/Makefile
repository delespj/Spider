NAME		=	client

SRC		=	main.cpp\
			connection.cpp\
			client.cpp

OBJ		=	$(SRC:.cpp=.o)

CC		=	g++

LDFLAGS		=	-L/opt/local/lib/boost_1_65_1/ABC/lib/ -lboost_system -Wl,-rpath,/opt/local/lib/boost_1_65_1/ABC/lib/

CPPFLAGS	=	-I /opt/local/lib/boost_1_65_1/

#LIB		=	-L /opt/local/lib

RM		=	rm -f


all:			$(NAME)

$(NAME):		$(OBJ)
			$(CC) $(CPPFLAGS) $(LDFLAGS) -o $(NAME) $(SRC)

clean:
			$(RM) $(OBJ)

fclean:			clean
			$(RM) $(NAME)

re:			fclean all
