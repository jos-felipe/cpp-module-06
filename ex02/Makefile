# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: josfelip <josfelip@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/13 11:14:42 by josfelip          #+#    #+#              #
#    Updated: 2025/02/13 11:14:45 by josfelip         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= identify
CC			= c++
CFLAGS		= -Wall -Wextra -Werror -std=c++98

SRCS		= main.cpp Base.cpp Functions.cpp
OBJS		= $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re