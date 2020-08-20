/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdrinkin <bdrinkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 18:37:58 by bdrinkin          #+#    #+#             */
/*   Updated: 2019/12/15 17:14:38 by bdrinkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define I_T "00010203"
# define IH_T "00102030"
# define O_T "00100111"
# define L_T "00010212"
# define LR_T "00102001"
# define LD_T "00101112"
# define LL_T "20011121"
# define J_T "10110212"
# define JR_T "00011121"
# define JD_T "00100102"
# define JL_T "00102021"
# define T_T "10011121"
# define TR_T "00011102"
# define TD_T "00102011"
# define TL_T "10011112"
# define S_T "10200111"
# define SR_T "00011112"
# define Z_T "00101121"
# define ZR_T "10011102"

# include "../libft/libft.h"
# include <fcntl.h>

typedef struct		s_tetris
{
	int				cord[8];
	char			letter;
	struct s_tetris	*next;
	int				num;
}					t_tetris;

int					main(int ac, char **av);
int					errors(int error);
int					fck_n(char *av);
int					write_tetra(int fd, t_tetris **tets);
int					read_file(int fd, char (*tetra)[4][5], int *check);
int					first_check(char tetra[4][5]);
int					second_check(char tetra[4][5], int (*cord)[8]);
int					write_cord(char tetra[4][5], int (*cord)[8]);
void				change_cord(int (*cord)[8]);
void				cord_to_char(char *char_cord, int cord[8]);
void				go_to_list(t_tetris **tets, int cord[8]);
void				ft_tetadd(t_tetris **tetlst, int cord[8]);
t_tetris			*ft_tetnew(int cord[8], char lettter, int num);
void				ft_tetdel(t_tetris **tets);
t_tetris			*ft_tetcpy(t_tetris *tets);
int					count_tets(t_tetris *tets);
void				input_map(t_tetris *tets, int c_tets);
int					ft_min_map(t_tetris *tets);
int					ft_sqrt(int nb);
void				whiles_shift(t_tetris **tets_r,
					t_tetris *tets, int *mp, int c);
int					put_tetra(t_tetris **tets_r, int k, int min_map);
int					check_shift(t_tetris *tets_r, int num);
int					while_temp(t_tetris *temp1, t_tetris *temp, int num);
int					right_shift(t_tetris **tets_r, int num, int mm);
int					down_shift(t_tetris **tets_r, int num, int mm);
void				return_shift(t_tetris **tets_r, int num);
void				write_map(t_tetris *tetra, int mm);
void				ft_dots(int mm, char map[106][106]);
void				print_map(int mm, char tetramino[106][106]);
#endif
