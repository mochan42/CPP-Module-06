/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 19:32:21 by mochan            #+#    #+#             */
/*   Updated: 2023/03/30 22:31:29 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.h"

int main(int ac, char **argv)
{
	if (ac != 2)
	{
		std::cout << RED << "Wrong number of arguments. Number of argument is 1" << D << "\n";
		return (1);
	}
	else
	{
		try
		{
			if (argv[1] == NULL)
				throw ScalarConverter::InputIsEmpty();
			else
			{
				ScalarConverter	Convert1(argv[1]);
				std::cout << "Input is: " << Convert1.getInput() << "\n";
			}
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		

	}
	return (0);
}