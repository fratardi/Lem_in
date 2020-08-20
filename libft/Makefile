
NAME  = libft.a

FLAGS = -Wall -Werror -Wextra

CC = gcc

C_LIB = libft/str/ft_strjoinfree.c\
libft/str/ft_strnlen.c\
libft/str/ft_strndup.c\
libft/str/ft_strequ.c\
libft/str/ft_strncat.c\
libft/str/ft_strsplit.c\
libft/str/ft_strcat.c\
libft/str/ft_striter.c\
libft/str/ft_strstr.c\
libft/str/ft_strchr.c\
libft/str/ft_striteri.c\
libft/str/ft_strncmp.c\
libft/str/ft_strsub.c\
libft/str/ft_strclr.c\
libft/str/ft_strjoin.c\
libft/str/ft_strncpy.c\
libft/str/ft_strtrim.c \
libft/str/ft_strcmp.c \
libft/str/ft_strlcat.c \
libft/str/ft_strnequ.c \
libft/str/ft_strcpy.c \
libft/str/ft_strlen.c \
libft/str/ft_strnew.c \
libft/str/ft_strdel.c\
libft/str/ft_strmap.c\
libft/str/ft_strnstr.c\
libft/str/ft_strdup.c\
libft/str/ft_strmapi.c\
libft/str/ft_strrchr.c\
libft/str/ft_joinfree.c\
libft/memory/ft_freetab.c\
libft/memory/ft_swap.c\
libft/memory/ft_memset.c\
libft/memory/ft_memaset.c\
libft/memory/ft_memalloc.c\
libft/memory/ft_bzero.c\
libft/memory/ft_memcpy.c \
libft/memory/ft_memcmp.c \
libft/memory/ft_memdel.c \
libft/memory/ft_memmove.c\
libft/lists/ft_lstmap.c\
libft/lists/ft_lstiter.c\
libft/lists/ft_lstadd.c\
libft/lists/ft_lstdel.c\
libft/lists/ft_lstdelone.c\
libft/lists/ft_lstnew.c\
libft/charset/ft_isspace.c\
libft/charset/ft_isalnum.c\
libft/charset/ft_isascii.c \
libft/charset/ft_isdigit.c \
libft/charset/ft_isprint.c\
libft/charset/ft_isalpha.c \
libft/convert/ft_itoa.c\
libft/convert/ft_atoi.c\
libft/convert/ft_ullitoa.c\
libft/convert/ft_tolower.c \
libft/convert/ft_llitoa.c\
libft/convert/ft_toupper.c \
libft/display/ft_putchar.c\
libft/display/ft_putchar_fd.c\
libft/display/ft_putendl.c\
libft/display/ft_putnbr.c \
libft/display/ft_putendl_fd.c \
libft/display/ft_putnbr_fd.c\
libft/display/ft_putstr.c\
libft/display/ft_putstr_fd.c\
libft/display/ft_print_table.c\
libft/display/ft_putnstr.c\
libft/maths/ft_pow2.c\
libft/maths/ft_pow.c\
libft/maths/math.c\
ft_printf/srcs/ft_printf.c\
ft_printf/srcs/convert/ft_convert.c \
ft_printf/srcs/convert/ft_displaybin.c\
ft_printf/srcs/convert/ft_size_convert.c\
ft_printf/srcs/maths/ft_annex_float.c\
ft_printf/srcs/maths/ft_annex_ldouble.c\
ft_printf/srcs/maths/ft_addstrings.c\
ft_printf/srcs/maths/ft_adjustfloat.c\
ft_printf/srcs/maths/ft_exception.c\
ft_printf/srcs/maths/ft_roundfloat.c\
ft_printf/srcs/maths/ft_new_addstring.c\
ft_printf/srcs/maths/ft_pow_str.c\
ft_printf/srcs/padding/ft_pad_prec.c\
ft_printf/srcs/padding/ft_padding_convert.c\
ft_printf/srcs/padding/ft_padding_digits.c\
ft_printf/srcs/padding/ft_padding_display.c\
ft_printf/srcs/padding/ft_padding_float_char.c\
ft_printf/srcs/padding/ft_print_preset_buf.c\
ft_printf/srcs/buffer/ft_fill_buffer_ouxf.c\
ft_printf/srcs/buffer/ft_fill_buffer.c\
ft_printf/srcs/parsing/ft_fill_struct1.c\
ft_printf/srcs/parsing/ft_fill_struct2.c\
ft_printf/srcs/parsing/ft_issyntax.c\
ft_printf/srcs/parsing/ft_same.c\
ft_printf/srcs/parsing/ft_sequence.c\
ft_printf/srcs/parsing/ft_va.c\
ft_printf/srcs/unicodes/ft_print_uni_char.c\
ft_printf/srcs/unicodes/ft_print_uni_str.c\
ft_printf/srcs/unicodes/ft_uni_char_len.c\
ft_printf/srcs/unicodes/ft_uni_str_len.c\
ft_printf/srcs/display/ft_disp_content_char.c\
ft_printf/srcs/display/ft_print_rest.c\

O_LIB = $(C_LIB:.c=.o)

all : $(NAME)

newline :
	@echo ""

title :
	@echo "--- Making LIBFT ---"

$(NAME): $(O_LIB)
	@echo ""
	@ar rc $(NAME) $(O_LIB)
	@echo ">> ar rc of" $(NAME) "is done"
	@ranlib $(NAME)
	@echo ">> Ranlib of" $(NAME) "is done"

%.o : %.c
	@$(CC) $(FLAGS) -c $< -o $@
	$(if $(findstring ft_strjoinfree, $@),@echo "\n--- Making \033[36mLIBFT\033[00m ---")
	@echo -n '*'
#	$(if $(findstring libft/ft_itoa.o,$@), @echo "")
#	$(if $(findstring libft/ft_itoa.o,$@), @echo ">>> Making LIBFT ...")

clean :
	@rm -rf $(O_LIB)
	@echo "Cleaning Done (Removed .o)"

fclean : clean
	@rm -rf $(NAME) $(LIB)
	@echo "libft.a Removed"

re : fclean newline all

.PHONY : all lib clean flean re
