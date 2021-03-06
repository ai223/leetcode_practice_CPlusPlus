// StringBinaryAddition.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <bitset>

using namespace std;

string addBinary(string a, string b) {
	// check for empty strings cases
	if (a.size() == 0 && b.size() == 0) return "";
	if (a.size() == 0) return b;
	if (b.size() == 0) return a;

	// if no empty strings, proceed with additon 
	string ret("");
	string::iterator it1 = a.end()-1, it2 = b.end()-1;
	int carryOverBit(0);

	string bitA, bitB;
	while (it1 >= a.begin() && it2 >= b.begin()) {
		bitA = *it1;
		bitB = *it2;
		
		if (bitA == "1" && bitB == "1" && carryOverBit == 1)
			ret.insert(0, "1");
		else if (bitA == "1" && bitB == "1" && carryOverBit == 0) {
			ret.insert(0, "0");
			carryOverBit = 1;
		}
		else if (bitA == "0" && bitB == "0" && carryOverBit == 1) {
			ret.insert(0, "1");
			carryOverBit = 0;
		}
		else if (bitA == "0" && bitB == "0" && carryOverBit == 0)
			ret.insert(0, "0");
		else {
			if (carryOverBit == 1) {
				ret.insert(0, "0");
				carryOverBit = 1;
			}
			else {
				ret.insert(0, "1");
			}  // end inner if
		}   // end outer if

		// decrement iterators
		if (it1 == a.begin() || it2 == b.begin())
			break;
		else {
			--it1;
			--it2;
		}
	}  //end while
	

	if (it1 > a.begin()) {  // string 1 is longer, string 2 is always 0
		--it1;
		while (it1 >= a.begin()) {
			bitA = *it1;
			if (bitA == "0" && carryOverBit == 1) {
				ret.insert(0, "1");
				carryOverBit = 0;
			}
			else if (bitA == "1" && carryOverBit == 1)
				ret.insert(0, "0");
			else if (bitA == "0" && carryOverBit == 0)
				ret.insert(0, "0");
			else if (bitA == "1" && carryOverBit == 0)
				ret.insert(0, "1");

			if (it1 == a.begin())
				break;
			else
				--it1;
		} // end while
	}  // end if


	if (it2 > b.begin()) {  // string 1 is longer, string 2 is always 0
		--it2;
		while (it2 >= b.begin()) {
			bitB = *it1;
			if (bitB == "0" && carryOverBit == 1) {
				ret.insert(0, "1");
				carryOverBit = 0;
			}
			else if (bitB == "1" && carryOverBit == 1)
				ret.insert(0, "0");
			else if (bitB == "0" && carryOverBit == 0)
				ret.insert(0, "0");
			else if (bitB == "1" && carryOverBit == 0)
				ret.insert(0, "1");

			if (it2 == b.begin())
				break;
			else
				--it2;
		} // end while
	}  // end if


	// check final overflow
	if (carryOverBit == 1)
		ret.insert(0, "1");

	return ret;
}

string addBinary2(string a, string b) {
	int al = a.size() - 1, bl = b.size() - 1;
	int sum = 0;
	int carry = 0;
	string result;
	while (al >= 0 || bl >= 0 || sum) {
		sum += al >= 0 ? a[al--] - '0' : 0;
		sum += bl >= 0 ? b[bl--] - '0' : 0;
		char tmp = (sum % 2 + '0');
		result = tmp + result;
		sum /= 2;

	}
	return result;
}


int main()
{
	string res = addBinary2("1011", "10");
	cout << "Result: " << res << '\n';
    return 0;
}

