#include <stdint.h>
#include <stdio.h>
#include <string.h>

extern uint64_t get_cycles();
extern uint64_t find_string(uint64_t xs, int ns);


int main(void)
{
    int n = 4;
    uint64_t test_data[] = {0x0f00000000000000,
                            0x0000000000000000,
                            0x0123456789abcdef};

    /* measure cycles */
    uint64_t oldcount = get_cycles();
    //printf("%d  0x%016llx %lld\n",1,test_data[0],find_string(test_data[0], n));
    //printf("%d  0x%016llx %d\n",2,test_data[1],find_string(test_data[1], n));
    //printf("%d  0x%016llx %lld\n",3,test_data[2],find_string(test_data[2], n));
    
    printf("%lld\n",find_string(0x0f00000000000000, 4));
    printf("%d\n",find_string(0x0000000000000000, 4));
    printf("%lld\n",find_string(0x0123456789abcdef, 4));
    
    uint64_t cyclecount = get_cycles() - oldcount;
    printf("cycle count: %u\n", (unsigned int) cyclecount);
    return 0;
}
