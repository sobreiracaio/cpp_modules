/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 20:29:41 by crocha-s          #+#    #+#             */
/*   Updated: 2024/10/10 19:12:53 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>
# include <cstdio>
# include <cstdlib>

#define CLEAR "\033c"

class Contact{
    
    private:
    std::string _name;
    std::string _lastName;
    std::string _nickname;
    std::string _phoneNumber;
    std::string _darkSecret;
        
    public:
    Contact();
    ~Contact();
    Contact(std::string firstName, std::string lastName, std::string nickname, std::string phoneNumber, std::string darkSecret);
    void displayContact(void);
    std::string getFirstName(void);
    std::string getLastName (void);
    std::string getNickname (void);
    static std::string formatWidth(std::string field);
};


#endif