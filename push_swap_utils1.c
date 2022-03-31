/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-agu <rdel-agu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 13:28:21 by rdel-agu          #+#    #+#             */
/*   Updated: 2022/03/29 17:09:00 by rdel-agu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_only_num(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] < '0' || str[i] > '9') && str[i] != '+' && str[i] != '-')
			return (0);
		i++;
	}
	return (1);
}

int verif(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc > 2)
	{
		while (i < argc)
		{
			if (is_only_num(argv[i]) == 0)
				return (0);
			i++;
		}
		return (1);
	}
	return (0);
}
