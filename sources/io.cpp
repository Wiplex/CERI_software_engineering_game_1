#include "../headers/io.h"
#include <termios.h>	// Needed for terminal input manipulation
#include <stdio.h>	// Needed for terminal input manipulation

namespace io {
	char de()
	{
		// Create new structures for
		// storing new and old configs
		// of the current terminal.
		static struct termios old;
		static struct termios mew;
		// Return character
		char ch;

		/* Initialize new terminal i/o settings */
		// initTermios(int echo)
		tcgetattr(0, &old);			/* grab old terminal i/o settings */
		mew = old;				/* make new settings same as old settings */
		mew.c_lflag &= ~ICANON;			/* disable buffered i/o */
		mew.c_lflag &= ~ECHO;			/* set echo mode */
		tcsetattr(0, TCSANOW, &mew);		/* use these new terminal i/o settings now */
		// ~initTermios(int echo)

		ch = getchar();

		/* Restore old terminal i/o settings */
		// resetTermios()
		tcsetattr(0, TCSANOW, &old);
		// ~resetTermios()

		return ch;
	}
	void Bienvenue()
	{
        std::puts("\n");
        std::puts(  "                                       Welcome to");
        std::puts(" __________   ___    ___   __________     __________   __________   __________   __________");
        std::puts("/___   ___/  /  /   /  /  /  _______/    /  _______/  /  ____   /  /   __    /  /  _______/");
        std::puts("   /  /     /  /__ /  /  /  /__         /  /  __     /  /___/  /  /  /   /  /  /  /__");
        std::puts("  /  /     /   __    /  /   __/        /  /  /  \\   /  ____   /  /  /   /  /  /   __/");
        std::puts(" /  /     /  /   /  /  /  /______     /  /___/  /  /  /   /  /  /  /   /  /  /  /______");
        std::puts("/_ /     /_ /   /_ /  /_________/    /_________/  /_ /   /_ /  /_ /   /_ /  /_________/");
        std::puts("\n");
	}
}
