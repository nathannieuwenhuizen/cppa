// Algoritmes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

#include <vector>
#include <algorithm>
#include <functional>
#include <string>

void coutArray(std::vector<std::string> arr) {
	std::cout << "string vector(";
	for (int i = 0; i <arr.size(); i++) {
		std::cout << arr[i] << ", ";
	}

	std::cout << ") " << std::endl;
}

void coutArray(std::vector<double> arr) {
	std::cout << "double vector(";
	for (int i = 0; i < arr.size(); i++) {
		std::cout << arr[i] << ", ";
	}

	std::cout << ") " << std::endl;
}

std::vector<std::vector<std::string>> splitVectors(std::vector<std::string> arr, std::string key ) {
	std::vector<std::vector<std::string>> result;
	std::vector<std::string> vector1 = {};
	std::vector<std::string> vector2;

	std::vector<std::string> sorted = arr;
	std::sort(sorted.begin(), sorted.end());

	bool left = true;

	for (int i = 0; i < sorted.size(); i++) {
		if (sorted[i] == key) {
			left = false;
		}

		if (left) {
			vector1.push_back(sorted[i]);
		}
		else {
			vector2.push_back(sorted[i]);

		}
	}
	result.push_back(vector1);
	result.push_back(vector2);
	return result;

}

std::string toUpperCase(std::string _val) {
	std::string result = _val;
	for (int i = 0; i <= result.size(); i++) {

		if (result[i] >= 97 && result[i] <= 122)
		{
			result[i] = result[i] - 32;
		}
	}
	return result;
}

std::vector<std::string> toUpperVector(std::vector<std::string> arr) {
	auto result = arr;
	for (int i = 0; i < arr.size(); i++) {
		arr[i] = toUpperCase(arr[i]);
	}
	return arr;
}

std::vector<std::string> noDuplicates(std::vector<std::string> arr) {
	std::vector<std::string> result;
	for (int i = 0; i < arr.size(); i++) {
		if (std::find(result.begin(), result.end(), arr[i]) != result.end()) {
			//duplicate!
		}
		else {
			result.push_back(arr[i]);
		}
	}
	return result;
}

std::vector<double> noNegatives(std::vector<double> arr) {
	std::vector<double> result;

	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] < 0) {
			//negative!
		}
		else {
			//std::cout << arr[i] << " ";
			result.push_back(arr[i]);
		}
	}
	return result;
}

void checkEven(std::vector<double> arr) {
	for (int i = 0; i < arr.size(); i++) {
		if ((int(arr[i]) % 2) == 0) {
			std::cout << arr[i] << " is even |";
		}
		else {
			std::cout << arr[i] << " is uneven |";
		}
	}
	std::cout << std::endl;

}

std::vector<double> sumProductAndAverage(std::vector<double> arr) {
	std::vector<double> result;
	double sum = 0;
	double product = 1;
	double average = 0;
	for (int i = 0; i < arr.size(); i++) {
		sum += arr[i];
		product *= arr[i];
	}
	average = sum / arr.size();

	result.push_back(sum);
	result.push_back(product);
	result.push_back(average);
	return result;
}


int main() {
	std::vector<std::string> colours{ "red", "green", "white", "blue", "orange", "green", "orange", "black", "purple" };
	// gebruik functies uit <algorithm> en <functional> om (steeds vanuit een ORIGINELE copie van deze vector)
	// 1) de vector in 2 nieuwe vectoren te splitsen: 1 met alles wat alfabetisch voor 'purple' komt, 1 met alles er na
	std::vector<std::vector<std::string>> splitColour = splitVectors(colours, "purple");
	coutArray(splitColour[1]);
	coutArray(splitColour[0]);

	// 2) alle elementen UPPERCASE te maken.
	std::vector<std::string> UppercaseColours = toUpperVector(colours);
	coutArray(UppercaseColours);
	//std::cout

	// 3) alle dubbele te verwijderen

	std::vector<std::string> noDuplicateVector = noDuplicates(colours);
	coutArray(noDuplicateVector);


	std::vector<double> numbers{ 10, 324422, 6, -23, 234.5, 654.1, 3.1242, -9.23, 635 };

	// gebruik functies uit <algorithm> en <functional> om (steeds vanuit een ORIGINELE copie van deze vector)
	// 1) alle negatieve elementen te verwijderen
	std::vector<double> noNegativesVector = noNegatives(numbers);
	coutArray(noNegativesVector);

	// 2) voor alle elementen te bepalen of ze even of oneven zijn
	checkEven(numbers);

	// 3) de som, het gemiddelde, en het product van alle getallen te berekenen
	std::vector<double> sumAverageAndProduct = sumProductAndAverage(numbers);
	coutArray(sumAverageAndProduct);


	return 0;
}