#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <string>
#include <vector>

using namespace std;

// ---------------------------------------------

class Wrong {};

// ---------------------------------------------

char rand_char(const string &set);

string rand_string(size_t length, bool has_digits = true,
                   bool has_uppercase = true, bool has_lowercase = true);

string rand_string(size_t length, const string &set);

bool rand_bool();

template <typename T>
T choice(vector<T> vec);

template <typename T, size_t N>
T choice(T (&arr)[N]);

template <typename X, typename A>
inline void Assert(A assertion);

// ---------------------------------------------

const string DIGITS = "0123456789";
const string UPPERCASE = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string LOWERCASE = "abcdefghijklmnopqrstuvwxyz";

unsigned seed = chrono::system_clock::now().time_since_epoch().count();
default_random_engine gen(seed);

char rand_char(const string &set) { return set[rand() % set.size()]; }

string rand_string(size_t length, bool has_digits, bool has_uppercase,
                   bool has_lowercase) {
  string set;
  if (has_digits) set += DIGITS;
  if (has_uppercase) set += UPPERCASE;
  if (has_lowercase) set += LOWERCASE;
  string str(length, 0);
  for (char &c : str) c = rand_char(set);
  return str;
}

string rand_string(size_t length, const string &set) {
  string str(length, 0);
  for (char &c : str) c = rand_char(set);
  return str;
}

bool rand_bool() {
  uniform_int_distribution<int> uni(0, 1);
  return bool(uni(gen));
}

template <typename T>
T choice(vector<T> vec) {
  uniform_int_distribution<int> uni(0, vec.size() - 1);
  return vec[uni(gen)];
}

template <typename T, size_t N>
T choice(T (&arr)[N]) {
  uniform_int_distribution<int> uni(0, N - 1);
  return arr[uni(gen)];
}

template <typename X, typename A>
inline void Assert(A assertion) {
  if (!assertion) throw X();
}

// int main() {
//   int arr[5]{0, 1, 2, 3, 4};
//   cout << choice<int>(arr) << endl;
//   vector<char> vec{'0', '1', '2', '3', '4'};
//   cout << choice<char>(vec) << endl;
// }