/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 < jaferna2@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 18:35:14 by jaferna2          #+#    #+#             */
/*   Updated: 2025/05/02 12:37:54 by jaferna2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "include/Contact.hpp"
#include "include/PhoneBook.hpp"

int	main (void)
{
	PhoneBook phoneBook;
	std::string command;

	while (true)
	{
		std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
		std::cin >> command;
		if (command == "ADD")
		{
			std::string firstName, lastName, nickname, phoneNumber, darkestSecret;
			std::cout << "Enter First Name: ";
			std::cin >> firstName;
			std::cout << "Enter Last Name: ";
			std::cin >> lastName;
			std::cout << "Enter Nickname: ";
			std::cin >> nickname;
			std::cout << "Enter Phone Number: ";
			std::cin >> phoneNumber;
			std::cout << "Enter Darkest Secret: ";
			std::cin >> darkestSecret;
			Contact newContact(firstName, lastName, nickname, phoneNumber, darkestSecret);
			phoneBook.addContacts(newContact);	
		}
		else if (command == "SEARCH")
		{
			phoneBook.searchContacts();
			int indx;
			std::cout << "Enter contact index: ";
			std::cin >> indx;
			phoneBook.printContactDetails(indx);
		}
		else if (command == "EXIT")
			break ;
		else
			std::cout << "INVALID COMMAND: " << command << "!" << std::endl;
	}
	return (0);
}
