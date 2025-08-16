# Platform Device Drivers for Embedded Linux

A collection of custom platform device drivers implementing PWM, GPIO, and character device interfaces for embedded Linux systems.

## 📋 Overview
This repository contains platform framework drivers developed for embedded Linux, specifically targeting ARM-based systems like Raspberry Pi. The drivers utilize the Linux kernel's platform device model to provide clean abstractions for hardware peripherals.

## 🚀 Features

### Platform Framework Drivers
- **Platform Device Model** - Clean device registration and resource management
- **Device Tree Integration** - Full device tree overlay support
- **Hot-plug Support** - Dynamic loading/unloading of drivers
- **Resource Management** - Automatic cleanup of GPIO, IRQ, and memory resources

### PWM (Pulse Width Modulation) Driver
- **Hardware PWM Control** - Direct hardware PWM register manipulation
- **Configurable Frequency** - Support for multiple PWM frequencies
- **Duty Cycle Control** - Precise duty cycle adjustment (0-100%)
- **Multiple Channels** - Support for multi-channel PWM controllers
- **sysfs Interface** - Easy userspace control via `/sys/class/pwm/`

### GPIO Driver
- **GPIO Line Management** - Individual GPIO pin control
- **Direction Control** - Input/output configuration
- **Interrupt Support** - Edge-triggered GPIO interrupts
- **Pull-up/Pull-down** - Internal resistor configuration
- **Bulk Operations** - Efficient multi-pin operations
- **sysfs Integration** - Standard Linux GPIO sysfs interface

### Character Device Interface
- **Character Device Model** - Standard `/dev/` device files
- **IOCTL Commands** - Custom control operations
- **Read/Write Operations** - Direct data transfer interface
- **Blocking/Non-blocking I/O** - Flexible I/O modes
- **Poll/Select Support** - Asynchronous I/O notification

## 🏗️ Architecture
┌─────────────────┐    ┌─────────────────┐    ┌─────────────────┐
│   Application   │    │   Application   │    │   Application   │
│     Space       │    │     Space       │    │     Space       │
└─────────┬───────┘    └─────────┬───────┘    └─────────┬───────┘
          │                      │                      │
          ▼                      ▼                      ▼
┌─────────────────┐    ┌─────────────────┐    ┌─────────────────┐
│  /sys/class/pwm │    │ /sys/class/gpio │    │    /dev/mydev   │
└─────────┬───────┘    └─────────┬───────┘    └─────────┬───────┘
          │                      │                      │
          ▼                      ▼                      ▼
┌─────────────────┐    ┌─────────────────┐    ┌─────────────────┐
│   PWM Driver    │    │  GPIO Driver    │    │  Char Driver    │
└─────────┬───────┘    └─────────┬───────┘    └─────────┬───────┘
          │                      │                      │
          └──────────────────────┼──────────────────────┘
                                 ▼
                    ┌─────────────────┐
                    │ Platform Driver │
                    │   Framework     │
                    └─────────┬───────┘
                              ▼
                    ┌─────────────────┐
                    │    Hardware     │
                    │   (GPIO/PWM)    │
                    └─────────────────┘

## 💡 Usage Examples

### PWM Driver - Control LED Brightness
```bash
# Export PWM channel 0
echo 0 > /sys/class/pwm/pwmchip0/export

# Set frequency to 1kHz (1,000,000 nanoseconds period)
echo 1000000 > /sys/class/pwm/pwmchip0/pwm0/period

# Set 25% brightness (250,000ns duty cycle)
echo 250000 > /sys/class/pwm/pwmchip0/pwm0/duty_cycle

# Enable PWM output
echo 1 > /sys/class/pwm/pwmchip0/pwm0/enable

# Change brightness to 75%
echo 750000 > /sys/class/pwm/pwmchip0/pwm0/duty_cycle

# Turn off PWM
echo 0 > /sys/class/pwm/pwmchip0/pwm0/enable
GPIO Driver - Control LED and Read Button
bash
# Control LED on GPIO18
echo 18 > /sys/class/gpio/export
echo out > /sys/class/gpio/gpio18/direction

# Turn LED on
echo 1 > /sys/class/gpio/gpio18/value

# Turn LED off  
echo 0 > /sys/class/gpio/gpio18/value

# Read button on GPIO2
echo 2 > /sys/class/gpio/export
echo in > /sys/class/gpio/gpio2/direction

# Check button state (0=pressed, 1=released with pull-up)
cat /sys/class/gpio/gpio2/value

# Clean up
echo 18 > /sys/class/gpio/unexport
echo 2 > /sys/class/gpio/unexport
Character Device - Send Commands and Read Data
bash
# Check if device exists
ls -la /dev/myplatform*

# Write data to device
echo "LED_ON" > /dev/myplatform0
echo "PWM_50" > /dev/myplatform0
echo "GPIO_READ_2" > /dev/myplatform0

# Read response from device
cat /dev/myplatform0

# Advanced: Use with redirection
echo "TEMP_READ" > /dev/myplatform0
temperature=$(cat /dev/myplatform0)
echo "Current temperature: $temperature"
Scripted Automation Examples
LED Blink Script
bash
#!/bin/bash
# LED Blink Script
LED_GPIO=18
echo $LED_GPIO > /sys/class/gpio/export
echo out > /sys/class/gpio/gpio${LED_GPIO}/direction

for i in {1..10}; do
    echo 1 > /sys/class/gpio/gpio${LED_GPIO}/value  # LED ON
    sleep 0.5
    echo 0 > /sys/class/gpio/gpio${LED_GPIO}/value  # LED OFF  
    sleep 0.5
done

echo $LED_GPIO > /sys/class/gpio/unexport
PWM Breathing LED Effect
bash
#!/bin/bash
# PWM Breathing LED Effect
PWM_CHIP=0
echo $PWM_CHIP > /sys/class/pwm/pwmchip0/export
echo 1000000 > /sys/class/pwm/pwmchip0/pwm${PWM_CHIP}/period
echo 1 > /sys/class/pwm/pwmchip0/pwm${PWM_CHIP}/enable

# Fade in and out
for brightness in $(seq 0 10000 1000000); do
    echo $brightness > /sys/class/pwm/pwmchip0/pwm${PWM_CHIP}/duty_cycle
    sleep 0.1
done

for brightness in $(seq 1000000 -10000 0); do
    echo $brightness > /sys/class/pwm/pwmchip0/pwm${PWM_CHIP}/duty_cycle
    sleep 0.1
done

echo 0 > /sys/class/pwm/pwmchip0/pwm${PWM_CHIP}/enable
📥 Installation
To use these drivers:

Clone the repository:

bash
git clone https://github.com/yourusername/embedded-platform-drivers.git
Build the kernel modules:

bash
make -C /lib/modules/$(uname -r)/build M=$(pwd) modules
Load the modules:

bash
sudo insmod pwm_driver.ko
sudo insmod gpio_driver.ko
sudo insmod char_driver.ko
