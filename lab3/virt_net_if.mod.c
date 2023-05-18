#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
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

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xf704969, "module_layout" },
	{ 0xdce9f68d, "param_ops_charp" },
	{ 0x45f788d2, "unregister_netdev" },
	{ 0xf4a567be, "netdev_rx_handler_unregister" },
	{ 0xdccec3cd, "proc_remove" },
	{ 0x6e720ff2, "rtnl_unlock" },
	{ 0x41031c3c, "netdev_rx_handler_register" },
	{ 0xc7a4fbed, "rtnl_lock" },
	{ 0x56860d2, "register_netdev" },
	{ 0x2a5df4af, "dev_alloc_name" },
	{ 0xfc8b7ff6, "free_netdev" },
	{ 0xffa108c3, "__dev_get_by_name" },
	{ 0xa21071e2, "init_net" },
	{ 0xd0b4800e, "alloc_netdev_mqs" },
	{ 0x84644378, "proc_create" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0xa916b694, "strnlen" },
	{ 0x9503a88f, "dev_queue_xmit" },
	{ 0xf9c0b663, "strlcat" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x69acdf38, "memcpy" },
	{ 0x1108293, "ether_setup" },
	{ 0x92997ed8, "_printk" },
	{ 0x5b8239ca, "__x86_return_thunk" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "EBE2C52092B09F62AFC13C3");
