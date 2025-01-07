/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 19:09:43 by crocha-s          #+#    #+#             */
/*   Updated: 2024/10/10 16:41:14 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void){}

Contact::~Contact(void){}

Contact::Contact(std::string firstName, std::string lastName, std::string nickname,std::string phoneNumber,std::string darkSecret){
    
    this->_name = firstName;
    this->_lastName = lastName;
    this->_nickname = nickname;
    this->_phoneNumber = phoneNumber;
    this->_darkSecret = darkSecret;
}

void Contact::displayContact(void){
    std::cout << "*********CONTACT DETAILS*********" << std::endl;
    std::cout << "Name: " << this->_name << std::endl;
    std::cout << "Last Name: " << this->_lastName << std::endl;
    std::cout << "Nickname: " << this->_nickname << std::endl;
    std::cout << "Phone number: " << this->_phoneNumber << std::endl;
    std::cout << "Darkest Secret: " << this->_darkSecret << std::endl;
}

std::string Contact::getFirstName(){
    return (this->_name);
}

std::string Contact::getLastName(){
    return(this->_lastName);
}

std::string Contact::getNickname(){
    return (this->_nickname);
}

std::string Contact::formatWidth(std::string field){
    if(field.length() > 10)
        return (field.substr(0, 9) + '.');
    return (field);
}
