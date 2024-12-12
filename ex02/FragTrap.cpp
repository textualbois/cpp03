#include "FragTrap.hpp"

// Comstructor // Destructor //

FragTrap::FragTrap() : ClapTrap("FragTrap")
{
	_hit_points = 100;
	_energy_points = 100;
	_attack_damage = 30;
	std::cout << "FragTrap: " << _name << " default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name)
	:	ClapTrap(name)
{
	_hit_points = 100;
	_energy_points = 100;
	_attack_damage = 30;
	std::cout << "FragTrap: " << _name << " was constructed" << std::endl;
}

FragTrap::FragTrap(const FragTrap& otherFragTrap)
{
	std::cout << "FragTrap " << "copy constructor called" << std::endl;
	*this = otherFragTrap;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap: " << _name << " was destructed" << std::endl;
}

// operator overloads //

FragTrap&	FragTrap::operator=(const FragTrap& otherFragTrap)
{
	std::cout << "Assignment operator called" << std::endl;
	if (this != &otherFragTrap)
	{
		_name = otherFragTrap._name;
		_hit_points = otherFragTrap._hit_points;
		_energy_points = otherFragTrap._energy_points;
		_attack_damage = otherFragTrap._attack_damage;
	}
	return (*this);
}

// member functions //

void FragTrap::highFivesGuys(void)
{
	std::cout << "Hey guys, I'm " << _name << ". Shall we have highfives?" << std::endl;
}

void	FragTrap::attack(const std::string& target)
{
	if (_hit_points == 0)
		std::cout << "FragTrap " << _name << " is dead and cannot attack " << target << std::endl;
	else if (_energy_points == 0)
		std::cout << "FragTrap " << _name << " has no energy points to attack " << target << std::endl;
	else if (_energy_points > 0 && _hit_points > 0)
	{
		std::cout << "FragTrap " << _name << " attacks " << target;
		std::cout << " causing " << _attack_damage << " damage" << std::endl;
		_energy_points--;
	}
}
