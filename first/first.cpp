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
		if (message[i] == 65) message[i] = 32; else if (message[i] == 32) message[i] = 90;
			else message[i] = message[i] - 1;
	}
	return message;
}


int main()
{
	string now;
	string path = "C:\\Users\\Трактирщик\\source\\repos\\IP\\first";
	ifstream input;
	input.open(path+"\\input.txt");

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
	list <string> words;
	string word = "";
	string clone_message_clone="";
	int counter = 0;
	int now_max = 0;
	string good_message;
	for (int i = 65; i < 91; i++)
	{
		message_clone = shift_left(message_clone);
		
		clone_message_clone = message_clone;
		words.clear();
		for (int j = 0; j < clone_message_clone.size(); j++)
		{
			if (clone_message_clone[j] == ' ')
			{
				words.push_back(word);
				
				word = "";
			}
			else
				word += clone_message_clone[j];

		}
		counter = 0;
		for (list<string>::iterator str = words.begin(); str != words.end(); ++str)
		{
			for (list<string>::iterator str1 = File_List.begin(); str1 != File_List.end(); ++str1)
			{
				if (*str == *str1) counter++;
			}
		}
		if (counter > now_max)
		{
			for (list<string>::iterator str = words.begin(); str != words.end(); ++str)
			{
				good_message += *str + " ";
				
			}
			
			decode_messages.push_back(good_message);
			now_max = counter;
		}
	}
	

	ofstream output(path + "\\output_cod.txt");
		for (list<string>::iterator str = decode_messages.begin(); str != decode_messages.end(); ++str)
			output << *str << " ";
}	
