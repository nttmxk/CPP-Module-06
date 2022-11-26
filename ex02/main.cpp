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
#include <random>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base*	generate(void);
void	identify(Base* p);
void	identify(Base& p);

void check_leaks(){
	system("leaks type");
}

int main(void)
{
	atexit(check_leaks);
	Base* random[10];

	for (int i = 0; i < 10; ++i)
	{
		random[i] = generate();
		identify(random[i]);
		identify(*random[i]);
		delete random[i];
	}
	return (0);
}

Base*	generate(void)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dis(0,2);
	Base* ret;
	int random;

	random = dis(gen);
	if (random == 1)
		ret = new A;
	else if (random == 2)
		ret = new B;
	else
		ret = new C;
	return (ret);
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Base pointer p is identified as A\n";
	else if (dynamic_cast<B*>(p))
		std::cout << "Base pointer p is identified as B\n";
	else if (dynamic_cast<C*>(p))
		std::cout << "Base pointer p is identified as C\n";
	else
		std::cout << "Base pointer p cannot be identified\n";
}

void	identify(Base& p)
{
	try {
		static_cast<void>(dynamic_cast<A&>(p));
		std::cout << "Reference A\n";
	} catch (std::exception &e) {}

	try {
		static_cast<void>(dynamic_cast<B&>(p));
		std::cout << "Reference B\n";
	} catch (std::exception &e) {}

	try {
		static_cast<void>(dynamic_cast<C&>(p));
		std::cout << "Reference C\n";
	} catch (std::exception &e) {}

}
