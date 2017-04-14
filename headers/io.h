//! cette classe sera une classe permettant de définir un buffer custom pour les input, ainsi que de pouvoir afficher tout ce que l'on souhaite.
using namespace std;

class io : public streambuf
{
	std::streambuf* buf_;
	char* input_;
	public:
		io();
}
