#include "DiamondTrap.hpp"

// Comstructor // Destructor //

DiamondTrap::DiamondTrap() : ClapTrap("Default_ClatTrap"), ScavTrap(), FragTrap(), _name("Default")
{
	std::cout << "DiamondTrap default constructor called" << std::endl;
	_energy_points = ScavTrap::_energy_points;
	_hit_points = FragTrap::_hit_points;  // Set hit points from FragTrap
	_attack_damage = FragTrap::_attack_damage;  // Set attack damage from FragTrap
}
DiamondTrap::DiamondTrap(std::string const & name) : 
	ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap(), _name(name)
{
	std::cout << "DiamondTrap name constructor called" << std::endl;
	_energy_points = ScavTrap::_energy_points;

}

DiamondTrap::DiamondTrap(DiamondTrap const & otherDiamondTrap)
{
	std::cout << "DiamondTrap " << "copy constructor called" << std::endl;
	*this = otherDiamondTrap;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << _name << " was destructed" << std::endl;
}

// operator overloads //

DiamondTrap&	DiamondTrap::operator=(DiamondTrap const & otherDiamondTrap)
{
	std::cout << "Assignment operator called" << std::endl;
	if (this != &otherDiamondTrap)
	{
		_name = otherDiamondTrap._name;
		_hit_points = otherDiamondTrap._hit_points;
		_energy_points = otherDiamondTrap._energy_points;
		_attack_damage = otherDiamondTrap._attack_damage;
	}
	return (*this);
}

// member functions //

void	DiamondTrap::whoAmI(void)
{
	std::cout << "DiamondTrap name: " << _name << std::endl;
	std::cout << "ClapTrap name: " << ClapTrap::_name << std::endl;
}

void	DiamondTrap::attack(const std::string & target)
{
	ScavTrap::attack(target);
}
