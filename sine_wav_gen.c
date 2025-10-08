// sine_wav_gen.c
// Usage: sine_wav_gen fs f L out.wav
// Example: sine_wav_gen 8000 3000 1.0 sincos_fs8000_f3000_L1.0.wav
// Output: stereo 16-bit PCM WAV, left=sin(2πft), right=cos(2πft)

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <string.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// ---- WAV header (16-bit PCM, stereo) ----
#pragma pack(push, 1)
typedef struct {
    char     ChunkID[4];      // "RIFF"
    uint32_t ChunkSize;       // 36 + Subchunk2Size
    char     Format[4];       // "WAVE"

    char     Subchunk1ID[4];  // "fmt "
    uint32_t Subchunk1Size;   // 16 for PCM
    uint16_t AudioFormat;     // 1 = PCM
    uint16_t NumChannels;     // 2 = stereo
    uint32_t SampleRate;      // fs
    uint32_t ByteRate;        // fs * NumChannels * BitsPerSample/8
    uint16_t BlockAlign;      // NumChannels * BitsPerSample/8
    uint16_t BitsPerSample;   // 16

    char     Subchunk2ID[4];  // "data"
    uint32_t Subchunk2Size;   // NumSamples * NumChannels * BitsPerSample/8
} WavHeader;
#pragma pack(pop)

// 16-bit clipping
static inline double clip16(double x){
    if (x >  32767.0) return  32767.0;
    if (x < -32768.0) return -32768.0;
    return x;
}

int main(int argc, char** argv) {
    if (argc != 5) {
        fprintf(stderr, "Usage: %s fs f L out.wav\n", argv[0]);
        fprintf(stderr, "Example: %s 8000 3000 1.0 sincos_fs8000_f3000_L1.0.wav\n", argv[0]);
        return 1;
    }

    const double fs = atof(argv[1]);     // sampling rate (Hz)
    const double f  = atof(argv[2]);     // tone frequency (Hz)
    const double L  = atof(argv[3]);     // length (sec)
    const char* outfn = argv[4];

    if (fs <= 0 || f <= 0 || L <= 0) {
        fprintf(stderr, "Error: fs, f, L must be positive.\n");
        return 1;
    }

    const uint16_t channels = 2;
    const uint16_t bits     = 16;
    const uint32_t N        = (uint32_t)llround(fs * L); // samples per channel
    const double   A        = 0.9 * 32767.0;             // amplitude (avoid clipping)

    FILE* fp = fopen(outfn, "wb");
    if (!fp) { perror("fopen"); return 1; }

    // ---- fill WAV header ----
    WavHeader h;
    memcpy(h.ChunkID, "RIFF", 4);
    memcpy(h.Format,  "WAVE", 4);
    memcpy(h.Subchunk1ID, "fmt ", 4);
    memcpy(h.Subchunk2ID, "data", 4);

    h.Subchunk1Size = 16;
    h.AudioFormat   = 1;
    h.NumChannels   = channels;
    h.SampleRate    = (uint32_t)fs;
    h.BitsPerSample = bits;
    h.BlockAlign    = channels * bits / 8;
    h.ByteRate      = h.SampleRate * h.BlockAlign;
    h.Subchunk2Size = N * h.BlockAlign;        // total bytes of PCM data
    h.ChunkSize     = 36 + h.Subchunk2Size;

    fwrite(&h, sizeof(h), 1, fp);

    // ---- write stereo samples: left=sin, right=cos ----
    for (uint32_t n = 0; n < N; ++n) {
        double t  = (double)n / fs;
        double Ls = sin(2.0 * M_PI * f * t);   // left channel: sin
        double Rs = cos(2.0 * M_PI * f * t);   // right channel: cos
        int16_t sL = (int16_t)lrint(clip16(A * Ls));
        int16_t sR = (int16_t)lrint(clip16(A * Rs));
        fwrite(&sL, sizeof(int16_t), 1, fp);
        fwrite(&sR, sizeof(int16_t), 1, fp);
    }

    fclose(fp);
    fprintf(stderr,
            "WAV written: %s  (fs=%.0f Hz, f=%.0f Hz, L=%.2f s, stereo 16-bit)\n",
            outfn, fs, f, L);
    return 0;
}