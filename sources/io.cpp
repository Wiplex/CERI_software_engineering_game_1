#include "../headers/io.h"

namespace io {
	char de()
	{
		char c[1];
		std::fgets(c, 2, stdin);
		return c[0];
	}
}
