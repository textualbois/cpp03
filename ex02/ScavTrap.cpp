#include "ScavTrap.hpp"

// Comstructor // Destructor //

ScavTrap::ScavTrap() : ClapTrap("ScavTrap")
{
	_hit_points = 100;
	_energy_points = 50;
	_attack_damage = 20;
	std::cout << "ScavTrap: " << _name << " default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name)
	:	ClapTrap(name)
{
	_hit_points = 100;
	_energy_points = 50;
	_attack_damage = 20;
	std::cout << "ScavTrap: " << _name << " was constructed" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& otherScavTrap)
{
	std::cout << "ScavTrap " << "copy constructor called" << std::endl;
	*this = otherScavTrap;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap: " << _name << " was destructed" << std::endl;
}

// operator overloads //

ScavTrap&	ScavTrap::operator=(const ScavTrap& otherScavTrap)
{
	std::cout << "Assignment operator called" << std::endl;
	if (this != &otherScavTrap)
	{
		_name = otherScavTrap._name;
		_hit_points = otherScavTrap._hit_points;
		_energy_points = otherScavTrap._energy_points;
		_attack_damage = otherScavTrap._attack_damage;
	}
	return (*this);
}

// member functions //

void ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << _name << " is now in Gate keeper mode" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (_hit_points == 0)
		std::cout << "ScavTrap " << _name << " is dead and cannot attack " << target << std::endl;
	else if (_energy_points == 0)
		std::cout << "ScavTrap " << _name << " has no energy points to attack " << target << std::endl;
	else if (_energy_points > 0 && _hit_points > 0)
	{
		std::cout << "ScavTrap " << _name << " attacks " << target;
		std::cout << " causing " << _attack_damage << " damage" << std::endl;
		_energy_points--;
	}
}
