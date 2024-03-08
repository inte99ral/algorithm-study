/**
 * <regex> 라이브러리 http://www.cplusplus.com/reference/regex/
 * ECMAScript Grammar 사용 http://www.cplusplus.com/reference/regex/ECMAScript/
 * 
 * @author https://caniro.tistory.com/196
 */

#include <iostream>
#include <regex>

int         main()
{
    using namespace std;

    regex   re("\\d");
    //regex   re("[ab]");
    //regex   re("[[:digit:]]{3}");
    //regex   re("[A-Z]+");
    //regex   re("[A-Z]{3}");
    //regex   re("[A-Z]{1, 5}");
    //regex   re("([0-9]{1})([-]?)([0-9]{1,4})");
    //regex   re("([0]{1}[1]{1}[0-9]{1})([-]?)([0-9]{3,4})([-]?)([0-9]{4})");
    //regex   re("([[:digit:][:alpha:]]+)([@]{1})([[:digit:][:alpha:]]+)([.]{1})([[:alpha:]]+)");

    string  str;

    while (true)
    {
        getline(cin, str);

        if (std::regex_match(str, re))
            cout << "Match\n";
        else
            cout << "No match\n";

        auto begin = std::sregex_iterator(str.begin(), str.end(), re);
        auto end = std::sregex_iterator();
        for (auto itr = begin; itr != end; ++itr)
        {
            std::smatch match = *itr;
            cout << match.str() << ' ';
        }
        cout << endl;
    }
}

/* stdin
1
2
123
*/

/* stdout stderr
Match
1
Match
2
No match
1 2 3
*/