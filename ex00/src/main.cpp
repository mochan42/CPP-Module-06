/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 19:32:21 by mochan            #+#    #+#             */
/*   Updated: 2023/03/30 21:25:00 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.h"

int main()
{
	ScalarConverter	Convert1("3");

	std::cout << "Input is: " << Convert1.getInput() << "\n";

	return 0;
}