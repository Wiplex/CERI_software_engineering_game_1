//! cette classe sera une classe permettant de définir un buffer custom pour les input, ainsi que de pouvoir afficher tout ce que l'on souhaite.
using namespace std;

namespace io
{
	std::basic_istream<char, char_traits<char>> io_input;
	public:
		io();
		~io();
		char de();
		void vider();
}
