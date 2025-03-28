#include <string>
#include <sstream>
#include <fstream>
using namespace std;

ofstream out;

string inputText(const string &pot) {
	ifstream input(pot);
	stringstream sstream;

	if (!input.is_open()) {
		return string();
	}
	
	sstream << input.rdbuf();
	return sstream.str();
}

void izpis_KMPnext(const int* polje, int len) {
	for (int i = 0; i < len; ++i) {
		out << polje[i] << ' ';
	}
	out << endl;
}

void KMP(const string& text, const string& vzorec) {
	/*
	 * implementacija algoritma KMP 
	 * za izpis polja KMPnext lahko uporabite funkcijo izpis_KMPnext
	 * Za izpis navidezne spremenljivke index uporabite: out << index << ' ';
	 */
	int n = text.size();
 	int m = vzorec.size();
 
 	int* KMPnext = new int[m]();
 	KMPnext[0] = -1;
 	int j = -1;//afafafaafas
 
 	for (int i = 2; i < m; i++) {
 		while (j >= 0 && vzorec[j] != vzorec[i - 1]) {
 			j = KMPnext[j]; 
 		}
 		j++;
 		KMPnext[i] = j;
 	}
 	izpis_KMPnext(KMPnext,m);
 
 	int j1 = 0; 
 	int i = 0; 
 
 	while (j1 + i < n) {
 		if (vzorec[i] == text[j1 + i]) {
 			i++;
 			if (i == m) {
 				out << j1 << ' '; 
 				j1 += m - KMPnext[m - 1]; 
 				i = 0;
 			}
 		}
 		else {
 			if (KMPnext[i] >= 0) {
 				j = j1 + i - KMPnext[i]; 
 				i = KMPnext[i];
 			}
 			else {
 				j1++;
 				i = 0;
 			}
 		}
 	}
}

int main(int argc, const char *const argv[]) {
	if (argc != 4) {
		return -1;
	}

	string text = inputText(argv[3]);
	string vzorec = argv[2];
	out.open("out.txt");

	if (!out) {
		return -2;
	}

	if (argv[1][0] == '0') {
		KMP(text, vzorec);
	}
	else {
		//Sunday
	}

	
	return 0;
}