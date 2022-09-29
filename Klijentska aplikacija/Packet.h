//---------------------------------------------------------------------------

#ifndef PacketH
#define PacketH
using namespace std;

#include <string>

class izracun {
		int velicina;
		int paket;
		double popust;
	public:
		string rezultat;
		string cijena_paketa();
		string cijena_paketa_popust();
		int calculate_paket(int velicina, int paket);
        izracun(int _velicina, int _paket, float _popust);


};
//---------------------------------------------------------------------------
#endif
