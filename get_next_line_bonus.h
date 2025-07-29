/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 19:43:10 by dmontana          #+#    #+#             */
/*   Updated: 2025/02/21 19:43:12 by dmontana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# ifndef FT_FD_MAX
#  define FT_FD_MAX 1024
# endif

# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		check_newline(char *str);
char	*extract_line(char *str);
char	*fix_buffer(char *str);
char	*ft_strdup(char *s);
size_t	ft_strlen(char *str);
size_t	ft_strncpy(char *dest, char *src, size_t n);
char	*create_buffer(int fd, char *buffer);
char	*get_next_line(int fd);
void	*ft_calloc(size_t nmemb, size_t size);
void	*null_free(void **ptr, void **ptr2, int flag1, int flag2);

#endif
