/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_cstring_split.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 15:11:03 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/15 18:55:22 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	get_number_of_words(char *s, char c)
{
	int	i;
	int	number_of_words;

	i = 0;
	number_of_words = 0;
	while (1)
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		number_of_words++;
		while (s[i] && s[i] != c)
			i++;
		if (s[i] == '\0')
			break ;
	}
	return (number_of_words);
}

static void	get_words_logic(t_mini mini, char *s, char c, char ***words)
{
	size_t	i;
	size_t	start;
	size_t	end;
	size_t	index_of_current_word;

	i = 0;
	index_of_current_word = 0;
	while (1)
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		end = i - 1;
		(*words)[index_of_current_word] = mini_cstring_get_subcstring(mini, s, start, end);
		index_of_current_word = index_of_current_word + 1;
		if (s[i] == '\0')
			break ;
	}
	(*words)[index_of_current_word] = 0;
}

static char	**get_words(t_mini mini, char *s, char c, int number_of_words)
{
	char	**words;

	words = mini_alloc(mini, (number_of_words + 1) * sizeof(char *));
	if (words == 0)
		return (0);
	get_words_logic(mini, s, c, &words);
	return (words);
}

t_cstring	*mini_cstring_split(t_mini mini, t_cstring s, t_i8 c)
{
	char	**words;
	int		number_of_words;

	number_of_words = get_number_of_words(s, c);
	words = get_words(mini, s, c, number_of_words);
	return (words);
}
