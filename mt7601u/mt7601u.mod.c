#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/export-internal.h>
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
	{ 0x587f22d7, "devmap_managed_key" },
	{ 0xef896490, "usb_alloc_urb" },
	{ 0x85d71dd9, "__skb_pad" },
	{ 0xc6d09aa9, "release_firmware" },
	{ 0xa8fffac6, "simple_attr_open" },
	{ 0x49cd25ed, "alloc_workqueue" },
	{ 0x96bd2490, "usb_free_urb" },
	{ 0xb8af3d07, "bpf_trace_run4" },
	{ 0xeb3d6acf, "debugfs_attr_write" },
	{ 0x4a3ad70e, "wait_for_completion_timeout" },
	{ 0x3fb3e87a, "devm_kmalloc" },
	{ 0x5e9dead4, "skb_put" },
	{ 0x8d522714, "__rcu_read_lock" },
	{ 0x65b6576d, "usb_alloc_coherent" },
	{ 0xa9a70137, "consume_skb" },
	{ 0xb0e602eb, "memmove" },
	{ 0xa6257a2f, "complete" },
	{ 0xeae1ab10, "trace_raw_output_prep" },
	{ 0x6b8bf149, "netif_receive_skb_list" },
	{ 0x608741b5, "__init_swait_queue_head" },
	{ 0xb80e9b84, "__trace_trigger_soft_disabled" },
	{ 0xeba933ba, "ieee80211_free_hw" },
	{ 0xc75bb86a, "request_firmware" },
	{ 0xdd00515a, "trace_event_printf" },
	{ 0xc38418b1, "usb_register_driver" },
	{ 0x53569707, "this_cpu_off" },
	{ 0xde28d15f, "skb_add_rx_frag" },
	{ 0x300ab09d, "ieee80211_tx_status_ext" },
	{ 0x18b14dd, "trace_event_raw_init" },
	{ 0x69acdf38, "memcpy" },
	{ 0x37a0cba, "kfree" },
	{ 0x39d9014b, "seq_lseek" },
	{ 0xf852a2ff, "__put_devmap_managed_page_refs" },
	{ 0xf6ad06fc, "ieee80211_register_hw" },
	{ 0xc3055d20, "usleep_range_state" },
	{ 0x9f126fc8, "bpf_trace_run2" },
	{ 0xb032cf07, "ieee80211_get_hdrlen_from_skb" },
	{ 0x4c2a9dd3, "ieee80211_wake_queue" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0x5640caa9, "__dynamic_dev_dbg" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x9cbcedb6, "pskb_expand_head" },
	{ 0xbd5779a2, "trace_event_buffer_commit" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xa6b72cfa, "ieee80211_get_tx_rates" },
	{ 0xb5e73116, "flush_delayed_work" },
	{ 0xa93ce86d, "ieee80211_send_bar" },
	{ 0x1d24c881, "___ratelimit" },
	{ 0x92f53be, "usb_put_dev" },
	{ 0x1717d3af, "usb_bulk_msg" },
	{ 0x84955382, "usb_reset_device" },
	{ 0xa19b956, "__stack_chk_fail" },
	{ 0xb2fcb56d, "queue_delayed_work_on" },
	{ 0xe46021ca, "_raw_spin_unlock_bh" },
	{ 0x4f087439, "usb_get_dev" },
	{ 0x398ad470, "__alloc_skb" },
	{ 0x618911fc, "numa_node" },
	{ 0xf48cc2f2, "__free_pages" },
	{ 0x3c23ff1a, "usb_submit_urb" },
	{ 0x8a5704bf, "_dev_info" },
	{ 0x49c62f3a, "ieee80211_stop_tx_ba_cb_irqsafe" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0xbcb36fe4, "hugetlb_optimize_vmemmap_key" },
	{ 0xea3c74e, "tasklet_kill" },
	{ 0x881f7fc5, "debugfs_attr_read" },
	{ 0x44353940, "ieee80211_queue_delayed_work" },
	{ 0x807c6fd3, "devm_kmemdup" },
	{ 0xad5f0017, "perf_trace_buf_alloc" },
	{ 0x1f9e3b2, "perf_trace_run_bpf_submit" },
	{ 0xcc9a65f9, "_dev_err" },
	{ 0xaeb42876, "usb_free_coherent" },
	{ 0xfdf304fd, "skb_pull" },
	{ 0x5fd1f232, "simple_attr_release" },
	{ 0x2469810f, "__rcu_read_unlock" },
	{ 0x8c03d20c, "destroy_workqueue" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0xfebffc97, "skb_push" },
	{ 0x3a2a67f1, "usb_control_msg" },
	{ 0xd6fecb37, "seq_putc" },
	{ 0x26cba853, "usb_poison_urb" },
	{ 0xc5cf3d94, "trace_event_reg" },
	{ 0x9d2ab8ac, "__tasklet_schedule" },
	{ 0xf9464647, "ieee80211_wake_queues" },
	{ 0x5a5a2271, "__cpu_online_mask" },
	{ 0x3c3fce39, "__local_bh_enable_ip" },
	{ 0xa2086ad3, "ieee80211_free_txskb" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x1924ad07, "ieee80211_alloc_hw_nm" },
	{ 0x4ad33fcd, "usb_deregister" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0xacb3c95c, "bpf_trace_run9" },
	{ 0xc1f51998, "ieee80211_rx_list" },
	{ 0xaae87f47, "_dev_warn" },
	{ 0x31549b2a, "__x86_indirect_thunk_r10" },
	{ 0x64aeeffb, "__alloc_pages" },
	{ 0x5b8239ca, "__x86_return_thunk" },
	{ 0xd9fa7eda, "debugfs_create_u32" },
	{ 0x5a1bbeb3, "ieee80211_tx_status" },
	{ 0x57d37597, "ieee80211_stop_queue" },
	{ 0xdc375ace, "ieee80211_stop_queues" },
	{ 0x29429c46, "skb_trim" },
	{ 0xd8a44097, "bpf_trace_run3" },
	{ 0x6c99329b, "seq_read" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0x7a2af7b4, "cpu_number" },
	{ 0x4629334c, "__preempt_count" },
	{ 0xa96db9d6, "debugfs_create_file" },
	{ 0x255a7547, "trace_event_buffer_reserve" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x9fa7184a, "cancel_delayed_work_sync" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0xfe4e1339, "ieee80211_unregister_hw" },
	{ 0x66b4cc41, "kmemdup" },
	{ 0x6667e88c, "__folio_put" },
	{ 0x4989be28, "usb_kill_urb" },
	{ 0x56470118, "__warn_printk" },
	{ 0xac8427d8, "seq_printf" },
	{ 0xffeedf6a, "delayed_work_timer_fn" },
	{ 0x7ef39823, "ieee80211_hdrlen" },
	{ 0xc3690fc, "_raw_spin_lock_bh" },
	{ 0xdda83385, "seq_puts" },
	{ 0xdc5d0c58, "single_release" },
	{ 0x41ed3709, "get_random_bytes" },
	{ 0xae6c33b7, "firmware_request_cache" },
	{ 0x52dd86bf, "kmalloc_trace" },
	{ 0xa07d1b3c, "tasklet_setup" },
	{ 0x754d539c, "strlen" },
	{ 0x688e72e1, "__SCT__preempt_schedule_notrace" },
	{ 0xac353690, "debugfs_create_u8" },
	{ 0x8c694071, "single_open" },
	{ 0xd4212f2c, "debugfs_create_dir" },
	{ 0x7381287f, "trace_handle_return" },
	{ 0xf9a482f9, "msleep" },
	{ 0xc80d0404, "kmalloc_caches" },
	{ 0x160c03af, "module_layout" },
};

MODULE_INFO(depends, "usbcore,mac80211,cfg80211");

MODULE_ALIAS("usb:v0B05p17D3d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0E8Dp760Ad*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0E8Dp760Bd*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v13D3p3431d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v13D3p3434d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v148Fp7601d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v148Fp760Ad*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v148Fp760Bd*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v148Fp760Cd*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v148Fp760Dd*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v2001p3D04d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v2717p4106d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v2955p0001d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v2955p1001d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v2955p1003d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v2A5Fp1000d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v7392p7710d*dc*dsc*dp*ic*isc*ip*in*");
