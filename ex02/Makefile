SRCS=  main.cpp PmergeMe.cpp
OBJS= $(SRCS:.cpp=.o)
CFLAGS= -Wall -Wextra -Werror -std=c++98 -fsanitize=address -g
CPP= c++
NAME= PmergeMe

.PHONY: clean

all: $(NAME)

%.o: %.cpp  PmergeMe.hpp
	$(CPP) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CPP) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all