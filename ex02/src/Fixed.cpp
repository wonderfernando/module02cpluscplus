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
    int value = (int)fixed_point >> fractional_bits; // num / 2^frac
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

bool Fixed::operator>(const Fixed& other) const {
    return this->fixed_point > other.fixed_point;
}

bool Fixed::operator<(const Fixed& other) const {
    return this->fixed_point < other.fixed_point;
}
bool Fixed::operator==(const Fixed& other) const {
    return this->fixed_point == other.fixed_point;
}
bool Fixed::operator!=(const Fixed& other) const {
    return this->fixed_point != other.fixed_point;
}
bool Fixed::operator>=(const Fixed& other) const {
    return this->fixed_point >= other.fixed_point;
}
bool Fixed::operator<=(const Fixed& other) const {
    return this->fixed_point <= other.fixed_point;
}

Fixed Fixed::operator+(const Fixed& other) {
    float plus = other.toFloat() + this->toFloat();
    return Fixed(plus);
}

Fixed Fixed::operator-(const Fixed& other) {
    float minus = other.toFloat() - this->toFloat();
    return Fixed(minus);
}

Fixed Fixed::operator*(const Fixed& other) {
    float mult = other.toFloat() * this->toFloat();
    return Fixed(mult);
}

Fixed Fixed::operator/(const Fixed& other) {
    if (other.toInt() == 0)
        return Fixed(0);
    float div = this->toFloat() / other.toFloat();
    return Fixed(div);
}

Fixed &Fixed::operator++() {
   this->fixed_point++;
   return *this;
}

Fixed Fixed::operator++(int) {
   Fixed temp(*this);
    this->fixed_point++;
   return temp;
}

Fixed &Fixed::operator--() {
   this->fixed_point--;
   return *this;
}

Fixed Fixed::operator--(int) {
   Fixed temp(*this);
    this->fixed_point--;
   return temp;
}

 Fixed& Fixed::min(Fixed& a, Fixed& b){
    if (a > b)
        return b;
    return a;
}

 const Fixed& Fixed::min(const Fixed& a, const Fixed& b)  {
    if (a > b)
        return b;
    return a;
}

 Fixed& Fixed::max(Fixed& a, Fixed& b){
    if (a > b)
        return a;
    return b;
}

 const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    if (a > b)
        return a;
    return b;
}

