CXX 			= c++

CXXFLAGS 		= -Wall -Wextra -Werror -std=c++98

RM 			= rm -f

NAME 		= phonebook

INCLUDE 	= -I ./

SRCS 		= cpp01.cpp

OBJS		= $(SRCS:.cpp=.o)

all:		$(NAME)

$(NAME): 	$(OBJS)
			$(CXX) $(CXXFLAGS) $(SRCS) $(INCLUDE) -c
			$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME) $(INCLUDE)

clean:
			$(RM) -r $(OBJS)

fclean : 	clean
			$(RM) $(NAME)

re:			fclean all