#include <cmath>

#include "wav.h"

int main() {
	double freqHz = 440;
	double amp = 0.5;
	double durationSeconds = 2;

	Wav wav;
	wav.sampleRate = 48000;

	for (size_t i = 0; i < durationSeconds*wav.sampleRate; ++i) {
		double time = i/(double)wav.sampleRate;
		double value = sin(time*freqHz*2*M_PI)*amp;
		wav.samples.push_back(value);
	}

	wav.write("tone-440.wav");
}