/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <fratardi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 20:59:48 by tpacaud           #+#    #+#             */
/*   Updated: 2020/05/12 23:05:15 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# include "ft_printf.h"
# define BUFF_RSIZE 1000000

typedef struct	s_lines{
	char				*line;
	struct s_lines		*next;
}				t_lines;

typedef struct	s_room{
	char				*name;
	size_t				x;
	size_t				y;
	int					start_end;
	struct s_room		*next;
}				t_room;

typedef struct	s_formset{
	unsigned int		nb_pths;
	unsigned int		longest;
	unsigned int		min_ants;
	unsigned int		ret;
	struct s_formset	*next;
}				t_formset;

typedef struct	s_distribute{
	unsigned int		good_set;
	unsigned int		longest;
	unsigned int		nb_pths;
	unsigned int		nb_f_all;
	unsigned int		nb_f_extra;
	unsigned int		*dis;
	unsigned int		len;
}				t_distrubute;

typedef struct	s_best_set{
	unsigned int		nb_pths;
	t_formset			*form;
	unsigned int		nb_f_all;
	unsigned int		start_set;
	unsigned char		**mat_pths;
}				t_best_set;

typedef struct	s_anthill
{
	unsigned int		skiml;
	struct s_lines		*read;
	struct s_room		*room;
	struct s_formset	*form;
	struct s_formset	*current_set;
	struct s_distribute	dis;
	unsigned char		**matrice;
	unsigned char		**paths;
	unsigned char		**layer;
	unsigned char		**dfs_map;
	unsigned char		**dfs_dup;
	unsigned char		*bfs_total;
	unsigned char		*total_pths;
	unsigned char		*update_total;
	unsigned int		ants;
	unsigned int		real_s;
	unsigned int		size;
	unsigned int		layer_depth;
	struct s_best_set	b_set;
}				t_anthill;

typedef	struct	s_explore{
	unsigned char		*tots;
	unsigned int		id;
	unsigned int		pid;
	unsigned int		rid;
	unsigned int		last;
	unsigned int		f_st;
	struct s_explore	*next;
}				t_explore;

/*
**Parsing
*/

unsigned char	ft_init_anthill_parse(t_anthill *anthill);
t_lines			*ft_to_buf_file(void);
char			ft_factor_anthill(t_room *rooms);
int				is_conform(char *str);
char			*join_left(char *s1, char *s2);
size_t			ft_line_len(char *str, size_t i);

/*
**Errors_Checking
*/

int				check_first(char *str, size_t read);
t_room			*check_second(t_lines *buf);
int				is_instruction(char *str);
int				check_last(t_lines *buf);

/*
**Mod Rooms
*/

t_room			*start_first(t_room *rooms);
t_room			*end_last(t_room *rooms);

/*
**Init_Struct_rooms
*/

int				ft_fill_rooms(char *str, t_room *rooms);
void			print_rooms(t_room *rooms);

/*
**Matrice
*/

unsigned char	**dup_matrice(t_anthill *anthill);
t_lines			*init_mat(t_lines *buf, t_room *rooms,
	unsigned char **matrice);
unsigned char	**malloc_matr(int row, int collumn);
unsigned char	**matrice(t_lines *buf, t_room *rooms);
unsigned char	**ft_cpy_matrice(unsigned char **matrice,
	unsigned char **cpy, unsigned int map_size);
unsigned char	**ft_create_matrice(t_room *rooms);
unsigned int	ft_matr_size(unsigned char **matrice);

/*
**Debug Printing
*/

void			print_distribution(t_anthill *anthill);
void			ft_print_bits(void *data, unsigned int size);
void			ft_print_matrice(unsigned char **matrice, char *name,
	unsigned int size);
void			ft_print_matrice_line(unsigned char *matrice_line,
	unsigned int size);
char			*roomname_from_roomid(t_room *rooms, unsigned int room_id);

/*
**Algos
*/

unsigned int	ft_bfs(t_anthill *anthill);
void			apply_layer(unsigned char *next_layer, unsigned int index,
	t_anthill *anthill);
