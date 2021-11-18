/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 05:08:46 by tayamamo          #+#    #+#             */
/*   Updated: 2021/11/19 06:54:51 by tayamamo         ###   ########.fr       */
/*   Copyright 2021                                                           */
/* ************************************************************************** */

#ifndef EX03_INTERN_HPP_
#define EX03_INTERN_HPP_

#include <string>

#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
 public:
    Intern();
    virtual ~Intern();
    Intern(Intern const& src);

    Intern& operator=(Intern const& rhs);

    Form* makeForm(std::string const& name, std::string const& target);

 private:
    Form* makeShrubberyCreationForm(std::string const& target);
    Form* makeRobotomyRequestForm(std::string const& target);
    Form* makePresidentialPardonForm(std::string const& target);

    typedef Form* (Intern::*f)(std::string const&);
    struct makeFormType_ {
        std::string const name;
        f const func;
    };
    static const makeFormType_ makeFormTypeList_[];
};
#endif  // EX03_INTERN_HPP_
