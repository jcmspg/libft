/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamiran <joamiran@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 14:16:23 by joamiran          #+#    #+#             */
/*   Updated: 2024/12/11 17:39:28 by joamiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*printf_ft.h*/
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

// macros

# define HEXA "0123456789abcdef"
# define HEXA_UPPER "0123456789ABCDEF"
# define DECIMAL "0123456789"
# define OCTAL "01234567"
# define BINARY "01"
# define FLAGS "-0# +"
# define TYPES "csdiupxX%"

/* struct to store all the flag values */

typedef struct s_flags
{
	int			minus_sign;
	int			zero_padding;
	int			width;
	int			precision;
	int			hashtag;
	int			space_inb4;
	int			plus_sign;
	char		type;
	int			upper_case_flag;
	int			base;
	int			unsigned_flag;
	int			percent_flag;
}				t_flags;

// struct to store all the data needed to print

typedef struct s_data
{
	const char	*str;
	va_list		ap;
	int			chars_printed;
	t_flags		format;
}				t_data;

typedef struct s_padding_data
{
	int			n;
	int			abs_n;
	int			padding;
	int			pre_p;
}				t_padding_data;

// function prototypes

int				ft_printf(const char *format, ...);
void			ft_print_type(t_data *data);

// parse data
void			ft_parse_wrapper(t_data *data);
void			ft_parse_flags(t_data *data);
void			ft_parse_width(t_data *data);
void			ft_parse_precision(t_data *data);
void			ft_parse_type(t_data *data);
void			ft_parse_base(t_data *data);

void			init_data(t_data *data, const char *format);
void			init_flags(t_data *data);

void			ft_print_char(t_data *data, int c);
void			ft_print_str(t_data *data, char *str);
void			ft_print_id(t_data *data, int n);
void			ft_print_ptr(t_data *data, void *p);
void			ft_print_u(t_data *data, unsigned int n);
void			ft_print_xx(t_data *data, unsigned int arg, int uppercase);
void			ft_print_percent(t_data *data);

void			ft_print_padding(t_data *data, int padding);

int				ft_write(int c);
int				ft_write_str(char *str, int len);
int				ft_write_nbr(int n);
int				ft_write_nbr_padding(t_data *data, int n, int padding);
int				ft_write_nbr_zpadding(t_data *data, int n, int padding);
void			ft_print_plus_sign(t_data *data, int n);

size_t			ft_strlen(const char *s);
int				ft_isdigit(int c);
int				ft_atoi(const char *str);
int				ft_nbrlen(int n);
int				ft_max(int a, int b);

char			*set_hex_str(t_data *data, unsigned int arg);
int				set_prpad(t_data *data, char *hex_str);

char			*ft_strchr(const char *s, int c);
char			*ft_strdup(const char *s1);

void			print_sign(t_data *data, int n);
void			print_padding(t_data *data, int padding, char c);
int				calculate_padding(t_data *data, int n);
char			*ft_itoa_base(unsigned long n, int base);

int				ft_toupper(int c);
void			ft_strtoupper(char *str);

// printf_fd
int				ft_printf_fd(int fd, const char *format, ...);
void			ft_print_type_fd(t_data *data, int fd);
void			ft_print_char_fd(t_data *data, int c, int fd);
void			ft_print_str_fd(t_data *data, char *str, int fd);
void			ft_print_id_fd(t_data *data, int n, int fd);
void			ft_print_ptr_fd(t_data *data, void *p, int fd);
void			ft_print_u_fd(t_data *data, unsigned int n, int fd);
void			ft_print_xx_fd(t_data *data, unsigned int arg, int upcase,
					int fd);
void			ft_print_percent_fd(t_data *data, int fd);
int				ft_write_fd(int c, int fd);
int				ft_write_str_fd(char *str, int len, int fd);
void			ft_print_padding_fd(t_data *data, int padding, char c, int fd);
int				ft_write_nbr_fd(int n, int fd);

#endif /* PRINTF_FT_H */
