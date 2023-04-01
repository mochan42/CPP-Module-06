/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 13:13:49 by mochan            #+#    #+#             */
/*   Updated: 2023/04/01 13:23:54 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP
#include <iostream>

class	Data
{
	public:
		// CONSTRUCTORS - DESTRUCTOR
		Data(); // Default constructor
		Data(const Data& src); // Default copy constructor
		~Data(); // Destructor

		// OVERLOAD OPERATOR
		Data&	operator=(const Data& src);
		// GETTERS - SETTERS


		// MEMBER FUNCTIONS


	private:
		
};

#endif