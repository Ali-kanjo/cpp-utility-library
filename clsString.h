#pragma once
#include<iostream>
#include<string>
#include<cctype>
#include<vector>
using namespace std;
class clsString
{
private:
	string _Value;

	static char _InvertLetterCase(char Char1) {

		return (isupper(Char1) ? tolower(Char1) : toupper(Char1));

	};
	static bool IsVowel(char Ch1) {

		Ch1 = tolower(Ch1);

		return ((Ch1 == 'a') || (Ch1 == 'e') || (Ch1 == 'i') || (Ch1 == 'o') || (Ch1 == 'u'));

	}
	static 	string Join(vector<string>vString, string Separator) {
		string S1 = "";
		for (string& Word : vString) {

			S1 = S1 + Word + Separator;

		}
		return S1.substr(0, S1.length() - Separator.length());

	}

public:

	clsString() {
		_Value = "";
	}
	clsString(string Value) {
		_Value = Value;
	}
	void SetValue(string Value) {
		_Value = Value;
	}
	string GetValue() {
		return _Value;
	}
	__declspec(property(get = GetValue, put = SetValue))string Value;

	static string UpperFirstLetterOfEachWord(string& str) {
		bool IsFirstLetter = true;
		for (int i = 0; i < str.length(); i++) {

			if (str[i] != ' ' && IsFirstLetter)
				str[i] = toupper(str[i]);

			IsFirstLetter = (str[i] == ' ') ? true : false;

		}
		return str;
	};
	void UpperFirstLetterOfEachWord() {
		_Value = UpperFirstLetterOfEachWord(_Value);
	};

	static string LowerFirstLetterOfEachWord(string str) {
		bool IsFirstLetter = true;
		for (short i = 0; i < str.length(); i++) {
			if (str[i] != ' ' && IsFirstLetter)
				str[i] = tolower(str[i]);

			IsFirstLetter = (str[i] == ' ' ? true : false);

		}
		return str;
	}
	void LowerFirstLetterOfEachWord() {
		_Value = LowerFirstLetterOfEachWord(_Value);
	}

	static string UpperAllString(string str) {

		for (short i = 0; i < str.length(); i++) {
			str[i] = toupper(str[i]);
		}

		return str;

	}
	void UpperAllString() {
		_Value = UpperAllString(_Value);
	}

	static string LowerAllString(string str) {

		for (short i = 0; i < str.length(); i++) {
			str[i] = tolower(str[i]);
		}

		return str;

	}
	void LowerAllString() {
		_Value = LowerAllString(_Value);
	}

	static string InvertAllLettersCase(string str) {

		for (int i = 0; i < str.length(); i++) {

			str[i] = _InvertLetterCase(str[i]);

		}

		return str;
	}
	void InvertAllLettersCase() {
		_Value = InvertAllLettersCase(_Value);
	}


	static short CountCapitalLetters(string str) {

		short CountCapitalLetter = 0;

		for (short i = 0; i < str.length(); i++) {

			if (isupper(str[i]))
				CountCapitalLetter++;

		}
		return CountCapitalLetter;
	}
	short CountCapitalLetters() {
		return CountCapitalLetters(_Value);
	}

	static short CountSmallLetters(string str) {

		short CountSmallLetter = 0;

		for (short i = 0; i < str.length(); i++) {

			if (islower(str[i]))
				CountSmallLetter++;

		}

		return CountSmallLetter;
	}
	short CountSmallLetters() {
		return CountSmallLetters(_Value);
	}

	static short CountSpecificLetter(string Str, char Ch, bool MatchCase = true) {

		short Counter = 0;

		for (short i = 0; i < Str.length(); i++) {

			if (MatchCase) {

				if (Str[i] == Ch)
					Counter++;
			}

			else
				if (tolower(Str[i]) == tolower(Ch))
					Counter++;

		}

		return Counter;

	}
	short CountSpecificLetter(char Ch, bool MachCase) {
		return CountSpecificLetter(_Value, Ch, MachCase);
	}

	static short CountVowelLetters(string S1) {
		short Counter = 0;
		for (short i = 0; i < S1.length(); i++) {
			if (IsVowel(S1[i]))
				Counter++;
		}
		return Counter;
	}
	short CountVowelLetters() {
		return CountVowelLetters(_Value);
	}

