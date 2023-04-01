/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 15:01:08 by mochan            #+#    #+#             */
/*   Updated: 2023/04/01 16:43:42 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP
#include <iostream>

class	Base
{
	public:
		// DESTRUCTOR
		virtual ~Base(); // Virtual Default constructor
		
		// MEMBER FUNCTIONS
		Base*	generate(void);
		void	identify(Base* p);
		void	identify(Base& p);
};

#endif