/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 18:35:32 by fratardi          #+#    #+#             */
/*   Updated: 2019/09/05 00:31:12 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "../../libft/includes/libft.h"

/*
**Defines for the static padding buffer
*/

# define BUFF_SIZE  100

/*
**Defines for unicodes hexas masks matching  hardware specifcations
*/

# define UNI1  0x80
# define UNI2  0xC0
# define UNI3  0xE0
# define UNI4  0xF0

/*
**Syntax Infos
*/

typedef struct			s_printinfo {
	int					prec;
	int					width;
	unsigned int		ndol;
	unsigned int		max;
	unsigned int		is_long_double;
	unsigned int		is_char;
	unsigned int		is_unsigned;
	unsigned int		is_short;
	unsigned int		is_long;
	unsigned int		is_float_ten;
	unsigned int		alt;
	unsigned int		space;
	unsigned int		left;
	unsigned int		showsign;
	unsigned int		group;
	unsigned int		extra;
	unsigned int		bin;
	char				t;
	char				special;
}						t_printinfo;

/*
**Variable position struct
*/

typedef struct			s_rep {
	int		ret;
	int		seglen;
	int		syntaxlen;
	int		strpos;
	int		vapos;
	va_list	current;
	va_list	start;
}						t_rep;

/*
**Not_sytax
*/

typedef struct			s_no_syntax{
	size_t	ret;
	char	left;
	char	extra;
	int		width;
}						t_no_syntax;

/*
**Content of elypse
*/

typedef struct			s_elem{
	void					*value;
	long long int			lli;
	unsigned long long int	ulli;
	double					dble;
	long double				long_double;
	int						c;
	unsigned int			pos;
	signed char				s_c;
}						t_elem;

/*
**Struct for va_read
*/

typedef struct			s_va{
	size_t		nb_va;
	size_t		nb_pos;
	t_elem		*elem;
	t_elem		*start;
	t_printinfo	*pstart;
}						t_va;

/*
**	Datatype made to handle floating point content operations
*/

typedef struct			s_double{
	char	*m;
	int		ex;
	char	*ent;
	char	*dec;
	char	*temp;
	char	*tempent;
	int		b;
}						t_double;

typedef struct			s_power{
	char	*base;
	int		p;
	int		i;
}						t_power;

/*
** Functions to print content and values
*/

void					ft_hexfloat(void *content, size_t n);
void					ft_displaybin(void *content, size_t n);
size_t					ft_printlli(long long int n, t_printinfo *l);
size_t					ft_printulli(unsigned long long int n, t_printinfo *l);
size_t					ft_display_char_content(void *content, size_t len);
size_t					ft_print_uni_str(char *str);
size_t					ft_print_uni_char(char *str);
int						ft_print_n_uni_str(char *str, int size);
int						ft_print_rest(char *seg, int size);
int						ft_print_preset_buf(unsigned char c, int n);
int						ft_same(char *s1, char *s2);

/*
** Functions to convert content into char *
*/

char					*ft_convert_o(unsigned long long int to_convert);
char					*ft_convert_x(unsigned long long int to_convert);
char					*ft_convert_up_x(unsigned long long int to_convert);
char					*ft_convert_p(void *to_convert);
char					*ft_binary(void *content, size_t n);
char					*ft_binary_string(void *content, size_t n);
char					*ft_rest(char *str);

/*
**len indicators
*/

size_t					ft_size_octal(unsigned long long int to_convert);
size_t					ft_size_hexa(unsigned long long int to_convert);
size_t					ft_uni_char_len(char *str);
size_t					ft_uni_str_len(char *str);
size_t					ft_sequence(char *s, int len);
int						ft_sequencelen(const char *format);
int						ft_syntaxlen(const char *format);
int						ft_issyntax(char *s, size_t len);

/*
**Float Handling Functions
*/

char					*ft_ldouble(long double a, int prec,
	unsigned int is_ten, int sign);
t_double				init_dble(long double a);
char					*ft_exception(long double a, t_printinfo *list);
char					*ft_casenull(char *str, int *last);
char					*ft_float_zero(int prec, unsigned int is_ten,
	long double a, int s);
int						ft_expldouble(long double a);
void					ft_adjustpospo(char **s1, char **s2);
void					ft_adjustnegpo(char **s1, char **s2);
char					ft_addchar(char *s1, char *s2, char *ret, char carry);
char					*ft_addstrings(char *s1, char *s2);
void					ft_addstrings_stack(char *assign, char *base,
	int po_assig, int po_base);
char					*ft_new_addstrings(char *s1, char *s2);
char					*ft_pow_pos(int po, int end);
char					*ft_pow2str(int ex, char end);
char					*ft_floatexp(char *str, int prec);
t_double				ft_rounding_float(t_double dble, int prec);
char					*ft_round_dec(char *str, int prec, int *round_ent);
char					*ft_mantissaldouble(long double d);

/*
**Fill Stuct Print_Info
*/

char					*ft_fillbuf(t_printinfo *list, t_rep *rep);
void					ft_fillzerolist(t_printinfo *list);
t_printinfo				*ft_fillstruct(char **tab);
t_printinfo				*ft_fillflag(char *str, t_printinfo *list);
t_printinfo				*ft_fillmod(char *str, t_printinfo *list);
t_printinfo				*ft_fillprec(char *str, t_printinfo *list);
t_printinfo				*ft_fillndol(char *str, t_printinfo *list);
t_printinfo				*ft_fillwidth(char *str, t_printinfo *list, t_rep *rep);
t_printinfo				*ft_filltype(char *str, t_printinfo *list);

/*
** Fill Buffer
*/

char					*ft_fillbuf_float(t_printinfo *l, t_rep *rep);
char					*ft_fillbuf_convert(t_printinfo *l, t_rep *rep);
char					*ft_fillbuf_digits(t_printinfo *l, t_rep *rep);
char					*ft_fillbuf_bin(t_printinfo *l, t_rep *rep);
long long int			ft_filldi(t_printinfo *list, t_rep *rep);
unsigned long long int	ft_fillunsigned(t_printinfo *list, t_rep *rep);
t_elem					*ft_fillfloats(t_printinfo *list, va_list va,
	t_elem *elem);

/*
** Padding
*/

int						ft_pad_char_type(t_printinfo *l, char **buf);
int						ft_pad_xo(t_printinfo *l, int zero, char **buf);
int						ft_pad_di(t_printinfo *l, char **buf);
void					ft_padding_convert(t_printinfo *l, int zero);
void					ft_padding_str(t_printinfo *l);
char					*ft_pad_prec(t_printinfo *l, char *buf);
int						ft_pad_float(t_printinfo *l, char **buf);
int						ft_padding_display(t_printinfo *l, char **buf,
	int zero);
/*
**	va_operations
*/

void					ft_pick_va_string(char **ret, t_rep *rep);
void					ft_star_search(t_rep *rep, t_printinfo *info);
void					ft_arg_search(t_rep *rep, t_printinfo *info);

/*
**Main Function of ft_printf
*/

int						ft_printf(const char *format, ...);
void					ft_print_t_list_content(t_printinfo *info);
int						ft_binary_exopnent(char *bin);
int						ft_exp_ldouble(long double a);
#endif
