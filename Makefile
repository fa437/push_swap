# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fasare <fasare@student.42wolfsburg.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/19 15:29:21 by fasare            #+#    #+#              #
#    Updated: 2023/08/08 13:32:33 by fasare           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= push_swap

LIBFT			= libft.a

SRCS			= push.c \
 				  push_swap.c \
				  push_swap_utils.c \
				  rotate.c \
				  reverse_rotate.c \
				  swap.c \
				  simple_sort.c \
				  quick_sort.c \
				  checker.c
				  
OBJS			= $(SRCS:.c=.o)

CFLAGS			= -Wall -Wextra -Werror

CC				= gcc

FSANITIZE 		= -fsanitize=address -g3

INCLUDE			= -I include

RM 				= rm -rf

$(NAME):		$(OBJS)
				$(MAKE) -C libft
				@cp libft/$(LIBFT) .
				$(CC) $(CFLAGS) $(INCLUDE) $(OBJS) $(LIBFT) -o $(NAME)

all:			$(NAME)
				
clean:			
				make clean -C libft
				$(RM) $(OBJS)
						
fclean:			clean			
				make fclean -C libft
				$(RM) $(NAME)
				$(RM) $(LIBFT)

re:				fclean all

.PHONY:			all clean fclean re