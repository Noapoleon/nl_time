/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nl_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 04:53:17 by nlegrand          #+#    #+#             */
/*   Updated: 2022/11/02 07:27:29 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nl_time.h"

static void	set_unit(char *unit, char *s)
{
	while (*s)
		*unit++ = *s++;
	*unit = '\0';
}

long	nl_time(char masks)
{
	long			elapsed;
	static clock_t	start;
	char			unit[13];

	// first call, start counting time
	if (start == 0)
	{
		printf("nl_time -> started counting...\n");
		start = clock();
		return (-1);
	}

	// second call, calculate time span and reset start
	if (masks & NLT_MICRO)
	{
		elapsed = (clock() - start)/(CLOCKS_PER_SEC/1000000);
		set_unit(unit, "microseconds");
	}
	else if (masks & NLT_SEC)
	{
		elapsed = (clock() - start)/CLOCKS_PER_SEC;
		set_unit(unit, "seconds");
	}
	else
	{
		elapsed = (clock() - start)/(CLOCKS_PER_SEC/1000);
		set_unit(unit, "milliseconds");
	}

	start = 0;
	if (masks & NLT_PRINT)
		printf("nl_time -> %ld %s\n", elapsed, unit);
	return (elapsed);
}

