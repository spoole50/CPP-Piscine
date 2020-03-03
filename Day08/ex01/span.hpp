/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 14:10:04 by spoole            #+#    #+#             */
/*   Updated: 2020/01/24 14:10:06 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SPAN_H
#define SPAN_H
# include <string>
# include <iostream>
# include <exception>
# include <algorithm>

	class Span
	{
		private:
		public:

			class MaxCapacity : public std::exception
			{
				public:
					virtual const char *what() const throw();
			};

			Span(unsigned int);
			Span(Span & spn);
			~Span(void);
			Span & operator = (Span & spn);
	};

#endif