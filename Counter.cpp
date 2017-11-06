#include "Counter.h"

Counter::Counter() {
    count = 0;
}
void Counter::AddRef() {
    count++;
    printf("Increment %d\n", count);
}
size_t Counter::Release() {
    printf("Decrement %d\n", count-1);
    count--;
}