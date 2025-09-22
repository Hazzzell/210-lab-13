//COMSC-210-5293 | Lab 13 | Keng C Chan
//IDE used: Visual Studio Code (VS Code) 
#include <iostream>
#include <fstream>
#include <algorithm>  // for sort(), find()
#include <numeric>    // for accumulate()
#include <vector>
using namespace std;

const int DAYS = 30;

int main() {
    //declarations
    vector<double> temperatures;

    //Read data from external file
    ifstream infile("temperatures.txt");
    if (!infile) {
        cerr << "Error: Could not open file!" << endl;
        return 1;
    }

    double temp;
    while (infile >> temp) {
        temperatures.push_back(temp);
    }
    infile.close();
    
    //<vector> objects can report their own size, unlike C-style arrays
    cout << "1.  Size: " << temperatures.size() << endl;

    //range loop to access elements
    cout << "2.  Temperatures: ";
    for (double t : temperatures) cout << t << " "; cout << endl;

    //accessing individual elements
    cout << "3.  Element 2: " << temperatures.at(2) << endl;
    cout << "4.  Element 2: " << temperatures[2] << endl;
    cout << "5.  Front: " << temperatures.front() << endl;
    cout << "6.  Back: " << temperatures.back() << endl;
    cout << "7.  Is it Empty? " << (temperatures.empty() == 0? "False" : "True") << endl;
    cout << "8.  What's the Address? " << temperatures.data() << endl;

    // use iterators to sort ascending
    sort(temperatures.begin(), temperatures.end());
    cout << "9.  Sorted temperatures: ";
    for (double t : temperatures) cout << t << " "; cout << endl;
    // use iterators to sort descending
    sort(temperatures.rbegin(), temperatures.rend());
    cout << "10. Reverse sorted temperatures: ";
    for (double t : temperatures) cout << t << " "; cout << endl;

    // find an element
    double target = 75.0;   // search target
    vector<double>::iterator it;  // declare iterator to point to the found element
    it = find(temperatures.begin(), temperatures.end(), target);
    cout << "11. Value " << target;
    if (it != temperatures.end())
        cout << " found in position " << it - temperatures.begin() << endl;
    else
        cout << " was not found.\n";
    cout << "    Value: " << *it << endl;

    // find max & min & sum
    cout << "12. Max: " << *max_element(temperatures.begin(), temperatures.end()) << endl;
    cout << "13. Min: " << *min_element(temperatures.begin(), temperatures.end()) << endl;
    cout << "14. Sum: " << accumulate(temperatures.begin(), temperatures.end(), 0) << endl;

    // create empty <vector> and fill with one value
    vector<double> week1(7);
    fill(week1.begin(), week1.end(), 80.0);  // fill with 80°F
    cout << "15. Week1 temperatures: ";
    for (double t : week1) cout << t << " ";
    cout << endl;

    vector<double> week2(7);
    fill(week2.begin(), week2.end(), 70.0);  // fill with 70°F
    cout << "16. Week2 temperatures: ";
    for (double t : week2) cout << t << " ";
    cout << endl;

    // swap vector
    week1.swap(week2);
    cout << "17. After swap, week 1 temperatures: ";
    for (double t : week1) cout << t << " "; cout << endl;

    return 0;
}
