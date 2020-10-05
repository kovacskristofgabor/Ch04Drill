#include "std_lib_facilities.h"

using namespace std;

constexpr double cm_m_conv_ratio {0.01};

constexpr double in_m_conv_ratio {2.54*cm_m_conv_ratio};

constexpr double ft_m_conv_ratio {12.0*in_m_conv_ratio};

const vector<string> legal_units {"m", "cm", "in", "ft"};

bool is_legal_unit(string unit)

{
    bool is_legal {false};

    for (string legal_unit: legal_units)
        if (legal_unit == unit)
            is_legal = true;

    return is_legal;
}

double convert_to_mts(double amount, string units)

{
    double mts {0};

    if (units == "ft")
        mts = amount*ft_m_conv_ratio;
    else if (units == "in")
        mts = amount*in_m_conv_ratio;
    else if (units == "cm")
        mts = amount*cm_m_conv_ratio;
    else
        mts = amount;

    return mts;
}

void print_legal_units()
{
    cout << "\tm mint méter\n" << "\tcm mint centiméter\n"
        << "\tin mint inch\n" << "\tft mint láb\n";
}

int main()

{
    double a {0}; 
    string unit {""};
    double mts {0};
    double smallest {0}; 
    double largest {0}; 
    double sum {0};
    int count {0};
    vector<double> values;
    
    cout.precision(15);

    cout << "Írj be egy számot majd utána egy mértékegységet:\n";
    print_legal_units();

    while (cin >> a >> unit){
        if (is_legal_unit(unit)){
            mts = convert_to_mts(a, unit);
            if (count == 0){
                cout << a << unit << " (" << mts << "m) "
                    << " a legelső szám, a legkisebb és a legnagyobb is egyben\n";
                smallest = mts;
                largest = mts;
            }
            else if (mts < smallest){
                cout << a << unit << " (" << mts << "m) "
                    << " a legkisebb szám eddig\n";
                smallest = mts;
            }
            else if (mts > largest){
                cout << a << unit << " (" << mts << "m) "
                    << " a legnagyobb szám eddig\n";
                largest = mts;
            }
            ++count;
            sum += mts;
            values.push_back(mts);
        }
        else {
            cout << unit << " ez egy nem megengedett mértékegység, kérlek használd ezeket:\n";
            print_legal_units();
        }
    }

    cout << "Legkisebb érték: " << smallest << " méter\n";
    cout << "Legnagyobb érték: " << largest << " méter\n";
    cout << "Értékek száma: " << count << '\n';
    cout << "Összérték: " << sum << " méter\n";

    cout << "Értékek listája növekvő sorrendben:\n";
    sort(values);
    for (double value: values)
        cout << '\t' << value << " méter\n";
    
    return 0;
}
