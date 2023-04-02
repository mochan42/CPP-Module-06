/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 19:32:21 by mochan            #+#    #+#             */
/*   Updated: 2023/04/02 15:56:43 by mochan           ###   ########.fr       */
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
	if (argv[1] == NULL)
	{
		std::cout << RED << "Input string is empty." << D << "\n";
		return (0);
	}
	else
	{
		std::string	input;
		ScalarConverter* Convert1 = ScalarConverter::createInstance();

		input = argv[1];
		Convert1->setInput(input);
		Convert1->convert(input);
		delete Convert1;
	}
	return (0);
}