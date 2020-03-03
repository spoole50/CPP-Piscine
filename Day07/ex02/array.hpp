/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 13:37:14 by spoole            #+#    #+#             */
/*   Updated: 2020/01/23 13:37:15 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ARRAY_H
#define ARRAY_H
# include <string>
# include <iostream>

	template <typename F>
	class Array
	{
		private:
			F				*_array;
			unsigned int 	_size;
		public:
			class BadAccess : public std::exception
			{
				public:
					virtual const char *what() const throw();
			};

			Array(void);
			Array(unsigned int n);
			Array(const Array<F> & arr);
			~Array(void);
			Array & operator = (const Array & arr);
			F & operator[] (int idx);
			const F & operator[] (int idx) const;
	};

#endif