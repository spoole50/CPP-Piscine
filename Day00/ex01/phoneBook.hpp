/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 13:12:26 by spoole            #+#    #+#             */
/*   Updated: 2020/01/13 13:13:10 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include <iomanip>

    const std::string contactInfo[11] = {"First Name", "Last Name", "Nickname", "Login", "Address", "Email", "Phone", "Birthdate", "Favorite Meal", "Favorite Underwear Color", "Darkest Secret"};
    class Contact
    { 
        public:
            std::string contact[11][1];
            void    setContactInfo(void);
    };

    class phoneBook
    {
        private:
            Contact book[9];
            int numContacts;
        public:
            phoneBook (void) {numContacts = 0;}
            void add();
            void search();
            int getNum();
    };

    std::string		sanitize_input(std::string input);
    std::string		concat(std::string str);

#endif
