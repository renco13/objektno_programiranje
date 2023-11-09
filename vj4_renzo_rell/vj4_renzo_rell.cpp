#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>

using namespace std;

//1:
int search_str(string str, string strsub) {
	int count = 0;
	int location = 0;
	while((location = str.find(strsub, location)) != string::npos) {
		count++;
		location += strsub.length();
	}
	return count;
}

//2:
void ispravljanje(string& str) {
	//string new;
	char lik;
	int i = 0;
	while (i < str.length()) {
		if (str[i] == ' ' && str[i+1] == ',') {
			lik = str[i];
			str[i] = str[i + 1];
			str[i + 1] = lik;
		}
		i++;
	}
}

//3:
string reverse(string& input) {
	string str_rev = input;
	reverse(str_rev.begin(), str_rev.end());
	return str_rev;
}

//4:
string translation(string& str) {
	string translate;
	string word;
	int i = 0;

	while (i < str.length()) {
		char lik = str[i];

		if (isalpha(lik)) {
			word.push_back(lik);
			i++;
		}
		else {
			if (!word.empty()) {
				if (word[0] == 'a' || word[0] == 'e' || word[0] == 'i' || word[0] == 'o' || word[0] == 'u' || word[0] == 'A' || word[0] == 'E' || word[0] == 'I' || word[0] == 'O' || word[0] == 'U') {
					translate += word + "hay";
				}
				else {
					translate += word.substr(1) + word[0] + "ay";
				}
				word.clear();
			}
			translate += lik;
			i++;
		}
	}
	str = translate;
	return str;
}

int main(){

	//1:
	//string str = "Au ovo je toliko dugi string da ja ovo ne mogu vjerovat, ovo je ludo!";
	//string strsub = "ovo";
	//int count = search_str(str, strsub);
	//cout << "Broj ponvaljanja: " << count << endl;

	//2:
	//string str = "Ja bih ,ako ikako mogu ,ovu recenicu napisala ispravno.";
	//ispravljanje(str);
	//cout << str << endl;

	//3:
	//vector<string> str;
	//int strnum = 4;
	//string input;
	//cout << "Unesite stringove: \n";
	//for (int i = 0; i < strnum; i++) {
	//	getline(cin, input);
	//	str.push_back(reverse(input));
	//}
	//sort(str.begin(), str.end());
	//cout << "Sort and reverse: \n";
	//for (string& str_rev : str) {
	//	cout << str_rev << endl;
	//}

	//4:
	//string str = "What time is it?";
	//translation(str);
	//cout << str << endl;

}
