/*
 *  junos/mm.h    -- kernel mm interface.
 *
 *  This file is part of JunOS Operating System.
 *
 *  Copyright (C) 2016, Liu Xiaofeng <lxf.junos@aliyun.com>
 *  Licensed under MIT, http://opensource.org/licenses/MIT.
 */

#ifndef _JUNOS_MM_H
#define _JUNOS_MM_H

#define PAGE_SIZE	4096

typedef unsigned long phys_t;
typedef unsigned long virt_t;

#define __pa(addr)  ((virt_t)(addr)-0xc0000000)
#define __va(addr)  ((phys_t)(addr)+0xc0000000)

struct page_struct {
	int    count;
	phys_t addr;
	struct page_struct *next;
};

extern phys_t get_page(void);
extern void   put_page(phys_t addr);
extern phys_t unmap_page(virt_t line, long pdtr);
extern void   map_page(virt_t va, phys_t pa, long pdtr);
extern long   copy_mm(void);
extern void   alloc_mm(long pdtr, long addr, long size);
extern void   free_mm(void);

#endif /* _JUNOS_MM_H */
