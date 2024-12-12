#include "ClapTrap.hpp"

// Comstructor // Destructor //

ClapTrap::ClapTrap() : _name("ClapTrap"), _hit_points(10), _energy_points(10), _attack_damage(0)
{
	std::cout << _name << " default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name)
	:	_name(name),
		_hit_points(10),
		_energy_points(10),
		_attack_damage(0)
{
	std::cout << _name << " was constructed" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& otherClapTrap)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = otherClapTrap;
}

ClapTrap::~ClapTrap()
{
	std::cout << _name << " was destructed" << std::endl;
}

// operator overloads //

ClapTrap&	ClapTrap::operator=(const ClapTrap& otherClapTrap)
{
	std::cout << "Assignment operator called" << std::endl;
	if (this != &otherClapTrap)
	{
		_name = otherClapTrap._name;
		_hit_points = otherClapTrap._hit_points;
		_energy_points = otherClapTrap._energy_points;
		_attack_damage = otherClapTrap._attack_damage;
	}
	return (*this);
}

// member functions //

void	ClapTrap::attack(const std::string& target)
{
	if (_hit_points <= 0)
		std::cout << "ClapTrap " << _name << " is dead and cannot attack " << target << std::endl;
	else if (_energy_points <= 0)
		std::cout << "ClapTrap " << _name << " has no energy points to attack " << target << std::endl;
	else if (_energy_points > 0 && _hit_points > 0)
	{
		std::cout << "ClapTrap " << _name << " attacks " << target;
		std::cout << " causing " << _attack_damage << " damage" << std::endl;
		_energy_points--;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_hit_points <= 0)
		std::cout << "ClapTrap " << _name << " is already dead" << std::endl;
	else if (_hit_points < (long)amount)
	{
		_hit_points = 0;
		std::cout << "ClapTrap " << _name << " was attacked and died" << std::endl;
	}
	else
	{
		_hit_points -= amount;
		std::cout << "ClapTrap " << _name << " was attacked. Hit points left: " << _hit_points << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_hit_points <= 0)
		std::cout << "ClapTrap " << _name << " is already dead and cannot be repaired" << std::endl;
	else if (_energy_points <= 0)
		std::cout << "ClapTrap " << _name << " has no energy points to be repaired" << std::endl;
	else if (_energy_points > 0 && _hit_points > 0)
	{
		_hit_points += amount;
		_energy_points--;
		std::cout << "ClapTrap " << _name << " was repaired. Hit points: " << _hit_points << std::endl;
	}
}
