#ifndef ALL_FUNCTIONS_H
#define ALL_FUNCTIONS_H
int Edinicy(int n) ;
int askToRunProgram();
void Groopy(int groops[], int size);
void getOneBit(int n, int indices[], int& count);
void FindGroup(const int groops[], bool slaves[], const bool barrels[], int groops_size);
int NumberGroup_Barr(const bool slaves[], int slaves_size);
void UpdateSurvivingSlaves(bool slaves[], int slaves_size);
void findBarrel(int number, const int groops[], bool slaves[], const bool barrels[], int slaves_size);
#endif
