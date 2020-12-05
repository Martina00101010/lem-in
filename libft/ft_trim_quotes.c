/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trim_quotes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koparker <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 19:30:22 by koparker          #+#    #+#             */
/*   Updated: 2020/03/13 21:00:04 by koparker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_trim_quotes(char const *s, char quote)
{
	size_t	n;

	if (!s)
		return (NULL);
	n = ft_strlen(s);
	ft_putendl_fd(s, 1);
	if (s[0] == quote && s[n - 1] == quote)
		return (ft_strndup(s + 1, n - 2));
	return (NULL);
}
