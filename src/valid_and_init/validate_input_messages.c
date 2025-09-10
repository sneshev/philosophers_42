/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input_messages.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stefuntu <stefuntu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 20:17:43 by stefuntu          #+#    #+#             */
/*   Updated: 2025/09/10 20:18:56 by stefuntu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

size_t	ft_strlen(char *str);

void	explain_message(void)
{
	write(1, "to run philosophers:\n", 21);
	write(1, "./philosophers argv[1] argv[2] argv[3] ", 39);
	write(1, "argv[4] (optional: argv[5])\n", 28);
	write(1, "where: \n", 8);
	write(1, "argv[1] -> number of philosophers\n", 34);
	write(1, "argv[2] -> time to die (miliseconds)\n", 37);
	write(1, "argv[3] -> time to eat (miliseconds)\n", 37);
	write(1, "argv[4] -> time to sleep (miliseconds)\n", 39);
	write(1, "argv[5] (optional) -> number of meals\n", 38);
}

void	positive_int_message(char *arg_name)
{
	write(1, "WARNING: Argument \"", 19);
	write(1, arg_name, ft_strlen(arg_name));
	write(1, "\" should be a positive int\n", 27);
}
