#include <check.h>
#include <math.h>
#include <stdlib.h>

#include "../viewer.h"

START_TEST(test_open_obj_1) {
  float** vertex_matrix = NULL;
  char* filename = "./models/no_file.obj";
  int vertex_count = 0, edges_count = 0;
  side* ptr = NULL;
  vertex_matrix = open_obj(filename, &vertex_count, &edges_count, &ptr);
  ck_assert_ptr_eq(vertex_matrix, NULL);
  ck_assert_int_eq(vertex_count, 0);
  ck_assert_int_eq(edges_count, 0);
  ck_assert_ptr_eq(ptr, NULL);
}
END_TEST

START_TEST(test_open_obj_2) {
  float** vertex_matrix = NULL;
  float vertex_matrix_check[8][3] = {
      {0, 0.5, 0}, {-1, -0.5, -1}, {1, -0.5, -1}, {1, -0.5, 1}, {-1, -0.5, 1}};
  char* filename = "./models/pyramid.obj";
  int vertex_count = 0, edges_count = 0;
  side* ptr = NULL;
  side* tmp;
  vertex_matrix = open_obj(filename, &vertex_count, &edges_count, &ptr);
  while (ptr) {
    tmp = ptr;
    free(ptr->edges);
    ptr = ptr->ptr;
    free(tmp);
  }
  for (int i = 0; i < vertex_count; i++)
    for (int j = 0; j < 3; j++)
      ck_assert_float_eq(vertex_matrix[i][j], vertex_matrix_check[i][j]);
  ck_assert_int_eq(vertex_count, 5);
  ck_assert_int_eq(edges_count, 18);
  free(vertex_matrix);
}
END_TEST

START_TEST(test_rotate_1) {
  float** vertex_matrix = (float**)malloc(sizeof(float*) + 3 * sizeof(float));
  float* start = (float*)((char*)vertex_matrix + sizeof(float*));
  vertex_matrix[0] = start;
  vertex_matrix[0][0] = 1;
  vertex_matrix[0][1] = 1;
  vertex_matrix[0][2] = 1;
  rotate(vertex_matrix, 90, 'x', 1);
  ck_assert_float_eq(vertex_matrix[0][0], 1);
  ck_assert_float_eq(vertex_matrix[0][1], -1);
  ck_assert_float_eq(vertex_matrix[0][2], 1);
  free(vertex_matrix);
}
END_TEST

START_TEST(test_rotate_2) {
  float** vertex_matrix = (float**)malloc(sizeof(float*) + 3 * sizeof(float));
  float* start = (float*)((char*)vertex_matrix + sizeof(float*));
  vertex_matrix[0] = start;
  vertex_matrix[0][0] = 1;
  vertex_matrix[0][1] = 1;
  vertex_matrix[0][2] = 1;
  rotate(vertex_matrix, 90, 'y', 1);
  ck_assert_float_eq(vertex_matrix[0][0], 1);
  ck_assert_float_eq(vertex_matrix[0][1], 1);
  ck_assert_float_eq(vertex_matrix[0][2], -1);
  free(vertex_matrix);
}
END_TEST

START_TEST(test_rotate_3) {
  float** vertex_matrix = (float**)malloc(sizeof(float*) + 3 * sizeof(float));
  float* start = (float*)((char*)vertex_matrix + sizeof(float*));
  vertex_matrix[0] = start;
  vertex_matrix[0][0] = 1;
  vertex_matrix[0][1] = 1;
  vertex_matrix[0][2] = 1;
  rotate(vertex_matrix, 90, 'z', 1);
  ck_assert_float_eq(vertex_matrix[0][0], -1);
  ck_assert_float_eq(vertex_matrix[0][1], 1);
  ck_assert_float_eq(vertex_matrix[0][2], 1);
  free(vertex_matrix);
}
END_TEST

START_TEST(test_rotate_4) {
  float** vertex_matrix = (float**)malloc(sizeof(float*) + 3 * sizeof(float));
  float* start = (float*)((char*)vertex_matrix + sizeof(float*));
  vertex_matrix[0] = start;
  vertex_matrix[0][0] = 1;
  vertex_matrix[0][1] = 1;
  vertex_matrix[0][2] = 1;
  rotate(vertex_matrix, 90, 'X', 1);
  ck_assert_float_eq(vertex_matrix[0][0], 1);
  ck_assert_float_eq(vertex_matrix[0][1], -1);
  ck_assert_float_eq(vertex_matrix[0][2], 1);
  free(vertex_matrix);
}
END_TEST

