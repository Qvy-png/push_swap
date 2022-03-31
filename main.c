/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-agu <rdel-agu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 13:28:58 by rdel-agu          #+#    #+#             */
/*   Updated: 2022/03/30 19:01:33 by rdel-agu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_array(char **twoD)
{
	int	i;

	i = 0;
	while (twoD && twoD[i] != NULL)
	{
		free(twoD[i]);
		i++;
	}
	if (twoD)
		free(twoD);
}

void    ft_print_list(t_list *liste)
{
	t_list  *tmp;

	tmp = liste;
	if (tmp)
	{
		while (tmp->next != NULL)
		{
			printf("%d\n", tmp->num);
			tmp = tmp->next;
		}
		printf("%d\n", tmp->num);
	}
}

int	is_num_space(char *str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		if (str[i] != ' ' && (str[i] > '9' || str[i] < '0') && str[i] != '-' && str[i] != '+')
			return (0);
		i++;
	}
	return (1);
}

int	no_double_sign(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] == '+' && str[i + 1] == '+') || ((str[i] == '-' && str[i + 1] == '-')))
			return (0);
		i++;
	}
	return (1);
}

int	is_only_signs(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] <= '9'&& str[i] >= '0')
			return (0);
		i++;
	}
	return (1);
}

int	blender(int argc, char **argv, struct s_pushSwap *ps)
{
	int		i;
	int 	j;	
	int 	k;
	char	**split_tmp;
	t_list	*tmp;
	
	i = 1;
	j = 0;
	k = 0;
	while (argv[i])
	{
		if (is_num_space(argv[i]) == 1 && no_double_sign(argv[i]) == 1
			&& is_only_signs(argv[i]) == 0)
		{
			split_tmp = ft_split(argv[i], ' ');
			while (split_tmp[j] != NULL)
			{
				if (k++ == 0)
					ps->a_stack = ft_lstnew(ft_atoi(split_tmp[j]));
				else
				{
					tmp = ft_lstnew(ft_atoi(split_tmp[j]));
					ft_lstadd_back(&ps->a_stack, tmp);
				}
				j++;
			}
			free_array(split_tmp);
		}
		else
			return (-1);
		j = 0;
		i++;
	}
	return (1);
}

int main(int argc, char **argv)
{
	struct	s_pushSwap   *ps;
	int		i;
	
	ps = malloc(sizeof(struct s_pushSwap));
	if (ps == NULL)
		return (0);
	ps->argc = argc;
	ps->argv = argv;
	i = blender(argc, argv, ps);
	if (i == -1)
		printf("un canard\n");
	else
		ft_print_list(ps->a_stack);
	return (0);
}
