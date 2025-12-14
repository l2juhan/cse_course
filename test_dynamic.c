#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

/* 함수 포인터 타입 정의 */
typedef void (*print_all_courses_t)(void);
typedef void (*print_courses_by_category_t)(const char*);
typedef void (*print_categories_t)(void);
typedef const char* (*get_course_category_t)(const char*);
typedef int (*get_course_count_t)(const char*);

int main(void) {
    void* handle;
    char* error;
    
    printf("=== 동적 라이브러리 런타임 링킹 테스트 (dlopen) ===\n\n");
    
    /* 공유 라이브러리 로드 */
    handle = dlopen("./libcse.so", RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "dlopen 오류: %s\n", dlerror());
        exit(EXIT_FAILURE);
    }
    printf("[OK] 라이브러리 로드 성공: libcse.so\n\n");
    
    /* 에러 초기화 */
    dlerror();
    
    /* 함수 심볼 로드 */
    print_all_courses_t print_all_courses = 
        (print_all_courses_t)dlsym(handle, "print_all_courses");
    if ((error = dlerror()) != NULL) {
        fprintf(stderr, "dlsym 오류: %s\n", error);
        dlclose(handle);
        exit(EXIT_FAILURE);
    }
    
    print_courses_by_category_t print_courses_by_category = 
        (print_courses_by_category_t)dlsym(handle, "print_courses_by_category");
    if ((error = dlerror()) != NULL) {
        fprintf(stderr, "dlsym 오류: %s\n", error);
        dlclose(handle);
        exit(EXIT_FAILURE);
    }
    
    print_categories_t print_categories = 
        (print_categories_t)dlsym(handle, "print_categories");
    if ((error = dlerror()) != NULL) {
        fprintf(stderr, "dlsym 오류: %s\n", error);
        dlclose(handle);
        exit(EXIT_FAILURE);
    }
    
    get_course_category_t get_course_category = 
        (get_course_category_t)dlsym(handle, "get_course_category");
    if ((error = dlerror()) != NULL) {
        fprintf(stderr, "dlsym 오류: %s\n", error);
        dlclose(handle);
        exit(EXIT_FAILURE);
    }
    
    get_course_count_t get_course_count = 
        (get_course_count_t)dlsym(handle, "get_course_count");
    if ((error = dlerror()) != NULL) {
        fprintf(stderr, "dlsym 오류: %s\n", error);
        dlclose(handle);
        exit(EXIT_FAILURE);
    }
    
    printf("[OK] 모든 함수 심볼 로드 성공\n\n");
    
    /* 함수 호출 테스트 */
    printf("[ 테스트 1: print_categories() ]\n");
    print_categories();
    printf("\n");
    
    printf("[ 테스트 2: print_courses_by_category(\"전공선택\") ]\n");
    print_courses_by_category("전공선택");
    printf("\n");
    
    printf("[ 테스트 3: get_course_category() ]\n");
    const char* course = "딥러닝";
    const char* category = get_course_category(course);
    printf("  '%s' -> %s\n", course, category ? category : "찾을 수 없음");
    printf("\n");
    
    printf("[ 테스트 4: get_course_count() ]\n");
    printf("  전공선택 과목 수: %d\n", get_course_count("전공선택"));
    printf("\n");
    
    /* 라이브러리 언로드 */
    if (dlclose(handle) != 0) {
        fprintf(stderr, "dlclose 오류: %s\n", dlerror());
        exit(EXIT_FAILURE);
    }
    printf("[OK] 라이브러리 언로드 성공\n");
    
    return 0;
}