	static short CountEachWordInString(string S1) {

		string Delim = " ";
		short Counter = 0;
		string sWord = "";
		short Pos = 0;

		while ((Pos = S1.find(Delim)) != string::npos) {

			sWord = S1.substr(0, Pos);

			if (sWord != "") {
				Counter++;
			}

			S1.erase(0, Pos + Delim.length());

		}

		if (sWord != "") {
			Counter++;
		}

		return Counter;

	}
	short CountEachWordInString() {
		return CountEachWordInString(_Value);
	}

	static vector<string> Split(string S1, string Delim="#//#") {

		vector<string> vWordsInString;
		string sWord = "";
		short Pos = 0;

		while ((Pos = S1.find(Delim)) != string::npos) {

			sWord = S1.substr(0, Pos);
			vWordsInString.push_back(sWord);
			S1.erase(0, Pos + Delim.length());

		}

		if (S1 != "") {
			vWordsInString.push_back(S1);
		}

		return vWordsInString;

	}
	vector<string> Split() {
		return Split(_Value, " ");
	}

	static string TrimLeft(string S1) {

		for (short i = 0; i < S1.length(); i++) {

			if (S1[i] != ' ')

				return S1.substr(i, S1.length() - i);

		}
		return "";
	}
	void TrimLeft() {
		_Value = TrimLeft(_Value);
	}

	static string TrimRight(string S1) {

		for (short i = S1.length() - 1; i >= 0; i--) {

			if (S1[i] != ' ')

				return S1.substr(0, i + 1);

		}
		return "";
	}
	void TrimRight() {
		_Value = TrimRight(_Value);
	}

	static string TrimString(string S1) {

		return TrimLeft(TrimRight(S1));;
	}
	void TrimString() {
		_Value = TrimString(_Value);
	}

	static short CountPunctuation(string S1) {

		short Counter = 0;

		for (short i = 0; i < S1.length(); i++) {

			if (ispunct(S1[i]))
				Counter++;

		}

		return Counter;
	}
	short CountPunctuation() {
		return CountPunctuation(_Value);
	}

	static short CountDigit(string S1) {

		short Counter = 0;

		for (short i = 0; i < S1.length(); i++) {

			if (isdigit(S1[i]))
				Counter++;

		}

		return Counter;

	}
	short CountDigit() {
		return CountDigit(_Value);
	}

	static short CountSpace(string S1) {

		short Counter = 0;

		for (short i = 0; i < S1.length(); i++) {

			if (isspace(S1[i]))
				Counter++;

		}

		return Counter;

	}
	short CountSpace() {
		return CountSpace(_Value);
	}

	static string ReplaceWords(string S1, string ToReplace, string ReplacedTo, bool MatchCase = true) {
		vector<string>vString = Split(S1, " ");

		for (string& Word : vString) {

			if (MatchCase) {
				if (Word == ToReplace) {
					Word = ReplacedTo;

				}
			}

			else
				if (UpperAllString(Word) == UpperAllString(ToReplace)) {

					Word = ReplacedTo;

				}
		}
		return Join(vString, " ");
	}
	string ReplaceWords(string ToReplace, string ReplacedTo, bool MatchCase = true) {
		return ReplaceWords(ToReplace, ReplacedTo, MatchCase);
	}

	static string RemovePunctuation(string S1) {

		string S2 = "";

		for (short i = 0; i < S1.length(); i++) {

			if (!ispunct(S1[i]))
				S2 += S1[i];

		}
		return S2;
	}
	string RemovePunctuation() {
		return RemovePunctuation(_Value);
	}

	static string ReverseWords(string S1, string Delim) {

		vector<string>vString = Split(S1, Delim);

		vector<string>::iterator itr;
		itr = vString.end();
		string S2 = "";

		while (itr != vString.begin()) {
			--itr;
			S2 += *itr + Delim;
		}

		return S2.substr(0, S2.length() - Delim.length());


	}
	void ReverseWords(string Delim) {
		_Value = ReverseWords(_Value, Delim);
	}
	void ReverseWords() {
		_Value = ReverseWords(_Value, " ");
	}
};


