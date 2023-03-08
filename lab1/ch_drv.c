#include <linux/module.h>
#include <linux/version.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/types.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/device.h>
#include <linux/cdev.h>
#include <linux/proc_fs.h>
#include <linux/string.h>
#include <linux/uaccess.h>
#include <linux/vmalloc.h>

#define SPACE_CHAR ' '
#define OUTPUT_SIZE 1024
#define MAX_SIZE_T_LEN 22

MODULE_LICENSE("GPL");
MODULE_AUTHOR("MIKE AND ROMAN");
MODULE_DESCRIPTION("A dev Linux module with procfs statistic.");
MODULE_VERSION("1.0");

static dev_t first;
static struct cdev c_dev; 
static struct class *cl;
static struct proc_dir_entry *entry;
struct device_list *device_list_head = NULL;


struct device_list {
	size_t count;
  struct device_list *next;
};

static void create_device_list_node(size_t value) {
	if (device_list_head == NULL) {
    device_list_head = vmalloc(sizeof(struct device_list));
  } else {
  	struct device_list *device_list_temp = vmalloc(sizeof(struct device_list));
    device_list_temp->next = device_list_head;
    device_list_head = device_list_temp;
  }
  device_list_head->count = value;
}


static int my_open(struct inode *i, struct file *f)
{
  return 0;
}

static int my_close(struct inode *i, struct file *f)
{
  return 0;
}

static ssize_t my_read(struct file *f, char __user *buf, size_t len, loff_t *off)
{
	printk(KERN_INFO "BUFFER INFORMATION HERE (indexing from the last):");
  size_t index = 1;
  struct device_list *tmp_head = device_list_head;
  while(tmp_head != NULL) {
  	printk(KERN_INFO "%zu: %zu", index++, tmp_head->count);
    tmp_head = tmp_head->next;
  }
  return 0;
}

static ssize_t my_write(struct file *f, const char __user *buf,  size_t len, loff_t *off)
{
  size_t space_cnt = 0;
  size_t i;

  for (i = 0; i < len; i++){
  	space_cnt += (buf[i] == SPACE_CHAR);
  }
  create_device_list_node(space_cnt);
  return len;
} 

static int my_dev_uevent(struct device *dev, struct kobj_uevent_env *env)
{
    add_uevent_var(env, "DEVMODE=%#o", 0666);
    return 0;
}

static struct file_operations mychdev_fops =
{
  .owner      = THIS_MODULE,
  .open       = my_open,
  .release    = my_close,
  .read       = my_read,
  .write      = my_write
};



static ssize_t proc_write(struct file *file, const char __user * ubuf, size_t count, loff_t* ppos) 
{
	return -1;
}

static ssize_t proc_read(struct file *file, char __user * ubuf, size_t count, loff_t* ppos) 
{
	char buf[OUTPUT_SIZE];
  char tmp_buf[MAX_SIZE_T_LEN];
  sprintf(buf, "buf: ");
  struct device_list *tmp_head = device_list_head;
  size_t len = strlen(buf);
  while(tmp_head != NULL && len + MAX_SIZE_T_LEN + 2 < OUTPUT_SIZE) {
  	sprintf(tmp_buf, "%zu, ", tmp_head->count);
    strcat(buf, tmp_buf);
    tmp_head = tmp_head->next;
  	len = strlen(buf);
  }
  strcat(buf, "\n");
  buf[len-2] = ' ';
  len = strlen(buf);
	if (*ppos > 0 || count < len){
		return 0;
	}
	if (copy_to_user(ubuf, buf, len) != 0)
	{
		return -EFAULT;
	}
	*ppos = len;
	return len;
}

static struct proc_ops proc_ops = {
	.proc_read = proc_read,
	.proc_write = proc_write,
};





static int __init ch_drv_init(void){
    entry = proc_create("var4", 0444, NULL, &proc_ops);
    if(entry == NULL)
   		return -1;
      
    printk(KERN_INFO "%s: proc file is created\n", THIS_MODULE->name);

    if (alloc_chrdev_region(&first, 0, 1, "ch_dev") < 0)
	  {
		  return -1;
	  }
    if ((cl = class_create(THIS_MODULE, "chardrv")) == NULL)
	  {
		  unregister_chrdev_region(first, 1);
		  return -1;
	  }

    cl->dev_uevent = my_dev_uevent;

    if (device_create(cl, NULL, first, NULL, "var4") == NULL)
	  {
		  class_destroy(cl);
		  unregister_chrdev_region(first, 1);
		  return -1;
	  }
    cdev_init(&c_dev, &mychdev_fops);
    if (cdev_add(&c_dev, first, 1) == -1)
	  {
		  device_destroy(cl, first);
		  class_destroy(cl);
		  unregister_chrdev_region(first, 1);
		  return -1;
	  }
    return 0;
}
 
static void __exit ch_drv_exit(void){
    proc_remove(entry);
    cdev_del(&c_dev);
    device_destroy(cl, first);
    class_destroy(cl);
    unregister_chrdev_region(first, 1);
    printk(KERN_INFO "Bye!!!\n");
}
 
module_init(ch_drv_init);
module_exit(ch_drv_exit);

