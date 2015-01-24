// TAMK, G-02019, Ohjelmointi 2, kev‰t 2013
// Laivanupotuspeli, battleship.cpp
// Mikko Kukkola 12I220B
// mikko.kukkola@eng.tamk.fi
// tyˆn tekemiseen kulunut aika tunteina: >20h
// perustoiminnot, 1a, 1b, 2b , 2c 

/*
Pelin ominaisuudet on jaettu kymmeneen eri aliohjelmaan, joita kutsutaan ohjelman erivaiheissa.
Ohjelma pyˆrii p‰‰ohjelman kautta valikossa (menu) saadun valinnan perusteella.
Pelaamisessa ja tietojen tallentamisessa k‰ytet‰‰n kahta kaksiulotteista 7x7 -taulukkoa.
Toiseen on tallennettu laivojen sijainnit ja toisessa esitet‰‰n pelitilannetta.
P‰‰valikosta menn‰‰n p‰‰see k‰ytt‰m‰‰n eri toimintoja, mutta k‰ytt‰j‰n on kuitenkin pakko ensin syˆtt‰‰ laivojen sijainnit
tai antaa ohjelman arpoa sijainnit ennen kuin voi menn‰ ampumismoodiin tai alkaa simuloimaan ammuntaa. T‰t‰ varten on luotu int muuttuja x
joka saa sopivan arvon kun laivat on sijoiteltuna. Arvo mahdollistaa ammunta-aliohjelmiin p‰‰syn. Ammunnan j‰lkeen x nollataan
jolloin ohjelma vaatii laivojen uudelleensijoittamista. Sijaintien tallentaminen tapahtuu sijainnitlauta -aliohjelmassa.
T‰m‰n aliohjelman alussa menn‰‰n sijoittelu aliohjelmaan jossa kysyt‰‰n laivan alkupisteen koordinaatit char muodossa sek‰ laivan suunta.
T‰t‰ kysely‰ jatketaan niin kauan kunnes laiva osuu koko pituudeltaan pelilaudalle eik‰ riste‰ mink‰‰n muun laivan kanssa.
N‰iden asioiden tarkistusta varten on aliohjelmat raja ja paallekkaisyys. Kun on saatu hyv‰ksytyt alkupistekoordinaatit sek‰ suunta
niin palataan takaisin sijainnitlauta -aliohjelmaan, jossa koordinaateista v‰hennet‰‰n ASCII -merkistˆkoodauksen mukaisesti sopiva kokonaisluku.
N‰in saadaan laivan alkupiste osumaan ja tallennettua 7x7 sijainnit-taulukkoon.
Seuraavaksi liikutaan laivan mitan verran laivalle annettuun suuntaan taulukossa ja tallennetaan laivan sijainti n‰ihin kohtiin.
Tallennukset sijainnit -taulukkoon tehd‰‰n numeroilla. Viiden pituinen laiva merkit‰‰n 55555, nelj‰n pituinen 4444 jne.,
yhteens‰ laivoja on nelj‰ kappaletta. Sijainnitlauta -aliohjelman silmukassa kutsutaan sijoittelu aliohjelmaa nelj‰ kertaa.
Sijoittelu -aliohjelmassa on k‰ytetty static muuttujaa jotta ohjelma tiet‰‰ kysy‰ oikean laivan tietoja ja tulostaa oikean lauseen n‰ytˆlle.
Mik‰li k‰ytt‰j‰ ei halua sijoittaa itse laivoja niin sijoittelun voi tehd‰ myˆs aliohjelmassa joka arpoo laivojen sijainnit.
Arpomisessa k‰ytet‰‰n rand() valmisaliohjelmaa.
Myˆs t‰ss‰ tapauksessa laivojen sijaintien sopivuus tarkistetaan jo yll‰ mainituissa raja- ja paallekkaisyys -aliohjelmissa ennen sijaintien tallentamista.

Laivojen sijoittelun j‰lkeen voidaan valikosta valita joko ampuminen, ampumisen simulointi tai laivat voidaan halutessa sijoitella uudestaan.
Ampuminen on toteutettu "ikuisella" silmukalla, josta p‰‰see pois vain osumalla sijoitettujen laivojen jokaiseen osaan.
T‰m‰n silmukan sis‰ll‰ on toinen silmukka jossa kysyt‰‰n niin kauan ampumakoordinaatteja kunnes k‰ytt‰j‰n syˆte on oikeanlainen. Syˆte on kaksiosainen,
oikeaksi syˆtteeksi lasketaan paitsi pelilaudalle osuvat koordinaatit, myˆs jos ensimm‰inen osa on p-kirjain tai ensimm‰inen osa on @ ja toinen osa \.
Syˆtteen oikeellisuus tarkistetaan sit‰ varten tehdyss‰ aliohjelmassa.
Seuraavaksi ohjelma tarkistaa onko koordinaattien osoittamaan kohtaan sijainnit-taulukossa tallennettu numero 5, 4, 3 tai 2, jos on niin samaiseen kohtaan
tilanne-taulukkoon tallennetaan osuman merkki. Jos taas koordinaattien osoittamassa kohdassa on tyhj‰ niin tilanne-taulukkoon laitetaan hudin merkki.
Jokaisen laukauksen j‰lkeen nollataan jokaiselle laivalle luotu oma laskuri muuttuja. T‰m‰n j‰lkeen k‰yd‰‰n l‰pi molempien taulukoiden jokainen alkio
samanaikaisesti. Jos sijainneissa on tallennettuna numero ja tilanteessa osuman merkki kasvatetaan kyseisen laivan laskuria yhdell‰. Jos l‰pik‰ynnin j‰lkeen
jonkun laivan laskuri on saavuttanut kyseisen laivan mitan suuruuden arvoisen arvon muutetaan tilanne taulukkoon kyseisiin kohtiin upotetun laivan merkit.
Sitten on erikseen luotu laskuri muuttuja joka lopettaa aliohjelman ajon jos kaikki nelj‰ laivaa on upotettu. T‰m‰n laskurin arvo kasvaa yhdell‰ aina
kun jonkun laivan osumamerkit muutetaan upotusmerkeiksi tilanne-taulukkossa. Ajo p‰‰ttyy kun laskuri saavuttaa arvon nelj‰.
Ammunnansimulointi toimii samalla periaattella paitsi ett‰ kohta johon ammutaan on t‰ysin sattumanvaraisesti arvottu rand() valmisaliohjelmalla.

Kaikki aliohjelmat joissa tehd‰‰n tarkistuksia ovat bool, joten paluu arvoina true/false. Jos true niin syˆte on k‰yp‰,
jos false niin ohjelman ajoa ei jatketa vaan kysyt‰‰n uutta syˆtett‰.
*/

