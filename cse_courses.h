#ifndef CSE_COURSES_H
#define CSE_COURSES_H

/**
 * CSE Courses Library
 * 컴퓨터공학과 교과목 조회 라이브러리
 */

// 카테고리 상수 정의
#define CAT_GENERAL_REQUIRED    "교양필수"
#define CAT_MAJOR_REQUIRED      "전공필수"
#define CAT_MAJOR_ELECTIVE      "전공선택"
#define CAT_MAJOR_BASIC         "전공기초"

/**
 * 전체 과목 출력
 */
void print_all_courses(void);

/**
 * 카테고리별 과목 출력
 * @param category 카테고리명 (교양필수, 전공필수, 전공선택, 전공기초)
 */
void print_courses_by_category(const char* category);

/**
 * 카테고리 목록 출력
 */
void print_categories(void);

/**
 * 특정 과목이 어느 카테고리인지 조회
 * @param course_name 과목명
 * @return 카테고리명 (없으면 NULL)
 */
const char* get_course_category(const char* course_name);

/**
 * 카테고리별 과목 수 반환
 * @param category 카테고리명
 * @return 과목 수 (잘못된 카테고리면 -1)
 */
int get_course_count(const char* category);

#endif /* CSE_COURSES_H */
