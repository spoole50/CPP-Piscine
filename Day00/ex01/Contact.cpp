/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 13:07:51 by spoole            #+#    #+#             */
/*   Updated: 2020/01/13 13:07:53 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phoneBook.hpp"

//phoneBook Method to add a contact
void    phoneBook::add()
{
    if (numContacts < 9)
    {
        //Gets user input for each contactInfo information point and stores in next avaliable Contact object
        for (int i = 0; i < 11; i++)
        {
            std::cout << "Please Enter Contacts " << contactInfo[i] << "." << std::endl;
            std::getline(std::cin >> std::ws, book[numContacts].contact[i][0]);
        }
        numContacts++;
    }
    else
        std::cout << "Apologies the phonebook is full" << std::endl;
}

//phoneBook method to search for a contact
void    phoneBook::search()
{
    std::string choice;
    int idx;
    if (numContacts > 0)
    {
        int valid = 0;
        while (!valid)
        {
            //Print Search Info Headers   
            std::cout << std::setw(10) << "Index" << " | ";
            std::cout << std::setw(10) << "First Name" << " | ";
            std::cout << std::setw(10) << "Last Name" << " | ";
            std::cout << std::setw(10) << "Nickname" << " | " << std::endl;

            //Print First, Last, and Nick name for each contact currently stored in phoneBook
            for (int i = 0; i < numContacts; i++)
            {
                std::cout << std::setw(10) << i << " | ";
                for (int x = 0; x < 3; x++)
                    std::cout << std::setw(10) << concat(book[i].contact[x][0]) << " | ";
                std::cout << std::endl;
            }

            //Get user index
            std::cout << std::endl << "Please enter the index of the contact for full information or BACK for main menu" << std::endl;
            std::cin >> std::ws >> choice;
            //Convert the user input to an integer and check for validity
            try
            {
                std::cout << std::endl;
                if ((sanitize_input(choice)).compare("BACK") == 0)
                    throw "exit";
                idx = std::stoi(choice);
                valid = 1;
                if (idx >= numContacts)
                    throw idx;
            }
            catch (std::invalid_argument)
            {
                valid = 0;
                std::cout << std::endl << "Please enter a valid index" << std::endl;
            }
            catch (int idx)
            {
                valid = 0;
                std::cout << std::endl << "Please select index in range" << std::endl;
            }
            catch (...)
            {
                break;
            }
            //Print full contact info of valid index
            if (valid)
            {
                for (int i = 0; i < 11; i++)
                    std::cout << contactInfo[i] << ": " << book[idx].contact[i][0] << std::endl;
            }
        }
    }
    else
        std::cout << std::endl << "Please ADD a contact first :)" << std::endl;
}

//Returns the PRIVATE variable storing the current number of contacts in the phoneBook
int     phoneBook::getNum()
{
    return (numContacts);
}