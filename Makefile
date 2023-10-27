# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgaume <lgaume@student.42lausanne.ch>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/26 20:05:02 by lgaume            #+#    #+#              #
#    Updated: 2023/10/26 20:05:04 by lgaume           ###   ########.fr        #
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

C-FILES = ft_printf ft_printstr ft_printnbr ft_print_char ft_print_unsigned ft_print_hex ft_print_ptr

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
				@echo "$(GREEN)ft_printf compiled!$(DEF_COLOR)"

$(OBJ_DIR)%.o: 	$(SRC_DIR)%.c | $(OBJF)
				@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
				@$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

$(OBJF):
				@mkdir -p $(OBJ_DIR)

clean:
				@$(RM) -rf $(OBJ_DIR)
				@make clean -C $(LIBFT)
				@echo "$(BLUE)ft_printf object files cleaned!$(DEF_COLOR)"
				@echo "$(BLUE)libft object files cleaned!$(DEF_COLOR)"

fclean:			clean
				@$(RM) -f $(NAME)
				@$(RM) -f $(LIBFT)/libft.a
				@echo "$(CYAN)ft_printf executable files cleaned!$(DEF_COLOR)"
				@echo "$(CYAN)libft executable files cleaned!$(DEF_COLOR)"

re:				fclean all
				@echo "$(GREEN)Cleaned and rebuilt everything for ft_printf!$(DEF_COLOR)"

norm:
				@echo "$(RED)Launching norminette...$(DEF_COLOR)"
				@norminette $(LIBFT) $(SRC) $(HEADER)

.PHONY:			all clean fclean re norm
