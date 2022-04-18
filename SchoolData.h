//
//  DataVariables.h
//  
//  collection of data from: https://www.kaggle.com/datasets/wsj/college-salaries?select=degrees-that-pay-back.csv
//  and: https://www.kaggle.com/datasets/wsj/college-salaries?select=salaries-by-region.csv
//  represented as a class object
//   
//  declarations of class:
//                          -Degrees
//                          -SchoolRegion

#ifndef SchoolData_h
#define SchoolData_h
#include <string>

namespace NS_SCHOOLDATA{
/**
 * relevant data:
 * 
 * for Degrees class:
 * 
 * Major  : unique data of major
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
    string getMajor() const;
     double getStart() const;
     double getMed() const;
     double getPercent() const;
     double getMid10() const;
     double getMid25() const;
     double getMid75() const;
     double getMid90() const;

     void setMajor(string newM);
     void setStart(double newS);
     void setMed(double newM);
     void setMid10(double newM);
     void setMid25(double newM);
     void setMid75(double newM);
     void setMid90(double newM);
private:
    string major;
     double mStart;
     double mMed;
     double percentChange;
     double mid10;
     double mid25;
     double mid75;
     double mid90;
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

    SchoolRegion(string name, string region, double mStart, double mMed, double mid10, double mid25, double mid75, double mid90);

    string getName() const;
    string getRegion() const;
    double getStart() const;
    double getMed() const;
    double getMid10() const;
    double getMid25() const;
    double getMid75() const;
    double getMid90() const;

    void setName(string newN);
    void setRegion(string newR);
    void setStart(double newS);
    void setMed(double newM);
    void setMid10(double newM);
    void setMid25(double newM);
    void setMid75(double newM);
    void setMid90(double newM);

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