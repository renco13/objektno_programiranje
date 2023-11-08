#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>

using namespace std;

//1:
//int search_str(string str, string strsub) {
//	int count = 0;
//	int location = 0;
//	while((location = str.find(strsub, location)) != string::npos) {
//		count++;
//		location += strsub.length();
//	}
//	return count;
//}

//2:
string ispravljanje(string& str) {
	//string new;
	char lik;
	for (int i = 0; i < str.length(); i++) {
		lik = str[i];
		if (ispunct(lik)) {
			if (i > 0 && str[i - 1] != ' ') {
				str.insert(i, " ");
				i++;
			}
		}
		else if (lik == ' ') {
			int j = i + 1;
			while (j < str.length() && str[j] == ' ') {
				str.erase(j, 1);
			}
		}
	}
	return str;
}

//3:
string reverse(string& input) {
	string str_rev = input;
	reverse(str_rev.begin(), str_rev.end());
	return str_rev;
}

int main(){

	//1:
	//string str = "Au ovo je toliko dugi string da ja ovo ne mogu vjerovat, ovo je ludo!";
	//string strsub = "ovo";
	//int count = search_str(str, strsub);
	//cout << "Broj ponvaljanja: " << count << endl;

	//2:
	//string str = "Ja bih ,ako ikako mogu , ovu recenicu napisala ispravno.";
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


}