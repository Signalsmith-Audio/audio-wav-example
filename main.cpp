#include <cmath>

#include "wav.h"

int main() {
	double freqHz = 440;
	double amp = 0.5;
	double durationSeconds = 2;

	Wav wav;
	wav.sampleRate = 48000;
	wav.resize(1, wav.sampleRate*durationSeconds);

	for (size_t i = 0; i < wav.length(); ++i) {
		double time = i/(double)wav.sampleRate;
		double value = sin(time*freqHz*2*M_PI)*amp;
		wav[0][i] = value;
	}

	wav.write("tone-440.wav");
}
