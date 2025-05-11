#include <stdint.h>

// فرضی: ساختار سخت‌افزاری یک DMA Controller
struct DMA_Channel {
    uint32_t SourceAddress;
    uint32_t DestAddress;
    uint32_t Count;
    uint32_t Control;
    uint32_t Start;
};

// فرض می‌کنیم کنترلر در آدرس خاصی از حافظه قرار دارد
volatile struct DMA_Channel DMA_Channel0 = {0};

void start_dma_transfer(uint32_t* src, uint32_t* dst, uint32_t length) {
    DMA_Channel0.SourceAddress = (uint32_t)src;
    DMA_Channel0.DestAddress = (uint32_t)dst;
    DMA_Channel0.Count = length;
    DMA_Channel0.Control = 0x01;
    DMA_Channel0.Start = 1;
}
