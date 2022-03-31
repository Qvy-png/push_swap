/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-agu <rdel-agu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 13:24:24 by rdel-agu          #+#    #+#             */
/*   Updated: 2022/03/29 16:53:22 by rdel-agu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

typedef struct s_list
{
	int				num;
	struct s_list	*next;
}					t_list;

struct s_pushSwap
{
	t_list	*a_stack;
	t_list	*b_stack;
	int		argc;
	char	**argv;
	char	**parsed;
};

int		is_only_num(char *str);
int		ft_lstsize(t_list *lst);
int		ft_atoi(const char *str);
int 	verif(int argc, char **argv);

t_list	*ft_lstnew(int content);
t_list	*ft_lstlast(t_list *lst);

char	**ft_split(char const *s, char c);

void	ft_lstadd_back(t_list **alst, t_list *new);
void	ft_lstadd_front(t_list **alst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void    parsing(struct s_pushSwap *ps, int argc, char **argv);
#endif
