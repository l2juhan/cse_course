# CSE Courses Library Makefile

CC = gcc
CFLAGS = -Wall -Wextra -fPIC
AR = ar
ARFLAGS = rcs

# 라이브러리 이름
LIB_NAME = cse
STATIC_LIB = lib$(LIB_NAME).a
SHARED_LIB = lib$(LIB_NAME).so

# 소스 파일
LIB_SRC = cse_courses.c
LIB_OBJ = cse_courses.o

# 테스트 프로그램
TEST_STATIC = test_static
TEST_DYNAMIC = test_dynamic

.PHONY: all clean static shared test

all: static shared test

# 정적 라이브러리 빌드
static: $(STATIC_LIB)

$(STATIC_LIB): $(LIB_OBJ)
	$(AR) $(ARFLAGS) $@ $^
	@echo "[OK] 정적 라이브러리 생성: $(STATIC_LIB)"

# 공유 라이브러리 빌드
shared: $(SHARED_LIB)

$(SHARED_LIB): $(LIB_SRC)
	$(CC) $(CFLAGS) -shared -o $@ $^
	@echo "[OK] 공유 라이브러리 생성: $(SHARED_LIB)"

# 오브젝트 파일
$(LIB_OBJ): $(LIB_SRC) cse_courses.h
	$(CC) $(CFLAGS) -c $< -o $@

# 테스트 프로그램 빌드
test: $(TEST_STATIC) $(TEST_DYNAMIC)

$(TEST_STATIC): test_static.c $(STATIC_LIB)
	$(CC) $(CFLAGS) -o $@ $< $(STATIC_LIB)
	@echo "[OK] 정적 링킹 테스트 프로그램 생성: $(TEST_STATIC)"

$(TEST_DYNAMIC): test_dynamic.c
	$(CC) $(CFLAGS) -o $@ $< -ldl
	@echo "[OK] 동적 링킹 테스트 프로그램 생성: $(TEST_DYNAMIC)"

# 실행
run_static: $(TEST_STATIC)
	@echo "=== 정적 라이브러리 테스트 실행 ==="
	./$(TEST_STATIC)

run_dynamic: $(TEST_DYNAMIC) $(SHARED_LIB)
	@echo "=== 동적 라이브러리 테스트 실행 ==="
	./$(TEST_DYNAMIC)

# 정리
clean:
	rm -f $(LIB_OBJ) $(STATIC_LIB) $(SHARED_LIB) $(TEST_STATIC) $(TEST_DYNAMIC)
	@echo "[OK] 정리 완료"
