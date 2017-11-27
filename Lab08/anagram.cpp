#include <iostream>
#include <string>
using namespace std;
int length_of_line(string input)
{
  //Accumulates the amount of characters in a string, excluding whitespace
  int pre_length(input.length()), length_line(0);
  for(int i = 0; i < pre_length; i++)
  {
    if(!isspace(input[i]))
    {
      length_line++;
    }
  }
  return length_line;
}
string alphabet_counter(string input, int length, int alphabet_1[26])
{
  //
  string alphabet_counts("");
  for(int i = 0; i < length; i++)
  {
    if(isalpha(input[i]))
    {
      int char_val(static_cast<int>(input[i]));
      if(char_val <= 90)
      {
        alphabet_1[char_val - 65] += 1;
      }
      else
      {
        alphabet_1[char_val - 97] += 1;
      }
    }
  }
  for(int i = 0; i < 26; i++)
  {
    alphabet_counts += alphabet_1[i];
  }
  return alphabet_counts;
}
int main()
{
  int alphabet_1[26] = {0}, alphabet_2[26] = {0}, length_1(0), length_2(0);
  string input_1(""), input_2(""), alphabet_counts_1(""), alphabet_counts_2("");

  cout << "Enter first string:" << endl;
  getline(cin,input_1);
  length_1 = length_of_line(input_1);
  alphabet_counts_1 = alphabet_counter(input_1, length_1, alphabet_1);

  cout << "Enter second string:" << endl;
  getline(cin,input_2);
  length_2 = length_of_line(input_2);
  alphabet_counts_2 = alphabet_counter(input_2, length_2, alphabet_2);

  if(alphabet_counts_1 == alphabet_counts_2)
  {
    cout << "The strings are anagrams." << endl;
  }
  else
  {
    cout << "The strings are not anagrams." << endl;
  }
}
