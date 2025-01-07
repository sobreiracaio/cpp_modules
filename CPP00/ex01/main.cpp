/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 19:53:16 by crocha-s          #+#    #+#             */
/*   Updated: 2024/10/10 21:34:16 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
void headerMenu()
{
    std::cout << CLEAR;
    std::cout << ":::::::::  :::    :::  ::::::::  ::::    ::: :::::::::: :::::::::   ::::::::   ::::::::  :::    ::: " << std::endl;
    std::cout << ":+:    :+: :+:    :+: :+:    :+: :+:+:   :+: :+:        :+:    :+: :+:    :+: :+:    :+: :+:   :+:  " << std::endl;
    std::cout << "+:+    +:+ +:+    +:+ +:+    +:+ :+:+:+  +:+ +:+        +:+    +:+ +:+    +:+ +:+    +:+ +:+  +:+   " << std::endl;
    std::cout << "+#++:++#+  +#++:++#++ +#+    +:+ +#+ +:+ +#+ +#++:++#   +#++:++#+  +#+    +:+ +#+    +:+ +#++:++    " << std::endl;
    std::cout << "+#+        +#+    +#+ +#+    +#+ +#+  +#+#+# +#+        +#+    +#+ +#+    +#+ +#+    +#+ +#+  +#+   " << std::endl;
    std::cout << "#+#        #+#    #+# #+#    #+# #+#   #+#+# #+#        #+#    #+# #+#    #+# #+#    #+# #+#   #+#  " << std::endl;
    std::cout << "###        ###    ###  ########  ###    #### ########## #########   ########   ########  ###    ### " << std::endl;
    std::cout << "                                                                                        Version 1.0 "<< std::endl << std::endl;
    std::cout << "Type ADD to add a contact, SEARCH to search for a contact or EXIT to quit." << std::endl;
}

int main(void)
{
    Phonebook phonebook;
    std::string user_input;
    int is_valid = 0;

    while(1)
    {
        user_input.clear();
        if(std::cin.eof())
            break;
        if(!is_valid)
        headerMenu();
        std::cout << "Enter a command:" << std::endl;
        std::getline(std::cin,user_input);
        if (user_input == "ADD")
            phonebook.add();
        else if (user_input == "SEARCH")
            phonebook.search();
        else if (user_input == "EXIT")
            break;
        else
        {
                std::cout << "Invalid command. Try again." << std::endl;
                is_valid = 1;
                continue;
        }
        is_valid = 0;
    }
    std::cout << CLEAR;
    
}