START_TEST(test_rotate_5) {
  float** vertex_matrix = (float**)malloc(sizeof(float*) + 3 * sizeof(float));
  float* start = (float*)((char*)vertex_matrix + sizeof(float*));
  vertex_matrix[0] = start;
  vertex_matrix[0][0] = 1;
  vertex_matrix[0][1] = 1;
  vertex_matrix[0][2] = 1;
  rotate(vertex_matrix, 90, 'Y', 1);
  ck_assert_float_eq(vertex_matrix[0][0], 1);
  ck_assert_float_eq(vertex_matrix[0][1], 1);
  ck_assert_float_eq(vertex_matrix[0][2], -1);
  free(vertex_matrix);
}
END_TEST

START_TEST(test_rotate_6) {
  float** vertex_matrix = (float**)malloc(sizeof(float*) + 3 * sizeof(float));
  float* start = (float*)((char*)vertex_matrix + sizeof(float*));
  vertex_matrix[0] = start;
  vertex_matrix[0][0] = 1;
  vertex_matrix[0][1] = 1;
  vertex_matrix[0][2] = 1;
  rotate(vertex_matrix, 90, 'Z', 1);
  ck_assert_float_eq(vertex_matrix[0][0], -1);
  ck_assert_float_eq(vertex_matrix[0][1], 1);
  ck_assert_float_eq(vertex_matrix[0][2], 1);
  free(vertex_matrix);
}
END_TEST

START_TEST(test_rotate_7) {
  float** vertex_matrix = (float**)malloc(sizeof(float*) + 3 * sizeof(float));
  float* start = (float*)((char*)vertex_matrix + sizeof(float*));
  vertex_matrix[0] = start;
  vertex_matrix[0][0] = 1;
  vertex_matrix[0][1] = 1;
  vertex_matrix[0][2] = 1;
  rotate(vertex_matrix, 90, 'Q', 1);
  ck_assert_float_eq(vertex_matrix[0][0], 1);
  ck_assert_float_eq(vertex_matrix[0][1], 1);
  ck_assert_float_eq(vertex_matrix[0][2], 1);
  free(vertex_matrix);
}
END_TEST

START_TEST(test_centering_1) {
  int k = 2;
  float max_coord[2][3] = {{0, 2, 0}, {0, 0, 0}};
  float** vertex_matrix =
      (float**)malloc(2 * sizeof(float*) + 3 * 2 * sizeof(float));
  float* start = (float*)((char*)vertex_matrix + 2 * sizeof(float*));
  for (int i = 0; i < 2; i++) vertex_matrix[i] = start + i * 3;
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 3; j++) vertex_matrix[i][j] = 1;
  centering(max_coord, vertex_matrix, &k);
  ck_assert_float_eq(vertex_matrix[0][0], 1);
  ck_assert_float_eq(vertex_matrix[0][1], 0);
  ck_assert_float_eq(vertex_matrix[0][2], 1);
  ck_assert_float_eq(vertex_matrix[1][0], 1);
  ck_assert_float_eq(vertex_matrix[1][1], 0);
  ck_assert_float_eq(vertex_matrix[1][2], 1);
  free(vertex_matrix);
}
END_TEST

START_TEST(test_centering_2) {
  int k = 2;
  float max_coord[2][3] = {{0, 0, 2}, {0, 0, 0}};
  float** vertex_matrix =
      (float**)malloc(2 * sizeof(float*) + 3 * 2 * sizeof(float));
  float* start = (float*)((char*)vertex_matrix + 2 * sizeof(float*));
  for (int i = 0; i < 2; i++) vertex_matrix[i] = start + i * 3;
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 3; j++) vertex_matrix[i][j] = 1;
  centering(max_coord, vertex_matrix, &k);
  ck_assert_float_eq(vertex_matrix[0][0], 1);
  ck_assert_float_eq(vertex_matrix[0][1], 1);
  ck_assert_float_eq(vertex_matrix[0][2], 0);
  ck_assert_float_eq(vertex_matrix[1][0], 1);
  ck_assert_float_eq(vertex_matrix[1][1], 1);
  ck_assert_float_eq(vertex_matrix[1][2], 0);
  free(vertex_matrix);
}
END_TEST

