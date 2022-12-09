# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmabel <jmabel@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/16 13:40:46 by jmabel            #+#    #+#              #
#    Updated: 2022/12/09 22:03:25 by jmabel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	main
HEADER		=	Array.hpp

CC			=	c++
CPPFLAGS	=	-Wall -Wextra -Werror
CPPFLAGS	+=	-std=c++98

RM			=	rm -f 

SRCS		=	main.cpp

OBJS		=	${SRCS:%.cpp=%.o}

%.o:		%.cpp $(HEADER)
			$(CC) $(CPPFLAGS) -c $< -o $@


all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(CPPFLAGS) $(OBJS) -o $(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re