// Studio19.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#pragma once
#include "../../SharedCode/TextFile.h"
#include "../../SharedCode/AbstractFile.h"
#include <vector>
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	TextFile tf = TextFile("text.txt");
	cout << "write: " << tf.write({ 'h', 'i', ' ', 'h', 'e', 'l', 'l', 'o', '!' }) << endl;
	vector<char> tfContents = tf.read();

	string temp = "";
	for (char c : tfContents) {
		temp += c;
	}
	cout << "tfContents: " << temp << endl;

	tfContents[2] = '-';

	temp = ""; //reset
	for (char c : tfContents) {
		temp += c;
	}

	cout << "edited tfContents: " << temp << endl;
	tf.write(tfContents);
	return success;
}
