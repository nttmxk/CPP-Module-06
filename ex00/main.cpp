/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinoh <jinoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 01:40:59 by jinoh             #+#    #+#             */
/*   Updated: 2022/09/24 01:41:00 by jinoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include <iomanip>

void conversion(char *argv);

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "[usage] : ./convert <number>\n";
		return (0);
	}
	conversion(argv[1]);
	return (0);
}

void conversion(char *argv)
{
	double	value;
	char	*ptr;

	ptr = NULL;
	value = std::strtod(argv, &ptr);
	if ((value == 0.0 && argv[0] != '-' && argv[0] != '+' && !std::isdigit(argv[0]))
		|| (*ptr != '\0' && std::strcmp(ptr, "f") != 0))
	{
		std::cout << "ERROR\n";
		return ;
	}

	std::cout << "char: ";
	if (value > CHAR_MAX || value < CHAR_MIN || isnan(value))
		std::cout << "impossible\n";
	else if (!isprint(value))
		std::cout << "Non displayable\n";
	else
		std::cout << '\'' << static_cast<char>(value) << "\'\n";

	std::cout << "int: ";
	if (value > INT_MAX || value < INT_MIN || isnan(value))
		std::cout << "impossible\n";
	else
		std::cout << static_cast<int>(value) << '\n';

	std::cout << "float: ";
	if ((static_cast<float>(value) == static_cast<int64_t>(static_cast<float>(value))) && (-100000 < static_cast<float>(value) && static_cast<float>(value) < 100000))
		std::cout << static_cast<float>(value) << ".0f\n";
	else
		std::cout << std::setprecision(std::numeric_limits<float>::digits10)
		<< static_cast<float>(value) << "f\n";

	std::cout << "double: ";
	if ((static_cast<double>(value) == static_cast<int64_t>(static_cast<double>(value))) && (-100000 < static_cast<double>(value) && static_cast<double>(value) < 100000))
		std::cout << static_cast<double>(value) << ".0\n";
	else
		std::cout << std::setprecision(std::numeric_limits<double>::digits10)
		<< static_cast<double>(value) << '\n';
}