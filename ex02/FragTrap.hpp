#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
private:
	
public:
	FragTrap();
	FragTrap(std::string name);
	FragTrap(FragTrap const& otherFragTrap);
	~FragTrap();

	FragTrap&	operator=(const FragTrap& otherFragTrap);

	void highFivesGuys(void);
	void attack(const std::string& target);
};


#endif