/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draudrau <draudrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 16:58:56 by draudrau          #+#    #+#             */
/*   Updated: 2019/06/20 16:05:49 by draudrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "../libft.h"

typedef struct		s_pf
{
	char			spec;
	int				znak;
	int				dot;
	int				resh;
	int				j;
	int				z;
	int				h;
	int				l;
	int				hh;
	int				ll;
	int				minus;
	int				plus;
	int				space;
	int				nul;
	int				bl;
	int				ml;
	int				procent;
	int				wid;
	int				prec;
}					t_pf;

void				ft_putchar_pf(char c, int *count);
void				ft_putstr_pf(char const *str, int *count);
void				ft_type_space(int spaces, int *count);
void				ft_type_nul(int nul, int *count);
void				ft_type_sp_nul(int nul, int *count);

void				ft_print_sit_1(t_pf *pf, char *num, int *count);
void				ft_print_sit_2(t_pf *pf, char *num, int *count);
void				ft_print_sit_4(t_pf *pf, char *num, int *count);
void				ft_print_sit_6(t_pf *pf, char *num, int *count);

int					ft_printf_nothing_minus(t_pf *pf, int *count);
int					ft_printf_nothing_without_minus(t_pf *pf, int *count);
int					ft_check_nothing(char *num, t_pf *pf, int *count);

int					ft_print_nothing_12(t_pf *pf, int sit, int *count);
int					ft_print_nothing_34(t_pf *pf, int sit, int *count);
int					ft_print_nothing_56(t_pf *pf, int sit, int *count);
int					ft_print_nothing_78(t_pf *pf, int sit, int *count);

void				ft_modul_char(char *num);
void				ft_cmp_wid_prec_num(t_pf *pf, char *num);
long long			ft_apply_modificator(va_list ap, t_pf *pf);

unsigned long long	ft_ucount_of_digits(unsigned long long n);
long long			ft_count_of_digits(long long n);
char				*ft_long_to_ascii(long long n);
char				*ft_ulong_to_ascii(unsigned long long n);

int					ft_fill_ost(int *ost, unsigned long long num,
								unsigned long long base);
char				*ft_convert_v_8(unsigned long long num);
char				*ft_convert_v_16(unsigned long long num, t_pf *pf);

void				ft_complex_constructor(t_pf *pf, char *new_num, int *count);
void				ft_create_num(char *new_num, t_pf *pf, int *count);
void				ft_decimal(va_list ap, int *count, t_pf *pf);

void				ft_char(va_list ap, int *count, t_pf *pf);
void				ft_char_2(char p, int *count, t_pf *pf);
void				ft_print_string(t_pf *pf, char *str, int *count);
void				ft_string(va_list ap, int *count, t_pf *pf);

void				ft_print_pointer(t_pf *pf, char *new_pnt,
									int pnt, int *count);
void				ft_pointer(va_list ap, int *count, t_pf *pf);
void				ft_percent(int *count, t_pf *pf);
t_pf				*ft_create_struct_printf(void);
void				ft_initialization(t_pf *temp);

int					ft_check_specificator(char *ptr);
void				ft_search_modificator_h(char *ptr, t_pf *pf);
void				ft_check_modificator(t_pf *pf, char *ptr);
int					ft_search_before_spec(char *p, char c);

void				ft_fill_width(t_pf *pf, char **p);
void				ft_fill_precision(t_pf *pf, char **p);
void				ft_fill_flags(t_pf *pf, char *p);
void				ft_fill_struct(t_pf *pf, char *p);
void				ft_analyze(t_pf *pf);

long double			ft_fraction(va_list ap, t_pf *pf);
char				*ft_create_fr(t_pf *pf, long double fraction,
									int *i, int *rounding);
long long			ft_rounding(t_pf *pf, char *fr, int i, long long whole);
char				*ft_new_float(t_pf *pf, char *fr, long long whole,
									long double fn);
void				ft_float(va_list ap, int *count, t_pf *pf);

char				*ft_strjoin_float(char *str1, char *str2, t_pf *pf);
void				ft_inf_minus(t_pf *pf, char *new_num, int znak, int *count);
void				ft_inf_without_minus(t_pf *pf, char *new_num, int znak,
										int *count);
int					ft_analyze_inf(long double num, int *znak);
int					ft_check_inf(t_pf *pf, long double num, int *count);

int					ft_valid_simbols(char c);
int					ft_csp(va_list ap, t_pf *pf, char *p, int *count);
int					ft_dioux_prc_f(va_list ap, t_pf *pf, char *p, int *count);
void				ft_if_procent(va_list ap, char **p, int *count);
int					ft_printf(const char *fmt, ...);

#endif
