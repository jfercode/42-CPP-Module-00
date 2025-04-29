/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 <jaferna2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 18:35:16 by jaferna2          #+#    #+#             */
/*   Updated: 2025/04/29 19:39:10 by jaferna2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PhoneBook.hpp"

#include <iostream>
#include <iomanip> 

PhoneBook::PhoneBook() : contactNum(0) {}

void	PhoneBook::addContacts(const Contact& contact)
{
	if (contactNum < 8)
		contacts[contactNum++] = contact;
	else
	{
		for (int i = 1; i < 8; ++i)
			contacts[i - 1] = contacts[i];
		contacts[7] = contact;
	}
}

void	PhoneBook::searchContacts() const
{
	std::cout << std::setw(10) << "Index" << "|"
			  << std::setw(10) << "First Name" << "|"
			  << std::setw(10) << "Last Name" << "|"
			  << std::setw(10) << "Nickname" << "|"
			  << std::endl;
	for (int i = 0; i < contactNum; ++i)
	{
		std::cout << std::setw(10) << contacts[i].getFirstName() << "|"
				  << std::setw(10) << contacts[i].getLastName() << "|"
				  << std::setw(10) << contacts[i].getNickname() << "|"
				  << std::setw(10) << contacts[i].getPhoneNumber() << "|"
				  << std::setw(10) << contacts[i].getDarkestSecret() << "|"
				  << std::endl;
	}
}

void	PhoneBook::printContactDetails(int indx) const
{
	if (indx < 0 || indx >= contactNum)
	{	std::cout << "Invalid index provided!" << std::endl;
		return ;
	}
	const Contact& c = contacts[indx];
	std::cout << "First Name: " << c.getFirstName() << std::endl;
	std::cout << "Last Name: " << c.getLastName() << std::endl;
	std::cout << "Nickname: " << c.getNickname() << std::endl;
	std::cout << "Phone Number: " << c.getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << c.getDarkestSecret() << std::endl;
	
}
