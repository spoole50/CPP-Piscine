/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 21:29:40 by spoole            #+#    #+#             */
/*   Updated: 2020/01/17 21:29:43 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SUPERTRAP_H
#define SUPERTRAP_H
# include "FragTrap.hpp"
# include "NinjaTrap.hpp"


	class SuperTrap : public virtual NinjaTrap, public virtual FragTrap
	{
		public:
			SuperTrap(std::string name);
			SuperTrap(const SuperTrap &sup);
			~SuperTrap(void);

			SuperTrap & operator = (const SuperTrap &sup);
	};

#endif