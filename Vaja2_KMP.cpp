#include <string>
#include <sstream>
#include <fstream>
#include <vector>
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

void sunday(const string& text, const string& vzorec){
	int m = vzorec.size();
	int n = text.size();
	vector<unsigned int> BCH(256, m+1);

	for(int i = 0; i < m; i++){
		BCH[vzorec[i]] = m - i;
	}

	int j = 0;
    while (j + m <= n) {
        int i = 0;
        while (i < m && vzorec[i] == text[j + i]) {
            i++;
        }

        if (i == m) {
            out << j << ' ';
        }

        if (vzorec[i] != text[j+i]) {
            j += BCH[text[j + m]];
			i = 0;
        } else {
            break;
        }
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
	int j = -1;

	for (int i = 1; i < m; i++) {
		while (j >= 0 && vzorec[i - 1] != vzorec[j]) {
			j = KMPnext[j];
		}
		
		j++;
		KMPnext[i] = j;
	}
	izpis_KMPnext(KMPnext, m);


	j = 0;
	int i = 0;
	while (j + i < n) {
		if (text[j + i] == vzorec[i]) {
			i++;
			if (i == m) {
				out << j << ' ';
				j += m;
				i = 0;
			}
		} else {
			if (i > 0) {
				j += (i - KMPnext[i]);
				i = 0;
			} else {
				j++;
			}
		}
	}
	out << endl;
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
		sunday(text, vzorec);
	}

	
	return 0;
}