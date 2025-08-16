## 📋 what I learned 
![gitHub](https://github.com/ismailTareq/Embedded_linux2024_diploma/blob/main/05.Customized%20Linux%20from%20scratch/Images/1.png)
![gitHub](https://github.com/ismailTareq/Embedded_linux2024_diploma/blob/main/05.Customized%20Linux%20from%20scratch/Images/2.png)
![gitHub](https://github.com/ismailTareq/Embedded_linux2024_diploma/blob/main/05.Customized%20Linux%20from%20scratch/Images/3%2C4.png)



# Raspberry Pi 4,5 Linux From Scratch (LFS)

A complete custom Linux system built from scratch for Raspberry Pi 4 featuring:
- **crosstool-ng** custom toolchain
- **U-Boot** bootloader with RPi4 patches
- **TFTP** kernel loading + **NFS** rootfs
- **BusyBox**-based userspace
- Custom-built **kernel/DTBs/modules**
- **Static/Dynamic library** toolchain

## 📋 Table of Contents
1. [Hardware Requirements](#-hardware-requirements)
2. [Build Dependencies](#-build-dependencies)
3. [Toolchain Setup](#-step-1-crosstool-ng-toolchain)
4. [U-Boot Configuration](#-step-2-u-boot-bootloader)
5. [Linux Kernel Build](#-step-3-linux-kernel)
6. [RootFS with BusyBox](#-step-4-busybox-rootfs)
7. [Library Support](#-step-5-staticdynamic-libraries)
8. [TFTP/NFS Setup](#-step-6-tftpnfs-deployment)
9. [Boot Process](#-booting-the-system)

## 🖥️ Hardware Requirements
| Component       | Requirement                         |
|-----------------|-------------------------------------|
| Raspberry Pi    | 4B (any RAM size)                   |
| Host System     | x86_64 Linux (Ubuntu 22.04 tested)  |
| Storage         | 16GB+ microSD (for U-Boot)          |
| Network         | Ethernet connection (for TFTP/NFS)   |
| Serial Debug    | USB-to-TTL cable (3.3V)             |

## 📦 Build Dependencies
```bash
# Ubuntu/Debian
sudo apt install build-essential git bison flex libncurses-dev \
    libssl-dev u-boot-tools tftpd-hpa nfs-kernel-server
```bash
🔨 Step 1: Crosstool-NG Toolchain
# Build custom toolchain
wget http://crosstool-ng.org/download/crosstool-ng/crosstool-ng-1.25.0.tar.bz2
tar xf crosstool-ng-*.tar.bz2
cd crosstool-ng-1.25.0
./configure --enable-local
make
./ct-ng aarch64-rpi4-linux-gnu
./ct-ng build
# Output: ~/x-tools/aarch64-rpi4-linux-gnu/bin/

🚀 Step 2: U-Boot Bootloader
git clone https://github.com/u-boot/u-boot.git
cd u-boot
make ARCH=arm64 CROSS_COMPILE=~/x-tools/aarch64-rpi4-linux-gnu/bin/aarch64-rpi4-linux-gnu- rpi_4_defconfig
make -j$(nproc)
#Output: u-boot.bin

🐧 Step 3: Linux Kernel
git clone --depth=1 https://github.com/raspberrypi/linux
cd linux
make ARCH=arm64 CROSS_COMPILE=~/x-tools/aarch64-rpi4-linux-gnu/bin/aarch64-rpi4-linux-gnu- bcm2711_defconfig
make ARCH=arm64 CROSS_COMPILE=~/x-tools/aarch64-rpi4-linux-gnu/bin/aarch64-rpi4-linux-gnu- menuconfig # Customize
make ARCH=arm64 CROSS_COMPILE=~/x-tools/aarch64-rpi4-linux-gnu/bin/aarch64-rpi4-linux-gnu- -j$(nproc) Image modules dtbs
export ROOTFS=$HOME/rpi4-rootfs
make ARCH=arm64 CROSS_COMPILE=~/x-tools/aarch64-rpi4-linux-gnu/bin/aarch64-rpi4-linux-gnu- INSTALL_MOD_PATH=$ROOTFS modules_install
#Outputs:
arch/arm64/boot/Image
arch/arm64/boot/dts/broadcom/*.dtb

📂 Step 4: BusyBox RootFS
wget https://busybox.net/downloads/busybox-1.36.1.tar.bz2
tar xf busybox-*.tar.bz2
cd busybox-1.36.1
make defconfig
make menuconfig # Enable static build or leave it and move the ~/x-tools/aarch64-rpi4-linux-gnu/aarch64-rpi4-linux-gnu/sysroot/ld* so it will need it
make CROSS_COMPILE=~/x-tools/aarch64-rpi4-linux-gnu/bin/aarch64-rpi4-linux-gnu- -j$(nproc)
make CONFIG_PREFIX=$HOME/rpi4-rootfs install

📚 Step 5: Static/Dynamic Libraries
Build glibc (dynamic)
# Built automatically in crosstool-ng toolchain
ls ~/x-tools/aarch64-rpi4-linux-gnu/aarch64-rpi4-linux-gnu/lib/libc.so.6

Build static library example
echo "void hello() { printf(\"Hello LFS!\\n\"); }" > hello.c
aarch64-rpi4-linux-gnu-gcc -c hello.c -o hello.o
ar rcs libhello.a hello.o
# check the photos

🌐 Step 6: TFTP/NFS Deployment
TFTP Setup (kernel/DTBs)
sudo cp linux/arch/arm64/boot/Image /var/lib/tftpboot/
sudo cp linux/arch/arm64/boot/dts/broadcom/*.dtb /var/lib/tftpboot/
NFS Setup (rootfs)
sudo echo "/home/$USER/rpi4-rootfs *(rw,sync,no_root_squash)" >> /etc/exports
sudo systemctl restart nfs-kernel-server

🎉 Project Completion
You’ve successfully built a fully custom Linux system for Raspberry Pi 4 from scratch! This includes:
✅ Cross-compiled toolchain (via crosstool-ng)
✅ U-Boot bootloader with TFTP/NFS support
✅ Custom Linux kernel with optimized modules
✅ Minimal rootfs powered by BusyBox
✅ Static/dynamic library support
please check the screenshots for more clarification and thanks for ur time.

## here is my bootfs and rootfs :https://github.com/ismailTareq/Raspi4-complete-tested-image/releases
### For LFS:
```bash
git lfs pull
tar -xJvf rpi4_bootfs.tar.xz
tar -xJvf rpi4_rootfs.tar.xz

### For Split Archives:
cat rpi4_bootfs.tar.xz.* | xz -d | tar -xv
cat rpi4_rootfs.tar.xz.* | xz -d | tar -xv

🔄 Next Steps will be found in yocto part and project check it out!!
Expand functionality: Add packages like dropbear (SSH) or lighttpd (web server).
Create a disk image: Use dd or buildroot for SD card deployment.
Optimize boot time: Trim init scripts and enable parallel startup.

# note
raspi5 doesn't support uboot still when it happens i will update this statment.





