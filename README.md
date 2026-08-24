# STM32 UART with LL 🚀

A simple UART communication project using the **STM32F411RE Nucleo** and **STM32 Low-Layer (LL) drivers**.

The project starts with a basic UART Echo and then processes the received characters by converting **uppercase ↔ lowercase**.

---

## 🔌 Hardware

- **Board:** NUCLEO-F411RE
- **MCU:** STM32F411RE
- **USART:** USART2

| Function | Pin | Alternate Function |
|----------|-----|--------------------|
| TX       | PA2 | AF7                |
| RX       | PA3 | AF7                |

The onboard **ST-LINK Virtual COM Port** is used for communication with the PC.

---

## ⚙️ UART Configuration

```text
Baud Rate : 115200
Data Bits : 8
Parity    : None
Stop Bits : 1
Mode      : Asynchronous
