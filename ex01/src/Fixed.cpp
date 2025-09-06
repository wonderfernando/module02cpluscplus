#include "Fixed.hpp"


Fixed::Fixed() : fixed_point(0){
    std::cout << "Default constructor called" << std::endl; 
}


Fixed::Fixed(const Fixed &master){
    std::cout << "Copy constructor called" << std::endl; 
    fixed_point = master.fixed_point;
}
Fixed::Fixed(int num)
{
    std::cout << "Int constructor called" << std::endl; 
    fixed_point = num << fractional_bits; //num x 2^frac_bits
}

Fixed::Fixed(float num)
{
    std::cout << "Float constructor called" << std::endl; 
    fixed_point = roundf(num * (1 << fractional_bits)); //num x 2^frac_bits
}

float Fixed::toFloat() const {
    float value = (float) fixed_point / (1 << fractional_bits);
    return value;
}

int Fixed::toInt() const {
    int value = fixed_point >> fractional_bits; // num / 2^frac
    return value;
}

std::ostream &operator<<(std::ostream& os, const Fixed &other)
{
    os << other.toFloat();
    return os;
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

 