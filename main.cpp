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
 };

void push_front(ReviewNode* next, double rating, string comment);

void push_back(ReviewNode* next, double rating, string comment);

void outputReviews(ReviewNode* next);

int main() {
    ReviewNode* head;

    cout << "Which linked list method should we use?" << endl
         << "\t[1] New nodes are added at the head of the linked list" << endl
         << "\t[2] New nodes are added at the tail of the linked list" << endl
         << "\tChoice: > ";
    
}

void push_front(ReviewNode* next, double rating, string comment) {

}

void push_back(ReviewNode* next, double rating, string comment) {

}

void outputReviews(ReviewNode* next) {

}