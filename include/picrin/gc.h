#ifndef GC_H__
#define GC_H__

enum pic_gc_mark {
  PIC_GC_MARK,
  PIC_GC_UNMARK
};

union header {
  struct {
    union header *ptr;
    size_t size;
    enum pic_gc_mark mark;
  } s;
  long alignment[2];
};

struct heap_page {
  union header *basep, *endp;
  struct heap_page *next;
};

struct pic_heap {
  union header base, *freep;
  struct heap_page *pages;
};

void init_heap(struct pic_heap *);

#endif
