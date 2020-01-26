#include <iostream>
#include <string>

using namespace std;

#define q_0 0
#define q_1 1
#define ACCEPTING_STATE q_1
#define REJECTING_STATE q_0
#define STARTING_STATE q_0

int DFA(string binaryNumber)

// 1. The 2D Array "table" is the corresponding transition table of the DFA
// 2. States q_0 and q_1 are equal to 0 and 1 respectively, this means
// 		that the current state affects the position of the table by means
//		of controlling the x-dimension of the array (i.e. the transition table)
// 3. Since input is a string, mod 48 is used to get 0 or 1. Anything other will prompt "Invalid.." msg
// 4. After exit of the for loop, currentState denotes the final state/position in the DFA graph

{
	int currentState = STARTING_STATE;
	int table[2][2] = { { q_0, q_1 },
						{ q_1, q_0 }  };

	for (int i = 0; i < binaryNumber.length(); i++)
	{
		int digit = binaryNumber[i] % 48;

		if (digit > 1)
			return -1;
		else
			currentState = table[currentState][digit];
	}

	return currentState;
}


int main()
{
	string inputNumber;

	for(int run = 0; run < 2; run++)
	{
		cout << "Enter a number in binary form: ";
		cin >> inputNumber;

		switch (DFA(inputNumber))
		{
			case -1:
				cout << "Invalid Input" << endl;
				break;
			case REJECTING_STATE:
				cout << "Rejected" << endl;
				break;
			case ACCEPTING_STATE:
				cout << "Accepted" << endl;
				break;
			default:
				cout << "Unforeseen Error." << endl;
				break;

		}

		cout << endl;

	}//for loop

	return 0;

}// main










