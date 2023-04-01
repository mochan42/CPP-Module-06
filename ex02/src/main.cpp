/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 16:28:58 by mochan            #+#    #+#             */
/*   Updated: 2023/04/01 17:25:52 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.h"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>


int	IntRandomGenerator(void)
{
	// Generate a random integer between 0 and 2 (inclusive)
	int random_integer = std::rand() % 3;
	return (random_integer);
}

Base*	generate(void)
{
	Base* randomBase = NULL;
	int i = IntRandomGenerator();
	switch (i)
	{
		case 0:
			randomBase = new A;
			std::cout << GREEN << "A " << D << "is created -";
			break;
		case 1:
			randomBase = new B;
			std::cout << YELL << "B " << D << "is created -";
			break;
		case 2:
			randomBase = new C;
			std::cout << PU << "C " << D << "is created -";
			break;
		default:
			std::cout << "Error: fatal.\n";
			break;
	}
	return (randomBase);
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << GREEN << " A " << D << "is identified w/ pointer -";
	else if (dynamic_cast<B*>(p))
		std::cout << YELL <<" B " << D << "is identified w/ pointer -";
	else if (dynamic_cast<C*>(p))
		std::cout << PU <<" C " << D << "is identified w/ pointer -";
	else
		std::cout << RED <<" Unkown base " << D << " -";
}

void	identify(Base& p)
{
	try
	{
		A& a = dynamic_cast<A&>(p);
		(void) a;
		std::cout << GREEN << " A " << D << "is identified w/ reference\n";
	}
	catch (std::bad_cast& e)
	{
	}
	try
	{
		B& b = dynamic_cast<B&>(p);
		(void) b;
		std::cout << YELL <<" B " << D << "is identified w/ reference\n";
	}
	catch (std::bad_cast& e)
	{
	}
	try
	{
		C& c = dynamic_cast<C&>(p);
		(void) c;
		std::cout << PU <<" C " << D << "is identified w/ reference\n";
	}
	catch (std::bad_cast& e)
	{
	}
}

int main()
{
	Base* ptr;
	// Seed the random number generator with the current time
	std::srand(std::time(NULL));

	for (int i = 0; i < 10; i++)
	{
		std::cout << CY << "[" << i << "]\t"<< D; 
		ptr = generate();
		Base& ref = *ptr;
		identify(ptr);
		identify(ref);
		delete ptr;
	}
	return (0);
}