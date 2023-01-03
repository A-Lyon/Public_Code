#include <algorithm>
#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <typeinfo>

using namespace std;

int main() {
    vector<short> pi = {3,1,4,1,5,9,2,6,5,3,5,8,9,7,9,3,2,3,8,4,6,2,6,4};
    string alpha="abcdefghijklmnopqrstuvwxyz", digits="0123456789";
    char cbuf[100] = { };	// contains 100 '\0' chars
    list<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    short powers[] = {1,2,4,8,16,32,64};
    int ibuf[100];		// contains unknown values

    cout << "Exercise 0\n";
    copy(alpha.begin(), alpha.end(), cbuf);
    cout << cbuf << '\n';

    cout << "Exercise 1\n";
    reverse(begin(cbuf), end(cbuf));
    for(auto c: cbuf)
        cout << c;
    cout << '\n';

    cout << "Exercise 2\n";
    //auto inc_by = [](auto i) {return i + 1;};
    transform(primes.begin(), primes.end(), ibuf, [](auto i) {return i + 1;} );
    for (int i; i < 10; i++)
        cout << ibuf[i] << ' ';
    cout << '\n';

    cout << "Exercise 3\n";
    if(any_of(primes.begin(), primes.end(), [](auto i) {return i/2;} ))
        cout << "div 2\n";
    if(any_of(primes.begin(), primes.end(), [](auto i) {return i/42;} ))
        cout << "div 42\n";

    cout << "Exercise 4\n";
    auto found = find(primes.begin(), primes.end(), 13);
    *found++;
    cout << *found << '\n';

    cout << "Exercise 5\n";
    cout << count(pi.begin(), pi.end(), 3) << '\n';

    cout << "Exercise 6\n";
    cout << count_if(pi.begin(), pi.end(), [](auto i) {return i < 5; }) << '\n';

    cout << "Exercise 7\n";
    cout << *max_element(pi.begin(), pi.end()) << '\n';

    cout << "Exercise 8\n";
    sort(pi.begin(), pi.end());
    for(auto i: pi)
        cout << i << " ";
    cout << '\n';

    cout << "Exercise 9\n";
    auto lower = lower_bound(pi.begin(), pi.end(), 7);
    //cout << *lower << '\n';
    auto dist = lower - pi.begin();
    cout << dist << '\n';

    cout << "Exercise 10\n";

    //for(auto a: ibuf)
     //   cout << a << ' ';

    auto last = set_intersection(pi.begin(), pi.end(), begin(powers), end(powers), ibuf);
    //cout << *last << '\n';

    for(auto iterator = begin(ibuf); iterator != last; iterator++)
        cout << *iterator << ' ';
    cout << '\n';    

}


/*
********************************
Take aways:*********************

Algorithms have 'half-open' intervals (usually pointers). first arg is included, second is not.
For example, the copy() algorithm takes three arguments:

first (beginning of input range)
last (one past the end of input range)
d_first (start of output)

The copy() algorithm copies the half-open interval [first, last ) to d_first]   runs last - first range

********************************
Questions:**********************

Why use alpha.begin(), but then begin(cbuf)  is it because alpha is a string and that has the begin method?


*/