//
//  DesignDoc.h
//  SchoolData and main function codes
//
//  Created in 4/20.
//  Written By: Hyok In Kwon

/* 
From SchoolData.h
Degree class:
used to store data from degrees-that-pay-back.csv as objects
variables:
    -string major
    -double mStart
    -double mMed
    -double mid10
    -double mid25
    -double mid75
    -double mid90

SchoolRegion class:
used to store data from salaries-by-region.csv
variables:
    -string name
    -string region
    -double mStart
    -double mMed
    -double mid10
    -double mid25
    -double mid75
    -double mid90

From main.cpp

double parseStringToDouble(string number)
-function takes a string thats a number and turns it into a double
algorithm:
    create double variable n = 0.0
    if (number == "N/A")
        return n
    else
        return n = std::stod(number)



string formatFile(string fileName)
-function processes a file by removing quotations, dollar signs, and extraneous commas
-algorithm:
    open file fileName
    open output file fileOutput //name of file will be fileName+"_processed"
    getline from fileName //removes column headers
    string line   
    while (getline(fileName, line) //loop to go through line
        size_t begin = 0; //index of open quotation
        size_t end = 0; //index of closing quotation
        begin = find index of quotation
        while (begin != std::string::npos)
            if (begin == npos)
                break
            end = find next quotation at begin+1
            for (size_t i = begin; i < end; i++)
                if (line.at(i) == '$' || line.at(i) == ',')
                    line.erase(i)
            begin = end + 1
        fileOutput << line << endl
        getline(fileName, line)
    close fileName
    close fileOutput
    return string fileOutputName

Degree createDegreeObj(stringstream& s)
-function parses through line of file to create new Degree object and return it
algorithm:
    string column
    getline(s, column, ',') //comma delimiter
    string major = column
    getline(s, column, ',')
    double (variable name) = column
    .
    . (repeat for as many variables)
    .
    Degree d(major, variable, . . . )
    return d

SchoolRegion createSRObj(stringstream& s)
-function parses through line of file to create new SchoolRegion object and returns it
algorithm:
    string column
    getline(s, column, ',') //comma delimiter
    string name = column
    getline(s, column, ',')
    string region = column
    getline(s, column, ',')
    double start = parseStringToDouble(column)
    .
    .
    .
    Region r(name, region)
    r.setStart(start)
    .
    .
    .
    return r


** End-of-DesignDoc_h 
*/