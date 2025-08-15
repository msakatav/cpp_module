# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msakata <msakata@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/13 23:09:23 by msakata           #+#    #+#              #
#    Updated: 2025/08/14 03:32:30 by msakata          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fixed_point_numvers
SRCS = main.cpp Fixed.cpp
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	
fclean: clean
	rm -f $(NAME)
	
re: fclean all

.PHONY: all clean fclean re