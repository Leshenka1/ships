#include <iostream>
#include <fstream>
#include <deque>
#include "Ship.h"
#include <vector>
using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    ifstream ifile("ships.in");
    ofstream ofile("ships.out");
    deque<Ship> raid;
    Ship shipFirst("");
    string temp;
    string name;
    int n = 0;

    if (ifile.peek() == EOF) {
        cout << "File is empty";
        exit(0);
    }

    ifile >> n;
    vector<Ship> pier(n);
    int i = 0;
    getline(ifile, temp);
    while (getline(ifile, temp)) 
    {
        for (int i = 0; i < temp.length(); i++) 
        {
            if (temp[i] == ' ') continue;
            else if (temp[i] == '1')
            {
                for (int l = i + 2; l < temp.length(); l++) 
                {
                    name.push_back(temp[l]);
                }
                ofile << "Корабль " << name << " прибыл в порт" << endl;
                Ship ship(name);
                bool a = false;
                for (int l = 0; l < pier.size(); l++) 
                {
                    if (pier[l].emptyName()) 
                    {
                        pier[l] = ship;
                        a = true;
                        break;
                    }
                }
                if (a == false) {
                    raid.push_back(ship);
                }
                name = "";
                break;
            }
            else if (temp[i] == '2') 
            {
                for (int l = i + 2; l < temp.length(); l++) 
                {
                    name.push_back(temp[l]);
                }
                int p = stoi(name) - 1;
                pier[p] = shipFirst;
                if (!raid.empty()) 
                {
                    pier[p] = raid.front();
                    raid.pop_front();
                }
                ofile << "Причал №" << p + 1 << " освободился" << endl;
                name = "";
                break;
            }
            else if (temp[i] == '3') 
            {
                ofile << "-----------------------------" << endl;
                ofile << "Список в рейде :" << endl;
                if (raid.empty()) 
                {
                    ofile << "Рейд пуст." << endl;
                }
                else 
                {
                    for (int l = 0; l < raid.size(); l++) 
                    {
                        ofile << "№" << l + 1 << " " << raid[l] << endl;
                    }
                }
                ofile << "-----------------------------" << endl;
                break;
            }
            else if (temp[i] == '4') 
            {
                ofile << "-----------------------------" << endl;
                ofile << "Состояние причалов:" << endl;
                for (int l = 0; l < pier.size(); l++) 
                {
                    ofile << "Причал №" << l + 1 << " - " << pier[l] << endl;
                }
                ofile << "-----------------------------" << endl;
                break;
            }
        }
    }
    ifile.close();
    ofile.close();
}


