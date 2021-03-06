// StringToInteger.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <map>
using namespace std;
//
//int stringToInt(string str) {
//	int ret = 0;
//	bool isNeg = false;
//	int pos1 = 0, pos2 = 0;
//	pos1 = str.find_first_not_of(' ');
//	if (pos1 == -1 || (!isdigit(str[pos1]) && str[pos1] != '-' && str[pos1] != '+'))
//		return ret;
//	else if (str[pos1] == '-')
//		if (isdigit(str[pos1 + 1])) {
//			isNeg = true;
//			pos1 = pos1 + 1;
//			pos2 = pos1 + 2;
//			while (isdigit(str[pos2]) && (pos2 < str.length()))
//				++pos2;
//		} 
//		else
//			return ret;
//	else if (str[pos1] == '+') {
//		if (isdigit(str[pos1 + 1])) {
//			pos2 = pos1 + 1;
//			while (isdigit(str[pos2]) && (pos2 < str.length()))
//				++pos2;
//		}
//		else
//			return ret;
//	}
//	else {
//		pos2 = pos1 + 1;
//		while (isdigit(str[pos2]) && (pos2 < str.length()))
//			++pos2;
//	}  // end if
//
//	try {
//		ret = stoi(str.substr(pos1, pos2 - pos1));
//		return isNeg ? (-1 * ret) : ret;
//	}
//	catch (std::out_of_range const&) {
//		return isNeg ? INT_MIN : INT_MAX;
//	}  // end try/catch
//}

//int stringToInt(string str) {
//	int pos1, pos2;
//	bool isNeg = false;
//
//	pos1 = str.find_first_not_of(' ');
//	if (pos1 == -1) return 0;
//
//	if (str[pos1] == '+' && isdigit(str[pos1 + 1])) {
//		pos1 += 1;
//		pos2 = str.find_last_of("1234567890") + 1;
//	}
//	else if (str[pos1] == '-' && isdigit(str[pos1 + 1])) {
//		isNeg = true;
//		pos1 += 1;
//		pos2 = str.find_last_of("1234567890") + 1;
//	}
//	else if (isdigit(str[pos1])) {
//		pos2 = str.find_last_of("1234567890") + 1;
//	}
//	else
//		return 0;
//
//	if (pos1 == -1) return 0;
//
//	try {
//		string s = str.substr(pos1, pos2 - pos1);
//		return isNeg ? -1 * stoi(s) : stoi(s);
//	}
//	catch (std::out_of_range const&) {
//		return isNeg ? INT_MIN : INT_MAX;
//	}  // end try/catch
//}

//int stringToInt(string str) {
//	bool isNeg = false;
//	int pos1 = str.find_first_of("1234567890");
//	int pos2 = str.find_last_of("1234567890") + 1;
//	if (pos1 == -1) return 0;
//
//	int pos3;
//	if (pos1 != 0) {
//		if (str[pos1 - 1] == '-') {
//			pos3 = str.find_first_not_of(' ');
//			if (pos3 != pos1-1) return 0;
//			isNeg = true;
//		}
//		else if (str[pos1 - 1] == '+') {
//			pos3 = str.find_first_not_of(' ');
//			if (pos3 != pos1-1) return 0;
//		}
//		else {
//			pos3 = str.find_first_not_of(' ');
//			if (pos3 != pos1) return 0;
//		}  // end inner if
//	}  // end outer if
//
//	try {
//		string s = str.substr(pos1, pos2 - pos1);
//		return isNeg ? -1 * stoi(s) : stoi(s);
//	}
//	catch (std::out_of_range const&) {
//		return isNeg ? INT_MIN : INT_MAX;
//	}  // end try/catch	
//}


int stringToInt(string str) {
	bool isNeg = false, firstNumFound = false;
	int pos1 = 0, pos2;
	while (!firstNumFound) {
		if (isdigit(str[pos1])) {
			firstNumFound = true;
			pos2 = pos1 + 1;
		}
		else if (str[pos1] == '+') {
			if (isdigit(str[pos1 + 1])) {
				++pos1;
				pos2 = pos1 + 1;
				firstNumFound = true;
			}
			else return 0;
		}
		else if (str[pos1] == '-') {
			if (isdigit(str[pos1 + 1])) {
				++pos1;
				pos2 = pos1 + 1;
				firstNumFound = true;
				isNeg = true;
			}
			else return 0;
		}
		else if (str[pos1] != ' ')
			return 0;
		else
			++pos1;

		if (pos1 == str.length())
			return 0;
	}  // end while

	while (isdigit(str[pos2])) {
		++pos2;
	}
	// 1, 10, 100
	map<char, int> numbers = { {'0', 0}, {'1', 1}, {'2', 2}, {'3', 3}, {'4', 4}, 
	                           {'5', 5}, {'6', 6}, {'7', 7}, {'8', 8}, {'9', 9} };
	long long temp = 0;
	int numDigits = pos2 - pos1;
	double startingPow = pow(10, numDigits-1);
	for (int i = 0, j = pos1; i < numDigits; i++, j++) {
		temp += (numbers[str[j]]) * startingPow;
		startingPow /= 10;
	}  // end for

	if (temp >= INT_MAX)
		return isNeg ? INT_MIN : INT_MAX;
	else 
		return isNeg ? -1 * (int) temp : (int) temp;
}

int main()
{
	// test cases
	string s1, s2, s3, s4, s5, s6, s7, s8, s9, s10,
		s11, s12, s13, s14, s15, s16, s17, s18, s19;

	s1 = "42";
	s2 = "-42";
	s3 = "   42";
	s4 = "   4224       ";
	s5 = "   -12345";
	s6 = "     -56789275       ";
	s7 = "4193 with words";
	s8 = "words and 987";
	s9 = " just words ";
	s10 = "    ";
	s11 = "-91283472332";
	s12 = "     91283472332   and words       ";
	s13 = ".1";
	s14 = "+1";
	s15 = "-";
	s16 = "+";
	s17 = "+-2";

	std::cout << "s1: " << stringToInt(s1) << endl;
	std::cout << "s2: " << stringToInt(s2) << endl;
	std::cout << "s3: " << stringToInt(s3) << endl;
	std::cout << "s4: " << stringToInt(s4) << endl;
	std::cout << "s5: " << stringToInt(s5) << endl;
	std::cout << "s6: " << stringToInt(s6) << endl;
	std::cout << "s7: " << stringToInt(s7) << endl;
	std::cout << "s8: " << stringToInt(s8) << endl;
	std::cout << "s9: " << stringToInt(s9) << endl;
	std::cout << "s10: " << stringToInt(s10) << endl;
	std::cout << "s11: " << stringToInt(s11) << endl;
	std::cout << "s12: " << stringToInt(s12) << endl;
	std::cout << "s13: " << stringToInt(s13) << endl;
	std::cout << "s14: " << stringToInt(s14) << endl;
	std::cout << "s15: " << stringToInt(s15) << endl;
	std::cout << "s16: " << stringToInt(s16) << endl;
	std::cout << "s17: " << stringToInt(s17) << endl;


	int wait;
	cin >> wait;


    return 0;
}