#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <windows.h>
using namespace std;

char menu();
void sijainnitlauta(int &x, char sijainnit[7][7], char tilanne[7][7]);
void sijoittelu(char &alkupistek, char &alkupisten, char &suunta, char sijainnit[7][7]);
void ampuminen(int &x, char sijainnit[7][7], char tilanne[7][7]);
void arpa(int &x, char sijainnit[7][7], char tilanne[7][7]);
bool ampumasyote(char laukausk, char laukausn);
void simulointi(int &x, char sijainnit[7][7], char tilanne[7][7]);
void tilannetulostus(char tilanne[7][7]);
bool raja(char, char, char, int);
bool paallekkaisyys(char, char, char, char sijainnit[7][7], int);

int main()
{
	char sijainnit[7][7] = { ' ' };	// laivojen sijaintien tallennus taulukko
	char tilanne[7][7] = { ' ' };		// pelitilanteen tallennus taulukko

	int ikuinen = 1;
	int x = 0;				// muuttuja joka kertoo onko laivoja sijoitettu vai ei = voidaanko ampua vai ei
	while (ikuinen = 1)	// ikuinen looppi, joka pyˆritt‰‰ ohjelman eritoimintoja ja josta poistutaan lopettamalla ohjelma
	{
		char valinta = menu();
		if (valinta == '1')
			sijainnitlauta(x, sijainnit, tilanne);
		else if (valinta == '2')
			ampuminen(x, sijainnit, tilanne);
		else if (valinta == '3')
			arpa(x, sijainnit, tilanne);
		else if (valinta == '4')
			simulointi(x, sijainnit, tilanne);
		else if (valinta == 'l' || valinta == 'L')
			return 0;
		cout << endl;
	}
	system("pause");
	return 0;
}
/*--------------------------------------------------
*
* nimi: menu
* toiminta: p‰‰valikko
* parametri(t): -
* paluuarvo(t): valinta
*
*--------------------------------------------------*/
char menu()
{
	char valinta = '0';
	while (valinta != '1' && valinta != '2' && valinta != '3' && valinta != '4' && valinta != 'l' && valinta != 'L')		// Loopissa kunnes tulee oikeanlainen syˆte
	{
		cout << "Laivanupotuspeli" << endl << "================" << endl << endl;
		cout << "Valinnat:" << endl;
		cout << "1) Sy\x94t\x84 laivat" << endl;
		cout << "2) Pelaa" << endl;
		cout << "3) Arvo laivojen sijainnit" << endl;
		cout << "4) Ammunnan simulointi" << endl;
		cout << "L) Lopeta" << endl;
		cin >> valinta;
		if (valinta != '1' && valinta != '2' && valinta != '3' && valinta != '4' && valinta != 'l' && valinta != 'L')
			cout << "Virheellinen valinta!" << endl;
	}
	return valinta;
}
/*--------------------------------------------------
*
* nimi: sijainnitlauta
* toiminta: laivojen sijaintien tallennnus sijainnit -taulukkoon
* parametri(t): x, sijainnit -taulukko ja tilanne -taulukko
* paluuarvo(t): -
*
*--------------------------------------------------*/
void sijainnitlauta(int &x, char sijainnit[7][7], char tilanne[7][7])
{
	char alkupistek = 'S';		// ALKUPISTE KIRJAIN
	char alkupisten = '0';		// ALKUPISTE NUMERO
	char suunta = 'e';			// SUUNTA
	for (int i = 0; i<7; i++)		// Alustus
	{
		for (int j = 0; j<7; j++)
			tilanne[i][j] = ' ';
	}
	for (int i = 0; i<7; i++)		// Alustus
	{
		for (int j = 0; j<7; j++)
			sijainnit[i][j] = ' ';
	}
	tilannetulostus(tilanne);	// tilanteen tulostus
	for (int i = 53; i>49; i--)
	{
		sijoittelu(alkupistek, alkupisten, suunta, sijainnit); // Kysyt‰‰n alkupiste ja suunta
		alkupistek = alkupistek - 65;	// ASCII
		alkupisten = alkupisten - 49;	// ASCII
		sijainnit[alkupistek][alkupisten] = i;		// ekan pisteen tallennus, seuraavaksi if-else-for viritelm‰ss‰ loput pisteet

		if (suunta == 'e' || suunta == 'E')
		{
			for (int j = 49; j<i; j++)
			{
				alkupistek++;
				sijainnit[alkupistek][alkupisten] = i;
			}
		}
		else if (suunta == 'p' || suunta == 'P')
		{
			for (int j = 49; j<i; j++)
			{
				alkupistek--;
				sijainnit[alkupistek][alkupisten] = i;
			}
		}
		else if (suunta == 'i' || suunta == 'I')
		{
			for (int j = 49; j<i; j++)
			{
				alkupisten++;
				sijainnit[alkupistek][alkupisten] = i;
			}
		}
		else if (suunta == 'l' || suunta == 'L')
		{
			for (int j = 49; j<i; j++)
			{
				alkupisten--;
				sijainnit[alkupistek][alkupisten] = i;
			}
		}

		char k = 65;
		cout << setw(2) << ' ' << setw(2) << '1' << setw(2) << setw(2) << '2' << setw(2) << '3' << setw(2) << '4' << setw(2) << '5' << setw(2) << '6' << setw(2) << '7' << endl << ' ' << '-' << '-' << '-' << '-' << '-' << '-' << '-' << '-' << '-' << '-' << '-' << '-' << '-' << '-' << '-' << '-' << endl;
		for (int i = 0; i<7; i++)
		{
			cout << k << '|';
			for (int j = 0; j<7; j++)
				cout << setw(2) << sijainnit[i][j];
			cout << '|' << k << endl;
			k++;
		}
		cout << setw(2) << '-' << '-' << '-' << '-' << '-' << '-' << '-' << '-' << '-' << '-' << '-' << '-' << '-' << '-' << '-' << '-' << endl << setw(2) << ' ' << setw(2) << '1' << setw(2) << '2' << setw(2) << '3' << setw(2) << '4' << setw(2) << '5' << setw(2) << '6' << setw(2) << '7' << endl << endl;
	}
	x = 1;	// muuttuja joka ilmaisee onko laivat sijoiteltuna ( ON = 1 )
}
/*--------------------------------------------------
*
* nimi: sijoittelu
* toiminta: kysyy laivojen alkupisteet ja suunnat
* parametri(t): alkupistek, alkupisten (=koordinaatit), suunta ja sijainnit -taulukko
* paluuarvo(t): -
*
*--------------------------------------------------*/
void sijoittelu(char &alkupistek, char &alkupisten, char &suunta, char sijainnit[7][7])
{
	static int i = 1;		// static jotta ohjelma muistaa mink‰laivan koordinaatteja pit‰isi kysy‰
	bool testi1 = false;
	bool testi2 = false;
	int laiva;				// kertoo aliohjelmalle mik‰ laiva kyseess‰
	while (testi1 == false || testi2 == false)	// silmukassa niin kauan kunnes annetut tiedot l‰p‰isev‰t testit
	{
		if (i == 1)
		{
			laiva = 5;
			cout << "Anna viiden pituisen laivan alkupiste: "; cin >> alkupistek >> alkupisten;
		}
		else if (i == 2)
		{
			laiva = 4;
			cout << "Anna neljan pituisen laivan alkupiste: "; cin >> alkupistek >> alkupisten;
		}
		else if (i == 3)
		{
			laiva = 4;
			cout << "Anna kolmen pituisen laivan alkupiste: "; cin >> alkupistek >> alkupisten;
		}
		else if (i == 4)
		{
			laiva = 4;
			cout << "Anna kahden pituisen laivan alkupiste: "; cin >> alkupistek >> alkupisten;
		}
		cout << "Anna suunta (p(ohjoinen) / i(t\x84) / e(tel\x84) / l(\x84nsi)): "; cin >> suunta;
		testi1 = raja(alkupistek, alkupisten, suunta, laiva);	// Osuuko laudalle
		testi2 = paallekkaisyys(alkupistek, alkupisten, suunta, sijainnit, laiva);	// Onko p‰‰llekk‰isyyksi‰
		if (testi1 == false || testi2 == false)		// Virheilmoitus
			cout << "Et voi sijoittaa laivaa t\x84h\x84n kohtaan tai sy\x94te on v\x84\x84r\x84. " << endl;
	}
	i++;
	if (i == 5)
		i = 1;
}
/*--------------------------------------------------
*
* nimi: ampuminen
* toiminta: ampuminen eli pelin pelaaminen tapahtuu t‰ss‰ aliohjelmassa
* parametri(t): x, sijainnit -taulukko ja tilanne -taulukko
* paluuarvo(t): -
*
*--------------------------------------------------*/
void ampuminen(int &x, char sijainnit[7][7], char tilanne[7][7])
{
	int loppu = 0;	// Muuttuja joka laskee onko kaikki laivat upotettu
	if (x == 1)	// Jos sijoittelu tehty, p‰‰st‰‰n ampumaan
	{
		int s = 1;
		while (s = 1)	// "Ikuinen" loop josta p‰‰see pois pausella tai tuhoamalla kaikki laivat
		{
			char laukausk = 'A';	// koordinaattien kirjainosa
			char laukausn = '1';	// koordinaattien numero-osa
			cout << endl << endl << "Pelitilanne on seuraava: " << endl << endl;
			tilannetulostus(tilanne);	// tilanteen tulostus
			bool testi = false;
			while (testi == false)	// kysyt‰‰n koordinaatteja niin kauan kunnes syˆte on oikeanlainen ja l‰p‰isee testin
			{
				cout << endl << "Anna ampumiskoordinaatit: ";
				cin >> laukausk;
				// VAKOILU ALKAA
				if (laukausk == 92)
				{
					char at;
					cin >> at;
					if (at == 64)
					{
						char k = 65;
						cout << setw(2) << ' ' << setw(2) << '1' << setw(2) << setw(2) << '2' << setw(2) << '3' << setw(2) << '4' << setw(2) << '5' << setw(2) << '6' << setw(2) << '7' << endl << ' ' << '-' << '-' << '-' << '-' << '-' << '-' << '-' << '-' << '-' << '-' << '-' << '-' << '-' << '-' << '-' << '-' << endl;
						for (int i = 0; i<7; i++)
						{
							cout << k << '|';
							for (int j = 0; j<7; j++)
								cout << setw(2) << sijainnit[i][j];
							cout << '|' << k << endl;
							k++;
						}
						cout << setw(2) << '-' << '-' << '-' << '-' << '-' << '-' << '-' << '-' << '-' << '-' << '-' << '-' << '-' << '-' << '-' << '-' << endl << setw(2) << ' ' << setw(2) << '1' << setw(2) << '2' << setw(2) << '3' << setw(2) << '4' << setw(2) << '5' << setw(2) << '6' << setw(2) << '7' << endl << endl;
					}
					cout << endl << "Anna ampumiskoordinaatit: ";
					cin >> laukausk;
				}
				// VAKOILU LOPPUU			
				if (laukausk == 'P' || laukausk == 'p')		// PAUSE, takaisin p‰‰valikkoon kesken pelin
					break;
				cin >> laukausn;
				testi = ampumasyote(laukausk, laukausn);		// syˆtteen tarkistus
				if (testi == false)
					cout << "V\x84\x84r\x84 sy\x94te. " << endl;
			}
			if (laukausk == 'P' || laukausk == 'p')
				break;
			if (laukausk < 80)
				laukausk = laukausk - 65;
			else
				laukausk = laukausk - 97;
			laukausn = laukausn - 49;
			if ((sijainnit[laukausk][laukausn] == '5' || sijainnit[laukausk][laukausn] == '4' || sijainnit[laukausk][laukausn] == '3' || sijainnit[laukausk][laukausn] == '2') && tilanne[laukausk][laukausn] == ' ')
			{
				tilanne[laukausk][laukausn] = '*';			// OSUMA, jos sijainneissa on numero ja tilanteessa tyhj‰
				cout << "Laukaus osui" << endl;
			}
			else if (sijainnit[laukausk][laukausn] == ' ')
			{
				tilanne[laukausk][laukausn] = 'x';			// HUTI, jos sijainneissa tyhj‰
				cout << "Laukaus ei osunut" << endl;
			}
			int a = 0, b = 0, c = 0, d = 0;		// muuttujat jotka laskee onko laivan jokaiseen osaan osuttu
			for (int i = 0; i<7; i++)			// k‰yd‰‰n taulukoiden jokainen alkio l‰pi ja lis‰t‰‰n +1 laivan muuttujaan jos siihen on osuttu
			{
				for (int j = 0; j<7; j++)
				{
					if (sijainnit[i][j] == '5' && tilanne[i][j] == '*')
						a++;
					else if (sijainnit[i][j] == '4' && tilanne[i][j] == '*')
						b++;
					else if (sijainnit[i][j] == '3' && tilanne[i][j] == '*')
						c++;
					else if (sijainnit[i][j] == '2' && tilanne[i][j] == '*')
						d++;
				}
			}
			if (a == 5)	// tarkistetaan onko laivan jokaiseen osaan osuttu --> merkit‰‰nkˆ laiva upotetuksi --> lis‰t‰‰n +1 muuttujaan joka laskee upotettuja laivoja
			{
				for (int i = 0; i<7; i++)
				{
					for (int j = 0; j<7; j++)
					{
						if (sijainnit[i][j] == '5')
							tilanne[i][j] = '#';
					}
				}
				loppu++;
			}
			if (b == 4)	// tarkistetaan onko laivan jokaiseen osaan osuttu --> merkit‰‰nkˆ laiva upotetuksi --> lis‰t‰‰n +1 muuttujaan joka laskee upotettuja laivoja
			{
				for (int i = 0; i<7; i++)
				{
					for (int j = 0; j<7; j++)
					{
						if (sijainnit[i][j] == '4')
							tilanne[i][j] = '#';
					}
				}
				loppu++;
			}
			if (c == 3)	// tarkistetaan onko laivan jokaiseen osaan osuttu --> merkit‰‰nkˆ laiva upotetuksi --> lis‰t‰‰n +1 muuttujaan joka laskee upotettuja laivoja
			{
				for (int i = 0; i<7; i++)
				{
					for (int j = 0; j<7; j++)
					{
						if (sijainnit[i][j] == '3')
							tilanne[i][j] = '#';
					}
				}
				loppu++;
			}
			if (d == 2)	// tarkistetaan onko laivan jokaiseen osaan osuttu --> merkit‰‰nkˆ laiva upotetuksi --> lis‰t‰‰n +1 muuttujaan joka laskee upotettuja laivoja
			{
				for (int i = 0; i<7; i++)
				{
					for (int j = 0; j<7; j++)
					{
						if (sijainnit[i][j] == '2')
							tilanne[i][j] = '#';
					}
				}
				loppu++;
			}
			if (loppu == 4)	// Jos kaikki laivat upotettu, takaisin p‰‰valikkoon
			{
				tilannetulostus(tilanne);
				cout << "Peli p\x84\x84ttyi, tuhosit kaikki laivat!" << endl;
				x = 0;	// x = 0 --> vaaditaan laivojen sijoittelu jotta voidaan pelata lis‰‰
				break;
			}
		}
	}
	else if (x == 0)	// Virhe ilmoitus, jos ei ole laivoja sijoiteltu
		cout << "Sinun t\x84ytyy ensin sy\x94tt\x84\x84 laivojen sijainnit!" << endl;
}
/*--------------------------------------------------
*
* nimi: raja
* toiminta: tarkistaa laivojen sopivuuden syˆtettyyn paikkaan rajojen puolesta
* parametri(t): alkupistek, alkupisten (=koordinaatit) ja suunta
* paluuarvo(t): true/false = voi sijoittaa/ei voi sijoittaa
*
*--------------------------------------------------*/
bool raja(char alkupistek, char alkupisten, char suunta, int laiva)
{
	switch (laiva)		// switch valitsee laivan perusteella oikean kohdan mist‰ tarkistetaan syˆtteen sopivuutta
	{
	case 5:		// viisi
	{
		if (alkupistek == 'A' || alkupistek == 'B' || alkupistek == 'C')
		{
			if (alkupisten == '1' || alkupisten == '2' || alkupisten == '3')
			{
				if (suunta == 'e' || suunta == 'E' || suunta == 'i' || suunta == 'I')
					return true;
				else
					return false;
			}
			else if (alkupisten == '4')
			{
				if (suunta == 'e' || suunta == 'E')
					return true;
				else
					return false;
			}
			else if (alkupisten == '5' || alkupisten == '6' || alkupisten == '7')
			{
				if (suunta == 'e' || suunta == 'E' || suunta == 'l' || suunta == 'L')
					return true;
				else
					return false;
			}
			else
				return false;
		}
		else if (alkupistek == 'D')
		{
			if (alkupisten == '1' || alkupisten == '2' || alkupisten == '3')
			{
				if (suunta == 'i' || suunta == 'I')
					return true;
				else
					return false;
			}
			else if (alkupisten == '4')
				return false;
			else if (alkupisten == '5' || alkupisten == '6' || alkupisten == '7')
			{
				if (suunta == 'l' || suunta == 'L')
					return true;
				else
					return false;
			}
			else
				return false;
		}
		else if (alkupistek == 'E' || alkupistek == 'F' || alkupistek == 'G')
		{
			if (alkupisten == '1' || alkupisten == '2' || alkupisten == '3')
			{
				if (suunta == 'p' || suunta == 'P' || suunta == 'i' || suunta == 'I')
					return true;
				else
					return false;
			}
			else if (alkupisten == '4')
			{
				if (suunta == 'p' || suunta == 'P')
					return true;
				else
					return false;
			}
			else if (alkupisten == '5' || alkupisten == '6' || alkupisten == '7')
			{
				if (suunta == 'p' || suunta == 'P' || suunta == 'l' || suunta == 'L')
					return true;
				else
					return false;
			}
			else
				return false;
		}
		else
			return false;
	}
	case 4:		// nelj‰
	{
		if (alkupistek == 'A' || alkupistek == 'B' || alkupistek == 'C')
		{
			if (alkupisten == '1' || alkupisten == '2' || alkupisten == '3')
			{
				if (suunta == 'e' || suunta == 'E' || suunta == 'i' || suunta == 'I')
					return true;
				else
					return false;
			}
			else if (alkupisten == '4')
			{
				if (suunta == 'e' || suunta == 'E')
					return true;
				else
					return false;
			}
			else if (alkupisten == '5' || alkupisten == '6' || alkupisten == '7')
			{
				if (suunta == 'e' || suunta == 'E' || suunta == 'l' || suunta == 'L')
					return true;
				else
					return false;
			}
			else
				return false;
		}
		else if (alkupistek == 'D')
		{
			if (alkupisten == '1' || alkupisten == '2' || alkupisten == '3')
			{
				if (suunta == 'l' || suunta == 'L')
					return false;
				else
					return true;
			}
			else if (alkupisten == '4')
				return true;
			else if (alkupisten == '5' || alkupisten == '6' || alkupisten == '7')
			{
				if (suunta == 'i' || suunta == 'I')
					return false;
				else
					return true;
			}
			else
				return false;
		}
		else if (alkupistek == 'E' || alkupistek == 'F' || alkupistek == 'G')
		{
			if (alkupisten == '1' || alkupisten == '2' || alkupisten == '3')
			{
				if (suunta == 'p' || suunta == 'P' || suunta == 'i' || suunta == 'I')
					return true;
				else
					return false;
			}
			else if (alkupisten == '4')
			{
				if (suunta == 'e' || suunta == 'E')
					return false;
				else
					return true;
			}
			else if (alkupisten == '5' || alkupisten == '6' || alkupisten == '7')
			{
				if (suunta == 'p' || suunta == 'P' || suunta == 'l' || suunta == 'L')
					return true;
				else
					return false;
			}
			else
				return false;
		}
		else
			return false;
	}
	case 3:		// kolme
	{if (alkupistek == 'A' || alkupistek == 'B')
	{
		if (alkupisten == '1' || alkupisten == '2')
		{
			if (suunta == 'e' || suunta == 'E' || suunta == 'i' || suunta == 'I')
				return true;
			else
				return false;
		}
		else if (alkupisten == '3' || alkupisten == '4' || alkupisten == '5')
		{
			if (suunta == 'p' || suunta == 'P')
				return false;
			else
				return true;
		}
		else if (alkupisten == '6' || alkupisten == '7')
		{
			if (suunta == 'e' || suunta == 'E' || suunta == 'l' || suunta == 'L')
				return true;
			else
				return false;
		}
		else
			return false;
	}
	else if (alkupistek == 'C' || alkupistek == 'D' || alkupistek == 'E')
	{
		if (alkupisten == '1' || alkupisten == '2')
		{
			if (suunta == 'l' || suunta == 'L')
				return false;
			else
				return true;
		}
		else if (alkupisten == '3' || alkupisten == '4' || alkupisten == '5')
			return true;
		else if (alkupisten == '6' || alkupisten == '7')
		{
			if (suunta == 'i' || suunta == 'I')
				return false;
			else
				return true;
		}
		else
			return false;
	}
	else if (alkupistek == 'F' || alkupistek == 'G')
	{
		if (alkupisten == '1' || alkupisten == '2')
		{
			if (suunta == 'p' || suunta == 'P' || suunta == 'i' || suunta == 'I')
				return true;
			else
				return false;
		}
		else if (alkupisten == '3' || alkupisten == '4' || alkupisten == '5')
		{
			if (suunta == 'e' || suunta == 'E')
				return false;
			else
				return true;
		}
		else if (alkupisten == '6' || alkupisten == '7')
		{
			if (suunta == 'p' || suunta == 'P' || suunta == 'l' || suunta == 'L')
				return true;
			else
				return false;
		}
		else
			return false;
	}
	else
		return false;
	}
	case 2:		// kaksi
	{
		if (alkupistek == 'A')
		{
			if (alkupisten == '1')
			{
				if (suunta == 'e' || suunta == 'E' || suunta == 'i' || suunta == 'I')
					return true;
				else
					return false;
			}
			else if (alkupisten == '2' || alkupisten == '3' || alkupisten == '4' || alkupisten == '5' || alkupisten == '6')
			{
				if (suunta == 'p' || suunta == 'P')
					return false;
				else
					return true;
			}
			else if (alkupisten == '7')
			{
				if (suunta == 'e' || suunta == 'E' || suunta == 'l' || suunta == 'L')
					return true;
				else
					return false;
			}
			else
				return false;
		}
		else if (alkupistek == 'B' || alkupistek == 'C' || alkupistek == 'D' || alkupistek == 'E' || alkupistek == 'F')
		{
			if (alkupisten == '1')
			{
				if (suunta == 'l' || suunta == 'L')
					return false;
				else
					return true;
			}
			else if (alkupisten == '2' || alkupisten == '3' || alkupisten == '4' || alkupisten == '5' || alkupisten == '6')
				return true;
			else if (alkupisten == '7')
			{
				if (suunta == 'i' || suunta == 'I')
					return false;
				else
					return true;
			}
			else
				return false;
		}
		else if (alkupistek == 'G')
		{
			if (alkupisten == '1')
			{
				if (suunta == 'p' || suunta == 'P' || suunta == 'i' || suunta == 'I')
					return true;
				else
					return false;
			}
			else if (alkupisten == '2' || alkupisten == '3' || alkupisten == '4' || alkupisten == '5' || alkupisten == '6')
			{
				if (suunta == 'e' || suunta == 'E')
					return false;
				else
					return true;
			}
			else if (alkupisten == '7')
			{
				if (suunta == 'p' || suunta == 'P' || suunta == 'l' || suunta == 'L')
					return true;
				else
					return false;
			}
			else
				return false;
		}
		else
			return false;
	}
	default:
		return false;
	}
}
/*--------------------------------------------------
*
* nimi: paallekkaisyys
* toiminta: tarkistaa ettei laivoja sijoitella p‰‰llekk‰in
* parametri(t): alkupistek, alkupisten (=koordinaatit), suunta, sijainnit -taulukko ja laiva (=ilmoittaa mik‰ laiva kyseess‰)
* paluuarvo(t): true/false = voi sijoittaa/ei voi sijoittaa
*
*--------------------------------------------------*/
bool paallekkaisyys(char alkupistek, char alkupisten, char suunta, char sijainnit[7][7], int laiva)
{
	alkupistek = alkupistek - 65;		// ASCII
	alkupisten = alkupisten - 49;		// ASCII
	if (sijainnit[alkupistek][alkupisten] == '5' || sijainnit[alkupistek][alkupisten] == '4' || sijainnit[alkupistek][alkupisten] == '3' || sijainnit[alkupistek][alkupisten] == '2')
		return false;
	else
	{
		if (suunta == 'p' || suunta == 'P')
		{
			for (int i = 1; i<laiva; i++)
			{
				alkupistek--;
				if (sijainnit[alkupistek][alkupisten] == '5' || sijainnit[alkupistek][alkupisten] == '4' || sijainnit[alkupistek][alkupisten] == '3' || sijainnit[alkupistek][alkupisten] == '2')
					return false;
			}
			return true;
		}
		else if (suunta == 'e' || suunta == 'E')
		{
			for (int i = 1; i<laiva; i++)
			{
				alkupistek++;
				if (sijainnit[alkupistek][alkupisten] == '5' || sijainnit[alkupistek][alkupisten] == '4' || sijainnit[alkupistek][alkupisten] == '3' || sijainnit[alkupistek][alkupisten] == '2')
					return false;
			}
			return true;
		}
		else if (suunta == 'l' || suunta == 'L')
		{
			for (int i = 1; i<laiva; i++)
			{
				alkupisten--;
				if (sijainnit[alkupistek][alkupisten] == '5' || sijainnit[alkupistek][alkupisten] == '4' || sijainnit[alkupistek][alkupisten] == '3' || sijainnit[alkupistek][alkupisten] == '2')
					return false;
			}
			return true;
		}
		else if (suunta == 'i' || suunta == 'I')
		{
			for (int i = 1; i<laiva; i++)
			{
				alkupisten++;
				if (sijainnit[alkupistek][alkupisten] == '5' || sijainnit[alkupistek][alkupisten] == '4' || sijainnit[alkupistek][alkupisten] == '3' || sijainnit[alkupistek][alkupisten] == '2')
					return false;
			}
			return true;
		}
		else
			return false;
	}
}
/*--------------------------------------------------
*
* nimi: arpa
* toiminta: arpoo laivojen sijainnit
* parametri(t): x, sijainnit -taulukko ja tilanne -taulukko
* paluuarvo(t): -
*
*--------------------------------------------------*/
void arpa(int &x, char sijainnit[7][7], char tilanne[7][7])
{
	for (int i = 0; i<7; i++)		// alustus
	{
		for (int j = 0; j<7; j++)
			sijainnit[i][j] = ' ';
	}
	for (int i = 0; i<7; i++)		// alustus
	{
		for (int j = 0; j<7; j++)
			tilanne[i][j] = ' ';
	}
	for (int a = 5; a>1; a--)		// silmukka jossa arvotaan sijainnit, suurimmasta laivasta pienimp‰‰n
	{
		srand((unsigned int)time(NULL));
		char alkupistek = 'A';
		char alkupisten = '1';
		char suunta = 'P';
		bool testi1 = false;	// jotta laiva osuu alueelle
		bool testi2 = false;	// jottei ole p‰‰llekk‰isyyksi‰
		int laiva = a;			// aliohjelmalle tieto mik‰ laiva on kyseess‰
		while (testi1 == false || testi2 == false)
		{
			alkupistek = rand() % 7 + 65;		// arpa
			alkupisten = rand() % 7 + 49;		// arpa
			int tempsuunta = rand() % 4;		// arpa
			if (tempsuunta == 0)
				suunta = 'P';
			else if (tempsuunta == 1)
				suunta = 'I';
			else if (tempsuunta == 2)
				suunta = 'E';
			else
				suunta = 'L';
			testi1 = raja(alkupistek, alkupisten, suunta, laiva);
			testi2 = paallekkaisyys(alkupistek, alkupisten, suunta, sijainnit, laiva);
		}
		alkupistek = alkupistek - 65;
		alkupisten = alkupisten - 49;
		sijainnit[alkupistek][alkupisten] = a + 48;		// ensimm‰isen pisteen tallennus ja seuraavaksi if-else-for viritelm‰ss‰ loput pisteet
		if (suunta == 'e' || suunta == 'E')
		{
			for (int j = 1; j<a; j++)
			{
				alkupistek++;
				sijainnit[alkupistek][alkupisten] = a + 48;
			}
		}
		else if (suunta == 'p' || suunta == 'P')
		{
			for (int j = 1; j<a; j++)
			{
				alkupistek--;
				sijainnit[alkupistek][alkupisten] = a + 48;
			}
		}
		else if (suunta == 'i' || suunta == 'I')
		{
			for (int j = 1; j<a; j++)
			{
				alkupisten++;
				sijainnit[alkupistek][alkupisten] = a + 48;
			}
		}
		else if (suunta == 'l' || suunta == 'L')
		{
			for (int j = 1; j<a; j++)
			{
				alkupisten--;
				sijainnit[alkupistek][alkupisten] = a + 48;
			}
		}
	}
	x = 1;		// laivat sijoiteltuina
}
/*--------------------------------------------------
*
* nimi: ampumasyote
* toiminta: tarkistaa ampumasyˆtteen oikeellisuuden
* parametri(t): laukausk, laukausn (=koordinaatit)
* paluuarvo(t): true/false = oikea/virheellinen
*
*--------------------------------------------------*/
bool ampumasyote(char laukausk, char laukausn)
{
	if (laukausk == 'p' || laukausk == 'P')	// Jos syˆte jotain muuta kuin pelilaudalle sopivaa niin palautetaan false
		return true;
	else if (laukausk == 'a' || laukausk == 'A' || laukausk == 'b' || laukausk == 'B' || laukausk == 'c' || laukausk == 'C' || laukausk == 'd' || laukausk == 'D' || laukausk == 'e' || laukausk == 'E' || laukausk == 'f' || laukausk == 'F' || laukausk == 'g' || laukausk == 'G' || laukausk == 92)
	{
		if (laukausn == '1' || laukausn == '2' || laukausn == '3' || laukausn == '4' || laukausn == '5' || laukausn == '6' || laukausn == '7')
			return true;
		else
			return false;
	}
	else
		return false;
}
/*--------------------------------------------------
*
* nimi: simulointi
* toiminta: simuloi ammunnan
* parametri(t): x, sijainnit -taulukko ja tilanne -taulukko
* paluuarvo(t): -
*
*--------------------------------------------------*/
void simulointi(int &x, char sijainnit[7][7], char tilanne[7][7])
{
	int ammunnat[7][7] = { 0 };	// simulointia varten luotu taulukko josta tarkistetaan mihin on jo ammuttu
	int loppu = 0;				// muuttuja joka lasketaan upotettuja laivoja
	if (x == 1)				// jos laivat sijoiteltuina p‰‰see simuloimaan
	{
		int a = 1;
		while (a = 1)		// loop josta p‰‰see pois vain kun kaikki laivat upotettu
		{
			cout << endl << endl << "Pelitilanne on seuraava: " << endl << endl;
			tilannetulostus(tilanne);	// tilanteen tulostus
			Sleep(2000);			// parin sekunnin viive ammuntojen v‰liss‰
			int k = rand() % 7;		// arpa
			int n = rand() % 7;		// arpa
			while (ammunnat[k][n] != 0)
			{
				k = rand() % 7;
				n = rand() % 7;
			}
			if (sijainnit[k][n] == '5' || sijainnit[k][n] == '4' || sijainnit[k][n] == '3' || sijainnit[k][n] == '2')
			{
				ammunnat[k][n]++;		// merkit‰‰n ammunnat taulukkoon +1 jottei ammuta uudestaan samaan kohtaan
				tilanne[k][n] = '*';	// OSUMA, jos sijainneissa numero
				cout << "Laukaus osui" << endl;
			}
			else if (sijainnit[k][n] == ' ')
			{
				ammunnat[k][n]++;		// merkit‰‰n ammunnat taulukkoon +1 jottei ammuta uudestaan samaan kohtaan
				tilanne[k][n] = 'x';	// HUTI, jos sijainneissa tyhj‰
				cout << "Laukaus ei osunut" << endl;
			}
			int a = 0, b = 0, c = 0, d = 0;	// muuttujat jotka laskevat onko kaikkiin laivan osiin osuttu --> upotetaanko laiva
			for (int i = 0; i<7; i++)
			{
				for (int j = 0; j<7; j++)	// tarkistetaan onko jokaiseen laivan osaan osuttu
				{
					if (sijainnit[i][j] == '5' && tilanne[i][j] == '*')
						a++;
					else if (sijainnit[i][j] == '4' && tilanne[i][j] == '*')
						b++;
					else if (sijainnit[i][j] == '3' && tilanne[i][j] == '*')
						c++;
					else if (sijainnit[i][j] == '2' && tilanne[i][j] == '*')
						d++;
				}
			}
			if (a == 5)	// jos jokaiseen laivan osaan on osuttu, merkit‰‰n kyseinen laiva upotetuksi
			{
				for (int i = 0; i<7; i++)
				{
					for (int j = 0; j<7; j++)
					{
						if (sijainnit[i][j] == '5')
							tilanne[i][j] = '#';
					}
				}
				cout << "Laiva upposi!" << endl;
				loppu++;
			}
			if (b == 4)	// jos jokaiseen laivan osaan on osuttu, merkit‰‰n kyseinen laiva upotetuksi
			{
				for (int i = 0; i<7; i++)
				{
					for (int j = 0; j<7; j++)
					{
						if (sijainnit[i][j] == '4')
							tilanne[i][j] = '#';
					}
				}
				cout << "Laiva upposi!" << endl;
				loppu++;
			}
			if (c == 3)	// jos jokaiseen laivan osaan on osuttu, merkit‰‰n kyseinen laiva upotetuksi
			{
				for (int i = 0; i<7; i++)
				{
					for (int j = 0; j<7; j++)
					{
						if (sijainnit[i][j] == '3')
							tilanne[i][j] = '#';
					}
				}
				cout << "Laiva upposi!" << endl;
				loppu++;
			}
			if (d == 2)	// jos jokaiseen laivan osaan on osuttu, merkit‰‰n kyseinen laiva upotetuksi
			{
				for (int i = 0; i<7; i++)
				{
					for (int j = 0; j<7; j++)
					{
						if (sijainnit[i][j] == '2')
							tilanne[i][j] = '#';
					}
				}
				cout << "Laiva upposi!" << endl;
				loppu++;
			}
			if (loppu == 4)	// jos kaikki laivat upotettu, peli loppuu
			{
				tilannetulostus(tilanne);
				cout << "Peli p\x84\x84ttyi, tuhosit kaikki laivat!" << endl;
				x = 0;
				break;
			}
		}
	}
	else if (x == 0)	// jos laivoja ei ole sijoiteltu tulee virheilmoitus
		cout << "Sinun t\x84ytyy ensin sy\x94tt\x84\x84 laivojen sijainnit!" << endl;
}
/*--------------------------------------------------
*
* nimi: tilannetulostus
* toiminta: tulostaa tilanteen
* parametri(t): tilanne -taulukko
* paluuarvo(t): -
*
*--------------------------------------------------*/
void tilannetulostus(char tilanne[7][7])
{
	char k = 65;	// muuttuja josta tulee rivien p‰‰tyihin kirjaimet
	cout << setw(2) << ' ' << setw(2) << '1' << setw(2) << setw(2) << '2' << setw(2) << '3' << setw(2) << '4' << setw(2) << '5' << setw(2) << '6' << setw(2) << '7' << endl << ' ' << '-' << '-' << '-' << '-' << '-' << '-' << '-' << '-' << '-' << '-' << '-' << '-' << '-' << '-' << '-' << '-' << endl;
	for (int i = 0; i<7; i++)
	{
		cout << k << '|';
		for (int j = 0; j<7; j++)
			cout << setw(2) << tilanne[i][j];
		cout << '|' << k << endl;
		k++;
	}
	cout << setw(2) << '-' << '-' << '-' << '-' << '-' << '-' << '-' << '-' << '-' << '-' << '-' << '-' << '-' << '-' << '-' << '-' << endl << setw(2) << ' ' << setw(2) << '1' << setw(2) << '2' << setw(2) << '3' << setw(2) << '4' << setw(2) << '5' << setw(2) << '6' << setw(2) << '7' << endl << endl;
}