#include <iostream>
class invalidCharacterException {
private: 
	int acv;
public:
	invalidCharacterException(int acv)
	{
		this->acv = acv;
	}


};
class invalidRangeException {
private:
	int target;
public:
	invalidRangeException(int target)
	{
		this->target = target;
	}

};

class caseConversionException {
private:
	int target;
	int acv;
public:
	caseConversionException( int acv, int target)
	{
		this->target = target;
		this->acv = acv;
	}

};
using namespace std;

char character(char start, int offset) {
	int acv = int(start);
	int target = acv + offset;

	if (acv < 65 || (acv > 90 && acv < 97) || acv > 122) {
	
		throw invalidCharacterException(acv);
	}

	if (target < 65 || (target > 90 && target < 97) || target > 122) {

		throw invalidRangeException(target);
	}

	if ((target >= 65 && target <= 90 && acv >= 95 && acv <= 122) || (target >= 95 && target <= 122 && acv >= 65 && acv <= 90)) {
	
		throw caseConversionException(acv, target);

	}

	return char(target);

}

int main() {
	char start;
	int offset;
	
	cout << "Enter a starting letter: ";
	cin >> start;
	cout << "\nEnter a value to offset it by: ";
	cin >> offset;
	
	try {
		cout << endl << character(start, offset);
	}
	catch (invalidCharacterException) {
	
		cout << "ERROR : Invalid character detected.";

	}
	catch (invalidRangeException) {
	
		cout << "ERROR : Character is out of range.";

	}
	catch (caseConversionException) {
	
		cout << "ERROR : Cannot convert cases.";

	}

	return 0;
}