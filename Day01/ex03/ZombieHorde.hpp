/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 14:28:37 by spoole            #+#    #+#             */
/*   Updated: 2020/01/14 14:28:39 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEHORDE_HPP
#define ZOMBIEHORDE_HPP

# include "Zombie.hpp"

    class ZombieHorde
    {
        private:
            int _n;
            Zombie *horde;
        public:
            ZombieHorde(int n);
            void    announce();
            ~ZombieHorde()
            {
                delete [] horde;
            }
    };

#endif