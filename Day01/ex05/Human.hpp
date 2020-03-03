/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 15:40:38 by spoole            #+#    #+#             */
/*   Updated: 2020/01/14 15:40:39 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_CPP
#define HUMAN_CPP

# include "Brain.hpp"

    class Human
    {
        private:
            const Brain brain;
        public:
            std::string identify() const;
            const Brain &getBrain() const;
    };

#endif