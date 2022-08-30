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

This is a simple library to read and write 16-bit WAV files - enough for demos, experimenting and learning, but probably not serious use.

### Shape and sample-rate

The basic properties are `.sampleRate`, `.channel` and `.length()`:

```cpp
Wav wav;
// Sample-rate, as a double
wav.sampleRate = 48000;
// Channel-count as an unsigned int
wav.channels = 2;

int length = wav.length(); // length (for each channel)
wav.resize(2, 1000); // resize with channel/length
```

WAV sample-rates are actually 32-bit integers, but `.sampleRate` is a `double` since we often divide by it.

### Sample data

The most convenient way to read/write samples is `wav[channel][index]`.  Samples are scaled to the unit range (-1, 1), and converted on input/output.

The actual data is stored in `.samples`, which is a `std::vector<double>`:

```cpp
wav.samples.resize(1000);
wav.samples[0] = 0;
```

Multichannel WAV data is interleaved, so for a stereo file:
* `wav.samples[0]` is the first left, sample
* `wav.samples[1]` is the first right sample
* `wav.samples[2]` is the second left sample
* etc.

### Reading and writing

You read/write with `.read()` and `.write()`, using filenames as `std::string`.

These return a `result` object, which converts to `bool` for success/failure, and has a `.reason` string for human-readable errors.

```cpp
Wav wav;
auto result = wav.read("input.wav");
if (!result) {
	std::cerr << "WAV error: " << result.reason << "\n";
}
```

The latest result is also stored as `wav.result`.

Since logging an error is so common, you can do this with the `.warn()` method:

```cpp
if (!wav.write("output.wav").warn()) {
	// handle failure
}
```

## License

It's released as [CC0](https://creativecommons.org/publicdomain/zero/1.0/).  If you need anything else, contact me.
