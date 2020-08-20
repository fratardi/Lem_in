# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/18 15:09:05 by tpacaud           #+#    #+#              #
#    Updated: 2019/09/17 03:18:40 by fratardi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

LIB = ../libft/libft.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

INC_PATH = ./includes

INC_NAME = ft_printf.h

C = srcs/ft_printf.c\
	srcs/convert/ft_convert.c \
	srcs/convert/ft_displaybin.c\
	srcs/convert/ft_size_convert.c\
	srcs/maths/ft_annex_float.c\
	srcs/maths/ft_annex_ldouble.c\
	srcs/maths/ft_addstrings.c\
	srcs/maths/ft_adjustfloat.c\
	srcs/maths/ft_exception.c\
	srcs/maths/ft_roundfloat.c\
	srcs/maths/ft_new_addstring.c\
	srcs/maths/ft_pow_str.c\
	srcs/padding/ft_pad_prec.c\
	srcs/padding/ft_padding_convert.c\
	srcs/padding/ft_padding_digits.c\
	srcs/padding/ft_padding_display.c\
	srcs/padding/ft_padding_float_char.c\
	srcs/padding/ft_print_preset_buf.c\
	srcs/buffer/ft_fill_buffer_ouxf.c\
	srcs/buffer/ft_fill_buffer.c\
	srcs/parsing/ft_fill_struct1.c\
	srcs/parsing/ft_fill_struct2.c\
	srcs/parsing/ft_issyntax.c\
	srcs/parsing/ft_same.c\
	srcs/parsing/ft_sequence.c\
	srcs/parsing/ft_va.c\
	srcs/unicodes/ft_print_uni_char.c\
	srcs/unicodes/ft_print_uni_str.c\
	srcs/unicodes/ft_uni_char_len.c\
	srcs/unicodes/ft_uni_str_len.c\
	srcs/display/ft_disp_content_char.c\
	srcs/display/ft_print_rest.c\


C_LIB 	:=	../libft/memory/ft_memset.o \
			../libft/memory/ft_memalloc.o \
			../libft/memory/ft_memccpy.o \
			../libft/memory/ft_memchr.o \
			../libft/memory/ft_memcmp.o \
			../libft/memory/ft_memaset.o \
			../libft/memory/ft_memcpy.o \
			../libft/memory/ft_memdel.o \
			../libft/memory/ft_memmove.o \
			../libft/memory/ft_bzero.o \
			../libft/memory/ft_freetab.o \
			../libft/memory/ft_swap.o \
			../libft/charset/ft_isdigit.o \
			../libft/charset/ft_isspace.o \
			../libft/charset/ft_isalnum.o \
			../libft/charset/ft_isprint.o \
			../libft/charset/ft_isalpha.o \
			../libft/charset/ft_isascii.o \
			../libft/str/ft_strnlen.o \
			../libft/str/ft_strndup.o \
			../libft/str/ft_strequ.o \
			../libft/str/ft_strncat.o \
			../libft/str/ft_strsplit.o \
			../libft/str/ft_strjoinfree.o \
			../libft/str/ft_strcat.o \
			../libft/str/ft_striter.o \
			../libft/str/ft_strstr.o \
			../libft/str/ft_strchr.o \
			../libft/str/ft_striteri.o \
			../libft/str/ft_strncmp.o \
			../libft/str/ft_strsub.o \
			../libft/str/ft_strclr.o \
			../libft/str/ft_strjoin.o \
			../libft/str/ft_strncpy.o \
			../libft/str/ft_strtrim.o \
			../libft/str/ft_strcmp.o \
			../libft/str/ft_strlcat.o \
			../libft/str/ft_strnequ.o \
			../libft/str/ft_strcpy.o \
			../libft/str/ft_strlen.o \
			../libft/str/ft_strnew.o \
			../libft/str/ft_strdel.o \
			../libft/str/ft_strmap.o \
			../libft/str/ft_strnstr.o \
			../libft/str/ft_strdup.o \
			../libft/str/ft_strmapi.o \
			../libft/str/ft_strrchr.o \
			../libft/str/ft_joinfree.o \
			../libft/lists/ft_lstmap.o \
			../libft/lists/ft_lstiter.o \
			../libft/lists/ft_lstadd.o \
			../libft/lists/ft_lstdel.o \
			../libft/lists/ft_lstdelone.o\
			../libft/lists/ft_lstnew.o \
			../libft/display/ft_putstr_fd.o \
			../libft/display/ft_print_table.o \
			../libft/display/ft_putchar.o \
			../libft/display/ft_putchar_fd.o \
			../libft/display/ft_putendl.o \
			../libft/display/ft_putnbr.o \
			../libft/display/ft_putnbr_fd.o \
			../libft/display/ft_putendl_fd.o \
			../libft/display/ft_putstr.o \
			../libft/display/ft_putnstr.o \
			../libft/convert/ft_tolower.o \
			../libft/convert/ft_llitoa.o \
			../libft/convert/ft_atoi.o \
			../libft/convert/ft_itoa.o \
			../libft/convert/ft_toupper.o \
			../libft/convert/ft_ullitoa.o \
			../libft/maths/ft_pow2.o \
			../libft/maths/ft_pow.o \

INC = $(addprefix $(INC_PATH)/,$(INC_NAME))

O = $(C:.c=.o)

O_LIB = $(C_LIB:.c=.o)

all : $(NAME)

newline :
	@echo ""

$(NAME): $(O) $(O_LIB) $(INC)
	@echo ""
	@ar rc $(NAME) $(O) $(O_LIB)
	@echo "ar rc of" $(NAME) "is done"
	@ranlib $(NAME)
	@echo "Ranlib of" $(NAME) "is done"

%.o : %.c	
	$(CC) $(FLAGS) -c $< -o $@
	$(if $(findstring srcs,$@),@echo "Making" $<)
	$(if $(findstring libft/ft_itoa.o,$@), @echo "")
	$(if $(findstring libft/ft_itoa.o,$@), @echo ">>> Making LIBFT ...")

clean :
	@rm -rf $(O)
	@rm -rf $(O_LIB)
	@echo "Cleaning Done (Removed .o)"

fclean : clean
	@rm -rf $(NAME) $(LIB)
	@echo "libft.a && libftprintf.a Removed"

re : fclean newline all

.PHONY : all lib clean flean re
