/*
COMSC-210 | Lab 18 | Rylan Der
IDE Used: Visual Studio Code
 */

#include <iostream>
#include <fstream>
#include <string>

 using namespace std;

 struct ReviewNode {
    string comment;
    double rating;
    ReviewNode* next;

    ReviewNode() { comment = "No comment"; rating = -1; next = nullptr; }
    ReviewNode(string c, double r): comment(c), rating(r), next(nullptr) { }
    ReviewNode(string c, double r, ReviewNode* next): comment(c), rating(r), next(next) { }
 }

 int main() {
 }

