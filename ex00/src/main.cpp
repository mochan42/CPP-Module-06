/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 19:32:21 by mochan            #+#    #+#             */
/*   Updated: 2023/04/02 12:23:16 by mochan           ###   ########.fr       */
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
				std::string	input;
				ScalarConverter* Convert1 = ScalarConverter::createInstance();

				input = argv[1];
				Convert1->setInput(input);
				std::cout << Convert1->getInput() << "\n";
				// Convert1.convert(input);
				
				ScalarConverter* Convert2 = ScalarConverter::createParameterizedInstance("34");
				std::cout << Convert2->getInput() << "\n";
				
				ScalarConverter* Convert3 = ScalarConverter::createDefaultCopyInstance(*Convert2);
				std::cout << Convert3->getInput() << "\n";

				delete Convert1;
				delete Convert2;
				delete Convert3;
			}
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	return (0);
}