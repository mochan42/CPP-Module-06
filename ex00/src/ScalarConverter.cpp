/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 13:24:59 by mochan            #+#    #+#             */
/*   Updated: 2023/03/30 21:24:44 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.h"

//======== CONSTRUCTORS =========================================================================

ScalarConverter::ScalarConverter()
{
	std::cout << BLU << "Default constructor called from ScalarConverter" << D << "\n";
}

ScalarConverter::ScalarConverter(std::string const & setInput)
{
	std::cout << BLU << "Parameterized constructor called from ScalarConverter" << D << "\n";
	this->input = setInput;
}

ScalarConverter::ScalarConverter(const ScalarConverter& src)
{
	std::cout << BLU << "Copy constructor called from ScalarConverter" << D << "\n";
	*this = src;
}

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& src)
{
	std::cout << BLU << "Copy assignment operator called from ScalarConverter" << D << "\n";
	this->input = src.input;
	return (*this);
}

//======== DESTRUCTOR ===========================================================================
ScalarConverter::~ScalarConverter()
{
	std::cout << CY << "Destructor called from ScalarConverter" << D << "\n";
}


//==== GETTERS / SETTERS ========================================================================
std::string	ScalarConverter::getInput(void) const
{
	return (this->input);
}

//======== MEMBER FUNCTIONS =====================================================================


//=============== FUNCTIONS =====================================================================
