/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/24 11:35:44 by dthuilli          #+#    #+#             */
/*   Updated: 2016/07/24 15:13:40 by jmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct		s_list
{
	struct s_list	*next;
	char			data;
}					t_list;

t_list				*ft_create_elem(char data);
void				ft_list_push_back(t_list **begin_list, char data);
char				*get_string(void);
int					check_lines_size(char *str, int l_size);
int					is_valid(char *str, int *l, int *h);
int					check_characters(char *str, int i);
void				colle_2(char *str);
void				check_colle(char *str, int *l, int *h);
void				print_colle(int	colle[5], int *l, int *h, int count);
int					is_colle00(char *str, int *l, int *h);
int					is_colle01(char *str, int *l, int *h);
int					is_colle02(char *str, int *l, int *h);
int					is_colle03(char *str, int *l, int *h);
int					is_colle04(char *str, int *l, int *h);

#endif
