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
	{ 0xc4162456, "module_layout" },
	{ 0xb5a459dc, "unregister_blkdev" },
	{ 0xa8c92043, "blk_cleanup_queue" },
	{ 0x250376e7, "put_disk" },
	{ 0xd38c3cea, "del_gendisk" },
	{ 0x999e8297, "vfree" },
	{ 0x75453904, "device_add_disk" },
	{ 0x111f1159, "set_capacity" },
	{ 0x23304faf, "__alloc_disk_node" },
	{ 0x5e4c95b7, "blk_mq_free_tag_set" },
	{ 0x5976b6df, "blk_mq_init_queue" },
	{ 0xc602b8e9, "blk_mq_alloc_tag_set" },
	{ 0x720a27a7, "__register_blkdev" },
	{ 0xd6ee688f, "vmalloc" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0xa67301f1, "__blk_mq_end_request" },
	{ 0x6e9267a5, "blk_update_request" },
	{ 0x5b8239ca, "__x86_return_thunk" },
	{ 0x92997ed8, "_printk" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "8F68C27D8E7AE866B9680A4");
