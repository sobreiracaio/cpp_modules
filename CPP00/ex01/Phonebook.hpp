/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 20:44:58 by crocha-s          #+#    #+#             */
/*   Updated: 2024/10/08 20:16:14 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H
#include "Contact.hpp"

class Phonebook{
    
    private:
        int _id;
        Contact _contacts[8];
        void _printTable();
        bool _isPrintable(std::string const str);
        bool _isDigit(std::string const str);
        
    public:
        Phonebook();
        ~Phonebook();
        void add(void);
        void search (void);
};
#endif
