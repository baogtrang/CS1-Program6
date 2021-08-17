//Bao Trang
//Computer Science 1 - Professor Benjamin Shelton
/*
This program will read in the values and store them in the array,
determines the largest number and the smallest number out of these 10 numbers using the array,
finds the average of all the numbers,
prints all positive numbers and all negative numbers in the array.
*/

#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

//array declaration
const int SIZE = 10;
double a[SIZE]; 

//global variables
double largest = a[0];
double smallest = a[0];
double average = 0;

//function headers
void storeArray(ifstream& inFile, double arr[]);
void largestNum(ofstream& outFile, double arr[], double largest);
void smallestNum(ofstream& outFile, double arr[], double smallest);
void averageNum(ofstream& outFile, double arr[], double average);
void positiveNums(ofstream& outFile, double arr[]);
void negativeNums(ofstream& outFile, double arr[]);

int main()
{
    ifstream inFile("input.txt");
    ofstream outFile("BaoTrangProgram6.txt");

    storeArray(inFile, a);

    largestNum(outFile, a, largest);
    smallestNum(outFile, a, smallest);
    averageNum(outFile, a, average);
    positiveNums(outFile, a );
    negativeNums(outFile, a);

    inFile.close();
    outFile.close();
    return 0;
}

//the function store inFile data in the array
void storeArray(ifstream & inFile, double arr[])
{
    for (int i = 0; i < SIZE; i++)
    {
        inFile >> arr[i];
        //cout << a[i] << endl;
    }
}

//the function determines the largest number
void largestNum(ofstream & outFile, double arr[], double largest)
{
    for (int i = 1; i < SIZE; i++)
    {
        if (arr[i] > largest)
        {
            largest = arr[i];
        }
    }
    outFile << "The largest number: " << largest << endl;
}

//the function determines the smallest number
void smallestNum(ofstream& outFile, double arr[], double smallest)
{
    for (int i = 1; i < SIZE; i++)
    {
        if (arr[i] < smallest)
        {
            smallest = arr[i];
        }
    }
    outFile << "The smallest number: " << smallest << endl;
}

//the function determines the average
void averageNum(ofstream & outFile, double arr[], double average)
{
    double sum = 0;
    for (int i = 0; i < 10; i++)
    {
        sum += arr[i];
    }
    average = sum / SIZE;
    outFile << "The average: " << average << endl;
}

//this function writes all positive numbers to outFile
void positiveNums(ofstream& outFile, double arr[])
{
    outFile << "Positive numbers: ";
    for (int i = 0; i < SIZE; i++)
    {
        if (arr[i] >= 0)
        {
            outFile << arr[i] << ", ";
        }

    }
    outFile << endl;
}

//this function writes all negative numbers to outFile
void negativeNums(ofstream& outFile, double arr[])
{
    outFile << "Negative numbers: ";
    for (int i = 0; i < SIZE; i++)
    {
        if (arr[i] < 0)
        {
            outFile << arr[i] << ", ";
        }

    }
}