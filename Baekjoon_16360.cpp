#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <map>
using namespace std;

string word_dict(char last) {
	if (last == 'a') return "as";
	else if (last == 'i' || last == 'y') return "ios";
	else if (last == 'l') return "les";
	else if (last == 'n') return "anes";
	else if (last == 'o') return "os";
	else if (last == 'r') return "res";
	else if (last == 't') return "tas";
	else if (last == 'u') return "us";
	else if (last == 'v') return "ves";
	else if (last == 'w') return "was";
	else return "exp";
}

int main() {
	int n; scanf("%d\n", &n);
  
	string word;
	for (int i = 0; i < n; i++) {
		getline(cin, word);
		if (word.substr(word.length() - 2, 2) == "ne")
			word.replace(word.length() - 2, 2, "anes");
		else if (word_dict(word.back()) == "exp")
			word.append("us");
		else word.replace(word.length() - 1, 1, word_dict(word.back()));
		printf("%s\n",word.c_str());
  }
	return 0;
}
