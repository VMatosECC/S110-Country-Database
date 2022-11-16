// S110-Country-Database.cpp 
// Author:  V. Matos
// Goal:    Create a prallel vector based database holding information
//          about countries of the world;
// ----------------------------------------------------------------------
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

//Prototypes -------------------------------------------------------------
void makeDatabase(vector<string>& vcountry, vector<string>& vcapital, 
                  vector<string>& vcurrency, vector<string>& vlanguages);

void queryDatabase(vector<string>& vcountry, vector<string>& vcapital,
                   vector<string>& vcurrency, vector<string>& vlanguages);
void populateVector(vector<string>& v, string fileName);
int  sequentialSearch(vector<string> v, string key);

int main()
{
    //Database
    vector<string> vcountry, vcapital, vcurrency, vlanguages;

    makeDatabase(vcountry, vcapital, vcurrency, vlanguages);
    queryDatabase(vcountry, vcapital, vcurrency, vlanguages);

}

//User-defined functions --------------------------------------------------
void makeDatabase(vector<string>& vcountry, vector<string>& vcapital,
                  vector<string>& vcurrency, vector<string>& vlanguages)
{
    populateVector(vcountry, "c:/temp/xcountry.txt");
    populateVector(vcapital, "c:/temp/xcapital.txt");
    populateVector(vcurrency, "c:/temp/xcurrency.txt");
    populateVector(vlanguages, "c:/temp/xlanguages.txt");
}

void queryDatabase(vector<string>& vcountry, vector<string>& vcapital,
                   vector<string>& vcurrency, vector<string>& vlanguages)
{
    do
    {
        cout << "\nEnter country [xxx to end]: ";
        string strCountry;
        getline(cin, strCountry);

        if (strCountry == "xxx") break;
        int pos = sequentialSearch(vcountry, strCountry);
        if (pos == -1)
        {
            cout << "Sorry - no data found for given country\n";
        }
        else
        {
            cout << "Capital:     " << vcapital[pos] << endl;
            cout << "Currency:    " << vcurrency[pos] << endl;
            cout << "Language(s): " << vlanguages[pos] << endl;
        }

    } while (true);

}

void populateVector(vector<string>& v, string fileName)
{
    ifstream infile(fileName);
    if (!infile)
    {
        cout << "Fatal error - file not found! \n";
        exit(1);
    }

    string strValue;
    while (getline(infile, strValue))
    {
        v.push_back(strValue);
    }
    infile.close();
}

int  sequentialSearch(vector<string> v, string key)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == key) return i;
    }
    return -1;
}