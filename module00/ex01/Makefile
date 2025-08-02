# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msakata <msakata@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/12 00:13:49 by msakata           #+#    #+#              #
#    Updated: 2025/07/30 06:28:15 by msakata          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook
SRCS =	Contact.cpp PhoneBook.cpp main.cpp
FLAGS = -Wall -Wextra -Werror -std=c++98
CXX = c++
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(FLAGS) $(OBJS) -o $(NAME)
	
%.o: %.cpp
	$(CXX) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	
fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re