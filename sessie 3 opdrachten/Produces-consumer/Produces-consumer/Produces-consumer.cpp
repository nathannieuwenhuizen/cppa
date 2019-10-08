// Produces-consumer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <thread>
#include <queue>
#include <condition_variable>
#include <mutex>

int counter = 0;
bool done = false;
std::queue<int> goods;

std::mutex mtx;
std::condition_variable cv;

void producer() {
	for (int i = 0; i < 500; ++i) {
		goods.push(i);
		counter++;
	}

	cv.notify_one();
	done = true;
}

void consumer() {
	std::unique_lock<std::mutex> lck(mtx);
	while (!done) {
		cv.wait(lck);
		while (!goods.empty()) {
			goods.pop();
			counter--;
		}
	}
}

int main() {
	std::thread producerThread(producer);
	std::thread consumerThread(consumer);
	producerThread.join();
	consumerThread.join();

	std::cout << "Net: " << counter << " goods " << goods.size() << " " << std::endl;
}
