#include <string>
#ifndef ALL_FUNCTIONS_H
#define ALL_FUNCTIONS_H
std::string* Spisok(long long base, long long& size);
long long stv(const std::string& sym, std::string* alph, long long size);
std::string vts(long long val, std::string* alph, long long size) ;
std::string add(const std::string& n1, const std::string& n2, std::string* alph, long long size);
std::string subtract(const std::string& n1, const std::string& n2, std::string* alph, long long size);
long double validate_input(const std::string& prompt);
std::string validate_string_input(const std::string& prompt);
void handle_operation();
int askToRunProgram() ;
#endif
