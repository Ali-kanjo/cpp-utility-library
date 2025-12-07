#pragma once
#pragma warning(disable:4996)

#include<iostream>
#include<ctime>
#include<vector>
#include<string>
#include"clsString.h"
using namespace std;

class clsDate
{
	short _Year;
	short _Month;
	short _Day;
	static short NumberOfDaysInAYear(short Year) {

		return (IsLeapYear(Year) ? 366 : 365);
	}
	static short NumberOfDaysInAMonth(short Month, short Year) {

		if (Month > 12 || Month < 1) {
			return 0;
		}
		short NumberOfDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

		return ((Month == 2) ? IsLeapYear(Year) ? 29 : 28 : NumberOfDays[Month - 1]);
	}
	static bool IsLeapYear(short Year) {
		return (Year % 400 == 0 || (Year % 100 != 0 && Year % 4 == 0));
	}
	
public:
	clsDate() {
		time_t t = time(NULL);
		tm* LocalTime = localtime(&t);
		_Year = LocalTime->tm_year + 1900;
		_Month = LocalTime->tm_mon + 1;
		_Day = LocalTime->tm_mday;

	}
	clsDate(string Date) {
		vector<string> vStringDate = clsString::Split(Date, "/");

		_Day = stoi(vStringDate.at(0));
		_Month = stoi(vStringDate.at(1));
		_Year = stoi(vStringDate.at(2));
	}
	clsDate(short Day, short Month, short Year) {
		_Day = Day;
		_Month = Month;
		_Year = Year;
	}
	clsDate(short Days, short Year) {
		short DaysOfCurrentMonth;
		short RemainingDays = Days;
		_Month = 1;
		_Year = Year;
		while (true) {
			DaysOfCurrentMonth = NumberOfDaysInAMonth(_Month, Year);

			if (RemainingDays > DaysOfCurrentMonth) {
				RemainingDays -= DaysOfCurrentMonth;
				_Month++;

				if (_Month > 12) {
					_Month = 1;
					_Year++;
				}
			}
			else {
				_Day = RemainingDays;
				break;
			}
		}
	}

	short GetDay() {
		return _Day;
	}
	void SetDay(short Day) {
		_Day = Day;
	}
	short GetMonth() {
		return _Month;
	}
	void SetMonth(short Month) {
		_Month = Month;
	}
	short GetYear() {
		return _Year;
	}
	void SetYear(short Year) {
		_Year = Year;
	}
	__declspec(property(get = GetDay, put = SetDay))short Day;
	__declspec(property(get = GetMonth, put = SetMonth))short Month;
	__declspec(property(get = GetYear, put = SetYear))short Year;


	static void SwapDates(clsDate& Date1, clsDate& Date2) {

		clsDate TempDate;

		TempDate.Day = Date1.Day;
		TempDate.Month = Date1.Month;
		TempDate.Year = Date1.Year;

		Date1.Day = Date2.Day;
		Date1.Month = Date2.Month;
		Date1.Year = Date2.Year;

		Date2.Day = TempDate.Day;
		Date2.Month = TempDate.Month;
		Date2.Year = TempDate.Year;


	}
	static clsDate StringToDate(string strDate) {

		vector<string> vStringDate = clsString::Split(strDate, "/");

		short Day, Month, Year;

		Day = stoi(vStringDate.at(0));
		Month = stoi(vStringDate.at(1));
		Year = stoi(vStringDate.at(2));

		return clsDate(Day, Month, Year);

	}
	static  clsDate GetSystemDate() {
		clsDate Date;

		time_t t = time(NULL);
		tm* LocalTime = localtime(&t);

		Date.Year = LocalTime->tm_year + 1900;
		Date.Month = LocalTime->tm_mon + 1;
		Date.Day = LocalTime->tm_mday;


		return Date;
	}
	static string GetSystemDateTimeString() {

		short Year, Month, Day, Hours, Minutes, Seconds;
		time_t t = time(NULL);
		tm* LocalTime = localtime(&t);
		Year = LocalTime->tm_year + 1900;
		Month = LocalTime->tm_mon + 1;
		Day = LocalTime->tm_mday;
		Hours = LocalTime->tm_hour ;
		Minutes = LocalTime->tm_min;
		Seconds = LocalTime->tm_sec;

		return to_string(Day) + "/" + to_string(Month) + "/" + to_string(Year) + " - " 
			+ to_string(Hours) + ":" + to_string(Minutes) + ":" + to_string(Seconds);
	}
	static string FormatDate(clsDate Date, string Format) {
		short Pos = 0;

		Pos = Format.find("yyyy");
		Format.replace(Pos, 4, to_string(Date.Year));
		Pos = Format.find("mm");
		Format.replace(Pos, 2, to_string(Date.Month));
		Pos = Format.find("dd");
		Format.replace(Pos, 2, to_string(Date.Day));

		return Format;
	}
	string FormatDate(string Format) {
		return FormatDate(*this, Format);
	}

