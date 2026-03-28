# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/28 10:49:37 by rde-mour          #+#    #+#              #
#    Updated: 2026/03/28 18:09:28 by rde-mour         ###   ########.org.br    #
#                                                                              #
# **************************************************************************** #

RED					:= $(shell tput setaf 1)
GREEN				:= $(shell tput setaf 2)
YELLOW				:= $(shell tput setaf 3)
BLUE				:= $(shell tput setaf 4)
MAGENTA				:= $(shell tput setaf 5)
RESET				:= $(shell tput sgr0)


NAME				:= ft_ls

INCLUDES			:= ./includes

FILES				:= main.c \
					   list/list_add_back.c \
					   list/list_add_front.c \
					   list/list_clear.c \
					   list/list_last.c \
					   list/list_new.c \
					   list/list_size.c \
					   sort/sort_list.c \
					   sort/sort_name.c \
					   sort/sort_size.c \
					   sort/sort_mtim.c \
					   sort/sort_ctim.c \
					   sort/sort_atim.c \
					   sort/sort_extension.c \
					   sort/sort_version.c \
					   sort/sort_revert.c

SRCSDIR				:= ./srcs
OBJSDIR				:= ./objs

SRCS				:= $(FILES:%.c=$(SRCSDIR)/%.o)
OBJS				:= $(FILES:%.c=$(OBJSDIR)/%.o)

CFLAGS				:= -Wall -Wextra -Werror -g3 -O3

COMPILER			:= cc


all: 				$(NAME)

$(NAME):			$(OBJS)
					@$(COMPILER) $(CFLAGS) $(OBJS) -o $@
					@echo "$(BLUE)Compiled $(NAME) successfully$(RESET)"

$(OBJSDIR)/%.o:		$(SRCSDIR)/%.c
					@mkdir -p $(@D)
					@$(COMPILER) $(CFLAGS) -c $< -o $@ -I $(INCLUDES)
					@echo "$(GREEN)Compiled$(RESET) $(notdir $<)"

clean:
					@echo "$(RED)Removing$(RESET) $(NAME) objects"
					@rm -rf $(OBJSDIR)

fclean: 			clean
					@echo "$(RED)Removing$(RESET) $(NAME)"
					@rm -rf $(NAME)

re:					fclean all

.PHONY: 			all clean fclean re
