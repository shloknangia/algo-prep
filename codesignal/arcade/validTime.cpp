// Check if the given string is a correct time representation of the 24-hour clock.

// Example

//     For time = "13:58", the output should be
//     validTime(time) = true;
//     For time = "25:51", the output should be
//     validTime(time) = false;
//     For time = "02:76", the output should be
//     validTime(time) = false.


#include<bits/stdc++.h>
using namespace std;

bool validTime(string time) {
    regex r("^((0[0-9]{1})|(1[0-9]{1})|(2[0-3]{1})):[0-5]{1}[0-9]{1}$");
    return regex_match(time, r);

}
