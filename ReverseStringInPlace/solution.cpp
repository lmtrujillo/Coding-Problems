#include <iostream>
#include <string>

// C++11 lest unit testing framework
#include "lest.hpp"

using namespace std;

void reverse(string& str)
{
    // reverse the input string in place
    int last = str.length() -1;
    int first = 0;
    while(first<last){
        int temporal = str[first];
        str[first] = str[last];
        str[last] = temporal;
        first++;
        last--;
    }
}


// tests

const lest::test tests[] = {
    {CASE("empty string") {
        const string expected;
        string actual;
        reverse(actual);
        EXPECT(actual == expected);
    }},
    {CASE("single character string") {
        const string expected("A");
        string actual("A");
        reverse(actual);
        EXPECT(actual == expected);
    }},
    {CASE("longer string") {
        const string expected("EDCBA");
        string actual("ABCDE");
        reverse(actual);
        EXPECT(actual == expected);
    }},
    {CASE("longer pair string") {
        const string expected("CEDBAX");
        string actual("XABDEC");
        reverse(actual);
        EXPECT(actual == expected);
    }}
};

int main(int argc, char** argv)
{
    return lest::run(tests, argc, argv);
}