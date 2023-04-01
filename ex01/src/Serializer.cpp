/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 15:00:50 by mochan            #+#    #+#             */
/*   Updated: 2023/04/01 16:19:55 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.h"

//======== CONSTRUCTORS =========================================================================
Serializer::Serializer()
{
	std::cout << BLU << "Default constructor called from Serializer" << D << "\n";
}

Serializer::Serializer(const Serializer& src)
{
	std::cout << BLU << "Copy constructor called from Serializer" << D << "\n";
	*this = src;
}

Serializer&	Serializer::operator=(const Serializer& src)
{
	std::cout << BLU << "Copy assignment operator called from Serializer" << D << "\n";
	(void)src;
	return (*this);
}

//======== DESTRUCTOR ===========================================================================
Serializer::~Serializer()
{
	std::cout << CY << "Destructor called from Serializer" << D << "\n";
}


//======== FUNCTIONS =========================0000000============================================
uintptr_t	Serializer::serialize(Data* ptr)
{
	return(reinterpret_cast<uintptr_t>(ptr));
}

Data*		Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}