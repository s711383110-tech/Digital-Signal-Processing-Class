// RC_filtering.c
// Usage: RC_filtering in.wav out.wav
// Example: RC_filtering sincos_fs8000_f3000_L1.0.wav filtered_sincos_fs8000_f3000_L1.0.wav

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#pragma pack(push, 1)
typedef struct {
    char     ChunkID[4];
    uint32_t ChunkSize;
    char     Format[4];
    char     Subchunk1ID[4];
    uint32_t Subchunk1Size;
    uint16_t AudioFormat;
    uint16_t NumChannels;
    uint32_t SampleRate;
    uint32_t ByteRate;
    uint16_t BlockAlign;
    uint16_t BitsPerSample;
    char     Subchunk2ID[4];
    uint32_t Subchunk2Size;
} WavHeader;
#pragma pack(pop)

static inline double clip16(double x){
    if (x >  32767.0) return  32767.0;
    if (x < -32768.0) return -32768.0;
    return x;
}

int main(int argc, char** argv){
    if (argc != 3){
        fprintf(stderr, "Usage: %s in.wav out.wav\n", argv[0]);
        return 1;
    }
    const char* infn  = argv[1];
    const char* outfn = argv[2];

    FILE* fi = fopen(infn, "rb");
    if (!fi){ perror("fopen(in)"); return 1; }

    WavHeader h;
    if (fread(&h, sizeof(h), 1, fi) != 1){
        fprintf(stderr, "Error: bad WAV header.\n");
        fclose(fi); return 1;
    }
    // 基本格式檢查：16-bit PCM 立體聲
    if (memcmp(h.ChunkID,"RIFF",4) || memcmp(h.Format,"WAVE",4) ||
        memcmp(h.Subchunk1ID,"fmt ",4) || memcmp(h.Subchunk2ID,"data",4) ||
        h.AudioFormat != 1 || h.NumChannels != 2 || h.BitsPerSample != 16){
        fprintf(stderr, "Only supports 16-bit PCM stereo WAV.\n");
        fclose(fi); return 1;
    }

    // 從 header 取樣率取得 T 與 RC → a1, b0
    const double fs = (double)h.SampleRate;
    const double T  = 1.0 / fs;
    const double RC = 1.0 / (2.0 * M_PI * 400.0); // 截止 400 Hz 的一階 RC
    const double a1 = RC / (RC + T);
    const double b0 = T  / (RC + T);

    // 輸出檔：沿用相同 header（fs/通道/位元深度都不變）
    FILE* fo = fopen(outfn, "wb");
    if (!fo){ perror("fopen(out)"); fclose(fi); return 1; }
    if (fwrite(&h, sizeof(h), 1, fo) != 1){
        fprintf(stderr, "Error: write header failed.\n");
        fclose(fi); fclose(fo); return 1;
    }

    const uint32_t frames = h.Subchunk2Size / h.BlockAlign; // 立體聲一幀
    double yL_prev = 0.0, yR_prev = 0.0;                    // 初始靜止

    for (uint32_t i = 0; i < frames; ++i){
        int16_t sL, sR;
        if (fread(&sL, sizeof(int16_t), 1, fi) != 1 ||
            fread(&sR, sizeof(int16_t), 1, fi) != 1){
            fprintf(stderr, "Error: read samples failed.\n");
            fclose(fi); fclose(fo); return 1;
        }

        // x[n]
        const double xL = (double)sL;
        const double xR = (double)sR;

        // y[n] = a1*y[n-1] + b0*x[n]
        const double yL = a1 * yL_prev + b0 * xL;
        const double yR = a1 * yR_prev + b0 * xR;

        yL_prev = yL;
        yR_prev = yR;

        int16_t oL = (int16_t)lrint(clip16(yL));
        int16_t oR = (int16_t)lrint(clip16(yR));

        if (fwrite(&oL, sizeof(int16_t), 1, fo) != 1 ||
            fwrite(&oR, sizeof(int16_t), 1, fo) != 1){
            fprintf(stderr, "Error: write samples failed.\n");
            fclose(fi); fclose(fo); return 1;
        }
    }

    fclose(fi);
    fclose(fo);
    fprintf(stderr, "Filtered WAV written: %s (fs=%.0f Hz, a1=%.6f, b0=%.6f)\n",
            outfn, fs, a1, b0);
    return 0;
}