/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneshev <sneshev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 20:15:01 by stefuntu          #+#    #+#             */
/*   Updated: 2025/09/12 21:15:41 by sneshev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	positive_int_message(char *arg_name);
void	explain_message(void);

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_isdigit(int c)
{
	if (c < '0')
		return (0);
	if (c > '9')
		return (0);
	return (2048);
}

bool	is_number(char *str)
{
	while (*str == '+')
		str++;
	if (!*str)
		return (false);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (false);
		str++;
	}
	return (true);
}

bool	is_positive_int(char *str)
{
	const char	*int_max = "2147483647";
	int			i;

	if (!is_number(str))
		return (false);
	while (*str == '+')
		str++;
	while (*str == '0')
		str++;
	if (!*str)
		return (false);
	if (ft_strlen(str) < 10)
		return (true);
	else if (ft_strlen(str) > 10)
		return (false);
	i = 0;
	if (*str > '2')
		return (false);
	while (str[i] == int_max[i])
	{
		i++;
		if (str[i] > int_max[i])
			return (false);
	}
	return (true);
}

bool	is_valid_input(int argc, char *argv[])
{
	if (argc < 5 || argc > 6)
		return (explain_message(), false);
	if (!is_positive_int(argv[1]))
		return (positive_int_message("number of philosophers"), false);
	if (!is_positive_int(argv[2]))
		return (positive_int_message("time to die"), false);
	if (!is_positive_int(argv[3]))
		return (positive_int_message("time to eat"), false);
	if (!is_positive_int(argv[4]))
		return (positive_int_message("time to sleep"), false);
	if (argc == 6 && !is_positive_int(argv[5]))
		return (positive_int_message("number of meals"), false);
	return (true);
}
