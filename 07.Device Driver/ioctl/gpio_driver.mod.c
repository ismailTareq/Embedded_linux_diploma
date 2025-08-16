#include <linux/module.h>
#include <linux/export-internal.h>
#include <linux/compiler.h>

MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};



static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xe3ec2f2b, "alloc_chrdev_region" },
	{ 0x4a41ecb3, "class_destroy" },
	{ 0xaa9d006b, "gpiod_set_raw_value" },
	{ 0xfe990052, "gpio_free" },
	{ 0x122c3a7e, "_printk" },
	{ 0xf0fdf6cb, "__stack_chk_fail" },
	{ 0xcc335c1c, "cdev_add" },
	{ 0x64dc7955, "gpiod_direction_output_raw" },
	{ 0xab5c9881, "device_create" },
	{ 0xf311fc60, "class_create" },
	{ 0xdcb764ad, "memset" },
	{ 0x6091b333, "unregister_chrdev_region" },
	{ 0x7d958a42, "device_destroy" },
	{ 0x55bf416, "gpio_to_desc" },
	{ 0x12a4e128, "__arch_copy_from_user" },
	{ 0x47229b5c, "gpio_request" },
	{ 0x5d9d9fd4, "cdev_init" },
	{ 0x607587f4, "cdev_del" },
	{ 0x39ff040a, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "DC9D6650EB0D132CE893B70");
