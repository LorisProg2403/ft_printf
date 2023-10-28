# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgaume <lgaume@student.42lausanne.ch>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/28 20:05:02 by lgaume            #+#    #+#              #
#    Updated: 2023/10/28 20:05:04 by lgaume           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Variables

NAME		= libftprintf.a
HEADER		= header
LIBFT		= libft
SRC_DIR		= c-files/
OBJ_DIR		= obj/
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -I
RM			= rm -f
AR			= ar rcs

# Colors

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

#Sources

C-FILES = ft_printf ft_putstr ft_print_char ft_print_str ft_print_nbr ft_print_unsigned ft_print_hex ft_print_ptr

SRC 	= $(addprefix $(SRC_DIR), $(addsuffix .c, $(C-FILES)))
OBJ 	= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(C-FILES)))

#Rules

OBJF	=		.cache_exists

all:			$(NAME)

$(NAME):		$(OBJ)
				@make -C $(LIBFT)
				@cp libft/libft.a .
				@mv libft.a $(NAME)
				@$(AR) $(NAME) $(OBJ)

$(OBJ_DIR)%.o: 	$(SRC_DIR)%.c | $(OBJF)
				@$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

$(OBJF):
				@mkdir -p $(OBJ_DIR)

clean:
				@$(RM) -rf $(OBJ_DIR)
				@make clean -C $(LIBFT)

fclean:			clean
				@$(RM) -f $(NAME)
				@$(RM) -f $(LIBFT)/libft.a

re:				fclean all

norm:
				@echo "$(RED)Launching norminette...$(DEF_COLOR)"
				@echo "$(CYAN)Norminette of LIBFT"
				@norminette $(LIBFT)
				@echo "$(MAGENTA)Norminette of C-FILES"
				@norminette $(SRC)
				@echo "$(GREEN)Norminette of HEADER"
				@norminette $(HEADER)

.PHONY:			all clean fclean re norm
