#include <iostream>
#include <string>

using namespace std;

int const ROWS = 13;
int const COLS = 4;
char const MARK = 'X';

char seats[COLS][ROWS] = {
	{'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A'},
	{'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B'},
	{'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', ' '},
	{'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', ' '}
};

//char seats[ROWS][COLS] = {
//	{'A','B', 'C', 'D'},
//	{'A','B', 'C', 'D'},
//	{'A','B', 'C', 'D'},
//	{'A','B', 'C', 'D'},
//	{'A','B', 'C', 'D'},
//	{'A','B', 'C', 'D'},
//	{'A','B', 'C', 'D'},
//	{'A','B', 'C', 'D'},
//	{'A','B', 'C', 'D'},
//	{'A','B', 'C', 'D'},
//	{'A','B', 'C', 'D'},
//	{'A','B', 'C', 'D'},
//	{'A','B', 'C', 'D'}
//};

int findRowIndex(int thisRow);
int findSeatIndex(char thisSeat);
void displaySeatColumn(char seats[][ROWS], int column);
void displaySeatRowNum();
void displaySeats();

int main() {
	string seatInput;

	while (true) {
		int seatRow = 0;
		char seatCol;
		int rowIndex;
		int seatIndex;

		displaySeats();

		cout << "Enter a seat or Q to quit: ";
		cin >> seatInput;

		if (seatInput == "Q" || seatInput == "q") {
			break;
		}

		for (int i = 0; i < seatInput.length(); i++) {
			if (isalpha(seatInput[i])) {
				seatCol = toupper(seatInput[i]);
			}
			else if (isdigit(seatInput[i])) {
				seatRow = seatRow * 10 + (seatInput[i] - '0');
			}
		}
		
		rowIndex = findRowIndex(seatRow);
		seatIndex = findSeatIndex(seatCol);

		if (rowIndex != -1 && seatIndex != -1) {
			if (rowIndex == 12 && (seatCol == 'C' || seatCol == 'D')) {
				cout << "Sorry, no such seat exists on the CRJ 200." << endl;
			}
			else if (seats[seatIndex][rowIndex] != MARK) {
				seats[seatIndex][rowIndex] = MARK;
			}
			else {
				cout << "Sorry, seat " << seatCol << seatRow << " is already booked." << endl;
			}
		}
	}
}

int findRowIndex(int thisRow) {
	if (thisRow >= 1 && thisRow <= ROWS) {
		return thisRow - 1;
	}
	else {
		cout << "Sorry, no such seat exists on the CRJ 200." << endl;
		return -1;
	}
}

int findSeatIndex(char thisSeat) {
	if (thisSeat >= 'A' && thisSeat <= 'D') {
		return thisSeat - 'A';
	}
	else {
		cout << "Sorry, no such seat exists on the CRJ 200." << endl;
		return -1;
	}
}



void displaySeatColumn(char seats[][ROWS], int column){
	for (int i = 0; i < ROWS; i++) {
		cout << seats[column][i] << " ";
	}
}

void displaySeatRowNum() {
	cout << endl;
	cout << "                  1 1 1 1" << endl;
	cout << "1 2 3 4 5 6 7 8 9 0 1 2 3" << endl;
	cout << endl;
}

void displaySeats() {
	cout << endl;
	for (int i = COLS-1; i >= 0; i--) {
		if (i == 1) {
			displaySeatRowNum();
		}
		displaySeatColumn(seats, i);
		cout << endl;
	}
	cout << endl;
}