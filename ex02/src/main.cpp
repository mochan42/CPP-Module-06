/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 16:28:58 by mochan            #+#    #+#             */
/*   Updated: 2023/04/01 16:44:53 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.h"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>

Base*	generate(void)
{
	Base* randomBase = NULL;
	// Seed the random number generator with the current time
	std::srand(std::time(NULL));

	// Generate a random integer between 0 and 2 (inclusive)
	int random_integer = std::rand() % 3;

	// Print the random integer to the console
	std::cout << random_integer << std::endl;
	return (randomBase);
}

// void	identify(Base* p)
// {

// }

// void	identify(Base& p)
// {
	
// }

int main()
{

	generate();
	return (0);
}