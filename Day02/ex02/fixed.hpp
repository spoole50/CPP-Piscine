/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 16:01:50 by spoole            #+#    #+#             */
/*   Updated: 2020/01/15 16:01:54 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H
# include <iostream>

	class							Fixed
	{
		private:
			int						_val;
			static const int		_frac;
		public:
			//Constructors
									Fixed(void);
									Fixed(const Fixed &fix);
									Fixed(const int num);
									Fixed(const float num);

			//Destructor
									~Fixed(void);

			//Assignation Overload
			Fixed &					operator = (const Fixed &fix);
			
			//Comparison
			bool					operator == (const Fixed &fix) const;
			bool					operator != (const Fixed &fix) const;
			bool					operator < (const Fixed &fix) const;
			bool					operator <= (const Fixed &fix) const;
			bool					operator > (const Fixed &fix) const;
			bool					operator >= (const Fixed &fix) const;

			//Arithmetic
			Fixed					operator + (const Fixed &fix) const;
			Fixed					operator - (const Fixed &fix) const;
			Fixed					operator / (const Fixed &fix) const;
			Fixed					operator * (const Fixed &fix) const;

			//Inc/Dec
			Fixed &					operator ++ (void);
			Fixed					operator ++ (int);
			Fixed & 				operator -- (void);
			Fixed					operator -- (int);

			//Non-Member Functions
			static Fixed &			min(Fixed &one, Fixed &two);
			static const Fixed &	min(const Fixed &one, const Fixed &two);
			static Fixed &			max(Fixed &one, Fixed &two);
			static const Fixed &	max(const Fixed &one, const Fixed &two);

			//Member Functions
			float					toFloat(void) const;
			int						toInt(void) const;
			int						getRawBits(void) const;
			void					setRawBits(int const raw);
	};

	std::ostream &					operator << (std::ostream &o, const Fixed &fix);
#endif
