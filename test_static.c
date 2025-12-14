#include <stdio.h>
#include "cse_courses.h"

int main(void) {
    printf("=== 정적 라이브러리 테스트 (libcse.a) ===\n\n");
    
    /* 1. 카테고리 목록 출력 */
    printf("[ 테스트 1: 카테고리 목록 ]\n");
    print_categories();
    printf("\n");
    
    /* 2. 전공필수 과목 출력 */
    printf("[ 테스트 2: 전공필수 과목 조회 ]\n");
    print_courses_by_category(CAT_MAJOR_REQUIRED);
    printf("\n");
    
    /* 3. 특정 과목 카테고리 조회 */
    printf("[ 테스트 3: 과목 카테고리 조회 ]\n");
    const char* course1 = "시스템 프로그래밍";
    const char* course2 = "자료구조";
    const char* course3 = "존재하지않는과목";
    
    const char* cat1 = get_course_category(course1);
    const char* cat2 = get_course_category(course2);
    const char* cat3 = get_course_category(course3);
    
    printf("  '%s' -> %s\n", course1, cat1 ? cat1 : "찾을 수 없음");
    printf("  '%s' -> %s\n", course2, cat2 ? cat2 : "찾을 수 없음");
    printf("  '%s' -> %s\n", course3, cat3 ? cat3 : "찾을 수 없음");
    printf("\n");
    
    /* 4. 카테고리별 과목 수 */
    printf("[ 테스트 4: 카테고리별 과목 수 ]\n");
    printf("  교양필수: %d과목\n", get_course_count(CAT_GENERAL_REQUIRED));
    printf("  전공필수: %d과목\n", get_course_count(CAT_MAJOR_REQUIRED));
    printf("  전공선택: %d과목\n", get_course_count(CAT_MAJOR_ELECTIVE));
    printf("  전공기초: %d과목\n", get_course_count(CAT_MAJOR_BASIC));
    printf("\n");
    
    /* 5. 전체 과목 출력 */
    printf("[ 테스트 5: 전체 과목 출력 ]\n");
    print_all_courses();
    
    return 0;
}
