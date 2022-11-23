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

struct Data{
	int			stack[10];
	std::string	name;
};

uintptr_t	serialize(Data* ptr);
Data*		deserialize(uintptr_t raw);
void		printData(Data* ptr);

void check_leaks(){
	system("leaks serialize");
}

int main(void)
{
	atexit(check_leaks);
	uintptr_t	ptr;
	Data*		newData;
	Data*		raw = new Data;

	for (int i = 0; i < 10; ++i)
		raw->stack[i] = 11 + i;
	raw->name = "Julien";

	printData(raw);

	ptr = serialize(raw);
	std::cout << "raw:		" << std::hex << raw << std::dec << '\n';
	std::cout << "ptr:		" << std::hex << ptr << std::dec << '\n';

	newData = deserialize(ptr);
	std::cout << "newData:	"<< std::hex << newData << std::dec << '\n';
	printData(newData);

	delete raw;

	return (0);
}

void printData(Data* ptr)
{
	std::cout << ptr->name << " | ";
	for (int i = 0; i < 10; ++i)
		std::cout << ptr->stack[i] << ' ';
	std::cout << "|\n";
}

uintptr_t	serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*		deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}