/* File: OnlyConnect.cpp
 *
 * TODO: Edit these comments to describe anything interesting or noteworthy in your implementation.
 * First we check if the string is not empty, if it is just return it.
 * Else, we start from the end of the phrase string and find the last (first from the end) non-consonant character,
 * then we remove that character, combine the two parts of the string if necesarry and resize it.
 * Then we call the function again recursively and pass in the string we got from the last step as an input.
 * This continues untill we hit a base case which is that every character in the string is consonants,
 * in that case, convert the string to upper case and return it.
 *
 * TODO: Edit these comments to leave a puzzle for your section leader to solve!
 * BCKTTHFTR
 */
#include "OnlyConnect.h"
#include <algorithm>
using namespace std;

// Array of vowels
char vowels[] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

// Check if char is consonant
bool isConsonant(char a)
{
    if (!isalpha(a))
    {
        return false;
    }

    for (auto vowel : vowels)
    {
        if (a == vowel)
        {
            return false;
        }
    }

    return true;
}

// Remove the char from the string at a given index and resize
string shrinkPhrase(string phrase, int index)
{
    if (phrase.length() == 1)
    {
        return "";
    }

    for (int i = index + 1; i < phrase.length(); i++)
    {
        phrase[i - 1] = phrase[i];
    }
    phrase.resize(phrase.length() - 1);
    return phrase;
}

string onlyConnectize(string phrase) {
    /* TODO: The next few lines just exist to make sure you don't get compiler
     * warning messages when this function isn't implemented. Delete this
     * comment and the next few lines, then implement this function.
     */
    //(void) phrase;

    if (phrase.length() != 0)
    {
        for (int i = phrase.length() - 1; i >= 0; i --)
        {
            if (!isConsonant(phrase[i]))
            {
                return onlyConnectize(shrinkPhrase(phrase, i));
            }
        }

        // make phrase uppercase
        transform(phrase.begin(), phrase.end(), phrase.begin(), ::toupper);
        return phrase;
    }

    return "";
}






/* * * * * * Provided Test Cases * * * * * */
#include "GUI/SimpleTest.h"

PROVIDED_TEST("Handles single-character inputs.") {
    EXPECT_EQUAL(onlyConnectize("A"), "");
    EXPECT_EQUAL(onlyConnectize("Q"), "Q");
}

PROVIDED_TEST("Converts lower-case to upper-case.") {
    EXPECT_EQUAL(onlyConnectize("lowercase"), "LWRCS");
    EXPECT_EQUAL(onlyConnectize("uppercase"), "PPRCS");
}

/* TODO: You will need to add your own tests into this suite of test cases. Think about the sorts
 * of inputs we tested here, and, importantly, what sorts of inputs we *didn't* test here. Some
 * general rules of testing:
 *
 *    1. Try extreme cases. What are some very large cases to check? What are some very small cases?
 *
 *    2. Be diverse. There are a lot of possible inputs out there. Make sure you have tests that account
 *       for cases that aren't just variations of one another.
 *
 *    3. Be sneaky. Don't just try standard inputs. Try weird ones that you wouldn't expect anyone to
 *       actually enter, but which are still perfectly legal.
 *
 * Happy testing!
 */

STUDENT_TEST("Handles inputs with spaces") {
    EXPECT_EQUAL(onlyConnectize("     "), "");
    EXPECT_EQUAL(onlyConnectize("   __HelloWorld!   "), "HLLWRLD");
}






