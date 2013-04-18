#include <iostream>
#include <cmath>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

bool check_square(int input){
  float calc_tmp = 0;
  calc_tmp = sqrt(input);
  if (calc_tmp == floor(sqrt(input))){
    return true;
  } else {
    return false;
  }
}

bool check_palindrom(int input) {
  string converted_input;

  if (input < 10) {
    return true;
  } else {
    ostringstream converter;
    converter << input;
    converted_input = converter.str();
    int end = converted_input.size()-1;

    for (int start = 0; start <= end; start++) {
      if (converted_input[start] != converted_input[end]){
        return false;
      } else {
        end--;
      }
    }
  }
  input = sqrt(input);
  if( check_square(input) == false){
    if (check_palindrom(input) == true){
      return true;
    } else {
      return false;
    }
  } else {
    return true;
  }
}

void build_cache(){
  string str_tmp;
  string tmp;
  int test_cases;
  long double start, end;

  ofstream output_file;
  output_file.open("cache", ios::out);

  start = 0;
  end = 1000000000000000000;

  for (long double a=start; a <=end; a++){
    if(check_square(a)){
      if (check_palindrom(a))
        output_file << a << endl;
    }
  }

  output_file.close();
}

int main(){
  build_cache();
  return 0;
}