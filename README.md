# Hello, DSP!

This is a self-contained piece of C++ audio code.  The interesting bit is [`main.cpp`](main.cpp).

It generates a 2-second 440Hz sine wav, and writes it as a WAV file.

## To build and run

Using the [`Makefile`](Makefile):

```
make
```

This builds `main.cpp` into  `out/main`, and then runs it from the `out/` directory, producing  `out/tone-440.wav`.

## `wav.h`

This is a simple library to read and write 16-bit WAV files - enough for demos and experiments.

### Sample-rate and channel count

Get/set these as `.sampleRate` and `.channel`:

```cpp
Wav wav;
// Sample-rate, as a double
wav.sampleRate = 48000;
// Channel-count as an unsigned int
wav.channels = 2;
```

WAV sample-rates are actually 32-bit integers, but it's stored here as a `double` so you can divide by it more easily.

### Sample data

Samples are in `.samples`, which is a `std::vector<double>`:

```cpp
wav.samples.resize(1000);
wav.samples[0] = 0;
```

Samples are scaled to the unit range (-1, 1), and converted on input/output.

#### Multichannel data

Multichannel WAV samples are interleaved, so for a stereo file:
* `wav.samples[0]` is the first left, sample
* `wav.samples[1]` is the first right sample
* `wav.samples[2]` is the second left sample
* etc.

### Reading and writing

You read/write with `.read()` and `.write()`, using filenames as `std::string`.

These return a `result` object, which evaluates `true` for success, and `false` for failure.  It has a `.reason` string for human-readable errors;

```cpp
Wav wav;
auto result = wav.read("input.wav");
if (!result) {
	std::cerr << "WAV error: " << result.reason << "\n";
}
```

The result of the latest operation is also available as `wav.result`, so you can write stuff like this:

```cpp
if (!wav.write("output.wav")) {
	std::cerr << wav.result.reason << "\n";
}
```

## License

Uh... [CC0](https://creativecommons.org/publicdomain/zero/1.0/).  If you need anything else, contact me.
