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
	{ 0xb5a459dc, "unregister_blkdev" },
	{ 0xf8850c22, "blk_cleanup_queue" },
	{ 0x8fb9ddae, "put_disk" },
	{ 0x18b3904e, "del_gendisk" },
	{ 0x999e8297, "vfree" },
	{ 0xa64645f4, "device_add_disk" },
	{ 0x7903e2cc, "set_capacity" },
	{ 0xc6bcbcc3, "__alloc_disk_node" },
	{ 0xdf082e98, "blk_mq_free_tag_set" },
	{ 0x8cf437b9, "blk_mq_init_queue" },
	{ 0x1b28264e, "blk_mq_alloc_tag_set" },
	{ 0x720a27a7, "__register_blkdev" },
	{ 0xd6ee688f, "vmalloc" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0x102dc8, "__blk_mq_end_request" },
	{ 0x9a3252c1, "blk_update_request" },
	{ 0x5b8239ca, "__x86_return_thunk" },
	{ 0x92997ed8, "_printk" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "BA81747F3E5C5AF4B23A0CA");
