#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <iomanip>

using namespace std;

class train
{
protected:
    int number;
    string departure, destination;
public:
    train() :number(0), departure(0), destination(0) {}
    train(const train& copy) :number(copy.number), departure(copy.departure), destination(copy.destination) {}
    train(int _number, string _departure, string _destination)
    {
        number = _number; 
        departure = _departure;
        destination = _destination;
    }
    int getNumber()
    {
        return number;
    }
    string getDeparture()
    {
        return departure;
    }
    string getDestination()
    {
        return destination;
    }
    void operator = (train other)
    {
        number = other.number;
        departure = other.departure;
        destination = other.destination;
    }

};

void addTrain(vector <train>& a) 
{
    int num;
    string station, time;
    cout << "Enter train number: " << endl;
    cin >> num;
    cin.ignore();
    cout << "Enter your destination: " << endl;
    cin >> station;
    cin.ignore();
    cout << "Enter departure time: " << endl;
    cin >> time;
    cin.ignore();
    a.push_back(train(num, time, station));
}

void allInfo(vector <train>& a) 
{
    if (a.empty())
    {
        cout << "the list is empty! " << endl; return;
    }
    vector <train>::iterator it = a.begin();
    cout << "train number  " << '\t' << " Departure time " << '\t' << " Destination " << endl;
    while (it != a.end())
    {
        cout << it->getNumber() << setw(25) << it->getDeparture() << setw(25) << it->getDestination() << '\n';
        it++;
    }
}
void info_one_train(const vector<train>& a)
{
    if (a.empty()) { cout << "the list is empty\n"; return; }
    int user_train;
    cout << "Enter train number: " << endl;
    cin >> user_train;

    bool found = false;
    for (vector <train>::iterator it = a.begin(); it != a.end(); ++it)
    {
        if (it->getNumber() == user_train)
        {
            cout << it->getDestination() << '\t' << it->getDeparture() << endl;
            found = true;
            break;
        }
    }

    if (!found) cout << "Train not found! " << endl;
}
void main()
{
    cout << setw(55) << "Task 2 " << endl;
    vector <train> database;
    for (int i = 0; i < 2; i++)
    {
        addTrain(database);
    }
    allInfo(database);
    info_one_train(database);
}