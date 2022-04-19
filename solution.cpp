#include "solution.h"
#include "util.h"
#include <unordered_set>
#include <algorithm>
#include <iterator>
#include <unordered_map>
#include <set>
#include <cstring>
using namespace sol243;
using namespace std;

/*takeaways
  - scan the dictionary once
  - scenario 1
    ...w1...w1...w2...
    - we will calculate the distance only once
      as we always record what's the index
      last time we found w1 or w2. In this
      case, when we are visiting w2, we will
      subtract its index to the last index
      we found which is for w1
  - scenario 2
    ...w2...w1...w1
    - we will calculate the distance only once
    - when you are visiting the second w1
      , since last time you also visited
      a w1, which if the first w1 was used to calculate
      for the distance, the current w1 we are visiting
      would not help as we know it's further away
      from the w2 when comparing to the first w1
*/

int Solution::find(vector<string> &words, string w1, string w2)
{
  auto dist = INT_MAX;

  auto visited = 0, visitng = 0, indexLastFound = -1;

  for (auto i = 0; i < words.size(); i++)
  {
    /* don't forget to reset this as if
       the word is not w1 or w2 we will
       not do anything
     */
    visitng = 0;
    if (words[i] == w1 || words[i] == w2)
      visitng = words[i] == w1 ? 1 : 2;

    /* calculate the distance if we are
       visiting two different words
       consecutively
    */
    if (visited && visitng && visited != visitng)
      dist = min(dist, i - indexLastFound);

    /* if we keep visiting the same word and the other
       word has not been visited before then the other
       word must be on further right. Updating the
       indexLastFound to a larger value will make sure
       the edit distance calculated later is the shorter
       one
    */
    if (visitng)
      visited = visitng, indexLastFound = i;
  }

  return dist;
}