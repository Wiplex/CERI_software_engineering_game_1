#include "../headers/io.h"
#include <vector>

// Notes :
// Get the terminal column number :
// 	> stty -a | grep "col" | tail -c 22 | tail -c 13 | head -c 3
// Get the terminal rows number :
// 	> stty -a | grep "col" | tail -c 22 | head -c 2

namespace io
{
	void ChangeTerminal(bool Ech)
	{
		tcgetattr(0, &before);			/* Grab old terminal i/o settings */
		after = before;				/* Make new settings same as old settings */
		after.c_lflag &= ~ICANON;		/* Disable buffered i/o */
		after.c_lflag &= Ech==1 ? ECHO:~ECHO;	/* Set echo mode */
		tcsetattr(0, TCSANOW, &after);		/* Use these new terminal i/o settings now */
	}

	void ResetTerminal()
	{
		tcsetattr(0, TCSANOW, &before);		// Restore old terminal I/O settings
	}

	char de()
	{
		char ch;				// Return character
		ChangeTerminal();
		ch = getchar();				// getchar() now takes only one char
		ResetTerminal();
		return ch;
	}

	std::string long_input()
	{
		std::stringstream input;
		char charInput,deletedChar;
		ChangeTerminal(1);
		do {
			charInput = getchar();
			if (charInput != 127)
				input << charInput;
			else
				removeLastChar(input);
			//	if (input.tellp() > 0)
			//		input.seekp(-1, input.cur);
		} while(charInput != 10);
		ResetTerminal();
		return input.str().length() == 1 ? long_input() : input.str();
	}

	void removeLastChar(std::stringstream& input)
	{
		std::stringstream str;
		std::string s = input.str();
		if (s.size() != 0)
		{
			s.erase(s.end()-1);
			input.swap(str);
			input << s;
		}
	}

	void bienvenue()
	{
		std::puts("\n");
		std::puts("					    Welcome to");
		std::puts(" __________   ___   ___   __________     __________   __________   ___    ___   __________");
		std::puts("/___   ___/  /  /  /  /  /  _______/    /  _______/  /  ____   /  /   \\_/   /  /  _______/");
		std::puts("   /  /     /  /__/  /  /  /__         /  /   __    /  /___/  /  /         /  /  /__");
		std::puts("  /  /     /   __   /  /   __/        /  /   /  \\  /  ____   /  /  / - /  /  /   __/");
		std::puts(" /  /     /  /  /  /  /  /______     /  /___/  /  /  /   /  /  /  /   /  /  /  /______");
		std::puts("/_ /     /_ /  /_ /  /_________/    /_________/  /_ /   /_ /  /_ /   /_ /  /_________/");
		std::puts("\n");

		std::puts("Dans The Game, vous devez débusquer et tuer tous les monstres présents sur la carte. Bonne chance!");
		std::puts("\n");
	}
}

////! Implémentation classe test
//personnage::personnage()
//{
//	name = "";
//	description = "";
//}
//
//personnage::personnage(string nom, string desc)
//{
//	name = nom;
//	description = desc;
//}
//
//string personnage::get_name()
//{
//	return name;
//}
//
//string personnage::get_desc()
//{
//	return description;
//}
