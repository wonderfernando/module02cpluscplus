#include "Fixed.hpp"


Fixed::Fixed() : fixed_point(0){
    std::cout << "Default constructor called" << std::endl; 
}

Fixed::Fixed(const Fixed &master){
    std::cout << "Copy constructor called" << std::endl; 
    fixed_point = master.fixed_point;
}

int Fixed::getRawBits() const {
    std::cout << "getRawBits member function called" << std::endl;    
    return  fixed_point;
}

void Fixed::setRawBits(int raw)
{
    fixed_point = raw;
}

Fixed &Fixed::operator=(const Fixed &other){
    std::cout << "Copy assignment operator called" << std::endl;  
    if (this == &other)
        return *this;
    fixed_point = other.fixed_point;
    return *this;
}

Fixed::~Fixed(){
    std::cout << "Destructor called" << std::endl;  
}

 