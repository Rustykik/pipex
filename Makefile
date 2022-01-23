# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rusty <rusty@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/22 04:24:09 by rusty             #+#    #+#              #
#    Updated: 2022/01/22 07:50:12 by rusty            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

PATH_LIBFT = ./libft/

LIBFT = $(PATH_LIBFT)libft.a

PI_SRCS = main \
			pipex \
			utils \
			errors \
			init_and_free \

PI_INCS = pipex.h 

PI_SRC = $(addsuffix .c, $(PI_SRCS))
PI_OBJ = $(addsuffix .o, $(PI_SRCS))

COMP = gcc

all: $(LIBFT) $(NAME) $(PI_INCS) Makefile

# include 		$(wildcard $(D) $(D_BONUS))

%.o : %.c 
	$(COMP) -Wall -Werror -Wextra -c $< -o $@ 

$(NAME): $(PI_OBJ) $(LIBFT)
	$(COMP) $(PI_OBJ) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C $(PATH_LIBFT)

bonus: all
# @make FSRC="$(FSRC_B)" FOBJ="$(FOBJ_B)" FINC="$(FINC_B)" all	

clean:
	rm -f $(PI_OBJ)
	make -C $(PATH_LIBFT) fclean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus


