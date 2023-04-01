/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 13:14:19 by mochan            #+#    #+#             */
/*   Updated: 2023/04/01 13:23:48 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.h"

//======== CONSTRUCTORS =========================================================================
Data::Data()
{
	std::cout << BLU << "Default constructor called from Data" << D << "\n";
}

Data::Data(const Data& src)
{
	std::cout << BLU << "Copy constructor called from Data" << D << "\n";
	*this = src;
}

Data&	Data::operator=(const Data& src)
{
	std::cout << BLU << "Copy assignment operator called from Data" << D << "\n";
	(void)src;
	return (*this);
}

//======== DESTRUCTOR ===========================================================================
Data::~Data()
{
	std::cout << CY << "Destructor called from Data" << D << "\n";
}


//==== GETTERS / SETTERS ========================================================================



//======== MEMBER FUNCTIONS =====================================================================
