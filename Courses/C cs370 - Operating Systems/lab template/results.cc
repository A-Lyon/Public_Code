#include <iomanip>	// for right, setw
#include <iostream>
#include <map>
#include <string>

using namespace std;

template <typename T>
class BarGraph {
  public:
    void operator+=(const T &datum) {
        data[datum]++;
    }
    friend ostream& operator<< (ostream& out, const BarGraph<T>& barG ){
        for (auto& val : barG.data){
            out << right << setw(10) << val.first << ' ' << string(val.second, '*') << '\n';
        }
        out << '\n';
        return out;
    }
    //void dump(){}
	// for (const auto &val : data)
	//     cout << right << setw(10) << val.first << ' '
	// 	 << string(val.second, '*') << '\n';
    //     cout << '\n';
    //}
  private:
    map<T, unsigned> data;
};

template <>
class BarGraph<bool> {
    unsigned false_count = 0, true_count = 0;
  public:
    void operator+=(bool datum) {
	datum ? true_count++ : false_count++;
    }
    friend ostream& operator<< (ostream& out, const BarGraph<bool>& barG ){
        out << "     false " << string(barG.false_count, '*') << "\n"
               "      true " << string(barG.true_count,  '*') << "\n\n";
        return out;
    }
};

template<>
class BarGraph<char> {
    array<int, 128> arr = { 0 };
  public:
    void operator+=(int datum){
        //cout << (short)datum << '\n';
        arr[datum]++;
    }
    void operator+=(string datum){
        for(unsigned i = 0; i < datum.size(); i++){
            //cout << (short)c << '\n';
            arr[datum[i]]++;
            //cout << arr[(short)c];
        }
    }  

    friend ostream& operator<< (ostream& out, const BarGraph<char>& barG ){
        //int pointer = 0;
        for (int i = 0; i < 128; i++){
            int num = barG.arr[i];
            //cout << barG.arr[i] << '\n';
            if(num > 0){
                out << right << setw(10) << (char)(i) << ' ' << string(barG.arr[i], '*') << '\n';
             }
        }
        out << '\n';
        
        return out;
    }
};


int main() {
    BarGraph<int> alpha;
    alpha += 12;
    alpha += 6;
    alpha += 4;
    alpha += 6;
    cout << alpha;

    BarGraph<double> beta;
    beta += 3.14;
    beta += 2.71828;
    beta += 6.023e23;
    beta += 2.71828;
    cout << beta;

    BarGraph<bool> gamma;
    gamma += false;
    gamma += true;
    gamma += false;
    gamma += true;
    gamma += true;
    cout << gamma;

    BarGraph<char> delta;
    delta += 'G';
    delta += 'e';
    delta += 'o';
    delta += 'f';
    delta += 'f';
    delta += "Colorado";
    cout << delta;

    return 0;
}

