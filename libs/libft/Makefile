# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pfaust <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/08 15:46:59 by pfaust            #+#    #+#              #
#    Updated: 2018/12/19 10:33:28 by pfaust           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FLAGS = -Wall -Wextra -Werror
INCLUDES = -I./includes
HEADER = includes/libft.h
SRC = ft_atoi ft_bzero ft_isalnum ft_isalpha ft_isascii \
	ft_isdigit ft_isprint ft_itoa ft_lstadd ft_lstdel \
	ft_lstdelone ft_lstiter ft_lstmap ft_lstnew ft_memalloc \
	ft_memccpy ft_memchr ft_memcmp ft_memcpy ft_memdel \
	ft_memmove ft_memset ft_putchar ft_putchar_fd ft_putendl \
	ft_putendl_fd ft_putnbr ft_putnbr_fd ft_putstr ft_putstr_fd \
	ft_strcat ft_strchr ft_strclr ft_strcmp ft_strcpy \
	ft_strdel ft_strdup ft_strequ ft_striter ft_striteri \
	ft_strjoin ft_strlcat ft_strlen ft_strmap ft_strmapi \
	ft_strncat ft_strncmp ft_strncpy ft_strnequ ft_strnew \
	ft_strnstr ft_strrchr ft_strsplit ft_strstr ft_strsub \
	ft_strtrim ft_tolower ft_toupper ft_pow ft_wordlen \
	ft_nbwords ft_itoa_base_ll ft_itoa_base_ull ft_itoa_base \
	ft_never_negative ft_itoa_ll ft_itoa_base_uint\
	ft_itoa_db ft_nb_entiers ft_print_bits ft_binary_long\
	ft_truncate ft_cpyalpha ft_putbinstr ft_dir_strncpy\
	ft_int_pow ft_tab_is_sort

OBJS = $(addprefix objs/, $(addsuffix .o, \
	   $(SRC) \
	 ))

all : $(NAME)

$(NAME): objs $(OBJS)
	@ar rcs $(NAME) $(OBJS)

objs/%.o: src/%.c $(HEADER)
	@gcc -o $@ -c $< $(FLAGS) $(INCLUDES)
objs:
	@mkdir -p objs/
clean :
	@rm -rf objs/
fclean : clean
	@rm -rf $(NAME)
re : fclean all
