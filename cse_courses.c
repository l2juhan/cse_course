#include <stdio.h>
#include <string.h>
#include "cse_courses.h"

/* 교과목 데이터 구조체 */
typedef struct {
    const char* category;
    const char** courses;
    int count;
} CourseCategory;

/* 교양필수 과목 */
static const char* general_required[] = {
    "커리어 디자인 1",
    "문제해결을 위한 글쓰기",
    "미래사회와 소프트웨어-IT계열",
    "커리어 디자인2",
    "의사소통 영어",
    "크로스오버1",
    "크로스오버3"
};

/* 전공필수 과목 */
static const char* major_required[] = {
    "객체지향프로그래밍1",
    "객체지향프로그래밍2",
    "이산구조",
    "자료구조",
    "컴퓨터공학 종합설계"
};

/* 전공선택 과목 */
static const char* major_elective[] = {
    "실전산학프로젝트",
    "컴퓨터공학입문 프로그래밍",
    "컴퓨터기반선형대수",
    "오픈소스SW개론",
    "논리회로",
    "컴퓨터응용확률",
    "컴퓨터구조론",
    "컴퓨터 네트워크",
    "시스템분석",
    "문제해결기법",
    "소프트웨어공학",
    "알고리즘",
    "프로그래밍언어 이론",
    "데이터베이스",
    "클라우드컴퓨팅",
    "데이터마이닝",
    "인공지능",
    "기계학습",
    "딥러닝",
    "오퍼레이팅시스템",
    "시스템 프로그래밍",
    "디지털시스템설계",
    "병렬 프로그래밍",
    "임베디드소프트웨어",
    "컴파일러",
    "컴퓨터보안",
    "인터넷 프로그래밍",
    "자바기반응용프로그래밍",
    "컴퓨터그래픽스",
    "오픈소스응용프로그래밍",
    "게임프로그래밍",
    "멀티미디어 컴퓨팅",
    "IoT와 엣지컴퓨팅 개론"
};

/* 전공기초 과목 */
static const char* major_basic[] = {
    "통계학",
    "일반수학1",
    "일반수학2"
};

/* 카테고리 배열 */
static const CourseCategory categories[] = {
    { CAT_GENERAL_REQUIRED, general_required, sizeof(general_required) / sizeof(general_required[0]) },
    { CAT_MAJOR_REQUIRED, major_required, sizeof(major_required) / sizeof(major_required[0]) },
    { CAT_MAJOR_ELECTIVE, major_elective, sizeof(major_elective) / sizeof(major_elective[0]) },
    { CAT_MAJOR_BASIC, major_basic, sizeof(major_basic) / sizeof(major_basic[0]) }
};

static const int NUM_CATEGORIES = sizeof(categories) / sizeof(categories[0]);

/* 카테고리 찾기 헬퍼 함수 */
static const CourseCategory* find_category(const char* category) {
    for (int i = 0; i < NUM_CATEGORIES; i++) {
        if (strcmp(categories[i].category, category) == 0) {
            return &categories[i];
        }
    }
    return NULL;
}

void print_all_courses(void) {
    printf("========================================\n");
    printf("    컴퓨터공학과 전체 교과목 목록\n");
    printf("========================================\n\n");
    
    for (int i = 0; i < NUM_CATEGORIES; i++) {
        printf("[%s] (%d과목)\n", categories[i].category, categories[i].count);
        for (int j = 0; j < categories[i].count; j++) {
            printf("  - %s\n", categories[i].courses[j]);
        }
        printf("\n");
    }
}

void print_courses_by_category(const char* category) {
    const CourseCategory* cat = find_category(category);
    
    if (cat == NULL) {
        printf("오류: '%s' 카테고리를 찾을 수 없습니다.\n", category);
        return;
    }
    
    printf("[%s] (%d과목)\n", cat->category, cat->count);
    for (int i = 0; i < cat->count; i++) {
        printf("  - %s\n", cat->courses[i]);
    }
}

void print_categories(void) {
    printf("========================================\n");
    printf("         카테고리 목록\n");
    printf("========================================\n");
    
    for (int i = 0; i < NUM_CATEGORIES; i++) {
        printf("  %d. %s (%d과목)\n", i + 1, categories[i].category, categories[i].count);
    }
}

const char* get_course_category(const char* course_name) {
    for (int i = 0; i < NUM_CATEGORIES; i++) {
        for (int j = 0; j < categories[i].count; j++) {
            if (strcmp(categories[i].courses[j], course_name) == 0) {
                return categories[i].category;
            }
        }
    }
    return NULL;
}

int get_course_count(const char* category) {
    const CourseCategory* cat = find_category(category);
    
    if (cat == NULL) {
        return -1;
    }
    
    return cat->count;
}
