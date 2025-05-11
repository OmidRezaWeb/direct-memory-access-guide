# 📦 مقدمه‌ای بر DMA (Direct Memory Access)

این پروژه یک معرفی ساده و کامل درباره‌ی مفهوم DMA، کاربرد آن در سیستم‌های کامپیوتری، انواع روش‌های انتقال، و یک نمونه کد ساده برای درک بهتر ارائه می‌دهد. مناسب برای دانشجویان رشته مهندسی کامپیوتر و علاقه‌مندان به معماری سیستم‌ها.

## 🧠 درباره‌ی پروژه

در این پروژه یاد می‌گیرید:

- DMA چیست و چه نیازی به آن داریم
- چگونه کار می‌کند و چه تفاوتی با انتقال سنتی دارد
- انواع حالات DMA (Burst, Cycle Stealing, Transparent)
- مثال‌های عملی از کاربرد DMA در سخت‌افزارها
- کد نمونه پیکربندی یک DMA ساده

## 📁 ساختار پوشه‌ها

- `src/`: کد نمونه C برای پیکربندی DMA
- `docs/`: توضیح مفصل و فنی (همانند مقاله)
- `README.md`: راهنمای پروژه
- `LICENSE`: مجوز استفاده

## 🧪 کد نمونه

```c
// src/dma_example.c

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
    DMA_Channel0.Control = 0x01; // فرض: فعال‌سازی DMA و تنظیم حالت
    DMA_Channel0.Start = 1;      // آغاز انتقال
}
```

## 📚 منابع بیشتر

برای درک بهتر مفاهیم مربوط به معماری سیستم و DMA، پیشنهاد می‌شود کتاب‌های زیر را مطالعه کنید:

- **Computer Organization and Design** – David A. Patterson
- **Operating System Concepts** – Abraham Silberschatz

## ⚖️ لایسنس

MIT © 2025
