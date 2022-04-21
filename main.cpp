
//  main.cpp
//  Degrees and Region Data Analysis
//
//created by Hyok In Kwon



#include "SchoolData.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

//function to change string number into a double
double parseStringToDouble(std::string number){
    double n = 0.0;
    for (size_t i = 0 ; i < number.size() ; i++){ //for loop erasing dollar signs and commas
        if (number.at(i) == ',' || number.at(i) == '$'){
            number.erase(number.begin() + i);
        }
    }
    n = std::stod(number);
    std::cout << number << std::endl;
    
    /** algorithm explained:
     * take the string
     * loop to scan through string
     * remove any instance of $ or ,
     * parse to double
     * return that double
     */
    return n;
}

//function to extract csv data from columns and create Degree object
NS_SCHOOLDATA::Degree createDegreeObj(std::stringstream s){
    std::string column; //string to hold column value
    std::getline(s, column, ',');
    std::string major =  column;
    std::getline(s, column, ',');
    double start = parseStringToDouble(column);
    std::getline(s, column, ',');
    double med = parseStringToDouble(column);
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
    std::cout << start <<std::endl;
    std::cout << start <<std::endl;
    
    NS_SCHOOLDATA::Degree d(major, start, med, percent, m10, m25, m75, m90);
    return d;
}

int main(){
    using namespace NS_SCHOOLDATA;
    using namespace std;

    ifstream degreeFS; //using the degrees-that-pay-back.csv
    ifstream regionFS; //using the salaries-by-region.csv
    string degreeFile = "degrees-that-pay-back.csv";
    string regionFile = "salaries-by-region.csv";
    cout << "openning " << degreeFile << " file" << endl;

    vector<Degree> degreeList; //vector to hold degree objects

    //starting to read degreeFile
    degreeFS.open(degreeFile);
    if (!degreeFS.is_open()){
        cout << "Could not open degrees-that-payback.csv" <<endl;
        return 1;
    }
    
    string line, temp; //used to hold row in csv file
 

    getline(degreeFS, line); //read column headers

    while (degreeFS >> temp){ //loop to go through each row
        getline(degreeFS, line);
        stringstream ss; //used to contain row
        ss.clear();
        ss.str(line);
        Degree d = createDegreeObj(ss); //creation of degree object that holds csv data
        degreeList.push_back(d);
    }

    degreeFS.close();
    

    cout << "openning " << regionFile <<" file" << endl;
}

