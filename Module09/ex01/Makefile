# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/16 13:40:46 by jmabel            #+#    #+#              #
#    Updated: 2023/06/12 18:49:05 by jmabel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	RPN
HEADER		=	RPN.hpp

CC			=	c++
CPPFLAGS	=	-Wall -Wextra -Werror
CPPFLAGS	+=	-std=c++98

RM			=	rm -f 

SRCS		=	main.cpp \
				RPN.cpp

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