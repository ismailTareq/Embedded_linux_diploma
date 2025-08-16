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
	{ 0x122c3a7e, "_printk" },
	{ 0xed6af888, "__platform_driver_register" },
	{ 0x546cd682, "gpiod_put" },
	{ 0x89411c2e, "proc_remove" },
	{ 0xdeebc9f4, "device_property_present" },
	{ 0xab4d6e82, "device_property_read_string" },
	{ 0x4838c840, "device_property_read_u32_array" },
	{ 0x832481e, "devm_gpiod_get" },
	{ 0xb68acd70, "proc_create" },
	{ 0x9115abcf, "gpiod_set_value" },
	{ 0xf0fdf6cb, "__stack_chk_fail" },
	{ 0xa223bac6, "platform_driver_unregister" },
	{ 0x12a4e128, "__arch_copy_from_user" },
	{ 0x39ff040a, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("of:N*T*Cismail-led");
MODULE_ALIAS("of:N*T*Cismail-ledC*");

MODULE_INFO(srcversion, "6692462482DC238E09F5D11");
