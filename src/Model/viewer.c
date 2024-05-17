#ifdef __cplusplus
extern "C" {
#endif

#include "viewer.h"

float **open_obj(char *filename, int *vertex_count, int *edges_count,
                 side **ptr) {
  float **vertex_matrix = NULL;
  int counter = 0;
  float max_coord[2][3] = {{0, 0, 0}, {0, 0, 0}};
  char buffer[256];
  *vertex_count = 0;
  *edges_count = 0;
  FILE *file;
  file = fopen(filename, "r");
  if (file) {
    while (fgets(buffer, 256, file) != NULL)
      if (buffer[0] == 'v' && buffer[1] == ' ')
        *vertex_count = *vertex_count + 1;
      else if (buffer[0] == 'f' && buffer[1] == ' ') {
        *ptr = scan_edges(buffer, *ptr, *vertex_count);
        *edges_count += (*ptr)->edge_count;
      }
    if (*vertex_count)
      vertex_matrix = (float **)malloc((*vertex_count) * sizeof(float *) +
                                       3 * (*vertex_count) * sizeof(float));
    float *start =
        (float *)((char *)vertex_matrix + *vertex_count * sizeof(float *));
    for (int i = 0; i < *vertex_count; i++) vertex_matrix[i] = start + i * 3;
    fseek(file, 0, SEEK_SET);
    while (fgets(buffer, 256, file) != NULL)
      if (buffer[0] == 'v' && buffer[1] == ' ') {
        scan_vertex(buffer, &(vertex_matrix[counter][0]),
                    &(vertex_matrix[counter][1]), &(vertex_matrix[counter][2]),
                    max_coord);
        if (counter == 0) {
          fill_max_coord(max_coord, vertex_matrix);
        }
        counter++;
      }
    fclose(file);
    centering(max_coord, vertex_matrix, vertex_count);
  }
  return vertex_matrix;
}

void scan_vertex(char *buffer, float *x, float *y, float *z,
                 float max_coord[2][3]) {
  float *ptr[3] = {x, y, z};
  float value;
  int k = 0;
  for (int i = 0; buffer[i] != '\0'; i++) {
    if (buffer[i] == ' ' && buffer[i + 1] != '\n' && buffer[i + 1] != '\0' &&
        buffer[i + 1] != '\t' && buffer[i + 1] != ' ') {
      value = atof(buffer + i);
      *ptr[k] = value;
      if (value > max_coord[0][k]) max_coord[0][k] = value;
      if (value < max_coord[1][k]) max_coord[1][k] = value;
      k++;
    }
  }
}

side *scan_edges(char *buffer, side *ptr, int vertex_count) {
  int count = 0, i = 1, j = 0, k = 0;
  side *new_ptr = ptr;
  int *edges;
  char str[256];
  while (buffer[i] != '\0') {
    if (buffer[i] == ' ' &&
        ((buffer[i + 1] > 47 && buffer[i + 1] < 58) || buffer[i + 1] == '-'))
      count++;
    i++;
  }
  if (count > 1) {
    edges = (int *)calloc(1, count * sizeof(int));
    new_ptr = (side *)calloc(1, sizeof(side));
    new_ptr->edge_count = count;
    new_ptr->ptr = ptr;
    for (i = 1; buffer[i] != '\0'; i++) {
      if (buffer[i] == ' ' && ((buffer[i + 1] > 47 && buffer[i + 1] < 58) ||
                               buffer[i + 1] == '-')) {
        for (j = 0; buffer[i + 1 + j] != ' ' && buffer[i + 1 + j] != '\0';
             j++) {
          str[j] = buffer[i + 1 + j];
        }
        str[j] = '\0';
        i += j;
        edges[k] =
            (atof(str) > 0) ? (atof(str)) : (vertex_count + atof(str) + 1);
        k++;
      }
    }
    new_ptr->edges = edges;
  }
  return new_ptr;
}

void fill_max_coord(float max_coord[2][3], float **vertex_matrix) {
  max_coord[0][0] = vertex_matrix[0][0];
  max_coord[0][1] = vertex_matrix[0][1];
  max_coord[0][2] = vertex_matrix[0][2];
  max_coord[1][0] = vertex_matrix[0][0];
  max_coord[1][1] = vertex_matrix[0][1];
  max_coord[1][2] = vertex_matrix[0][2];
}

void centering(float max_coord[2][3], float **vertex_matrix,
               int *vertex_count) {
  float max_lenth;
  moveVertex(vertex_matrix, *vertex_count,
             -(max_coord[0][0] + max_coord[1][0]) / 2,
             -(max_coord[0][1] + max_coord[1][1]) / 2,
             -(max_coord[0][2] + max_coord[1][2]) / 2);
  max_lenth = max_coord[0][0] - max_coord[1][0];
  if (max_lenth < (max_coord[0][1] - max_coord[1][1]))
    max_lenth = max_coord[0][1] - max_coord[1][1];
  if (max_lenth < (max_coord[0][2] - max_coord[1][2]))
    max_lenth = max_coord[0][2] - max_coord[1][2];
  scale(vertex_matrix, 2 / max_lenth, *vertex_count);
}

void rotate(float **vert_mat, float rotate_value, char axi, int vertex_count) {
  float sina = sin((M_PI / 180) * rotate_value);
  float cosa = cos((M_PI / 180) * rotate_value);
  if (axi == 'x' || axi == 'X') {
    for (int i = 0; i < vertex_count; i++) {
      float v_m_tmp[3] = {vert_mat[i][0], vert_mat[i][1], vert_mat[i][2]};
      vert_mat[i][0] = v_m_tmp[0];
      vert_mat[i][1] = v_m_tmp[1] * cosa + v_m_tmp[2] * (-sina);
      vert_mat[i][2] = v_m_tmp[1] * sina + v_m_tmp[2] * cosa;
    }
  } else if (axi == 'y' || axi == 'Y') {
    for (int i = 0; i < vertex_count; i++) {
      float v_m_tmp[3] = {vert_mat[i][0], vert_mat[i][1], vert_mat[i][2]};
      vert_mat[i][0] = v_m_tmp[0] * cosa + v_m_tmp[2] * sina;
      vert_mat[i][1] = v_m_tmp[1];
      vert_mat[i][2] = v_m_tmp[0] * (-sina) + v_m_tmp[2] * cosa;
    }
  } else if (axi == 'z' || axi == 'Z') {
    for (int i = 0; i < vertex_count; i++) {
      float v_m_tmp[3] = {vert_mat[i][0], vert_mat[i][1], vert_mat[i][2]};
      vert_mat[i][0] = v_m_tmp[0] * cosa + v_m_tmp[1] * (-sina);
      vert_mat[i][1] = v_m_tmp[0] * sina + v_m_tmp[1] * cosa;
      vert_mat[i][2] = v_m_tmp[2];
    }
  }
}

void scale(float **vert_mat, float scale_value, int vertex_count) {
  for (int i = 0; i < vertex_count; i++) {
    vert_mat[i][0] = vert_mat[i][0] * scale_value;
    vert_mat[i][1] = vert_mat[i][1] * scale_value;
    vert_mat[i][2] = vert_mat[i][2] * scale_value;
  }
}

void moveVertex(float **vert_mat, int vertex_count, float x, float y, float z) {
  for (int i = 0; i < vertex_count; i++) {
    if (x) vert_mat[i][0] = vert_mat[i][0] + x;
    if (y) vert_mat[i][1] = vert_mat[i][1] + y;
    if (z) vert_mat[i][2] = vert_mat[i][2] + z;
  }
}

#ifdef __cplusplus
}
#endif
