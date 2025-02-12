/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptintf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pahernan <pahernan@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 08:36:32 by pahernan          #+#    #+#             */
/*   Updated: 2025/02/12 11:09:11 by pahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>
#include <stdarg.h>

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	i;

	i = 0;

  while (s1[i] && s2[i] && s1[i] == s2[i])
    {
        i++;
    }
    return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int ft_to_string (const char *str)
{
if (ft_strcmp(str, "%c") == 0)
		return 1;
    else if (ft_strcmp(str, "%s") == 0)
		return 2;
	else if (ft_strcmp(str, "%p") == 0)
		return 3;
	else if (ft_strcmp(str, "%d") == 0)
		return 4;
	else if (ft_strcmp(str, "%i") == 0)
		return 5;
	else if (ft_strcmp(str, "%u") == 0)
		return 6;
	else if (ft_strcmp(str, "%x") == 0)
		return 7;
	else if (ft_strcmp(str, "%X") == 0)
		return 8;
		else if (ft_strcmp(str, "%%") == 0)
		return 9;
	else
		return 0;
}

void	ft_putchar (char c)
{
	write(1, &c, 1);
}

void	ft_putstr (char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}
void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		nb = nb % 10;
	}
	ft_putchar (nb + '0');
}

void ft_printf (char *b, ...)
{
	int	i;
	int	type;
	
	i = 0;
	
	while (b[i])
	{
		if (b[i] == '%')
		{
			type = ft_to_string(b);
			i++;
		}
		else 
		{
			ft_putchar(b[i]);
			i++;
		}
	}
	
	
	va_list args;
	va_start(args, b);
switch (type)
{

case 1:
ft_putchar(va_arg(args, int));
	break;
case 2:
ft_putstr(va_arg(args, char *));
	break;
case 5:
ft_putnbr(va_arg(args, int));
default:
	break;
	case 9:
	ft_putchar(va_arg(args, int));
	break;
}

va_end(args);
}

#include <stdio.h>

int main (void)
{	
	ft_printf("%s", "ch");
	ft_printf("%c", ' ');
	ft_printf("%c", 'c');
	ft_printf("%c", ' ');
	ft_printf("%i", 44);
	ft_printf("%c", ' ');
	ft_printf("hola %s %c", "ch", 'c');
	printf("\n");
	printf("%s", "ch");
	printf("%c", ' ');
	printf("%c", 'c');
	printf("%c", ' ');
	printf("%i", 44);
	printf("%c", ' ');
	printf("\n");
	printf("hola %s %c", "ch", 'c');
}