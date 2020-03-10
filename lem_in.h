/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 09:56:19 by jerbs             #+#    #+#             */
/*   Updated: 2020/02/25 20:30:13 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# define BUFF_SIZE 32
# define FD_SIZE 4092

typedef struct		s_room
{
	char			*name;
	struct s_room	*links;
	struct s_room	*next;
	struct s_room	*g_paths;
	int				visited;
	int				level;
	int				ant_num;
	int				prev_num;
	int				shortest;
	int				total_ants;
	char			*start;
	struct s_room	*indep_lst;
}					t_room;

/*
** count_func.c
*/
int					ct_nb_links(t_room *rooms);
int					strlen_til_c(char *s, char c);
int					strlena_til_c(char *s, char c);
int					strln_til_ba(char *path);
int					count_ba(char *path);

/*
**count_func_2.c
*/
int					lst_count(t_room *rooms);
int					size_path(char *path);
int					rooms_count(char *path);

/*
**coups_count.c
*/
double				coup_per_path(double moyenne_rooms, double total_ants);
double				coup_for_multi(t_room *rooms, double total_ants);
double				coup_for_shortest(t_room *rooms, double total_ants);

/*
**error_manage.c
*/
int					levels_errors(t_room *rooms, char **st_end, int *flag);
int					error_management(char **line, int **flag);
int					error_management_2(t_room *rooms, char **st_end,
					int **flag);

/*
**final_list.c
*/
t_room				*final_list(t_room *rooms, int total_ants);

/*
**free_shit.c
*/
void				free_elem(t_room *rooms);
void				free_lst(t_room *rooms);
void				free_room(t_room *to_del);
void				free_things(char **st_end, int *flag);
void				lst_free(t_room *list);

/*
**free_shit_2.c
*/
void				free_everything(t_room *rooms, char *line,
					char **st_end, int *flag);
void				free_everything_2(t_room *rooms, char **st_end, int *flag);

/*
**get_next_line.c
*/
int					get_next_line(const int fd, char **line);

/*
**go_to_lst.c
*/
t_room				*go_to_lst(t_room *rooms, char *name);

/*
**helper.c
*/
char				*str_after_c(char *str, char c);
int					was_visited(t_room *rooms, char *name);
t_room				*new_ant_elem(char *room_name);
int					are_st_end_connected(t_room *rooms, char *end);
t_room				*cure(t_room *final_lst);

/*
**indepance.c
*/
t_room				*create_new_name(char *s);
int					are_independant(char *path2, char *path1);
t_room				*create_indep_lst(t_room *paths_lst);

/*
**is_digit_only.c
*/
int					is_digit_only(char *s);

/*
**is_in.c
*/
int					is_char_or_ht(char *s, char c);
int					is_end_present(char *s, char *end);
int					is_c(char *s, char c);
int					is_in(t_room *rooms, char *s);
int					is_c_in(char *s, char c);

/*
**level_checking.c
*/
int					level_of_end(t_room *rooms, char *end);
int					level_of_name(t_room *rooms, char *s);
t_room				*go_to_level(t_room *rooms, int level);
t_room				*go_to_inf_level(t_room *rooms, char *s);

/*
**libft_func.c
*/
int					ft_strlen(char *str);
void				ft_putstr(char const *s);
void				ft_putnbr(int n);

/*
**libft_func_2.c
*/
char				*ft_strsub(char *s, int start, int len);
int					ft_atoi(char *str);
char				*ft_itoa(int n);

/*
**libft_func_3.c
*/
char				*ft_strchr(char *s, int c);
int					ft_strcmp(char *s1, char *s2);
char				*ft_strdup(char *s1);
void				ft_strdel(char **as);

/*
**libft_func_4.c
*/
char				*ft_strjoin(char *s1, char *s2);
char				*ft_strjoin_free(char *s1, char *s2);
char				*ft_strjoin_free_both(char *s1, char *s2);
int					ft_strstr(const char *haystack, const char *needle);
int					ft_strstra(char *path, char *str);

/*
**libft_func_5.c
*/
void				*ft_memset(void *b, int c, int len);
void				ft_bzero(void *s, int n);
char				*ft_strnew(int size);

/*
**mark_rooms.c
*/
void				mark_visited(t_room **rooms, char *name);
void				mark_start(t_room *rooms, char *start);
int					mark_levels(t_room *rooms, char *go_to, int level);

/*
**moving_ants.c
*/
void				one_path_mvt(t_room *path, int total_ants);
void				two_paths_mvt_2(t_room *path1, t_room *path2,
					int total_ants, int *count);
void				two_paths_mvt(t_room *path1, t_room *path2, int total_ants);
void				moving_ants(t_room *final_list, int total_ants);

/*
**moving_ants_2.c
*/
void				color_ants(int ant_num);
void				print_ants(t_room *path);
void				goto_antnum_n_print(t_room *path1, t_room *path2,
					int ant_num, int total_ants);

/*
**moving_ants_3.c
*/
int					path_contains_ant(t_room *path);
void				shift_ants_next_room(t_room *path, int count);
int					lowest_ant_num(t_room *path);
int					just_sup_ant_num(t_room *path, int current);

/*
**path_finder.c
*/
int					other_paths_inf_level(t_room *rooms, t_room *name);
t_room				*recursive_other_path_finder(t_room **rooms,
					char *go_to, char *path, int level);
void				flag_shortest(t_room *paths);
t_room				*return_shortest(t_room *paths);

/*
**path_to_lst.c
*/
t_room				*path_to_lst(char *path);

/*
**print_final_paths.c
*/
void				print_final_paths(t_room *final);

/*
**print_final_paths_2.c
*/
int					middle_string(char *s);
void				print_spaces(int count);
void				print_tube(int count);

/*
**print_helper.c
*/
void				print_room_name(t_room *rooms);
void				print_name_vis_lvl(t_room **rooms);
void				print_all(t_room *rooms);
void				print_links(t_room *rooms);
void				print_name_nblinks(t_room **rooms);

/*
**push_back_front.c
*/
void				lst_pushback(t_room **list, char *line);
void				links_pushback_part2(t_room **rooms, char *s);
void				links_pushback(t_room **rooms, char *s);
void				gpaths_pushback(t_room **rooms, char *path);
void				lst_pushcpyfront(t_room **paths, t_room *tmp);

/*
**push_back_front_2.c
*/
void				lst_pushback_room(t_room **list, char *str);
t_room				*lst_pushb_room(t_room *old, t_room *path);
void				add_links(t_room **rooms, char *line);

/*
**reverse_paths.c
*/
char				*ft_strcat_til_ba(char *dest, char *src);
char				*reverse_str(char *str);
void				reverse_paths(t_room *rooms);

/*
**str_til.c
*/
char				*dup_til_char(char *s, char c);
char				*str_til_c(char *s, char c);
char				*stra_til_c(char *s, char c);
char				*str_till_ba(char *patht);
char				*cut_st_end(char *path);

#endif
