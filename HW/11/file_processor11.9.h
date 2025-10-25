#ifndef C___FILE_PROCESSOR11_9_H
#define C___FILE_PROCESSOR11_9_H

#define FILE_F "F.txt"
#define FILE_H "H.txt" // Допоміжний файл
#define FILE_G "G.txt"

void create_test_file_f(int use_odd_set);

int count_pos_neg(const char* filename, int* pos_count, int* neg_count);

int separate_numbers_to_h(const char* file_f_name, const char* file_h_name);

int process_files_from_h(const char* file_g_name, const char* file_h_name, int pos_count, int neg_count);

#endif //C___FILE_PROCESSOR11_9_H
