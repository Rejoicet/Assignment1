#include <iostream>                 //for input output operations
#include <fstream>                  //to input and output from a file
#include <string>                   //to use strings
#include <cmath>                    //to use math functions like square root
#include <cstdlib>                  //to use rand function
#include <ctime>                    //to initialize srand function to time(NULL)
#include <algorithm>                //to use transform function
using namespace std;

int main() {
  float Totallength = 0, Numberofstr = 0, Mean, var = 0, Variance = 0, StdDev;
  float SingleProbOfA, SingleProbOfC, SingleProbOfG, SingleProbOfT;
  float BigramProbofAA, BigramProbofAT, BigramProbofAC, BigramProbofAG;
  float BigramProbofCA, BigramProbofCT, BigramProbofCC, BigramProbofCG;
  float BigramProbofTA, BigramProbofTT, BigramProbofTC, BigramProbofTG;
  float BigramProbofGA, BigramProbofGT, BigramProbofGC, BigramProbofGG;
  float TotBigramOutcomes = 0;
  float a, b, c, d;
  float A = 0, C = 0, T = 0, G = 0;
  float MakeupA = 0, MakeupT = 0, MakeupC = 0, MakeupG = 0;
  float newA, newT, newC, newG;
  const float pi = 3.1415927;

  char letter;
  char prompt = 'Y';

  int AAnum = 0, ACnum = 0, ATnum = 0, AGnum = 0;
  int CAnum = 0, CCnum = 0, CTnum = 0, CGnum = 0;
  int TAnum = 0, TCnum = 0, TTnum = 0, TGnum = 0;
  int GAnum = 0, GCnum = 0, GTnum = 0, GGnum = 0;

  ifstream DNAfile;                   //to read from a file

  string filename, str, bigram;

  while (prompt == 'Y' || prompt == 'y') {      /*prompted at the end of the execution*/

  cout << "Please enter the exact name of the file along with its extension to process: " << endl;
  cin >> filename;

  DNAfile.open(filename);     /*Opens the specified file name. Sum and Mean calculations begin.*/

  if (!DNAfile) {             //Exception if error in opening file
    cout << "Unable to open the file. Please check the following and run the program again -" << endl;
    cout << "1 - File is not open already" << endl;
    cout << "2 - Check some other program is not using it" << endl;
    cout << "3 - File name/path is correct" << endl;
    exit(1);
  }

  while (DNAfile >> str) {            //reading the file string by string
    Totallength = Totallength + str.length();
    ++Numberofstr;
  }

Mean = Totallength/Numberofstr;       //Mean calculation

DNAfile.close ();                     //Closing the file that is open

DNAfile.open(filename);     //Variance and Std Deviation calculation begin

if (!DNAfile) {
  cout << "Unable to open the file. Please check the following and run again -" << endl;
  cout << "1 - File is not open already" << endl;
  cout << "2 - Check some other program is not using it" << endl;
  cout << "3 - File name/path is correct" << endl;
  exit(1);
}

while (DNAfile >> str) {
  var = pow((str.length() - Mean), 2);

  Variance = Variance + var;        //Summation of the above calculation
}

Variance = Variance/Numberofstr;    //Variance calculation
StdDev = sqrt (Variance);           //Standard deviation calculation

DNAfile.close();

DNAfile.open(filename);   //Single probability calculations begin

if (!DNAfile) {
  cout << "Unable to open the file. Please check the following -" << endl;
  cout << "1 - File is not open already" << endl;
  cout << "2 - Check some other program is not using it" << endl;
  cout << "3 - File name/path is correct" << endl;
  exit(1);
}

 while (DNAfile >> letter) {        //Reading the file characer by character
   letter = toupper(letter);        //Converting each character to uppercase
   if (letter == 'A') {
     A++;
   }
   else if (letter == 'C') {
     C++;
   }
   else if (letter == 'T') {
     T++;
   }
   else if (letter == 'G') {
     G++;
   }

SingleProbOfA = A/Totallength;
SingleProbOfC = C/Totallength;
SingleProbOfT = T/Totallength;
SingleProbOfG = G/Totallength;

 }

DNAfile.close ();

DNAfile.open(filename);   //Bigram probability calculation begin

if (!DNAfile) {
  cout << "Unable to open the file. Please check the following -" << endl;
  cout << "1 - File is not open already" << endl;
  cout << "2 - Check some other program is not using it" << endl;
  cout << "3 - File name/path is correct" << endl;
  exit(1);
}

while (DNAfile >> bigram) {   //Reading file string by string
  transform (bigram.begin(), bigram.end(), bigram.begin(), ::toupper); /*Converting each string to uppercase*/
  cout << "Bigram: " << bigram << endl;
  {
    size_t nPosAA = bigram.find("AA", 0);  /*Storing the position of the first AA*/
    while (nPosAA != string::npos){   //until the position is not end of string
      AAnum++;
      nPosAA = bigram.find("AA", nPosAA+2); /*+2 as we it's a bigram and we have to skip the immediate next*/
  }
  }
  {
    size_t nPosAC = bigram.find("AC", 0);
    while (nPosAC != string::npos){
      ACnum++;
      nPosAC = bigram.find("AC", nPosAC+2);
  }
  }
  {
    size_t nPosAT = bigram.find("AT", 0);
    while (nPosAT != string::npos){
      ATnum++;
      nPosAT = bigram.find("AT", nPosAT+2);
  }
  }
  {
    size_t nPosAG = bigram.find("AG", 0);
    while (nPosAG != string::npos){
      AGnum++;
      nPosAG = bigram.find("AG", nPosAG+2);
  }
  }
  {
    size_t nPosCA = bigram.find("CA", 0);
    while (nPosCA != string::npos){
      CAnum++;
      nPosCA = bigram.find("CA", nPosCA+2);
  }
  }
  {
    size_t nPosCT = bigram.find("CT", 0);
    while (nPosCT != string::npos){
      CTnum++;
      nPosCT = bigram.find("CT", nPosCT+2);
  }
  }
  {
    size_t nPosCC = bigram.find("CC", 0);
    while (nPosCC != string::npos){
      CCnum++;
      nPosCC = bigram.find("CC", nPosCC+2);
  }
  }
  {
    size_t nPosCG = bigram.find("CG", 0);
    while (nPosCG != string::npos){
      CGnum++;
      nPosCG = bigram.find("CG", nPosCG+2);
  }
  }
  {
    size_t nPosTA = bigram.find("TA", 0);
    while (nPosTA != string::npos){
      TAnum++;
      nPosTA = bigram.find("TA", nPosTA+2);
  }
  }
  {
    size_t nPosTC = bigram.find("TC", 0);
    while (nPosTC != string::npos){
      TCnum++;
      nPosTC = bigram.find("TC", nPosTC+2);
  }
  }
  {
    size_t nPosTT = bigram.find("TT", 0);
    while (nPosTT != string::npos){
      TTnum++;
      nPosTT = bigram.find("TT", nPosTT+2);
  }
  }
  {
    size_t nPosTG = bigram.find("TG", 0);
    while (nPosTG != string::npos){
      TGnum++;
      nPosTG = bigram.find("TG", nPosTG+2);
  }
  }
  {
    size_t nPosGA = bigram.find("GA", 0);
    while (nPosGA != string::npos){
      GAnum++;
      nPosGA = bigram.find("GA", nPosGA+2);
  }
  }
  {
    size_t nPosGT = bigram.find("GT", 0);
    while (nPosGT != string::npos){
      GTnum++;
      nPosGT = bigram.find("GT", nPosGT+2);
  }
  }
  {
    size_t nPosGC = bigram.find("GC", 0);
    while (nPosGC != string::npos){
      GCnum++;
      nPosGC = bigram.find("GC", nPosGC+2);
  }
  }
  {
    size_t nPosGG = bigram.find("GG", 0);
    while (nPosGG != string::npos){
      GGnum++;
      nPosGG = bigram.find("GG", nPosGG+2);
  }
  }
}

DNAfile.close ();

DNAfile.open(filename);   //Bigram probabilities - 2

if (!DNAfile) {
  cout << "Unable to open the file. Please check the following -" << endl;
  cout << "1 - File is not open already" << endl;
  cout << "2 - Check some other program is not using it" << endl;
  cout << "3 - File name/path is correct" << endl;
  exit(1);
}

while (DNAfile >> bigram){
  TotBigramOutcomes = TotBigramOutcomes + (bigram.length() - 1);
}

BigramProbofAA = AAnum/TotBigramOutcomes;
BigramProbofAT = ATnum/TotBigramOutcomes;
BigramProbofAC = ACnum/TotBigramOutcomes;
BigramProbofAG = AGnum/TotBigramOutcomes;
BigramProbofCA = CAnum/TotBigramOutcomes;
BigramProbofCT = CTnum/TotBigramOutcomes;
BigramProbofCC = CCnum/TotBigramOutcomes;
BigramProbofCG = CGnum/TotBigramOutcomes;
BigramProbofTA = TAnum/TotBigramOutcomes;
BigramProbofTT = TTnum/TotBigramOutcomes;
BigramProbofTC = TCnum/TotBigramOutcomes;
BigramProbofTG = TGnum/TotBigramOutcomes;
BigramProbofGA = GAnum/TotBigramOutcomes;
BigramProbofGT = GTnum/TotBigramOutcomes;
BigramProbofGC = GCnum/TotBigramOutcomes;
BigramProbofGG = GGnum/TotBigramOutcomes;


DNAfile.close();

cout << "Processing completed. Do you want to process any other list? Press Y if yes, any other key if no. Then press enter." << endl;
cin >> prompt; //prompting the user for another go

}

  cout << "Thank you for using our feature. Tada!" << endl;

freopen ("Rejoice.out", "w", stdout); /*writes the output to the specified file. Creates a new file if not present*/

cout << "Name - Rejoice Thomas" << endl;
cout << "Student ID - 2325166" << endl;
cout << "Course number - CPSC350 \n" << endl;
cout << "Output of Assignment 1 :- \n \n" << endl;
cout << "Sum of all the DNA strings in the file - " << Totallength << endl;
cout << "Number of strings - " << Numberofstr << endl;
cout << "Mean - " << Mean << endl;
cout << "Variance - " << Variance << endl;
cout << "StdDev - " << StdDev << endl;
cout << "Prob of A - " << SingleProbOfA << endl;
cout << "Prob of C - " << SingleProbOfC << endl;
cout << "Prob of T - " << SingleProbOfT << endl;
cout << "Prob of G - " << SingleProbOfG << endl;
cout << "Total Outcomes - " << TotBigramOutcomes << endl;
cout << "BigramProbofAA - " << BigramProbofAA << endl;
cout << "BigramProbofAT - " << BigramProbofAT << endl;
cout << "BigramProbofAC - " << BigramProbofAC << endl;
cout << "BigramProbofAG - " << BigramProbofAG << endl;
cout << "BigramProbofCA - " << BigramProbofCA << endl;
cout << "BigramProbofCT - " << BigramProbofCT << endl;
cout << "BigramProbofCC - " << BigramProbofCC << endl;
cout << "BigramProbofCG - " << BigramProbofCG << endl;
cout << "BigramProbofTA - " << BigramProbofTA << endl;
cout << "BigramProbofTT - " << BigramProbofTT << endl;
cout << "BigramProbofTC - " << BigramProbofTC << endl;
cout << "BigramProbofTG - " << BigramProbofTG << endl;
cout << "BigramProbofGA - " << BigramProbofGA << endl;
cout << "BigramProbofGT - " << BigramProbofGT << endl;
cout << "BigramProbofGC - " << BigramProbofGC << endl;
cout << "BigramProbofGG - " << BigramProbofGG << endl;

cout << "\n\n1000 DNA strings following the Gaussian Distribution:- \n" << endl;
srand (time(NULL));         //intializing the rand function
for (int i=0; i<1000; i++) {    //1000 iterations for the 1000 strings
    a = rand()/(RAND_MAX+1.0);  //random floating number between 0 & 1
    b = rand()/(RAND_MAX+1.0);
    c = sqrt(-2*log(a)) * cos(2*pi*b);
    d = (StdDev*c) + Mean;
    A = SingleProbOfA * round (d); /*Rounding off the length to the nearest integer and finding the numner of A's required*/
    T = SingleProbOfT * round (d);
    C = SingleProbOfC * round (d);
    G = SingleProbOfG * round (d);
    A = A + MakeupA;      /*Adding the difference of the rounding off done below*/
    T = T + MakeupT;
    C = C + MakeupC;
    G = G + MakeupG;
    newA = round (A);     //rounding off A to the nearest integer
    newT = round (T);
    newC = round (C);
    newG = round (G);
    cout << string(newA, 'A');
    cout << string(newT, 'T');
    cout << string(newC, 'C');
    cout << string(newG, 'G') << endl;
    MakeupA = A - newA;  /*storing the difference incurred during rounding off to add to the next iteration*/
    MakeupT = T - newT;
    MakeupC = C - newC;
    MakeupG = G - newG;

  }

fclose (stdout);    //closing the output file

return 0;

}
