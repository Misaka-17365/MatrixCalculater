#include <iostream>

void emptybuffer()
{
	char c;
	while (std::cin.get(c), c != '\n');
}