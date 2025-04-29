/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 <jaferna2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 18:35:09 by jaferna2          #+#    #+#             */
/*   Updated: 2025/04/29 19:44:51 by jaferna2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Contact.hpp"

Contact::Contact() {}

Contact::Contact(std::string fN, std::string lN, std::string n, std::string pN, std::string dS)
	: firstName(fN), lastName(lN), nickname(n), phoneNumber(pN), darkestSecret(dS) {}

std::string Contact::getFirstName() const{
	return (firstName);
}

std::string Contact::getLastName() const{
	return (lastName);
}

std::string Contact::getNickname() const{
	return (nickname);
}

std::string Contact::getPhoneNumber() const{
	return (phoneNumber);
}

std::string Contact::getDarkestSecret() const{
	return (darkestSecret);
}
