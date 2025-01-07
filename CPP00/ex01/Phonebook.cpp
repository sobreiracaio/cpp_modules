/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 20:07:31 by crocha-s          #+#    #+#             */
/*   Updated: 2024/10/10 21:29:21 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

Phonebook::Phonebook(void)
{
    this->_id = 0;
}

Phonebook::~Phonebook(void){}

bool Phonebook::_isPrintable(std::string const str)
{
    for(int i = 0; str.length(); i++)
    {
        unsigned char c = static_cast<unsigned int>(str[i]);
        if(!isprint(c))
        {
            std::cout << "Word has non printable characters,Press Enter." << std::endl;
            std::cin.ignore();
            return (false);
        }
        else
            return (true);
    }
    return (true);
}

bool Phonebook::_isDigit(std::string const str)
{
    for(int i = 0; str.length(); i++)
    {
      if(!isdigit(str[i]))
      {
        std::cout << "Not a number, press Enter." << std::endl;
        std::cin.ignore();
        return (false);
      }
      else
        return(true);
    }
    return(true);
}

void Phonebook::add(void)
{
    std::string firstName, lastName, nickname, phoneNumber, darkSecret;
    int         current_id;
    
    std::cout << CLEAR;
    std::cout<<"    :::     :::::::::  :::::::::    ::::::::   ::::::::  ::::    ::: :::::::::::     :::      ::::::::  ::::::::::: " << std::endl; 
    std::cout<<"  :+: :+:   :+:    :+: :+:    :+:  :+:    :+: :+:    :+: :+:+:   :+:     :+:       :+: :+:   :+:    :+:     :+:     " << std::endl; 
    std::cout<<" +:+   +:+  +:+    +:+ +:+    +:+  +:+        +:+    +:+ :+:+:+  +:+     +:+      +:+   +:+  +:+            +:+     " << std::endl; 
    std::cout<<"+#++:++#++: +#+    +:+ +#+    +:+  +#+        +#+    +:+ +#+ +:+ +#+     +#+     +#++:++#++: +#+            +#+     " << std::endl; 
    std::cout<<"+#+     +#+ +#+    +#+ +#+    +#+  +#+        +#+    +#+ +#+  +#+#+#     +#+     +#+     +#+ +#+            +#+     " << std::endl; 
    std::cout<<"#+#     #+# #+#    #+# #+#    #+#  #+#    #+# #+#    #+# #+#   #+#+#     #+#     #+#     #+# #+#    #+#     #+#     " << std::endl; 
    std::cout<<"###     ### #########  #########    ########   ########  ###    ####     ###     ###     ###  ########      ###     " << std::endl << std::endl; 

    std::cout <<"Insert first name: " << std::endl;
    std::getline(std::cin, firstName);
    if(!_isPrintable(firstName))
        return;
    std::cout <<"Insert last name: " << std::endl;
    std::getline(std::cin, lastName);
    if(!_isPrintable(lastName))
        return;
    std::cout <<"Insert nickname: " << std::endl;
    std::getline(std::cin, nickname);
    if(!_isPrintable(nickname))
        return;
    std::cout <<"Insert phone number: " << std::endl;
    std::getline(std::cin, phoneNumber);
    if(!_isDigit(phoneNumber))
        return;
    std::cout <<"Insert darkest secret: " << std::endl;
    std::getline(std::cin, darkSecret);
    if(!_isPrintable(darkSecret))
        return;
    
    
    if(firstName.length() < 1
        || lastName.length() < 1
        || nickname.length() < 1
        || phoneNumber.length() < 1
        || darkSecret.length() < 1)
    {
        std::cout << "All fields must be filled. Contact not saved." << std::endl;
        std::cout << "Press ENTER to continue..." << std::endl;
        std::cin.ignore();
        return;
    }

    this->_contacts[this->_id++ % 8] = Contact(firstName, lastName, nickname, phoneNumber, darkSecret);
    std::cout << std::endl;
    if(this->_id % 8 == 0)
        current_id = 8;
    else
        current_id = this->_id % 8;
    if (this->_id > 8)
    {
        std::cout << "Contact saved at position: "<< current_id <<". Memory is full, oldest contact will be overwritten." << std::endl;
    }
    else
        std::cout << "Contact saved at position: " << current_id << std::endl;
    std::cout << "Press ENTER to continue..." << std::endl;
    std::cin.ignore();
}

void Phonebook::_printTable()
{
    std::string field;
    
    int i = 0;
    
    std::cout << "|     Index|      Name| Last Name|  Nickname|" << std::endl;
    std::cout << "|----------|----------|----------|----------|" << std::endl;
    while(i < 8)
    {
        if(this->_contacts->getFirstName().length() > 0 )
        {
            std::cout << "|" << std::setw(10) << i + 1 << "|";
            field = this->_contacts[i].getFirstName();
            std::cout << std::setw(10) << Contact::formatWidth(field) << "|";
            field = this->_contacts[i].getLastName();
            std::cout << std::setw(10) << Contact::formatWidth(field) << "|";
            field = this->_contacts[i].getNickname();
            std::cout << std::setw(10) << Contact::formatWidth(field) << "|" << std::endl;
            i++;
        }
    }
    std::cout << std::endl;
}

void Phonebook::search(void)
{
    std::string input;
    int index;
    int maxIndex;
    std::cout << CLEAR;
    std::cout<<" ::::::::  ::::::::::     :::     :::::::::   ::::::::  :::    :::" << std::endl; 
    std::cout<<":+:    :+: :+:          :+: :+:   :+:    :+: :+:    :+: :+:    :+:" << std::endl; 
    std::cout<<"+:+        +:+         +:+   +:+  +:+    +:+ +:+        +:+    +:+" << std::endl; 
    std::cout<<"+#++:++#++ +#++:++#   +#++:++#++: +#++:++#:  +#+        +#++:++#++" << std::endl; 
    std::cout<<"       +#+ +#+        +#+     +#+ +#+    +#+ +#+        +#+    +#+" << std::endl; 
    std::cout<<"#+#    #+# #+#        #+#     #+# #+#    #+# #+#    #+# #+#    #+#" << std::endl; 
    std::cout<<" ########  ########## ###     ### ###    ###  ########  ###    ###" << std::endl << std::endl;

    if(this->_id > 7)
        maxIndex = 8;
    else
        maxIndex = this->_id;
    if (this->_id == 0)
    {
        std::cout << "No contacts add yet." << std::endl;
        std::cout << "Press ENTER to continue..." << std::endl;
        std::cin.ignore();
        return;
    }
    this->_printTable();
    
   
    while(1)
    {
        std::cout << "Enter the index of the contact to search for it or type BACK to go to the previous menu:" << std::endl;
        std::getline(std::cin, input);
        if(std::cin.eof())
            return;
        index = std::atoi(input.c_str());
        if(input == "BACK")
            break;
        if(index < 1 || index > maxIndex)
        {
            std::cout << "Invalid index, try again." << std::endl;
            continue;
        }
        else
        {
            this->_contacts[index - 1].displayContact();
            std::cout << "Press ENTER to continue." << std::endl;
		    std::cin.ignore();
			break ;
        }
    }


}
