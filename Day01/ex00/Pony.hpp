/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 10:35:45 by spoole            #+#    #+#             */
/*   Updated: 2020/01/14 10:35:47 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PONY_HPP
#define PONY_HPP

# include <iostream>

    class Pony
    {
        public:
            int runSpeed;
            int tailFlipFreq;
            int cuteness;
            int carryCapacity;
            int racesWons;

            void    printPony();
    };

    void    ponyOnTheHeap(void);
    void    ponyOnTheStack(void);
#endif