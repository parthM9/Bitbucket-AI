#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

class ASquare {
public:
	double Area;
	void area();
	void setlength(double wid);
	double getlength(void);

private:
	double length;
};

void ASquare::area() {
	Area = length * length;
	cout << "The area of square is" << Area ;
}
// Member functions definitions
double ASquare::getlength(void) {
	return length;
}

void ASquare::setlength(double len) {
	length = len;
}

void populateArray()
{
	srand(time(nullptr));
	const int ARRAY_SIZE = 5;
	int ar[ARRAY_SIZE] = { 0 };
	for (int i = 0; i < 5; ++i) ar[i] = rand() % 50 + 1;
	cout << "\nArray Values are : ";
	for (int v : ar) cout << v << ' ' ;
}

void removeDupWord(string str)
{
	string word = "";
	for (auto x : str)
	{
		if (x == ' ')
		{
			cout << word << "\n";
			word = "";
		}
		else
		{
			word = word + x;
		}
	}
	cout << word << endl;
}

void printmessage(int a,int b)
{
	cout << a <<"\n" << b <<"\n";
}

int alteredmessage(int a)
{
	return a * 2;
}
void oddnumbers()
{
	cout << "Odd numbers list: ";
	for (int i = 0; i < 20; i++)
	{
		if (i % 2 != 0)
		{
			cout <<i<< " ";
		}
	}
}
int main()
{
	int value;
	string str = "this has spaces in it";
	int *mypointer;
	mypointer = &value;
	*mypointer = 10;
	cout << "value is " << value << '\n';
	printmessage(2,3);
	cout << alteredmessage(2) <<"\n";
	oddnumbers();
	populateArray(); 
	removeDupWord(str);
	ASquare square;

	
	square.setlength(10.0);  
	cout << "length of square : " << square.getlength() << endl;
	square.area();
	return 0;

}