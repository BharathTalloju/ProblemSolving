#include <stdio.h>
#include <malloc.h>

void *my_malloc_hook(size_t, const void *);
//void *my_realloc_hook(size_t, const void *);
//void my_free_hook(size_t, const void *);
static void my_init_hook(void);

static void *(*old_malloc_hook)(size_t, const void *);
void  (*__malloc_initialize_hook) (void) = my_init_hook;

static void my_init_hook(void){
    old_malloc_hook = __malloc_hook;
    __malloc_hook = my_malloc_hook;
}


static void revert_hooks(){
    __malloc_hook = old_malloc_hook;
}

void *my_malloc_hook(size_t s, const void *caller){
    void *result = NULL;
    FILE *fp = fopen("my_heap_log_file", "a");

    revert_hooks();
    result = malloc(s);
    
    old_malloc_hook = __malloc_hook;
    __malloc_hook = my_malloc_hook;

    fprintf(fp, "Memory allocated of size %d at %p for function %p\n", s, result, caller);
    fclose(fp);

    return result;
}
// (*__MALLOC_HOOK_VOLATILE)
