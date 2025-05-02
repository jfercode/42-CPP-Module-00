/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 < jaferna2@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 18:35:18 by jaferna2          #+#    #+#             */
/*   Updated: 2025/05/02 12:11:32 by jaferna2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <cstring>

class PhoneBook
{
	private:
		int			contactNum;
		Contact 	contacts[8];
		std::string	truncateStr(std::string str, int x) const;

	public:
		PhoneBook();

		void	addContacts(const Contact& contact);
		void	searchContacts() const;
		void	printContactDetails(int indx) const;
		
		int		getContactNum() const;
};

#endif
