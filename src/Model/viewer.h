#ifdef __cplusplus
extern "C" {
#endif

#ifndef VIEWER_H
#define VIEWER_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*!
        \brief Cтруктура, содержащая количество полигонов и ссылку на строчку в
   матрице с координатами
*/

typedef struct side {
  int edge_count;
  int *edges;
  struct side *ptr;
} side;

/*!
        \brief Основная функция открытия файла, определения количества полигонов
   и создания матрицы координат

*/
float **open_obj(char *filename, int *vertex_count, int *edges_count,
                 side **ptr);
/*!
        \brief Вспомогательная функция, непосредстенно звполняет матрицу вершин

        Переводит данные из .obj файла в матрицу вершин
*/
void scan_vertex(char *buffer, float *x, float *y, float *z,
                 float max_coord[2][3]);
/*!
        \brief Вспомогательная функция создания связного списка полигонов

*/
side *scan_edges(char *buffer, side *ptr, int vertex_count);
/*!
        \brief Вспомогательная функция записи максимальных значений координат

*/
void fill_max_coord(float max_coord[2][3], float **vertex_matrix);
/*!
        \brief Вспомогательная функция для центрирования изображения

*/
void centering(float max_coord[2][3], float **vertex_matrix, int *vertex_count);
/*!
        \brief Вспомогательная функция поворота картинки

*/
void rotate(float **vertex_matrix, float rotate_value, char axi,
            int vertex_count);
/*!
        \brief Вспомогательная функция изменения масштаба

*/
void scale(float **vert_mat, float scale_value, int vertex_count);
/*!
        \brief Вспомогательная функция смещения изображения

*/
void moveVertex(float **vert_mat, int vertex_count, float x, float y, float z);
#endif

#ifdef __cplusplus
}
#endif
