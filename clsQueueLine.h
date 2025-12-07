#include<iostream>
#include<queue>
#include<stack>
#include"clsDate.h"
using namespace std;
class clsQueueLine {
private:
	string _Prefix;
	short _TotalTickets = 0;
	short _AverageServeTime = 0;
	class clsTicket {
		string _Prefix;
		short _WaitingClients;
		short _AverageServeTime;
		short _TicketNumber;

	public:
		clsTicket(string Prefix, short TicketNumber, short WaitingClients, short AverageServeTime) {
			_Prefix = Prefix;
			_WaitingClients = WaitingClients;
			_AverageServeTime = AverageServeTime;
			_TicketNumber = TicketNumber;
		}
		string Prefix() {
			return _Prefix;
		}
		short WaitingClients() {
			return _WaitingClients;
		}
		short TicketNumber() {
			return _TicketNumber;
		}
		short GetExpectedTimeForWaiting() {
			return _WaitingClients * _AverageServeTime;
		}
		void Print() {
			cout << "\n\t\t\t\t________________________\n";
			cout << "\n\t\t\t\t\t  " << FullNumber();
			cout << "\n\n\t\t\t\t  " << clsDate::GetSystemDateTimeString();
			cout << "\n\t\t\t\t  Waiting Clients = " << _WaitingClients;
			cout << "\n\t\t\t\t    Serve Time In ";
			cout << "\n\t\t\t\t     " << GetExpectedTimeForWaiting() << " Minutes.\n";
			cout << "\n\t\t\t\t________________________\n";
		}
		string FullNumber() {
			return _Prefix + to_string(_TicketNumber);
		}

	};
	queue<clsTicket> _QueueLine;
public:
	clsQueueLine(string Prefix, short AverageServeTime) {
		_Prefix = Prefix;
		_AverageServeTime = AverageServeTime;
		_TotalTickets = 0;
	}
	void IssueTicket() {
		_TotalTickets++;
		clsTicket Ticket(_Prefix, _TotalTickets, WaitingClients(), _AverageServeTime);
		_QueueLine.push(Ticket);
	}
	bool ServeNextClient() {

		if (_QueueLine.empty()) {
			return false;
		}
		else {
			_QueueLine.pop();
			return true;
		}
	}
	void PrintInfo() {
		cout << "\n\t\t\t\t________________________\n\n";
		cout << "\t\t\t\t\tQueue Info";
		cout << "\n\t\t\t\t________________________\n";
		cout << "\n\t\t\t\t  Prefix          = " << _Prefix;
		cout << "\n\t\t\t\t  Total Tickets   = " << _TotalTickets;
		cout << "\n\t\t\t\t  Served Clients  = " << GetServedTickets();
		cout << "\n\t\t\t\t  Waiting Clients = " << _QueueLine.size();
		cout << "\n\t\t\t\t________________________\n";

	}
	short GetServedTickets() {
		return _TotalTickets - _QueueLine.size();
	}
	void PrintAllTickets() {
		if (_QueueLine.empty()) {
			cout << "\n\t\t\t\t No Tickets. \n";
			return;
		}
		else {
			cout << "\n\t\t\t\t - - - Tickets - - - ";
			queue<clsTicket> TempQueue = _QueueLine;
			while (!TempQueue.empty()) {
				TempQueue.front().Print();
				TempQueue.pop();
			}
		}
	}
	string WhoIsNext() {
		if (_QueueLine.empty()) {
			return "No Next Clients";

		}
		else {
			return _QueueLine.front().FullNumber();
		}
	}
	void PrintTicketsLineRTL() {
		queue<clsTicket>TempQueue = _QueueLine;
		cout << "\n\n";
		while (!TempQueue.empty()) {
			cout << TempQueue.front().FullNumber();
			cout << " < - - ";
			TempQueue.pop();
		}
		cout << "\n\n";
	}
	void PrintTicketsLineLTR() {
		queue<clsTicket> TempQueue = _QueueLine;
		stack<clsTicket> TempStack;
		while (!TempQueue.empty()) {
			TempStack.push(TempQueue.front());
			TempQueue.pop();
		}
		cout << "\n\n";
		while (!TempStack.empty()) {
			cout << TempStack.top().FullNumber();
			cout << " - - > ";
			TempStack.pop();
		}
		cout << "\n\n";
	}
	short WaitingClients() {
		return _QueueLine.size();
	}

};