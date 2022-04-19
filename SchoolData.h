//
//  SchoolData.h
//  
//  collection of data from: https://www.kaggle.com/datasets/wsj/college-salaries?select=degrees-that-pay-back.csv
//  and: https://www.kaggle.com/datasets/wsj/college-salaries?select=salaries-by-region.csv
//  represented as a class object
//   
//  declarations of class:
//                          -Degrees
//                          -SchoolRegion
//
//created by: Hyok In Kwon

#ifndef SchoolData_h
#define SchoolData_h
#include <string>

namespace NS_SCHOOLDATA{
    using namespace std;
/**
 * relevant data:
 * 
 * for Degrees class:
 * 
 * major  : unique data of major
 * mStart : starting median salary
 * mMed   : mid-career median salary
 * percentChange: percent change from starting to mid-career salary
 * mid10  : mid-career 10th percentile salary
 * mid25  : mid-career 25th percentile salary
 * mid75  : mid-career 75th percentile salary
 * mid90  : mid-career 90th percentile salary
 * 
 */
class Degree{
public:

    Degree(string major,  double mStart,  double mMed,  double percent,  double mC10,  double mc25,  double mc75,  double mc90);
    
    //accessors
    string getMajor() const;   //return major
    double getStart() const;   //return starting median salary
    double getMed() const;     //return mid-career median salary
    double getPercent() const; //return percent change
    double getMid10() const;   //return mid-career 10th percentile salary
    double getMid25() const;   //return mid-career 25th percentile salary
    double getMid75() const;   //return mid-career 75th percentile salary
    double getMid90() const;   //return mid-career 90th percentile salary
    //mutators
    void setMajor(string newM);     //newM => major
    void setStart(double newS);     //newS => mStart
    void setMed(double newM);       //newM => mMed
    void setMid10(double newM);     //newM => mid10
    void setMid25(double newM);     //newM => mid25
    void setMid75(double newM);     //newM => mid75
    void setMid90(double newM);     //newM => mid90
private:
    string major;
    double mStart; // in dollars (output as fixed, setprecision(2))
    double mMed;   // in dollars
    double percentChange; // percentage
    double mid10;  // in dollars
    double mid25;  // in dollars
    double mid75;  // in dollars
    double mid90;  // in dollars
}
/*
* for SchoolRegion class:
 * 
 * name         : school name
 * region       : school region
 * mStart       : starting median salary
 * mMed         : mid-career median salary
 * mid10
 * mid25
 * mid75
 * mid90 
 * 
 */
class SchoolRegion{

public:

    SchoolRegion(string name, string region); //constructor with only name values as there are some missing values in some data 

    //accessors
    string getName() const;     //return name
    string getRegion() const;   //return region
    double getStart() const;    //return mStart
    double getMed() const;      //return mMed
    double getMid10() const;    //return mid10
    double getMid25() const;    //return mid25
    double getMid75() const;    //return mid75
    double getMid90() const;    //return mid90
    //mutators
    void setName(string newN);      //newN => name
    void setRegion(string newR);    //newR => region
    void setStart(double newS);     //newS => mStart
    void setMed(double newM);       //newM => mMed
    void setMid10(double newM);     //newM => mid10
    void setMid25(double newM);     //newM => mid25
    void setMid75(double newM);     //newM => mid75
    void setMid90(double newM);     //newM => mid90

private:

    string name;
    string region;
    double mStart;
    double mMed;
    double mid10;
    double mid25;
    double mid75;
    double mid90;
}
}
#endif
