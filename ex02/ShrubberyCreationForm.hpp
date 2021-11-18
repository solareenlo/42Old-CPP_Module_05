/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 22:38:26 by tayamamo          #+#    #+#             */
/*   Updated: 2021/11/19 01:06:24 by tayamamo         ###   ########.fr       */
/*   Copyright 2021                                                           */
/* ************************************************************************** */

#ifndef EX02_SHRUBBERYCREATIONFORM_HPP_
#define EX02_SHRUBBERYCREATIONFORM_HPP_

#include <fstream>
#include <string>

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public AForm {
 public:
    explicit ShrubberyCreationForm(std::string const& target);
    virtual ~ShrubberyCreationForm();
    ShrubberyCreationForm(ShrubberyCreationForm const& src);

    ShrubberyCreationForm& operator=(ShrubberyCreationForm const& rhs);

 private:
    ShrubberyCreationForm();

    static const char* FORM_NAME_;
    static const int SIGN_GRADE_ = 145;
    static const int EXEC_GRADE_ = 137;
    static const char* ASCII_TREE_;

    void action() const;
};
#endif  // EX02_SHRUBBERYCREATIONFORM_HPP_
