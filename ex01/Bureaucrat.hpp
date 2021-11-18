/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 13:38:53 by tayamamo          #+#    #+#             */
/*   Updated: 2021/11/18 22:15:59 by tayamamo         ###   ########.fr       */
/*   Copyright 2021                                                           */
/* ************************************************************************** */

#ifndef EX01_BUREAUCRAT_HPP_
#define EX01_BUREAUCRAT_HPP_

#include <exception>
#include <iostream>
#include <string>

#include "Form.hpp"

class Form;

class Bureaucrat {
 public:
    Bureaucrat();
    Bureaucrat(std::string const& name, int grade);
    virtual ~Bureaucrat();
    Bureaucrat(Bureaucrat const& src);

    Bureaucrat& operator=(Bureaucrat const& rhs);

    std::string const& getName() const;
    int getGrade() const;

    void incrementGrade();
    void decrementGrade();

    void signForm(Form& form);

    class GradeTooHighException : public std::exception {
     public:
        char const* what() const throw();
    };

    class GradeTooLowException : public std::exception {
     public:
        char const* what() const throw();
    };

 private:
    static const int HIGHEST_GRADE_ = 1;
    static const int LOWEST_GRADE_ = 150;

    std::string const name_;
    int grade_;

    void setGrade(int grade);
    void checkGrade(int grade);
};

std::ostream& operator<<(std::ostream& ostream, Bureaucrat const& rhs);

#endif  // EX01_BUREAUCRAT_HPP_
