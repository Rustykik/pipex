# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ubeetroo <ubeetroo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/04 12:56:00 by ubeetroo          #+#    #+#              #
#    Updated: 2021/12/24 22:57:28 by ubeetroo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

COMP = gcc

FLAGS = 

SRCS =	ft_atoi \
		ft_bzero \
		ft_calloc \
		ft_isalnum \
		ft_isalpha \
		ft_isascii \
		ft_isdigit \
		ft_isprint \
		ft_memchr \
		ft_memcmp \
		ft_memcpy \
		ft_memmove \
		ft_memset \
		ft_strchr \
		ft_strdup \
		ft_strlcat \
		ft_strlcpy \
		ft_strlen \
		ft_strncmp \
		ft_strnstr \
		ft_strrchr \
		ft_tolower \
		ft_toupper \
		ft_substr \
		ft_strjoin \
		ft_strtrim \
		ft_split \
		ft_itoa \
		ft_putchar_fd \
		ft_putstr_fd \
		ft_putendl_fd \
		ft_putnbr_fd \
		ft_strmapi \
		ft_striteri \
		ft_get_next_line_bonus \
		ft_get_next_line_utils_bonus \
		ft_pow \
		ft_lstnew \
		ft_lstadd_front \
		ft_lstsize \
		ft_lstlast \
		ft_lstadd_back \
		ft_lstdelone \
		ft_lstclear \
		ft_lstiter \
		ft_lstmap \
		ft_printf \
		ft_putchar_fd_printf \
		ft_putnbr_base_printf \
		ft_putnbr_basep_printf \
		ft_putnbr_fd_printf \
		ft_putstr_fd_printf \
		ft_strlen_printf
		

# SRCS_B =	ft_lstnew \
# 			ft_lstadd_front \
# 			ft_lstsize \
# 			ft_lstlast \
# 			ft_lstadd_back \
# 			ft_lstdelone \
# 			ft_lstclear \
# 			ft_lstiter \
# 			ft_lstmap

SRC =  $(addsuffix .c, $(SRCS))
OBJ =  $(addsuffix .o, $(SRCS))

# SRC_B =  $(addsuffix .c, $(SRCS_B))
# OBJ_B =  $(addsuffix .o, $(SRCS_B))

INC = libft.h

$(NAME): $(OBJ) $(INC)
	ar rcs $@ $^

# bonus: $(OBJ) $(OBJ_B) 
# 	ar rcs $(NAME) $(OBJ) $(OBJ_B)

%.o: %.c
	$(COMP) $(FLAGS) -c $< -o $@ 

all: $(NAME)

clean: 
	rm -f $(OBJ) 
#	rm -f $(OBJ_B)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re