/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 13:24:59 by mochan            #+#    #+#             */
/*   Updated: 2023/03/30 23:25:54 by mochan           ###   ########.fr       */
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
	this->_input = setInput;
}

ScalarConverter::ScalarConverter(const ScalarConverter& src)
{
	std::cout << BLU << "Copy constructor called from ScalarConverter" << D << "\n";
	*this = src;
}

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& src)
{
	std::cout << BLU << "Copy assignment operator called from ScalarConverter" << D << "\n";
	this->_input = src._input;
	this->_type = src._type;
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
	return (this->_input);
}

void	ScalarConverter::setInput(std::string setInput)
{
	this->_input = setInput;
}

std::string	ScalarConverter::getType(void) const
{
	return (this->_type);
}

void	ScalarConverter::setType(std::string setType)
{
	this->_type = setType;
}

//======== MEMBER FUNCTIONS =====================================================================

void	ScalarConverter::checkType(void)
{
	if (this->_input.length() == 1)
		this->_type = "CHAR";
}

void	ScalarConverter::convert(void)
{
	checkType();
	std::cout << getType() << "\n";
}

//=============== FUNCTIONS =====================================================================
