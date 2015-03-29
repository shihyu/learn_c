#ifndef _FEATURES_H_
#define _FEATURES_H_

void stats_features_vectors(int fildernum, int feature_vectors[64], float feature_vectors_table[][64]); 
void tarin_feature_begin();
void cal_image_feature(int feature_vector[], char FilePathName[]); 
void stats_feature();

#endif
