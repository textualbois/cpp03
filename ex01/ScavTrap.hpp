#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
private:
	
public:
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(ScavTrap const& otherScavTrap);
	~ScavTrap();

	ScavTrap&	operator=(const ScavTrap& otherScavTrap);

	void guardGate(void);
	void attack(const std::string& target);
};


#endif