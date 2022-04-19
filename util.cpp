#include <string>
#include <sstream>
#include "node.h"
#include "util.h"

using namespace std;
using namespace sol243;

string Util::toString(vector<string> input)
{
    string result = "[";
    for (auto e : input)
    {
        result += e;
        result += ",";
    }
    /* remove the last comma */
    if (result.back() == ',')
        result.pop_back();
    result += "]";
    return result;
}

string Util::toString(vector<int> input)
{
    string result = "[";
    for (auto e : input)
    {
        result += to_string(e);
        result += ",";
    }
    /* remove the last comma */
    if (result.back() == ',')
        result.pop_back();
    result += "]";
    return result;
}

string Util::toString(vector<vector<int>> input)
{
    string result = "[";
    for (auto i : input)
        result += toString(i), result += ",";
    if (result.back() == ',')
        result.pop_back();
    result += "]";
    return result;
}

string Util::toString(vector<vector<string>> input)
{
    string result = "[";
    for (auto i : input)
        result += toString(i), result += ",";
    if (result.back() == ',')
        result.pop_back();
    result += "]";
    return result;
}

/* delimiter is the sapce */
vector<string> Util::split(string input)
{
    auto ss = stringstream(input);
    auto result = vector<string>();
    string token;
    while (ss >> token)
    {
        result.push_back(token);
    }
    return result;
}
vector<string> Util::split(string input, char delimiter)
{
    auto ss = stringstream(input);
    auto result = vector<string>();
    string token;
    while (getline(ss, token, delimiter))
    {
        result.push_back(token);
    }
    return result;
}
