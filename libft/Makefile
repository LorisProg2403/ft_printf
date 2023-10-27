# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgaume <marvin@42lausanne.ch>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/10 10:09:28 by lgaume            #+#    #+#              #
#    Updated: 2023/10/10 10:09:28 by lgaume           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = libft.a

HEADER = libft.h

FLAGS = -Wall -Wextra -Werror

SRC				=	ft_isalnum.c ft_isprint.c ft_memcmp.c  ft_putchar_fd.c ft_split.c \
					ft_strlcat.c ft_strncmp.c ft_substr.c ft_atoi.c ft_isalpha.c \
					ft_itoa.c ft_memcpy.c  ft_putendl_fd.c ft_strchr.c  ft_strlcpy.c \
					ft_strnstr.c ft_tolower.c ft_bzero.c   ft_isascii.c ft_strnew.c \
					ft_memmove.c ft_putnbr_fd.c  ft_strdup.c  ft_strlen.c  ft_strrchr.c \
					ft_toupper.c ft_calloc.c  ft_isdigit.c ft_memchr.c  ft_memset.c  \
					ft_putstr_fd.c  ft_strjoin.c ft_strmapi.c ft_strtrim.c ft_isspace.c \
					ft_striteri.c ft_strncat.c \
					ft_unsigned_itoa.c \

OBJ = $(SRC:.c=.o)

BONUS			= 	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
					ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
					ft_lstmap.c \

BONUS_OBJ = $(BONUS:.c=.o)

all: $(NAME)

$(NAME): 	$(OBJ)
				ar rc $(NAME) $(OBJ)
				ranlib $(NAME)

$(OBJ):
				$(CC) $(FLAGS) -c $(SRC)

bonus:		$(BONUS_OBJ)
				ar rc $(NAME) $(BONUS_OBJ)
				ranlib $(NAME)

clean:
				rm -f $(OBJ) $(BONUS_OBJ)

fclean: 	clean
				rm -f $(NAME)

re:			fclean all

.PHONY: 	all clean fclean re bonus
