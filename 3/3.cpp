#include <iostream>
#include <string>

using namespace std;

void delete_twice (string &message)
{
    for (int i = 0; i < message.size(); i++)
    {
        if (message[i] == message[i + 1]) message.erase(i, 2);
    }
}
bool have_twice(string message)
{
    bool a = false;
    for (int i = 0; i < message.size(); i++)
    {
        if (message[i] == message[i + 1]) a=1;
    }
    return a;
}
int main()
{
    string message;
    char now;
    bool have;
    cin >> message;
    while (have_twice(message) != false)
    {
        delete_twice(message);
    }

    cout << message;
}