	static string DateToString(clsDate Date) {

		return to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);

	}

	string DateToString() {
		return DateToString(*this);
	}

	static bool IsLeapYear(clsDate Date) {
		return IsLeapYear(Date.Year);
	}
	bool IsLeapYear() {
		return IsLeapYear(*this);
	}
	static short NumberOfDaysInAYear(clsDate Date) {

		return NumberOfDaysInAYear(Date.Year);
	}
	short NumberOfDaysInAYear() {

		return NumberOfDaysInAYear(*this);
	}

	static short NumberOfDaysInAMonth(clsDate Date) {
		return NumberOfDaysInAMonth(Date.Month, Date.Year);;
	}
	short NumberOfDaysInAMonth() {
		return NumberOfDaysInAMonth(*this);
	}

	static bool IsLastDayInMonth(clsDate Date) {
		return Date.Day == NumberOfDaysInAMonth(Date.Month, Date.Year);
	}
	bool IsLastDayInAMonth() {
		return IsLastDayInMonth(*this);
	}

	static bool IsLastMonthInYear(short Month) {
		return Month == 12;
	}
	static bool IsLastMonthInYear(clsDate Date) {
		return IsLastMonthInYear(Date.Month);
	}
	bool IsLastMonthInYear() {
		return IsLastMonthInYear(*this);
	}

	static bool IsValidDate(clsDate Date) {
		return (Date.Year < 0 ? false : (Date.Month > 12 || Date.Month < 1 ? false : (Date.Day > 0 && Date.Day <= NumberOfDaysInAMonth(Date.Month, Date.Year))));

	}
	bool IsValid() {
		return IsValidDate(*this);
	}
	static short GetDayOfWeekOrder(short Day, short Month, short Year) {
		short a, y, m;
		a = (14 - Month) / 12;
		y = Year - a;
		m = Month + 12 * a - 2;
		return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((m * 31) / 12)) % 7;

	}
	static short GetDayOfWeekOrder(clsDate Date) {

		return GetDayOfWeekOrder(Date.Day, Date.Month, Date.Year);
	}
	short GetDayOfWeekOrder() {
		return GetDayOfWeekOrder(*this);
	}
	static string GetDayShortName(short DayOfWeekOrder) {

		string ArrDays[7] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };

		return ArrDays[DayOfWeekOrder];
	}
	static string GetMonthShortName(short Month) {
		string months[12] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun","Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };

		return months[Month - 1];

	}

	static void PrintMonthCalendar(short Month, short Year) {
		short NumberOfDays = NumberOfDaysInAMonth(Month, Year);
		short Current = GetDayOfWeekOrder(1, Month, Year);
		printf("\n  _______________%s_______________  \n", GetMonthShortName(Month).c_str());

		printf("\n  Sun  Mon  Tue  Wed  Thu  Fri  Sat  \n");
		short i;
		for (i = 0; i < Current; i++) {
			printf("     ");
		}
		for (short j = 1; j <= NumberOfDays; j++) {

			printf("%5d", j);

			if (++i == 7) {
				i = 0;
				printf("\n");

			}
		}
		printf("\n  _________________________________  \n");
	}
	static void PrintMonthCalendar(clsDate Date) {
		return PrintMonthCalendar(Date.Month, Date.Year);
	}
	void PrintMonthCalendar() {
		return PrintMonthCalendar(*this);
	}

	static void PrintYearCalendar(short Year) {
		printf("\n\n  _________________________________  \n\n");
		printf("           Calendar - %d             ", Year);
		printf("\n  _________________________________  \n");

		for (short i = 1; i <= 12; i++) {
			PrintMonthCalendar(i, Year);
		}
	}
	static void PrintYearCalendar(clsDate Date) {
		return PrintYearCalendar(Date.Year);
	}
	void PrintYearCalendar() {
		return PrintYearCalendar(*this);
	}

	static short NumberOfDaysFromTheBeginningOfTheYear(short Day, short Month, short Year) {
		short Days = 0;
		for (short i = 1; i < Month; i++) {
			Days += NumberOfDaysInAMonth(i, Year);
		}
		Days += Day;
		return Days;
	}
	short NumberOfDaysFromTheBeginningOfTheYear(clsDate Date) {
		return NumberOfDaysFromTheBeginningOfTheYear(Date.Day, Date.Month, Date.Year);
	}
	short NumberOfDaysFromTheBeginningOfTheYear() {
		return NumberOfDaysFromTheBeginningOfTheYear(*this);
	}

	static clsDate GetDateFromDayOrderInYear(short DaysOrderInYear, short Year) {

		short DaysOfCurrentMonth;
		short RemainingDays = DaysOrderInYear;
		clsDate Date;
		Date.Month = 1;
		Date.Year = Year;

		while (true) {

			DaysOfCurrentMonth = NumberOfDaysInAMonth(Date.Month, Year);

			if (RemainingDays > DaysOfCurrentMonth) {
				RemainingDays -= DaysOfCurrentMonth;
				Date.Month++;

				if (Date.Month > 12) {
					Date.Month = 1;
					Date.Year++;
				}
			}
			else {
				Date.Day = RemainingDays;
				break;
			}
		}
		return Date;
	}
	static clsDate AddDays(int ToAdd, clsDate& Date) {

		int RemainingDays = NumberOfDaysFromTheBeginningOfTheYear(Date.Day, Date.Month, Date.Year) + ToAdd;
		short DaysInYear;
		short DaysInMonth;
		Date.Month = 1;

		while (true) {

			DaysInMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);

			if (RemainingDays > DaysInMonth) {
				RemainingDays -= DaysInMonth;
				Date.Month++;

				if (Date.Month > 12) {
					Date.Month = 1;
					Date.Year++;
				}
			}
			else {
				Date.Day = RemainingDays;
				break;
			}
		}
		return Date;

	}
	void AddDays(int ToAdd) {
		AddDays(ToAdd, *this);
	}

	static bool IsDate1BeforeDate2(clsDate Date1, clsDate Date2) {

		return (Date1.Year < Date2.Year ? true : (Date1.Year == Date2.Year ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false));

	}
	bool IsDateBeforeDate2(clsDate Date2) {
		return IsDate1BeforeDate2(*this, Date2);
	}
	static bool IsDate1EqualDate2(clsDate Date1, clsDate Date2) {

		return ((Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month) ? (Date1.Day == Date2.Day ? true : false) : false) : false);
	}
	bool IsDateEqualDate2(clsDate Date2) {
		return IsDate1EqualDate2(*this, Date2);
	}
	static bool IsDate1AfterDate2(clsDate Date1, clsDate Date2) {

		return !IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2);

	}
	bool IsDateAfterDate2(clsDate Date2) {
		return IsDate1AfterDate2(*this, Date2);
	}


	static clsDate AddOneDay(clsDate& Date) {

		if (IsLastDayInMonth(Date)) {

			if (IsLastMonthInYear(Date.Month)) {

				Date.Day = 1;
				Date.Month = 1;
				Date.Year++;
			}
			else {

				Date.Day = 1;
				Date.Month++;
			}
		}
		else
			Date.Day++;

		return Date;
	}
	void AddOneDay() {
		AddOneDay(*this);
	}

	static clsDate IncreaseDateByXDays(short Days, clsDate& Date) {

		for (int i = 1; i <= Days; i++) {
			Date = AddOneDay(Date);
		}
		return Date;
	}
	void IncreaseDateByXDays(short Days) {
		IncreaseDateByXDays(Days, *this);
	}

	static clsDate IncreaseDateByOneWeek(clsDate& Date) {
		return IncreaseDateByXDays(7, Date);
	}
	void IncreaseDateByOneWeek() {
		*this = IncreaseDateByOneWeek(*this);
	}

	static clsDate IncreaseDateByXWeeks(short Weeks, clsDate& Date) {
		for (int i = 1; i <= Weeks; i++) {
			Date = IncreaseDateByOneWeek(Date);
		}
		return Date;
	}
	void IncreaseDateByXWeeks(short Weeks) {
		IncreaseDateByXWeeks(Weeks, *this);
	}

	static clsDate IncreaseDateByOneMonth(clsDate& Date) {

		if (Date.Month == IsLastMonthInYear(Date.Month)) {
			Date.Month = 1;
			Date.Year++;
		}
		else {
			Date.Month++;
		}

		short NumberOfCurrentMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);
		if (Date.Day > NumberOfCurrentMonth) {
			Date.Day = NumberOfCurrentMonth;
		}

		return Date;
	}
	void IncreaseDateByOneMonth() {
		IncreaseDateByOneMonth(*this);
	}

	static clsDate IncreaseDateByXMonths(short Months, clsDate& Date) {
		for (int i = 1; i <= Months; i++) {
			Date = IncreaseDateByOneMonth(Date);
		}
		return Date;
	}
	void IncreaseDateByXMonths(short Months) {
		IncreaseDateByXMonths(Months, *this);
	}

	static clsDate IncreaseDateByOneYear(clsDate& Date) {
		Date.Year += 1;
		return Date;
	}
	void IncreaseDateByOneYear() {
		IncreaseDateByOneYear(*this);
	}

	static clsDate IncreaseDateByXYears(short X, clsDate& Date) {
		for (int i = 1; i <= X; i++) {
			Date = IncreaseDateByOneYear(Date);
		}
		return Date;
	}
	void IncreaseDateByXYears(short Years) {
		IncreaseDateByXYears(Years, *this);
	}

	static clsDate IncreaseDateByXYearsFaster(short X, clsDate& Date) {
		Date.Year += X;
		return Date;
	}
	void IncreaseDateByXYearsFaster(short Years) {
		IncreaseDateByXYearsFaster(Years, *this);
	}

	static clsDate IncreaseDateByOneDecade(clsDate& Date) {
		Date = IncreaseDateByXYears(10, Date);
		return Date;
	}
	void IncreaseDateByOneDecade() {
		IncreaseDateByOneDecade(*this);
	}

	static clsDate IncreaseDateByXDecades(short X, clsDate& Date) {
		for (int i = 1; i <= X; i++) {
			Date = IncreaseDateByOneDecade(Date);
		}
		return Date;
	}
	void IncreaseDateByXDecades(short Decades) {
		IncreaseDateByXDecades(Decades, *this);
	}

	static clsDate IncreaseDateByXDecadesFaster(short X, clsDate& Date) {
		Date.Year += (X * 10);
		return Date;
	}
	void IncreaseDateByXDecadesFaster(short Decades) {
		IncreaseDateByXDecadesFaster(Decades, *this);
	}

	static clsDate IncreaseDateByOneCentury(clsDate& Date) {
		Date.Year += 100;
		return Date;
	}
	void IncreaseDateByOneCentury() {
		*this = IncreaseDateByOneCentury(*this);
	}

	static clsDate IncreaseDateByOneMillennium(clsDate& Date) {
		Date.Year += 1000;
		return Date;
	}
	void IncreaseDateByOneMillennium() {
		IncreaseDateByOneMillennium(*this);
	}



	static clsDate DecreaseDateByOneDay(clsDate& Date) {
		if (Date.Day == 1) {

			if (Date.Month == 1) {
				Date.Year--;
				Date.Month = 12;
				//Date.Day = NumberOfDaysInAMonth(Date.Month, Date.Year);
				Date.Day = 31;
			}
			else {
				Date.Month--;
				Date.Day = NumberOfDaysInAMonth(Date.Month, Date.Year);
			}
		}
		else {
			Date.Day--;
		}

		return Date;
	}
	void DecreaseDateByOneDay() {
		DecreaseDateByOneDay(*this);
	}

	static clsDate DecreaseDateByXDays(short Days, clsDate& Date) {

		for (short i = 1; i <= Days; i++) {
			Date = DecreaseDateByOneDay(Date);
		}
		return Date;
	}
	void DecreaseDateByXDays(short Days) {
		DecreaseDateByXDays(Days, *this);
	}

	static clsDate DecreaseDateByOneWeek(clsDate& Date) {
		return DecreaseDateByXDays(7, Date);
	}
	void DecreaseDateByOneWeek() {
		DecreaseDateByOneWeek(*this);
	}

	static clsDate DecreaseDateByXWeeks(short Weeks, clsDate& Date) {
		for (int i = 1; i <= Weeks; i++) {
			Date = DecreaseDateByOneWeek(Date);
		}
		return Date;
	}
	void DecreaseDateByXWeeks(short Weeks) {
		DecreaseDateByXWeeks(Weeks, *this);
	}

	static clsDate DecreaseDateByOneMonth(clsDate& Date) {
		if (Date.Month == 1) {
			Date.Month = 12;
			Date.Year--;
		}
		else {
			Date.Month--;
		}
		short NumberOfCurrentMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);

		if (Date.Day > NumberOfCurrentMonth) {
			Date.Day = NumberOfCurrentMonth;
		}

		return Date;
	}
	void DecreaseDateByOneMonth() {
		DecreaseDateByOneMonth(*this);
	}

	static clsDate DecreaseDateByXMonths(short Months, clsDate& Date) {
		for (int i = 1; i <= Months; i++) {
			Date = DecreaseDateByOneMonth(Date);
		}
		return Date;
	}
	void DecreaseDateByXMonths(short Months) {
		DecreaseDateByXMonths(Months, *this);
	}

	static clsDate DecreaseDateByOneYear(clsDate& Date) {
		Date.Year -= 1;
		return Date;
	}
	void DecreaseDateByOneYear() {
		DecreaseDateByOneYear(*this);
	}

	static clsDate DecreaseDateByXYears(short X, clsDate& Date) {
		for (int i = 1; i <= X; i++) {
			Date = DecreaseDateByOneYear(Date);
		}
		return Date;
	}
	void DecreaseDateByXYears(short Years) {
		DecreaseDateByXYears(Years, *this);
	}

	static clsDate DecreaseDateByXYearsFaster(short X, clsDate& Date) {
		Date.Year -= X;
		return Date;
	}
	void DecreaseDateByXYearsFaster(short Years) {
		DecreaseDateByXYearsFaster(Years, *this);
	}

	static clsDate DecreaseDateByOneDecade(clsDate& Date) {
		Date = DecreaseDateByXYears(10, Date);
		return Date;
	}
	void DecreaseDateByOneDecade() {
		DecreaseDateByOneDecade(*this);
	}

	static clsDate DecreaseDateByXDecades(short X, clsDate& Date) {
		for (int i = 1; i <= X; i++) {
			Date = DecreaseDateByOneDecade(Date);
		}
		return Date;
	}
	void DecreaseDateByXDecades(short Decades) {
		DecreaseDateByXDecades(Decades, *this);
	}

	static clsDate DecreaseDateByXDecadesFaster(short X, clsDate& Date) {
		Date.Year -= (X * 10);
		return Date;
	}
	void DecreaseDateByXDecadesFaster(short Decades) {
		DecreaseDateByXDecadesFaster(Decades, *this);
	}

	static clsDate DecreaseDateByOneCentury(clsDate& Date) {
		Date.Year -= 100;
		return Date;
	}
	void DecreaseDateByOneCentury() {
		DecreaseDateByOneCentury(*this);
	}

	static clsDate DecreaseDateByOneMillennium(clsDate& Date) {
		Date.Year -= 1000;
		return Date;
	}
	void DecreaseDateByOneMillennium() {
		DecreaseDateByOneMillennium(*this);
	}

	static int GetDifferenceInDays(clsDate Date1, clsDate Date2, bool IncludeEndDay = false) {
		int Days = 0;
		while (IsDate1BeforeDate2(Date1, Date2)) {
			++Days;
			Date1 = AddOneDay(Date1);
		}
		return (IncludeEndDay ? ++Days : Days);
	}
	int GetDifferenceInDays(clsDate Date2, bool IncludeEndDay = false) {
		return GetDifferenceInDays(*this, Date2, IncludeEndDay);


	}

	static int GetDifferenceInDaysNegativeCase(clsDate Date1, clsDate Date2, bool IncludeEndDay = false) {
		int Days = 0;
		short SwapFlagValue = 1;

		if (!IsDate1BeforeDate2(Date1, Date2)) {
			SwapDates(Date1, Date2);
			SwapFlagValue = -1;
		}

		while (IsDate1BeforeDate2(Date1, Date2)) {
			++Days;
			Date1 = AddOneDay(Date1);
		}

		return (IncludeEndDay ? ++Days * SwapFlagValue : Days * SwapFlagValue);
	}
	int GetDifferenceInDaysNegativeCase(clsDate Date2, bool IncludeEndDay = false) {
		return GetDifferenceInDaysNegativeCase(*this, Date2, IncludeEndDay);
	}

	void Print() {
		cout << DateToString();
	}



	static bool IsEndOfWeek(clsDate Date) {
		short DayOrderInWeek = GetDayOfWeekOrder(Date);
		short EndOfWeekDay = 6;
		return DayOrderInWeek == EndOfWeekDay;
	}
	bool IsEndOfWeek() {
		return IsEndOfWeek(*this);
	}

	static bool IsWeekEnd(clsDate Date) {
		short DayOrderInWeek = GetDayOfWeekOrder(Date);
		short WeekEndDay1 = 5;
		short WeekEndDay2 = 6;
		return (DayOrderInWeek == WeekEndDay1 || (DayOrderInWeek == WeekEndDay2));
	}
	bool IsWeekEnd() {
		return IsWeekEnd(*this);
	}

	static bool IsBusinessDay(clsDate Date) {
		return !IsWeekEnd(Date);
	}
	bool IsBusinessDay() {
		return IsBusinessDay(*this);
	}

	static short DaysUntilTheEndOfWeek(clsDate Date) {
		short DayOrderInWeek = GetDayOfWeekOrder(Date);
		short EndDayOfWeek = 6;
		return (EndDayOfWeek - DayOrderInWeek) % 7;//We set %7 so that it will work if we change the last day of the week to another day.

	}
	short DaysUntilTheEndOfWeek() {
		return DaysUntilTheEndOfWeek(*this);
	}

	static short DaysUntilTheEndOfMonth(clsDate Date) {
		clsDate DateEndMonth;
		DateEndMonth.Day = NumberOfDaysInAMonth(Date.Year, Date.Month);
		DateEndMonth.Month = Date.Month;
		DateEndMonth.Year = Date.Year;
		return GetDifferenceInDays(Date, DateEndMonth, true);
	}
	short DaysUntilTheEndOfMonth() {
		return DaysUntilTheEndOfMonth(*this);
	}

	static short DaysUntilTheEndOfYear(clsDate Date) {
		clsDate DateEndYear;
		DateEndYear.Year = Date.Year;
		DateEndYear.Month = 12;
		DateEndYear.Day = 31;
		//There is no need to call a function to get the number of
		// days in the month because we know which month it is.
		return GetDifferenceInDays(Date, DateEndYear, true);

	}
	short DaysUntilTheEndOfYear() {
		return DaysUntilTheEndOfYear(*this);
	}

	static short CalculateVacationDays(clsDate DateFrom, clsDate DateTo) {
		short ActualDays = 0;
		while (IsDate1BeforeDate2(DateFrom, DateTo)) {
			if (IsBusinessDay(DateFrom)) {
				ActualDays++;
			}
			DateFrom = AddOneDay(DateFrom);
		}
		return ActualDays;
	}
	short CalculateVacationDays(clsDate DateTo) {
		return CalculateVacationDays(*this, DateTo);
	}

	static short CalculateBusinessDays(clsDate DateFrom, clsDate DateTo) {
		return CalculateVacationDays(DateFrom, DateTo);
	}
	short CalculateBusinessDays(clsDate DateTo) {
		return CalculateVacationDays(*this, DateTo);
	}
	clsDate CalculateVacationReturnDate(clsDate& DateFrom, short VacationDays) {
		short WeekEndCount = 0;

		while (IsWeekEnd(DateFrom)) {
			DateFrom = AddOneDay(DateFrom);
		}
		for (short i = 1; i <= VacationDays + WeekEndCount; i++) {
			if (IsWeekEnd(DateFrom))
				WeekEndCount++;
			DateFrom = AddOneDay(DateFrom);
		}
		while (IsWeekEnd(DateFrom)) {
			DateFrom = AddOneDay(DateFrom);
		}
		return DateFrom;
	}
	void CalculateVacationReturnDate(short VacationDays) {
		CalculateVacationReturnDate(*this, VacationDays);
	}
	enum enDateCompare { Date1BeforeDate2 = -1, Date1EqualDate2 = 0, Date1AfterDate2 = 1 };
	static enDateCompare CompareDates(clsDate Date1, clsDate Date2) {

		//Method No. 2.. very good used 
		if (IsDate1BeforeDate2(Date1, Date2))
			return enDateCompare::Date1BeforeDate2;

		else if (IsDate1EqualDate2(Date1, Date2))
			return enDateCompare::Date1EqualDate2;

		else
			return enDateCompare::Date1AfterDate2;

	}

};

