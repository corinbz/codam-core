/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corin <corin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 14:35:28 by corin             #+#    #+#             */
/*   Updated: 2023/11/19 14:35:49 by corin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

• Repeated calls (e.g., using a loop) to your get_next_line() function should
let you read the text file pointed to by the file descriptor, one line at a
time.
• Your function should return the line that was read. If there is nothing
else to read or if an error occurred, it should return NULL.
• Make sure that
your function works as expected both when reading a file and when reading from
the standard input.
• Please note that the returned line should include the
terminating \n character, except if the end of file was reached and does not end
with a \n character.

*/

#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>

char	*get_before_nl(char *s)
{
	char	*res;
	size_t	i;

	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	if (s[i] != '\0' && s[i] == '\n')
		i++;
	res = ft_calloc(i + 1, sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
	{
		res[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
	{
		res[i] = s[i];
		i++;
	}
	return (res);
}

char	*get_after_nl(char *s)
{
	char	*res;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[j] && s)
		j++;
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	if (s[i] != '\0' && s[i] == '\n')
		i++;
	res = ft_calloc((j - i) + 1, sizeof(char));
	if (!res)
		return (NULL);
	j = 0;
	while (s[i + j])
	{
		res[j] = s[i + j];
		j++;
	}
	return (res);
}

// reads the text file untill it finds newline or EOF
void	read_line(int fd, char **text, char **tmp)
{
	int		bytes_read;
	char	*buf;

	bytes_read = 1;
	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return ;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			ft_free_all(&buf, text, tmp);
			return ;
		}
		buf[bytes_read] = '\0';
		*tmp = ft_strdup(*text);
		ft_free_all(text, 0, 0);
		*text = join_strs(*tmp, buf);
		ft_free_all(tmp, 0, 0);
		if (contains_newline(*text))
			break ;
	}
	ft_free_all(&buf, 0, 0);
}

// parses the text and returns the string before newline
// text now contains the extra chars after newline
char	*parse_line(char **text, char **tmp)
{
	char	*chars_before_nl;

	*tmp = ft_strdup(*text);
	ft_free_all(text, 0, 0);
	*text = get_after_nl(*tmp);
	chars_before_nl = get_before_nl(*tmp);
	ft_free_all(tmp, 0, 0);
	return (chars_before_nl);
}

char	*get_next_line(int fd)
{
	static char	*text = NULL;
	char		*tmp;
	char		*line;

	tmp = NULL;
	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	read_line(fd, &text, &tmp);
	if (text != NULL && *text != '\0')
		line = parse_line(&text, &tmp);
	if (!line || *line == '\0')
	{
		ft_free_all(&text, &line, &tmp);
		return (NULL);
	}
	return (line);
}

// int main(int argc, char *argv[]) {
//   int fd = open("text.txt", O_RDONLY);
//   char *line;
//   while ((line = get_next_line(fd)) != NULL) {
//     printf("%s", line);
//     free(line);
//   }
//   close(fd);
//   return (0);
// }
