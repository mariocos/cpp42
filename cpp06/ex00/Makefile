CXX         = c++
CXXFLAGS    = -Wall -Wextra -Werror -std=c++98
RM          = rm -f

NAME        = baca

INCLUDES    = ScalarConverter.hpp

SRCS        = print_utils.cpp ScalarConverter.cpp find_type.cpp main.cpp

OBJS        = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp $(INCLUDES)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
