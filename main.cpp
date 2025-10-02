/*
COMSC-210 | Lab 18 | Rylan Der
IDE Used: Visual Studio Code
 */

#include <iostream>
#include <iomanip>
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

void push_front(ReviewNode* head, double rating, string comment);

void push_back(ReviewNode* head, double rating, string comment);

void outputReviews(ReviewNode* head);

int main() {
    ReviewNode* head;

    cout << "Which linked list method should we use?" << endl
         << "\t[1] New nodes are added at the head of the linked list" << endl
         << "\t[2] New nodes are added at the tail of the linked list" << endl
         << "\tChoice: > ";
    
}

void push_front(ReviewNode* head, double rating, string comment) {
    ReviewNode* newNode = new ReviewNode(comment, rating); //initialized w/ nullptr by default
    if (head) {
        newNode->next = head;
    }
    head = newNode;
}

void push_back(ReviewNode* head, double rating, string comment) {
    ReviewNode* current = head;
    ReviewNode* newNode = new ReviewNode(comment, rating); //initialized w/ nullptr by default
    if (!head) { //head is the new node if empty
        head = newNode;
    } else { //otherwise traverse & add to end
        while (current->next) { current = current->next; }
        current->next = newNode;
    }
}

void outputReviews(ReviewNode* head) {
    ReviewNode *current = head;
    int reviewNumber = 1;
    double sum = 0;
    cout << fixed << setprecision(2);
    cout << "Outputting all reviews:" << endl;
    while (current) {
        cout << "\t> Review #" << reviewNumber << ": " << current->rating << ": " << current->comment << endl;
        sum +- current->rating;
        reviewNumber++;
    }
    cout << "\t> Average: " << sum / reviewNumber << endl;
}