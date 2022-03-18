/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <gmelissi@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 14:43:19 by gmelissi          #+#    #+#             */
/*   Updated: 2022/02/22 14:43:21 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//	ft_validation - Проверка входных данных и отправка в другие функции.
int	ft_validation(int argc, char **argv)
{
	int	i;
	int	ret;

	ret = 0;
	i = 1;
	while (i < argc)
	{
		if (ft_only_spaces(argv[i]))
		{
			ft_number_availability(argv[i]);
			ft_valid_str(argv[i]);
			ret = 1;
		}
		i++;
	}
	return (ret);
}

//	ft_number_availability - Проверяет, что в строке только цифры
void	ft_number_availability(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			return ;
		i++;
	}
	ft_error();
}

//	ft_valid_str - Проверяет строку на валидность.
void	ft_valid_str(const char *str)
{
	size_t	i;
	int		nbr;
	int		sign;

	i = 0;
	nbr = 0;
	sign = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			nbr++;
		else if (str[i] == ' ' || str[i] == '\t')
		{
			if (sign != 0 && nbr == 0)
				ft_error();
			nbr = 0;
			sign = 0;
		}
		else if (((str[i] == '+' || str[i] == '-') && \
				(sign == 0 && nbr == 0)) && (str[i + 1] != '\0'))
			sign++;
		else
			ft_error();
		i++;
	}
}

//	ft_duplicate_check - Проверка данных на дубликаты.
void	ft_duplicate_check(t_data *new, t_stacks *stacks)
{
	int	*dup;

	dup = (int *)malloc(sizeof(int) * (new->count_element));
	if (!dup)
		exit(1);
	dup = ft_intcpy(dup, new->a, new->count_element);
	ft_quick_sort(dup, 0, new->count_element - 1);
	ft_search_duplicate(dup, new->count_element - 1);
	stacks->count_a = new->count_element;
	stacks->count_b = 0;
	stacks->min = dup[0];
	stacks->med = dup[new->count_element / 2];
	stacks->max = dup[new->count_element - 1];
	free(dup);
}

//	ft_search_duplicate - Проверка массива чисел на дубликаты.
void	ft_search_duplicate(const int *dup, int count)
{
	int	i;

	i = 0;
	while (i != count)
	{
		if (dup[i] == dup[i + 1])
			ft_error();
		i++;
	}
}
