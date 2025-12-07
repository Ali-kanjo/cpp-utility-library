#pragma once
#include"clsDate.h"
#include"clsUtil.h"
#include<iostream>
using namespace std;
class clsInputValidate
{

public:
	template <typename T> static bool IsNumberBetween(T Number, T From, T To) {
		return Number >= From && Number <= To;
	}
	static bool IsDateBetween(clsDate Date, clsDate DateFrom, clsDate DateTo) {

		if (!(clsDate::IsDate1BeforeDate2(Date, DateFrom)||clsDate::IsDate1AfterDate2(Date,DateTo))) {
			return true;
		}
		if (!(clsDate::IsDate1BeforeDate2(Date, DateTo) || clsDate::IsDate1AfterDate2(Date, DateFrom))) {
			return true;
		}
		return false;
	}
	static bool IsValidDate(clsDate Date) {
		return clsDate::IsValidDate(Date);
	}
	template <typename T> static T ReadNumberBetween(T From, T To, string ErrorMessage = "Invalid Number ,Enter again: \n") {
		T Number = 0;
		Number = ReadNumber<T>();
		while (!IsNumberBetween(Number, From, To)) {
			Number = ReadNumber<T>();
		}
		return Number;
	}
	template<typename T> static T ReadNumber(string ErrorMessage = "Invalid Number,Enter again : \n") {
		T Number = 0;
		while (!(cin >> Number)) {
			cout << ErrorMessage;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		};
		return Number;
	}
	static string ReadString() {

		string S1 = "";
		getline(cin >> ws, S1);
		return S1;
	}
	static char ReadChar() {
		char Ch1 = ' ';
		cin >> Ch1;
		return Ch1;
	}
};

