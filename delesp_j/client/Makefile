NAME		=	client

CXX		?=	g++

INCLUDES	+=	-I ./includes

CPPFLAGS	=	$(INCLUDES) -Wall -Werror -Wextra

RM		=	rm -f

#####################################
#         Compilation mode          #
#####################################

MODE		?=	NORM

TEST		=	TEST

NORM		=	NORM

######################################
#                SRC                 #
######################################

# MAINS

MAIN		=	sources/main.cpp \

MAINTEST	=	test/main.cpp \

# SRCS

ifeq ($(MODE), $(TEST))
SRC		=	$(MAINTEST)
else
SRC		=	$(MAIN)
endif

SRC		+=	sources/Core.cpp \
			sources/Event.cpp \
			sources/Network.cpp \
			sources/Protocol.cpp \
			sources/Record.cpp \

######################################
#                OBJ                 #
######################################

OBJ		=	$(SRC:.cpp=.o)

all:	$(OBJ)
	$(CXX) $(CPPFLAGS) -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
