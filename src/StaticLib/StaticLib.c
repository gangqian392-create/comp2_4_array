#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義

#include <stdlib.h>		// malloc, free
#include <stdbool.h>	// bool

#include "../include/lib_func.h"

// my_array を要素数nで初期化する
void initialize(my_array* ar, int n)
{
	 if (ar == NULL) return;

    if (n <= 0) {
        free(ar->addr);
        ar->addr = NULL;
        ar->num = 0;
        return;
    }

    int* new_addr = (int*)malloc(sizeof(int) * n);
    if (new_addr == NULL) return;

    int min_num = (ar->num < n) ? ar->num : n;
    for (int i = 0; i < min_num; i++) {
        new_addr[i] = ar->addr[i];
    }
    for (int i = min_num; i < n; i++) {
        new_addr[i] = 0;
    }

    free(ar->addr);
    ar->addr = new_addr;
    ar->num = n;
}

bool set(my_array* ar, int index, int val)
{
    if (ar == NULL || ar->addr == NULL) return false;
    if (index < 0 || index >= ar->num) return false;
    ar->addr[index] = val;
    return true;
}

int get(const my_array* ar, int index)
{
    if (ar == NULL || ar->addr == NULL) return 0;
    if (index < 0 || index >= ar->num) return 0;
    return ar->addr[index];
}

int size(const my_array* ar)
{
    if (ar == NULL) return 0;
    return ar->num;
}

	