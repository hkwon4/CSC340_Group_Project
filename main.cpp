
//  main.cpp
//  Degrees and Region Data Analysis
//
// created by Hyok In Kwon
// date created: 4/20/2022

#include "SchoolData.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

// function to change string number into a double
double parseStringToDouble(std::string number)
{
    double n = 0.0;
    if (number != "N/A")
    {
        return n = std::stod(number);;
    }
    else
    {
        return n;
    }
}
std::string formatFile(std::string fileName)
{
    using namespace std;
    string trueFileName = fileName + ".csv"; // concatenating .csv in order to make outputFileName easier
    string fileOutputName = fileName + "1.csv";
    ifstream inputStream;  // for extracting data
    ofstream outputStream; // for writing to a new file

    inputStream.open(trueFileName);
    if (!inputStream.is_open())
    {
        cout << "Could not open " << trueFileName << endl;
        return "1"; // if file open fails
    }

    outputStream.open(fileOutputName);
    if (!outputStream.is_open())
    {
        cout << "Could not open " << fileOutputName << endl;
        return "1"; // if file open fails
    }
    string line; // holds a row of values

    getline(inputStream, line); // skip column headers
    while (getline(inputStream, line))
    {
        //cout << "new line: " << endl;
        //cout << line << endl; //   ****************************** CHECK POINT
        //cout << endl;
        size_t begin = 0;
        size_t end = 0;
        size_t i; // iterator for the for loops
        for (i = 0; i < line.size(); i++)
        {
            if (line.at(i) == '\"')
            {
                begin = i;
                break; // leave loop after finding first ""
            }
        }

        while (begin != line.size())
        {
            //cout << "begin: " << begin << endl; //   ****************************** CHECK POINT
            //cout << "line before erase:" << endl;
            //cout << line << endl;
            for (i = begin + 1; i < line.size(); i++)
            { // loop to find ending quote
                if (line.at(i) == '\"')
                {
                    end = i;
                    break;
                }
            }
            //cout << "end: " << end << endl;
            line.erase(line.begin() + end);   // remove endquote
            line.erase(line.begin() + begin); // remove beginning quote
            //cout << "after removing quotes" << endl;
            //cout << line << endl;             //   ****************************** CHECK POINT
            for (i = begin; i < end - 3; i++)
            { // loop to erase $ and , inside quotations
                // range is now within the quote material
                if (line.at(i) == '$')
                {
                    line.erase(line.begin() + i);
                }
                if (line.at(i) == ',')
                {
                    line.erase(line.begin() + i); // since $ is erased, assume index is off by +1
                }
            }

            
            //cout << "line after erase:" << endl;
            //cout << line << endl;
            end = end - 3;
            //cout << "end after erases: " << end << endl;
            //cout << "size of line after erases: " << line.size() << endl;
            if (end >= line.size()-1)
            {
                //cout << "leaving inner while loop" << endl;
                begin = line.size(); // resets value to end of the line if another " is not found
            }
            else
            {
                for (i = end; i < line.size(); i++)
                { // for loop to find next begin
                    if (line.at(i) == '\"')
                    { // if next quotation is found
                        begin = i;
                        //cout << "changing begin to: " << begin << endl;
                        //cout << "NEXT STAGE OF ERASE" << endl;
                        break;
                    }
                    if (i == line.size()-1){
                        begin = line.size();
                    }
                }
                /*
                for (i = end; i < line.size(); i++)
                {
                    if (line.at(i) == 'N')
                    {
                        begin = line.size();
                        break;
                    }
                }
                */
                
            }
        }
        outputStream << line << endl;
    }
    inputStream.close();
    outputStream.close();

    return fileOutputName;
}
// function to extract csv data from columns and create Degree object

NS_SCHOOLDATA::Degree createDegreeObj(std::stringstream &s)
{
    std::string column; // string to hold column value
    std::getline(s, column, ',');
    std::string major = column;
    std::getline(s, column, ',');
    double start = parseStringToDouble(column);
    std::getline(s, column, ',');
    double mid = parseStringToDouble(column);
    std::getline(s, column, ',');
    double percent = parseStringToDouble(column);
    std::getline(s, column, ',');
    double m10 = parseStringToDouble(column);
    std::getline(s, column, ',');
    double m25 = parseStringToDouble(column);
    std::getline(s, column, ',');
    double m75 = parseStringToDouble(column);
    std::getline(s, column, ',');
    double m90 = parseStringToDouble(column);

    NS_SCHOOLDATA::Degree d(major, start, mid, percent, m10, m25, m75, m90);
    return d;
}

NS_SCHOOLDATA::SchoolRegion createSRObj(std::stringstream &s){
    std::string column;
    std::getline(s, column, ',');
    std::string name = column;
    std::getline(s, column, ',');
    std::string region = column;
    std::getline(s, column, ',');
    double start = parseStringToDouble(column);
    std::getline(s, column, ',');
    double med = parseStringToDouble(column);
    std::getline(s, column, ',');
    double mid10 = parseStringToDouble(column);
    std::getline(s, column, ',');
    double mid25 = parseStringToDouble(column);
    std::getline(s, column, ',');
    double mid75 = parseStringToDouble(column);
    std::getline(s, column, ',');
    double mid90 = parseStringToDouble(column);
    NS_SCHOOLDATA::SchoolRegion r(name, region);
    r.setStart(start);
    r.setMed(med);
    r.setMid10(mid10);
    r.setMid25(mid25);
    r.setMid75(mid75);
    r.setMid90(mid90);
    return r;
}

int main()
{
    using namespace NS_SCHOOLDATA;
    using namespace std;

    ifstream degreeFS; // using the degrees-that-pay-back.csv
    ifstream regionFS; // using the salaries-by-region.csv
    string degreeFile = "degrees-that-pay-back";
    string regionFile = "salaries-by-region";
    cout << "openning " << degreeFile << " file" << endl;

    vector<Degree> degreeList; // vector to hold degree objects
    vector<SchoolRegion> regionList;

    // starting to read degreeFile
    degreeFS.open(formatFile(degreeFile));
    if (!degreeFS.is_open())
    {
        cout << "Could not open degrees-that-payback.csv" << endl;
        return 1;
    }

    string line; // used to hold row in csv file

    while (getline(degreeFS, line))
    {                    // loop to go through each row
        stringstream ss(line); // used to contain row
        Degree d = createDegreeObj(ss); //creation of degree object that holds csv data
         degreeList.push_back(d);
    }
    cout << "closing degree file" << endl;
    degreeFS.close();
    cout<< "testing Degree object generation and addition to degreeList:" <<endl;
    cout <<degreeList.at(2).getMajor() << endl;
    cout << "openning " << regionFile << " file" << endl;
    regionFS.open(formatFile(regionFile));
    if (!regionFS.is_open()){
        cout << "Could not open salaries-by-region" << endl;
        return 1;
    }
    while (getline(regionFS, line))
    {                    // loop to go through each row
        stringstream ss(line); // used to contain row
        SchoolRegion r = createSRObj(ss); //creation of degree object that holds csv data
        regionList.push_back(r);
    }
    cout << "closing region file" << endl;
    regionFS.close();
    cout<< "testing Schoolregion object generation and addition to regionList:" <<endl;
    cout <<regionList.at(3).getMid25() <<endl;
    

    
}
