/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccraciun <ccraciun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 14:35:28 by corin             #+#    #+#             */
/*   Updated: 2023/12/12 15:08:43 by ccraciun         ###   ########.fr       */
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
	while (s[j])
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
int	read_line(int fd, char **text, char **tmp)
{
	int		bytes_read;
	char	*buf;

	bytes_read = 1;
	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (ft_free_all (text, 0, 0), 1);
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == -1)
			return (ft_free_all(&buf, text, tmp), 1);
		buf[bytes_read] = '\0';
		*tmp = ft_strdup(*text);
		if (*tmp == NULL)
			return (ft_free_all (&buf, text, tmp), 1);
		ft_free_all (text, 0, 0);
		*text = join_strs(*tmp, buf);
		if (*text == NULL)
			return (ft_free_all(&buf, tmp, text), 1);
		ft_free_all(tmp, 0, 0);
		if (contains_newline(*text))
			break ;
	}
	return (ft_free_all (&buf, 0, 0), 0);
}

// parses the text and returns the string before newline
// text now contains the extra chars after newline
char	*parse_line(char **text, char **tmp)
{
	char	*chars_before_nl;

	*tmp = ft_strdup(*text);
	if (*tmp == NULL)
		return (ft_free_all(0, text, 0), (char *)1);
	ft_free_all(text, 0, 0);
	*text = get_after_nl(*tmp);
	if (*text == NULL)
		return (ft_free_all(text, tmp, 0), (char *)1);
	chars_before_nl = get_before_nl(*tmp);
	if (chars_before_nl == NULL)
		return (ft_free_all(text, tmp, 0), (char *)1);
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
	if (!(read_line (fd, &text, &tmp)))
	{
		if (text != NULL && *text != '\0')
		{
			line = parse_line (&text, &tmp);
			if (line == (char *)1)
				return (NULL);
		}
		if (!line || *line == '\0')
		{
			ft_free_all(&text, &line, &tmp);
			return (NULL);
		}
	}
	return (line);
}

// int main() {
//   int fd = open("test.txt", O_RDONLY);
//   char *line;
//   line = get_next_line(fd);
// 	printf("%s", line);
// 	free(line);
//   line = get_next_line(fd);
//   	printf("%s", line);
// 	free(line);
//   close(fd);
//   return (0);
// }
