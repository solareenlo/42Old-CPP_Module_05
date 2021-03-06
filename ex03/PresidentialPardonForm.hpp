/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 02:52:25 by tayamamo          #+#    #+#             */
/*   Updated: 2021/11/19 06:53:30 by tayamamo         ###   ########.fr       */
/*   Copyright 2021                                                           */
/* ************************************************************************** */

#ifndef EX03_PRESIDENTIALPARDONFORM_HPP_
#define EX03_PRESIDENTIALPARDONFORM_HPP_

#include <fstream>
#include <string>

#include "Bureaucrat.hpp"
#include "Form.hpp"

class Bureaucrat;

class PresidentialPardonForm : public Form {
 public:
    explicit PresidentialPardonForm(std::string const& target);
    virtual ~PresidentialPardonForm();
    PresidentialPardonForm(PresidentialPardonForm const& src);

    PresidentialPardonForm& operator=(PresidentialPardonForm const& rhs);

 private:
    PresidentialPardonForm();

    static const char* FORM_NAME_;
    static const int SIGN_GRADE_ = 25;
    static const int EXEC_GRADE_ = 5;

    void action() const;
};

#endif  // EX03_PRESIDENTIALPARDONFORM_HPP_
