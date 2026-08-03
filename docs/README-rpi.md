Setup
======
> [!IMPORTANT]
> A `repo` manifest for Raspberry Pi (`common-torizon/rpi/default.xml`) is not published yet in
> `toradex-manifest.git`. Until it is, use the _Manual Setup_ section below to clone the layers.
> Common Torizon OS is only available on branches `scarthgap-7.x.y` or newer!

Build
======
1. Source `setup-environment`:
```bash
$ MACHINE=raspberrypi4-64 . setup-environment build-rpi4-64
```
This will create a build folder named `build-rpi4-64`, where all build artifacts will be stored.

2. Inside the build directory, start the build e.g.:
```bash
$ bitbake torizon-docker
```

All artifacts should be inside `build-rpi4-64/deploy/images/raspberrypi4-64`, including the `.wic` file.

Flashing to an SD card
======
Write the generated `.wic.bmap`/`.wic` image to an SD card with `bmaptool` (or `dd` if `bmaptool` isn't available):
```bash
$ sudo bmaptool copy torizon-docker-raspberrypi4-64.wic /dev/sdX
```
Insert the SD card into the Raspberry Pi 4 and power it on. Console output is available on the
board's UART at `115200;ttyS0`.

---

Manual Setup
======
1. Create your build folder structure. Something like:
```bash
$ mkdir common-torizon; cd common-torizon
$ mkdir layers; cd layers
```
2. Clone the layers needed to build Raspberry Pi Common Torizon:
  * Download Poky
```bash
$ git clone git://git.yoctoproject.org/poky -b scarthgap
```
  * Download `meta-raspberrypi` and `meta-toradex-torizon`:
```bash
$ git clone https://github.com/agherzan/meta-raspberrypi.git -b scarthgap
$ git clone https://github.com/torizon/meta-toradex-torizon.git -b scarthgap-7.x.y
```
  * Download `meta-toradex-torizon` dependencies:
```bash
$ git clone https://github.com/uptane/meta-updater.git -b scarthgap
$ git clone https://git.yoctoproject.org/meta-virtualization -b scarthgap
```
  * And finally, download `meta-updater` and `meta-virtualization` dependency:
```bash
$ git clone https://github.com/openembedded/meta-openembedded -b scarthgap
```
  * Go back into our top folder `common-torizon`
  * Create a symlink to our `setup-environment`:
```bash
$ ln -s layers/meta-toradex-torizon/scripts/setup-environment setup-environment
```
