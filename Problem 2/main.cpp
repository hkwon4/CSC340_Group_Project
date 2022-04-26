//Created by Dexter and Antonio

#include "SchoolData.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <utility>
 

using namespace std;

//function to get the average
double getAverage(int count, double total){
    double avg = 0;
    
    
    avg = (total / count);
    
    return avg;
}

vector<pair<string, double>> paired(vector<string> RegionList, vector<double> salaryList){
    vector<pair<string, double>> pairValues;
    int countCA=0;
    int countWest = 0;
    int countMidWest = 0;
    int countSouth = 0;
    int countNorthEast = 0;
    
    double salaryCA=0;
    double salaryWest = 0;
    double salaryMidWest = 0;
    double salarySouth = 0;
    double salaryNorthEast = 0;
    
    double averageCA=0;
    double averageWest = 0;
    double averageMidWest = 0;
    double averageSouth = 0;
    double averageNorthEast = 0;
    
    string Region;
    int regionVal = 0;
    for(int i = 0; i < RegionList.size(); i++){
        Region = RegionList.at(i);

        if(Region == "California"){
        regionVal = 1;
            salaryCA += salaryList.at(i);
    }else if(Region == "Western"){
        regionVal = 2;
        salaryWest += salaryList.at(i);

    }else if(Region == "Midwestern"){
        regionVal = 3;
        salaryMidWest += salaryList.at(i);

    }else if(Region == "Southern"){
        regionVal = 4;
        salarySouth += salaryList.at(i);

    }else if(Region == "Northeastern"){
        regionVal = 5;
        salaryNorthEast += salaryList.at(i);

    }
    
    
    switch (regionVal) {
        case 1:
            countCA++;
            
            break;
        case 2:
            countWest++;
            break;
        case 3:
            countMidWest++;
            break;
        case 4:
            countSouth++;
            break;
        case 5:
            countNorthEast++;
            break;
        default:
            break;
    }
        
    }
    
    // for CA
     averageCA = getAverage(countCA, salaryCA);
     pairValues.push_back(make_pair("California", averageCA));
   // for Western
    averageWest = getAverage(countWest, salaryWest);
    pairValues.push_back(make_pair("Western", averageWest));
   //midWest
    averageMidWest = getAverage(countMidWest, salaryMidWest);
    pairValues.push_back(make_pair("MidWest", averageMidWest));
  //South
    averageSouth = getAverage(countSouth, salarySouth);
    pairValues.push_back(make_pair("Southern", averageSouth));
    //NorthEast
    averageNorthEast = getAverage(countNorthEast, salaryNorthEast);
    pairValues.push_back(make_pair("NorthEastern", averageNorthEast));
    return pairValues;
    
}
