# Raspberry Pi 4 Model B (64-bit) machine configuration for Torizon OS

WKS_FILE:sota = "torizon-raspberrypi4-sota.wks"

# The VideoCore firmware can only load a bootloader from a FAT partition, so
# we always boot through u-boot instead of loading Linux directly. u-boot
# then uses the standard distro boot / extlinux mechanism to find the
# OSTree-managed kernel and rootfs on the ext4 partition, giving us OTA
# rollback support like the other u-boot based Common Torizon machines.
RPI_USE_U_BOOT = "1"
OSTREE_BOOTLOADER = "u-boot"

PREFERRED_PROVIDER_u-boot-default-script = "u-boot-distro-boot"

UBOOT_BOOT_PARTITION_NUMBER = "2"
OTAROOT_PARTITION_NUMBER = "2"

OSTREE_KERNEL_ARGS:sota = "console=ttyS0,115200 root=LABEL=otaroot rootfstype=ext4"

IMAGE_FSTYPES:append = " wic"
IMAGE_BOOT_FILES:append = " ${BOOTFILES_DIR_NAME}/* ${@make_dtb_boot_files(d)} ${RPI_EXTRA_IMAGE_BOOT_FILES}"

PREFERRED_PROVIDER_virtual/dtb = ""

hostname:pn-base-files = "torizon-raspberrypi4-64"
