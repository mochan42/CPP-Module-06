/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 19:32:21 by mochan            #+#    #+#             */
/*   Updated: 2023/03/30 23:13:49 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.h"

int main(int ac, char **argv)
{
	std::string	input;
	ScalarConverter	Convert1;

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
				input = argv[1];
				Convert1.setInput(input);
				std::cout << "Input is: " << Convert1.getInput() << "\n";
				Convert1.convert();
			}
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	return (0);
}