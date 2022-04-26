
//function to get the average
double getAverage(int count, double total) {
    double avg = 0;

    avg = (total / count);

    return avg;
}

/*pair<string, double>*/ double paired(vector<string> RegionList, vector<double> salaryList) {
    pair<string, double> pairValues;
    int countCA = 0;
    int countWest = 0;
    int countMidWest = 0;
    int countSouth = 0;
    int countNorthEast = 0;

    double salaryCA = 0;
    double salaryWest = 0;
    double salaryMidWest = 0;
    double salarySouth = 0;
    int salaryNorthEast = 0;


    string Region;
    int regionVal = 0;
    for (int i = 0; i < RegionList.size(); i++) {
        Region = RegionList.at(i);

        if (Region == "California") {
            regionVal = 1;
            salaryCA += salaryList.at(i);
        }
        else if (Region == "Western") {
            regionVal = 2;
            salaryWest += salaryList.at(i);

        }
        else if (Region == "Midwestern") {
            regionVal = 3;
            salaryMidWest += salaryList.at(i);

        }
        else if (Region == "Southern") {
            regionVal = 4;
            salarySouth += salaryList.at(i);

        }
        else if (Region == "Northeastern") {
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

    double average = getAverage(countCA, salaryCA);

    return average;

}

int main()
{
    vector<string> regions = { "California", "California", "Western", "Southern", "Northeastern" };
    vector<double> values = { 100.00, 250.50,300.45,45.73,50.50 };
    cout << paired(regions, values) << endl;
    return 0;
}

