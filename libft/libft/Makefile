# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/15 17:27:11 by fratardi          #+#    #+#              #
#    Updated: 2020/05/03 14:42:06 by tpacaud          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = -Wall -Werror -Wextra

SRC = str/ft_strjoinfree.c\
str/ft_strnlen.c\
str/ft_strndup.c\
str/ft_strequ.c\
str/ft_strncat.c\
str/ft_strsplit.c\
str/ft_strcat.c\
str/ft_striter.c\
str/ft_strstr.c\
str/ft_strchr.c\
str/ft_striteri.c\
str/ft_strncmp.c\
str/ft_strsub.c\
str/ft_strclr.c\
str/ft_strjoin.c\
str/ft_strncpy.c\
str/ft_strtrim.c \
str/ft_strcmp.c \
str/ft_strlcat.c \
str/ft_strnequ.c \
str/ft_strcpy.c \
str/ft_strlen.c \
str/ft_strnew.c \
str/ft_strdel.c\
str/ft_strmap.c\
str/ft_strnstr.c\
str/ft_strdup.c\
str/ft_strmapi.c\
str/ft_strrchr.c\
str/ft_joinfree.c\
memory/ft_freetab.c\
memory/ft_swap.c\
memory/ft_memset.c\
memory/ft_memaset.c\
memory/ft_memalloc.c\
memory/ft_bzero.c\
memory/ft_memccpy.c\
memory/ft_memchr.c\
memory/ft_memcpy.c \
memory/ft_memcmp.c \
memory/ft_memdel.c \
memory/ft_memmove.c\
lists/ft_lstmap.c\
lists/ft_lstiter.c\
lists/ft_lstadd.c\
lists/ft_lstdel.c\
lists/ft_lstdelone.c\
lists/ft_lstnew.c\
charset/ft_isspace.c\
charset/ft_isalnum.c\
charset/ft_isascii.c \
charset/ft_isdigit.c \
charset/ft_isprint.c\
charset/ft_isalpha.c \
convert/ft_itoa.c\
convert/ft_atoi.c\
convert/ft_ullitoa.c\
convert/ft_tolower.c \
convert/ft_llitoa.c\
convert/ft_toupper.c \
display/ft_putchar.c\
display/ft_putchar_fd.c\
display/ft_putendl.c\
display/ft_putnbr.c \
display/ft_putendl_fd.c \
display/ft_putnbr_fd.c\
display/ft_putstr.c\
display/ft_putstr_fd.c\
display/ft_print_table.c\
display/ft_putnstr.c\
maths/ft_pow2.c\
maths/ft_to_the_pow.c\
maths/math.c\
maths/ft_pow.c\

OBJ = $(SRC:.c=.o)
$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
all : $(NAME)
%.o : %.c ./libft.a .Makefile
	gcc $(FLAGS) -o $@ -c $<
clean :
	rm -f $(OBJ)
fclean : clean
	rm -f $(NAME)
re : 	fclean all

.PHONY :all opti clean fclean re
