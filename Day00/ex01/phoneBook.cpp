/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 13:08:05 by spoole            #+#    #+#             */
/*   Updated: 2020/01/13 13:08:06 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phoneBook.hpp"

//Helper function to shorten any text longer than 10 for search header formatting
std::string     concat(std::string str)
{
    if (str.length() >= 10)
    {
        str.resize(10);
        str[9] = '.';
    }
    return (str);
}

//Helper function to capitalize all input text
std::string   sanitize_input(std::string input)
{
    for (int i = 0; i < (int) input.length(); i++)
    {
        if (input[i] >= 'a' && input[i] <= 'z')
            input[i] -= 32;
    }
    return (input);
}

int main(void)
{
    phoneBook book;
    int end = 0;
    std::string input;

    std::string validCmds = "Valid Commands = ADD, SEARCH, EXIT";
    std::cout << "\n\nWelcome to your friendly neighborhood phonebook." << std::endl;
    while(!end)
    {
        std::cout << std::endl << "Phone book currently has " << book.getNum() << " out of 9 contacts filled." << std::endl;
        std::cout << validCmds << std::endl;
        std::cin >> input;
        input = sanitize_input(input);
        if (input.compare("ADD") == 0)
            book.add();
        else if (input.compare("SEARCH") == 0)
            book.search();
        else if (input.compare("EXIT") == 0)
        {
            std::cout << "Thanks for choosing phonebook today for all your contact needs. Goodbye" << std::endl;
            end = 1;
        }
        else
            std::cout << std::endl << "Invalid Command, Please try again" << std::endl;
    }
    return (0);
}