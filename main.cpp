/*
COMSC-210 | Lab 18 | Rylan Der
IDE Used: Visual Studio Code
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <istream>
#include <sstream>

 using namespace std;

 const int STREAM_IGNORE_CHARS = 100;

 struct ReviewNode {
    string comment;
    double rating;
    ReviewNode* next;

    ReviewNode() { comment = "No comment"; rating = -1; next = nullptr; }
    ReviewNode(string c, double r): comment(c), rating(r), next(nullptr) { }
    ReviewNode(string c, double r, ReviewNode* next): comment(c), rating(r), next(next) { }
 };

void push_front(ReviewNode* &head, double rating, string comment);

void push_back(ReviewNode* &head, double rating, string comment);

void outputReviews(ReviewNode* head);

template <typename T>
T validateRange(istream* input, string datatype, T min, T max);

int main() {
    ReviewNode* head = nullptr;
    istream* input = &cin;
    bool pushFront = false;
    string continueFlag = "";
    double rating;
    string comment;

    cout << "Which linked list method should we use?" << endl
         << "\t[1] New nodes are added at the head of the linked list" << endl
         << "\t[2] New nodes are added at the tail of the linked list" << endl
         << "\tChoice:" << endl;
    pushFront = validateRange(input, "integer", 1, 2) == 1;
    do {
        cout << "Enter review rating 0-5: " << endl;
        rating = validateRange(input, "double", 0.0, 5.0);
        cout << "Enter review comments: " << endl;
        getline(*input, comment);
        cout << "Enter another review? Y/N: " << endl;
        getline(*input, continueFlag);
        if (pushFront) {
            push_front(head, rating, comment);
        } else {
            push_back(head, rating, comment);
        }
    } while (continueFlag == "y" || continueFlag == "Y");
    outputReviews(head);
}

void push_front(ReviewNode* &head, double rating, string comment) {
    ReviewNode* newNode = new ReviewNode(comment, rating); //initialized w/ nullptr by default
    if (head) {
        newNode->next = head;
    }
    head = newNode;
}

void push_back(ReviewNode* &head, double rating, string comment) {
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
    int reviewNumber = 1; //keep track of # reviews while traversing
    double sum = 0;       //sum reviews to calculate average

    cout << fixed << setprecision(2);
    cout << "Outputting all reviews:" << endl;
    while (current) {
        cout << "\t> Review #" << reviewNumber << ": " << current->rating << ": " << current->comment << endl;
        sum += current->rating;
        reviewNumber++;
    }
    cout << "\t> Average: " << sum / reviewNumber << endl;
}

/**
 * Validates input from range min to max inclusive
 */
template <typename T>
T validateRange(istream* input, string datatype, T min, T max) {
    T val;
    string inputString = "";
    stringstream ss;
    bool failed = false;
    do {
        if (ss.fail()) {
            cout << "\tInput must be type " << datatype << endl;
            ss.clear();
            ss.str("");
        }
        cout << "\t> ";
        getline(*input, inputString);
        ss.str(inputString);
        ss >> val;
        if (val < min || val > max) {
            cout << "\tInput must be in range " << min << " - " << max << endl;
        }
    } while (ss.fail() || val < min || val > max);
    cout << val;
    return val;
}