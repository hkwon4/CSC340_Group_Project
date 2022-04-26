//
//  SchoolData.cpp
//  
//  collection of data from: https://www.kaggle.com/datasets/wsj/college-salaries?select=degrees-that-pay-back.csv
//  and: https://www.kaggle.com/datasets/wsj/college-salaries?select=salaries-by-region.csv
//  represented as a class object
//   
//  implementations and definitions of functions declared in SchoolData.h
//
//created by: Hyok In Kwon
//date created: 4/18/2022

#include "SchoolData.h"
#include <string>

namespace NS_SCHOOLDATA{

    /**
     * @brief Construct a new Degree:: Degree object
     * 
     * @param m 
     * @param Start 
     * @param Med 
     * @param percent 
     * @param m10 
     * @param m25 
     * @param m75 
     * @param m90 
     */

    Degree::Degree(string m,  double Start,  double Med,  double percent,  double m10,  double m25,  double m75,  double m90){
        major = m;
        mStart = mStart;
        mMed = Med;
        percentChange = percent;
        mid10 = m10;
        mid25 = m25;
        mid75 = m75;
        mid90 = m90;
    }
//accessors
    string Degree::getMajor() const{
        return major;
    }

    double Degree::getStart() const{
        return mStart;
    }

    double Degree::getMed() const{
        return mMed;
    }

    double Degree::getPercent() const{
        return percentChange;
    }

    double Degree::getMid10() const{
        return mid10;
    }

    double Degree::getMid25() const{
        return mid25;
    }

    double Degree::getMid75() const{
        return mid75;
    }

    double Degree::getMid90() const{
        return mid90;
    }
//mutators
    void Degree::setMajor(string newM){
        major = newM;
    }

    void Degree::setStart(double newS){
        mStart = newS;
    }

    void Degree::setMed(double newM){
        mMed = newM;
    }

    void Degree::setMid10(double newM){
        mid10 = newM;
    }

    void Degree::setMid25(double newM){
        mid25 = newM;
    }

    void Degree::setMid75(double newM){
        mid75 = newM;
    }

    void Degree::setMid90(double newM){
        mid90 = newM;
    }

    /**
     * @brief Construct a new School Region:: School Region object
     * 
     * @param sName 
     * @param sRegion 
     */
    SchoolRegion::SchoolRegion(string sName, string sRegion){
        name = sName;
        region = sRegion;
        mStart = 0.0;
        mMed = 0.0;
        mid10 = 0.0;
        mid25 = 0.0;
        mid75 = 0.0;
        mid90 = 0.0;
    }
//accessors
    string SchoolRegion::getName() const{
        return name;
    }

    string SchoolRegion::getRegion() const{
        return region;
    }

    double SchoolRegion::getStart() const{
        return mStart;
    }

    double SchoolRegion::getMed() const{
        return mMed;
    }

    double SchoolRegion::getMid10() const{
        return mid10;
    }

    double SchoolRegion::getMid25() const{
        return mid25;
    }

    double SchoolRegion::getMid75() const{
        return mid75;
    }

    double SchoolRegion::getMid90() const{
        return mid90;
    }
//mutators
    void SchoolRegion::setName(string newN){
        name = newN;
    }

    void SchoolRegion::setRegion(string newR){
        region = newR;
    }

    void SchoolRegion::setStart(double newS){
        mStart = newS;
    }

    void SchoolRegion::setMed(double newM){
        mMed = newM;
    }

    void SchoolRegion::setMid10(double newM){
        mid10 = newM;
    }

    void SchoolRegion::setMid25(double newM){
        mid25 = newM;
    }

    void SchoolRegion::setMid75(double newM){
        mid75 = newM;
    }

    void SchoolRegion::setMid90(double newM){
        mid90 = newM;
    }


}