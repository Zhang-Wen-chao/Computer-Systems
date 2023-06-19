/*
A template class named Pair is defined as follows. Please implement the overloading operator< which compares the value of the key, if  this->key is smaller than that of p.key, return true. Then define a friend function to overload << operator which displays the Pair’s data members. At last, run the program. The output sample is as follows:
*/

#include <iostream>
#include <string>
using namespace std;

template <class T1, class T2>
class Pair {
public:
  T1 key;
  T2 value;
  Pair(T1 k, T2 v) : key(k), value(v) { }
  bool operator<(const Pair<T1, T2>& p) const;

  // Declare the friend function for overloading the << operator
  template <class U1, class U2>
  friend ostream& operator<<(ostream& os, const Pair<U1, U2>& p);
};

// Implement the operator< for Pair class
template <class T1, class T2>
bool Pair<T1, T2>::operator<(const Pair<T1, T2>& p) const {
  return key < p.key;
}

// Define the friend function to overload the << operator
template <class U1, class U2>
ostream& operator<<(ostream& os, const Pair<U1, U2>& p) {
  os << "Key: " << p.key << ", Value: " << p.value;
  return os;
}

int main() {
  Pair<string, int> one("Tom", 19);
  Pair<string, int> two("Alice", 20);

  if (one < two)
    cout << one;
  else
    cout << two;

  return 0;
}
