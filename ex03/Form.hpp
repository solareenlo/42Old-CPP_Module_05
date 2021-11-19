/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 15:54:08 by tayamamo          #+#    #+#             */
/*   Updated: 2021/11/19 13:12:24 by tayamamo         ###   ########.fr       */
/*   Copyright 2021                                                           */
/* ************************************************************************** */

#ifndef EX03_FORM_HPP_
#define EX03_FORM_HPP_

#include <string>

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
 public:
    Form();
    Form(std::string const& name, int grade_sign, int grade_exec);
    Form(std::string const& name, int grade_sign, int grade_exec,
         std::string const& target);
    virtual ~Form();
    Form(Form const& src);

    Form& operator=(Form const& rhs);

    std::string const getName() const;
    bool getSigned() const;
    int getExecGrade() const;
    int getSignGrade() const;
    std::string const getTarget() const;

    void beSigned(Bureaucrat const& src);

    void execute(Bureaucrat const& executor) const;

    class GradeTooHighException : public std::exception {
     public:
        char const* what() const throw();
    };

    class GradeTooLowException : public std::exception {
     public:
        char const* what() const throw();
    };

    class NotSignedException : public std::exception {
     public:
        char const* what() const throw();
    };

 private:
    static const int HIGHEST_GRADE_ = 1;
    static const int LOWEST_GRADE_ = 150;

    std::string const name_;
    bool signed_;
    int const exec_grade_;
    int const sign_grade_;
    std::string const target_;

    void setSigned(bool sign);

    void checkGrade(int grade) const;

    virtual void action() const = 0;
};

std::ostream& operator<<(std::ostream& ostream, Form const& rhs);

#endif  // EX03_FORM_HPP_
