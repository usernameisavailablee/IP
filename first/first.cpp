#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <iterator>
using namespace std;

string shift_left(string message)
{
	for (int i = 0; i < message.size(); i++)
	{
		if (message[i] == 65) message[i] = 32; else
			message[i] = message[i] - 1;
	}
	return message;
}
string shift_right(string message)
{
	for (int i = 0; i < message.size(); i++)
	{
		if (message[i] == 90) message[i] = 65; else
			message[i] = message[i] + 1;
	}
	return message;
}
int main()
{
	string now;
	string path = "C:\\Users\\Трактирщик\\source\\repos\\IP\\first\\input.txt";
	ifstream input;
	input.open(path);

	list <string> File_List;
	while (!input.eof())
	{
		input >> now;
		File_List.push_back(now);
	}
	string message;
	message = File_List.back();
	File_List.pop_back();
	string message_clone = message;
	list <string> decode_messages;
	for (int i = 65; i < 91; i++)
	{
		message_clone = shift_left(message_clone);

	}

}	

//65A-90Z
//for (list<string>::iterator str = File_List.begin(); str != File_List.end(); ++str)
//	cout << *str << " ";