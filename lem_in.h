/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schornon <schornon@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 20:08:06 by schornon          #+#    #+#             */
/*   Updated: 2019/05/19 14:27:56 by schornon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "gnl/get_next_line.h"
# include "ft_printf/ft_printf.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>

typedef struct			s_s
{
	int					ants;
	int					**map;
	int					i;
	int					r;
	int					pai;
	char				*line;
	char				*buff;
	int					f_ant;
	int					f_word;
	int					r_start;
	int					r_end;
	int					rm_cnt;
	int					tun1;
	int					tun2;
	int					act_rm;
	int					**doors;
	char				**paths;
	int					links_cnt;
	int					max_lvl;
	struct s_qu			*q;
	struct s_qu			**s_path;
	int					p_cnt;
	struct s_g			**gph;
	int					ant_name;
	int					last_ant_dist;
	int					flag_n;
	int					minoneway;
	int					steps_count;
}						t_s;

typedef struct			s_qu
{
	struct s_g			*node;
	struct s_qu			*next;
	int					path_len;
	struct s_qu			*prev;
}						t_qu;

typedef struct			s_rm
{
	char				**rms;
	int					r_val;
	int					links;
	int					lvl;
	int					visited;
	struct s_rm			*next;
}						t_rm;

typedef struct			s_g
{
	char				*name;
	int					r_val;
	int					links;
	int					lvl;
	int					visited;
	int					block;
	int					links_in;
	int					links_out;
	struct s_g			**next;
}						t_g;

typedef struct			s_l
{
	char				*input;
	struct s_l			*next;
}						t_l;

t_s						*create_struct(void);
char					*bl_remalloc(char *buff);
void					pars_ants(t_s *s, char *line);
void					pars_rooms(t_s *s, char *line, t_rm *rm);
void					pars_words(t_s *s, char *line);
void					pars_tunnels(t_s *s, char *line, t_rm *rm);
void					create_map(t_s *s);
void					add_room(t_s *s, t_rm *rm);
void					path_finder(t_s *s, t_rm *rm);
int						visited_rooms(t_rm *rm);
int						check_connect(t_rm *curr, t_rm *tmp);
t_rm					*pars_tunnels_ext(t_rm *curr, t_s *s);
t_rm					*create_first_room(void);
t_rm					*add_r_list(t_rm *rm);
void					connect_rooms(t_rm *curr, t_rm *curr_2);
char					*ft_strjoin_f(char *s1, char const *s2);
char					*ft_jchar_f_i(char *s, char chr, int j);
char					*ft_jchar_f(char *s, char chr);
char					*ft_jchar_f_w(char *s, char chr);
char					*ft_strdup_f(char *src);
char					**tab_char_remalloc(char **tab, int row);
void					create_graph(t_s *s, t_rm *rm);
void					bfs(t_s *s);
int						count_visited(t_s *s);
void					p_visited_to_0(t_s *s);
void					ants_controller(t_s *s);
int						path_validator(t_qu *tmp_p);
void					validate_ants(t_s *s, char *line);
void					validate_start_end(t_s *s);
void					validate_room_names(t_s *s);
void					validate_links(t_s *s);
void					validate_min_one_way(t_s *s);
void					highwaytohell(t_s *s);
void					init_new_path(t_s *s, int r_val);
void					add_node_to_path(t_s *s, t_qu *tmp_p);
void					find_paths_len(t_s *s);
void					sort_paths(t_s *s);
void					show_me_paths(t_s *s);
void					bonus(t_s *s, int ac, char **av);
t_l						*input_validator(t_s *s);
int						sharp_validate(char *line);
void					check_tunnel(t_s *s, char *line);
void					rooms_validator_ext(char *line);
void					my_exit(void);
void					validate_same_names(t_s *s, t_rm *rm);
int						check_one_link(t_s *s);
void					usage(int ac, char **av);

#endif
