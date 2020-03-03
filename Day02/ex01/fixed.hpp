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

	class Fixed
	{
		private:
			int					_val;
			static const int	_frac;
		public:
			Fixed(void);
			Fixed(const Fixed &fix);
			Fixed(const int num);
			Fixed(const float num);

			~Fixed(void);

			Fixed &operator = (const Fixed &fix);
			
			float	toFloat(void) const;
			int		toInt(void) const;
			int		getRawBits(void) const;
			void	setRawBits(int const raw);
	};

	std::ostream &operator << (std::ostream &o, const Fixed &fix);
#endif
