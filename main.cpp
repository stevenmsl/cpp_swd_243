#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol243;

/*
words: ["practice", "makes", "perfect", "coding", "makes"]
Input: word1 = “coding”, word2 = “practice”
Output: 3
*/

tuple<vector<string>, string, string, int> testFixture1()
{
  return make_tuple(vector<string>{"practice", "makes", "perfect", "coding", "makes"},
                    "coding", "practice", 3);
}

/*
words: ["practice", "makes", "perfect", "coding", "makes"]
Input: word1 = "makes", word2 = "coding"
Output: 1
*/

tuple<vector<string>, string, string, int> testFixture2()
{
  return make_tuple(vector<string>{"practice", "makes", "perfect", "coding", "makes"},
                    "makes", "coding", 1);
}

void test1()
{
  auto f = testFixture1();
  cout << "Test 1 " << endl;
  cout << "Expect to see " << to_string(get<3>(f)) << endl;
  Solution sol;
  cout << to_string(sol.find(get<0>(f), get<1>(f), get<2>(f))) << endl;
}

void test2()
{
  auto f = testFixture2();
  cout << "Test 2 " << endl;
  cout << "Expect to see " << to_string(get<3>(f)) << endl;
  Solution sol;
  cout << to_string(sol.find(get<0>(f), get<1>(f), get<2>(f))) << endl;
}

main()
{
  test1();
  test2();
  return 0;
}