/*
There is a definition of an Example class. Please redefine it with class template. You need not define the member functions.
*/

// class Example
// {
// private:
//   int size;
//   double *parray;
//   double _min;
//   double _max;

// public:
//   Example(double min, double max);
//   Example(const double *array, int size);

//   double& operator[](int index);
//   bool operator==(const Example&) const;
//   bool insert(const double*, int);
//   bool insert(double);

//   double min() const; 
//   double max() const; 
//   void min(double);
//   void max(double);

//   ~Example();

// };


template <typename T>
class Example {
private:
  int size;
  T* parray;
  T _min;
  T _max;

public:
  Example(T min, T max);
  Example(const T* array, int size);

  T& operator[](int index);
  bool operator==(const Example<T>&) const;
  bool insert(const T*, int);
  bool insert(T);

  T min() const;
  T max() const;
  void min(T);
  void max(T);

  ~Example();
};
