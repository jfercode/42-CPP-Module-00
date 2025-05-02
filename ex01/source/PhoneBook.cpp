/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 < jaferna2@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 18:35:16 by jaferna2          #+#    #+#             */
/*   Updated: 2025/05/02 12:39:03 by jaferna2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PhoneBook.hpp"

#include <iostream>
#include <iomanip>
#include <string>

PhoneBook::PhoneBook() : contactNum(0) {}

std::string		PhoneBook::truncateStr(std::string str, int x) const
{
	int	size;

	size = str.length();
	if (size <= x)
		return (str);
	else
		return (str.substr(0, x) + ".");
}


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
	for (int i = 0; i < contactNum; i++)
	{
		std::cout << std::setw(10) << i << "|"
				  << std::setw(10) << truncateStr(contacts[i].getFirstName(), 8) << "|"
				  << std::setw(10) << truncateStr(contacts[i].getLastName(), 8) << "|"
				  << std::setw(10) << truncateStr(contacts[i].getNickname(), 8) << "|" 
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

int		PhoneBook::getContactNum() const
{
	return contactNum;	
}