START_TEST(test_scan_edges_1) {
  side* ptr;
  side* tmp = NULL;
  char* buffer = "f -5 6 34";
  ptr = scan_edges(buffer, tmp, 100);
  ck_assert_float_eq(ptr->edge_count, 3);
  ck_assert_int_eq(ptr->edges[0], 96);
  ck_assert_int_eq(ptr->edges[1], 6);
  ck_assert_int_eq(ptr->edges[2], 34);
  free(ptr->edges);
  free(ptr);
}
END_TEST

START_TEST(test_scan_edges_2) {
  side* ptr;
  side* tmp = NULL;
  char* buffer = "f  -5 6 34";
  ptr = scan_edges(buffer, tmp, 100);
  ck_assert_float_eq(ptr->edge_count, 3);
  ck_assert_int_eq(ptr->edges[0], 96);
  ck_assert_int_eq(ptr->edges[1], 6);
  ck_assert_int_eq(ptr->edges[2], 34);
  free(ptr->edges);
  free(ptr);
}
END_TEST

START_TEST(test_scan_edges_3) {
  side* ptr;
  side* tmp = NULL;
  char* buffer = "f  y -5 6 34";
  ptr = scan_edges(buffer, tmp, 100);
  ck_assert_float_eq(ptr->edge_count, 3);
  ck_assert_int_eq(ptr->edges[0], 96);
  ck_assert_int_eq(ptr->edges[1], 6);
  ck_assert_int_eq(ptr->edges[2], 34);
  free(ptr->edges);
  free(ptr);
}
END_TEST

START_TEST(test_scan_edges_4) {
  side* ptr = NULL;
  side* tmp = NULL;
  char* buffer = "f ";
  ptr = scan_edges(buffer, tmp, 100);
  ck_assert_ptr_null(ptr);
  ck_assert_ptr_null(tmp);
}
END_TEST

START_TEST(test_moveVertex_1) {
  float** vertex_matrix = (float**)malloc(sizeof(float*) + 3 * sizeof(float));
  float* start = (float*)((char*)vertex_matrix + sizeof(float*));
  vertex_matrix[0] = start;
  vertex_matrix[0][0] = 1;
  vertex_matrix[0][1] = 1;
  vertex_matrix[0][2] = 1;
  moveVertex(vertex_matrix, 1, 1, 0, 0);
  ck_assert_float_eq(vertex_matrix[0][0], 2);
  ck_assert_float_eq(vertex_matrix[0][1], 1);
  ck_assert_float_eq(vertex_matrix[0][2], 1);
  free(vertex_matrix);
}
END_TEST

Suite* test_open_obj(void) {
  Suite* s;
  TCase* tc_core;

  s = suite_create("Test_open_obj");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_open_obj_1);
  tcase_add_test(tc_core, test_open_obj_2);
  suite_add_tcase(s, tc_core);

  return s;
}

Suite* test_rotate(void) {
  Suite* s;
  TCase* tc_core;

  s = suite_create("Test_rotate");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_rotate_1);
  tcase_add_test(tc_core, test_rotate_2);
  tcase_add_test(tc_core, test_rotate_3);
  tcase_add_test(tc_core, test_rotate_4);
  tcase_add_test(tc_core, test_rotate_5);
  tcase_add_test(tc_core, test_rotate_6);
  tcase_add_test(tc_core, test_rotate_7);
  suite_add_tcase(s, tc_core);

  return s;
}

Suite* test_centering(void) {
  Suite* s;
  TCase* tc_core;

  s = suite_create("Test_centering");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_centering_1);
  tcase_add_test(tc_core, test_centering_2);
  suite_add_tcase(s, tc_core);

  return s;
}

Suite* test_scan_edges(void) {
  Suite* s;
  TCase* tc_core;

  s = suite_create("Test_scan_edges");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_scan_edges_1);
  tcase_add_test(tc_core, test_scan_edges_2);
  tcase_add_test(tc_core, test_scan_edges_3);
  tcase_add_test(tc_core, test_scan_edges_4);
  suite_add_tcase(s, tc_core);

  return s;
}

Suite* test_moveVertex(void) {
  Suite* s;
  TCase* tc_core;

  s = suite_create("Test_moveVertex");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_moveVertex_1);
  suite_add_tcase(s, tc_core);

  return s;
}

int main(void) {
  int no_failed = 0;
  Suite* s[] = {test_open_obj(), test_rotate(), test_centering(),
                test_scan_edges(), test_moveVertex()};
  SRunner* runner;

  for (int i = 0; i < 5; i++) {
    runner = srunner_create(s[i]);
    srunner_run_all(runner, CK_NORMAL);
    no_failed = srunner_ntests_failed(runner);
    srunner_free(runner);
  }

  return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