unsigned int	dfs(unsigned int entry, t_anthill *anthill,
	unsigned int collection);
unsigned int	update_map(t_anthill *anthill);

/*
**Flows
*/

unsigned int	up_flow_room_index(unsigned char **map,
	unsigned int room_index, unsigned int size);
unsigned char	upflower(t_anthill *anthill, unsigned int matrix_index,
	unsigned int last, unsigned char mark);

/*
**DFS
*/

unsigned int	generate_flow_sets(t_anthill *anthill);

/*
**Matching
*/

unsigned int	ft_get_match(t_anthill *anthill, unsigned int matrix_index,
	unsigned int layer_level);
unsigned int	find_first_match(unsigned char *line, unsigned int size);
unsigned int	match_upd(unsigned char *next, unsigned int last,
	t_anthill *anthill);
unsigned int	update_match(t_anthill *ant, unsigned int mid,
	unsigned int layer_level);

/*
** Saturated Matrice
*/

unsigned char	ft_is_adj_up(unsigned char **matrice, unsigned int l1,
	unsigned int l2);
void			ft_bzero_uctab(unsigned char **mat, unsigned int mat_size,
	unsigned int lsize);

/*
** Skim
*/

void			skim_layer(t_anthill *anthill, unsigned int last,
	unsigned int curr_line);
char			skim(t_anthill *anthill);
void			ft_skim_to_itself(unsigned char **matrice,
	unsigned int size);
void			ft_skim_dead_ends(unsigned char **matrice, unsigned int size,
	t_anthill *anthill);

/*
** Len & links
*/

unsigned int	max_len_path(unsigned char **layer, unsigned int real_s);
unsigned int	current_len_path(unsigned char *c_layer, unsigned int real_s);

/*
**Paths
*/

void			ft_get_shortpths(t_anthill *anthill);
unsigned int	ft_path_finding(t_anthill *anthill);
void			rem_adj(t_anthill *anthill);
void			ft_sort_pths(t_anthill *anthill, unsigned char **pths,
	unsigned int set_size);

/*
**Formule
*/

unsigned int	get_goodset(t_anthill *anthill);
t_formset		*init_form(t_anthill *anthill, unsigned char **mat,
	t_formset *form, unsigned int pth_id);
void			malloc_form(t_anthill *anthill);
unsigned int	init_distribute(t_anthill *anthill);
unsigned int	get_best(t_anthill *anthill,
	unsigned int id, unsigned char **mat, unsigned int start_set);

/*
**Send Ants - Print
*/

void			send_ants(t_anthill *anthill);
void			send_next(t_anthill *ant, t_explore *current, t_explore *expl);
unsigned int	next_row(t_anthill *ant, t_explore *explore, unsigned int rid);
t_explore		*init_f(t_anthill *anthill, unsigned char **set);

/*
**ROOMS
*/

unsigned char	ft_is_room_empty(unsigned char *room, unsigned int size);
unsigned char	is_room_linked_to_end(unsigned char *lign, unsigned int size);
unsigned char	is_room_linked_to_start(unsigned char *lign);
unsigned char	is_room_used(unsigned char *room, unsigned int size);
unsigned char	mark_room_used(unsigned char *room, unsigned int map_size);
unsigned char	mark_room_unused(unsigned char *room, unsigned int size);
void			fill_bool_map(unsigned char **map, char *l1, char *l2,
	t_room *room);
unsigned int	ft_countlink(unsigned char *ligne, unsigned int size);
unsigned int	c_column(unsigned char **matrice, unsigned int r,
	unsigned int size);

/*
**FREE
*/

void			free_expl(t_explore *tofree);
void			free_distri(t_anthill *anthill);
void			free_anthill(t_anthill *anthill);
void			free_rooms(t_room *rooms);
unsigned char	free_buf(t_lines *buf);
void			free_matrice(unsigned char **matrice, unsigned int size);

/*
**Print file
*/

void			print_buf(t_lines *buf);

#endif
